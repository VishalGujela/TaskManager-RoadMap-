#include <iostream>
#include <string>
#include <map>
#include <nlohmann/json.hpp>
#include <fstream>
#include "task.hpp"

using namespace std;
using json = nlohmann::json;

class TaskManager {
	private:
		map<int,Task> tasks;
		void Load(){
			ifstream f("tasks.json");
			if (!f.is_open()){
				return;
			}
			json j;
			f>>j;
			tasks = j.get<map<int,Task>>();
		}

		void Save(const map<int,Task> &tasks){
			ofstream f("tasks.json");
			if (!f.is_open()){
				return;
			}

			json j(tasks);
			f<<j.dump(4);
		}
	public:

		TaskManager(){Load();}

		void ListJSON(const string &statusFilter) {
			json j = json::array();
			for (auto &[id, task] : tasks) {
				if (task.status == statusFilter) {
					j.push_back(task);
				}else if(statusFilter == " "){
					j.push_back(task);
				}
			}
			cout << j.dump(4) << endl;
		}

		int generateAvailableId(){
			int id = 0;
			while (tasks.find(id) != tasks.end()) {
				id++;
			}
			return id;
		}

		int Add(const string &desc){
			for(auto &[id,task]:tasks){
				if (desc == task.description){
					cout<<"Task already exists : ID!!!"<<id<<endl;
					return -1;
				}
			}
			int id = generateAvailableId();
			// tasks[id] = AddDescription(desc); //Should be defined in task return Task
			tasks.emplace(id,Task(id,desc));
			Save(tasks);
			return 0;
		}

		int Delete(int id){
			if (tasks.find(id) == tasks.end()){
				cout<<"Id: "<<id<<" does not exists"<<endl;
				return -1;
			}
			tasks.erase(id);
			Save(tasks);
			return 0;
		}

		int Update(int id,const string &desc){
			auto itr = tasks.find(id);
			if(itr == tasks.end()){
				cout<<"Provided Id and present is different"<<endl;
				return -1;
			}
			for(auto &[id_itr,task]:tasks){
				if (id != id_itr && task.description == desc){
					cout<<"Task is present but id is different (Id :"<< id_itr<<" )!!!"<<endl;
					return -1;
				}
			}
			itr->second.updateDescription(desc);
			Save(tasks);
			return 0;
		}

		void List(){
			cout<<"List"<<endl;
			ListJSON(" ");
		}

		void ListDone(){
			cout<<"ListDone"<<endl;
			ListJSON("done");
		}

		void ListInProgress(){
			cout<<"ListInProgress"<<endl;
			ListJSON("in-progress");
		}

		void ListToDo(){
			cout<<"ListToDo"<<endl;	
			ListJSON("to-do");
		}

		int MarkDone(int id){
			auto itr = tasks.find(id);
			if(itr == tasks.end()){
				cout<<"Id : "<<id<<" not present"<<endl;
				return -1;
			}
			itr->second.markDone();
			Save(tasks);
			return 0;
		}

		int MarkInProgress(int id){
			auto itr = tasks.find(id);
			if(itr == tasks.end()){
				cout<<"Id : "<<id<<" not present"<<endl;
				return -1;
			}
			itr->second.markInProgress();
			Save(tasks);
			return 0;
		}
};
