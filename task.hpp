#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class Task {
	private:
		string getCurrentTimeStamp() {
			time_t now = time(0);
			tm *ltm = localtime(&now);
			stringstream ss;
			ss << put_time(ltm, "%Y-%m-%d %H:%M:%S");
			return ss.str();
		}
	public:
		int id;
		string description;
		string status;
		string createdAt;
		string updatedAt;

		Task(){};
		Task (int id,const string &desc): id(id),description(desc),status("to-do"),createdAt(getCurrentTimeStamp()){}



		void updateDescription(string const &desc){
			this->description = desc;
			this->updatedAt = getCurrentTimeStamp();
		}

		void markDone(){
			this->status = "done";
			this->updatedAt = getCurrentTimeStamp();
		}

		void markInProgress(){
			this->status = "in-progress";
			this->updatedAt = getCurrentTimeStamp();
		}
};

void to_json(json &j,const Task &t){
	j = {
		{"id",t.id},
		{"description",t.description},
		{"status",t.status},
		{"createdAt",t.createdAt},
		{"updatedAt",t.updatedAt}
	};
}

void from_json(const json &j,Task &t){
	j.at("id").get_to(t.id);
	j.at("description").get_to(t.description);
	j.at("status").get_to(t.status);
	j.at("createdAt").get_to(t.createdAt);
	j.at("updatedAt").get_to(t.updatedAt);
}
