#pragma once
#include<vector>
#include<string>
using namespace std;


class Resource {
public:
	struct ProcessInfo {
		string PID;
		int req_resource_num;
	};
	Resource(string RID,int resource_num,int free_unit_num);


	int request(string PID,int req_resource_num);
	string release(int release_resource_num);
	bool isSingleResource();//是否是单一资源
	bool isFull();//是否有空余资源

private:
	string RID;//资源RID
	int resource_num;
	int free_unit_num;//空闲单元数

	vector<ProcessInfo> waiting_list;//阻塞进程列表，填充进程的PID；
};