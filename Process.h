#pragma once
#include<map>
#include"ResourceController.h"
using namespace std;

class Process {
public:
	enum ProcessType {
		none, ready, running, blocked
	};
	enum ListType {
		RL, BL
	};
	enum PriorityType {
		Init, User, System
	};
	enum ProcessOperate {
		create,destroy,request,release,timeout,dispatch
	};
	struct Status
	{
		ProcessType process_type;
		ListType list_type;
	};
	Process(string name,string PID, Status status, PriorityType priority, string parent_process);		
	Process();
	PriorityType get_priority();
	string get_PID();
	string get_name();
	void set_process_status(ProcessType process_type);
	void set_list_status(ListType list_type);

	Process &add_children_process(string name,string PID, Status status, PriorityType priority);//添加子进程
	void set_parent_process(string PID);//设置父进程

	void get_resource(string RID, int resource_num);//获取资源
	int relase_resource(string RID);//释放资源
	//string* relase_all_resource(ResourceController resource_controller);//释放资源
	void relase_all_resource(ResourceController resource_controller,string* set_ready_process);//释放资源
	void change_status(ProcessOperate operater);

	map<string, Process>& get_children();

private:
	string PID;//进程PID
	string name;

	//Not used part
	string cpu_state = "";
	string memory = "";
	string open_files = "";
	//Not used part END

	map<string,int> other_resource;//资源列表
	Status status;//进程状态	
	PriorityType priority;//进程优先级
	string parent_process;//父进程PID
	map<string, Process> children;//子进程PID map
};