#pragma once
#include<string>
#include<map>
#include"Resource.h"


using namespace std;

class ResourceController {
public:
		map<string,Resource> resource_list;

		ResourceController(int resuorce_num);
		Resource & get_resource(string RID);
};