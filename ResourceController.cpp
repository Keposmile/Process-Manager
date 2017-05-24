#include"ResourceController.h"
#include"Tools.h"

ResourceController::ResourceController(int resuorce_num) {	
	for (auto i = 1; i <= resuorce_num; i++) {
		string RID = Tools::toString(i);
		resource_list.insert(make_pair(RID, Resource(RID, i, i)));
	}
}

Resource & ResourceController::get_resource(string RID)
{
	return resource_list.find(RID)->second;
}
