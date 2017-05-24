#include"ListController.h"
ListController::ListController() {
	for (int i = 0; i<size; i++)
	{
		ready_list[i].push_front("");//ready_list的初始化running位
	}
}
ListController & ListController::insert_ready_list(string PID, Process::PriorityType priority) {
	switch (priority)
	{
		case Process::Init:
			ready_list[0].push_back(PID);
			break;
		case Process::User:
			ready_list[1].push_back(PID);
			break;
		case Process::System:
			ready_list[2].push_back(PID);	
			break;
		default:
			throw "Priority error! Invalid priority value!";
			break;
	}
	return *this;
}

ListController & ListController::out_ready_list(string PID, Process::PriorityType priority) {
	switch (priority)
	{
	case Process::Init:
		ready_list[0].erase(++ready_list[0].begin());
		break;
	case Process::User:
		ready_list[1].erase(++ready_list[1].begin());
		break;
	case Process::System:
		ready_list[2].erase(++ready_list[0].begin());
		break;
	default:
		throw "Priority error! Invalid priority value!";
		break;
	}
	return *this;
}

ListController & ListController::insert_block_list(string PID, Process::PriorityType priority) {
	switch (priority)
	{
	case Process::Init:
		block_list[0].push_back(PID);
		break;
	case Process::User:
		block_list[1].push_back(PID);
		break;
	case Process::System:
		block_list[2].push_back(PID);
		break;
	default:
		throw "Priority error! Invalid priority value!";
		break;
	}
	return *this;
}

ListController & ListController::out_block_list(Process::PriorityType priority) {
	switch (priority)
	{
	case Process::Init:
		block_list[0].pop_front();
		break;
	case Process::User:
		block_list[1].pop_front();
		break;
	case Process::System:
		block_list[2].pop_front();
		break;
	default:
		throw "Priority error! Invalid priority value!";
		break;
	}
	return *this;
}
//调度停止当前running的进程,初始化running位
ListController & ListController::default_running_value(Process::PriorityType priority) {
	switch (priority)
	{
	case Process::Init:
		*(ready_list[0].begin())="";
		break;
	case Process::User:
		*(ready_list[1].begin()) = "";
		break;
	case Process::System:
		*(ready_list[2].begin()) = "";
		break;
	default:
		throw "Priority error! Invalid priority value!";
		break;
	}
	return *this;
}

ListController & ListController::change_running_to_list(string PID, Process::PriorityType priority, bool toReadyList) {
	default_running_value(priority);
	if (toReadyList){
		insert_ready_list(PID, priority);
	}
	else {
		insert_block_list(PID, priority);
	}
	return *this;
}
//调度对应优先级ready队列的第一个进程进入running
ListController & ListController::change_ready_to_running(Process::PriorityType priority) {
	
	switch (priority)
	{
	case Process::Init:
		*(ready_list[0].begin()) = *(++ready_list[0].begin());
		ready_list[0].erase(++ready_list[0].begin());
		break;
	case Process::User:
		*(ready_list[1].begin()) = *(++ready_list[1].begin());
		ready_list[1].erase(++ready_list[1].begin());
		break;
	case Process::System:
		*(ready_list[2].begin()) = *(++ready_list[2].begin());
		ready_list[2].erase(++ready_list[2].begin());
		break;
	default:
		throw "Priority error! Invalid priority value!";
		break;
	}
	return *this;
}

string ListController::get_running_process()
{
	string PID;
	if (*(ready_list[2].begin()) != "") {
		PID = *(ready_list[2].begin());
	}
	else if (*(ready_list[1].begin()) != "")	{
		PID= *(ready_list[1].begin());
	}
	else if (*(ready_list[0].begin()) != "") {
		PID = *(ready_list[0].begin());
	}
	else {
		PID = "";
	}
	return PID;
}