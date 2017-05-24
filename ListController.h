#pragma once
#include<list>
#include<string>
#include"Process.h"
using namespace std;
class ListController {
public:
	static const  int size = 3;
	list<string> ready_list[size];
	list<string> block_list[size];

	//ListController(string default_running);
	ListController();
	ListController & insert_ready_list(string PID, Process::PriorityType priority);

	ListController & out_ready_list(string PID, Process::PriorityType priority);

	ListController & insert_block_list(string PID, Process::PriorityType priority);

	ListController & out_block_list(Process::PriorityType priority);

	ListController & change_running_to_list(string PID, Process::PriorityType priority,bool toReadyList);
	//调度对应优先级ready队列的第一个进程进入running
	ListController & change_ready_to_running(Process::PriorityType priority);
	//调度停止当前running的进程
	ListController & default_running_value(Process::PriorityType prirority);

	string get_running_process();

};