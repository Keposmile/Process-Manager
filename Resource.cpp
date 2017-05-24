#include"Resource.h"

const Resource& default() {
	static Resource r("",1,1);
	return r;
}

bool Resource::isSingleResource() {
	return resource_num == 1;
}

bool Resource::isFull() {
	return free_unit_num == 0;
}

Resource::Resource(string RID, int resource_num, int free_unit_num)
				:RID(RID),resource_num(resource_num),free_unit_num(free_unit_num) {

}

int Resource::request(string PID, int req_resource_num) {
	if (req_resource_num > resource_num) {//请求资源大于资源总数
		throw "Error! Requested resource exceeded upper limit! ";
		return -1;
	}
	else {
		if (req_resource_num <= free_unit_num) {//请求的资源小于空闲单元数
			//分配资源
			free_unit_num = free_unit_num - req_resource_num;
			return 0;
		}
		else {//空闲资源不足
			//请求资源进程进入等待队列
			waiting_list.push_back({ PID, req_resource_num});
			return 1;
		}
	}
}

string Resource::release(int release_resource_num) {
	free_unit_num = free_unit_num + release_resource_num;
	//if (isSingleResource()) {//单一资源时，说明有足够空余资源可分配
	//	auto waiting_list_iter = waiting_list.begin();
	//}
	if(!waiting_list.empty()){//等待队列不为空
		auto &next_process = *(waiting_list.begin());
		if (next_process.req_resource_num <= free_unit_num) {
			//资源足够分配给下一个进程时
			string next_process_id = next_process.PID;
			free_unit_num = free_unit_num - next_process.req_resource_num;
			waiting_list.erase(waiting_list.begin());
			return next_process_id;
		}
		else {
			return "";
		}
	}
	else {
		return "";
	}
}