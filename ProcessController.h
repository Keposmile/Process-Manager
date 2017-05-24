#pragma once
#include<vector>
#include<string>
#include"Process.h"
#include"ListController.h"
using namespace std;

class ProcessController {
public:
	ProcessController();

	void insert_process(string PID, Process p);
	void destroy_process(string PID);
	Process&  get_process(string PID);
	void scheduler(ListController& list_controller);
	void timeout(ListController& list_controller);

	map<string, Process> process_map;
};