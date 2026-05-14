#include <iostream>
#include <string>
#include "taskManager.hpp"
using namespace std;

class CLI {
	private:
		int argc;
		char **argv;
		TaskManager Mgr;
		bool isAvailable;
		void help() {
			cout << "Task CLI Usage:\n" << endl;
			cout << "Add a new task:" << endl;
			cout << "  task-cli add \"Buy groceries\"" << endl;
			cout << "  Output: Task added successfully (ID: 1)\n" << endl;

			cout << "Update a task:" << endl;
			cout << "  task-cli update 1 \"Buy groceries and cook dinner\"\n"
				<< endl;

			cout << "Delete a task:" << endl;
			cout << "  task-cli delete 1\n" << endl;

			cout << "Mark task status:" << endl;
			cout << "  task-cli mark-in-progress 1" << endl;
			cout << "  task-cli mark-done 1\n" << endl;

			cout << "List tasks:" << endl;
			cout << "  task-cli list\n" << endl;

			cout << "List tasks by status:" << endl;
			cout << "  task-cli list done" << endl;
			cout << "  task-cli list todo" << endl;
			cout << "  task-cli list in-progress\n" << endl;

			cout << "Available Commands:" << endl;
			cout << "  add" << endl;
			cout << "  update" << endl;
			cout << "  delete" << endl;
			cout << "  mark-in-progress" << endl;
			cout << "  mark-done" << endl;
			cout << "  list" << endl;
			cout << "  help" << endl;
		}
	public:
		CLI(int argc,char **argv){
			if(argc < 2){
				help();
				isAvailable = false;
				return;
			}
			this->argc = argc;
			this->argv = argv;
			isAvailable = true;
		}

		bool isTrue(){
			return this->isAvailable;
		}

		void processArgs(){
			if (argc < 2){
				help();
			}
			string cmd = argv[1];
			if(cmd == "help"){
				help();
			}else if(cmd == "add"){
				if (argc < 3 ){
					cout << " Usage: ./cli add \"Buy groceries\"" << endl;
					return;
				}
				if (handleAdd(argv[2]) == -1){
					cout<<"Failed To Add Task!!!"<<endl;
				}else{
					cout<<"Task added successfully"<<endl;
				}

			}else if(cmd == "delete"){
				if (argc < 3){
					cout << "Usage: ./cli delete 1" << endl;
					return;
				}
				if (handleDelete((atoi)(argv[2])) == -1){
					cout<<"Failed To Delete Task!!!"<<endl;
				}else{	
					cout<<"Task deleted successfully"<<endl;
				}
			}else if(cmd == "update"){
				if (argc < 4){
					cout << "Usage: ./cli update <id> <description>" << endl;
					return;
				}
				if (handleUpdate((atoi)(argv[2]),argv[3]) == -1){
					cout<<"Failed To Update Task!!!"<<endl;
				}else{
					cout<<"Task updated successfully"<<endl;
				}
			}else if(cmd == "list"){
				if (argc < 3){
					handleList();
				}else{
					if (argv[2] == "done"){
						handleListDone();
					}else if (argv[2] == "todo"){
						handleListToDo();
					}else if(argv[2] == "in-progress"){
						handleListInProgress();
					}else{
						cout<<"Invalid status!!!"<<endl;	
						help();
					}
				}

			}else if(cmd == "mark-in-progress"){
				if (handleMarkInProgress((atoi)(argv[2])) == -1){
					cout<<"Failed To Mark-In-Progress!!!"<<endl;
				}	
			}else if(cmd == "mark-done"){
				if (handleMarkDone((atoi)(argv[2])) == -1){
					cout<<"Failed To Mark-Done!!!"<<endl;	
				}	
			}else{
				help();
			}
		}

		int handleAdd(string desc){
			return Mgr.Add(desc);
		}
		int handleDelete(int id){
			return Mgr.Delete(id);
		}
		int handleUpdate(int id,string desc){
			return Mgr.Update(id,desc);
		}
		int handleMarkInProgress(int id){
			return Mgr.MarkInProgress(id);
		}
		int handleMarkDone(int id){
			return Mgr.MarkDone(id);		
		}
		void handleList(){
			Mgr.List();
		}
		void handleListDone(){
			Mgr.ListDone();
		}
		void handleListToDo(){
			Mgr.ListToDo();
		}
		void handleListInProgress(){
			Mgr.ListInProgress();
		}

};
