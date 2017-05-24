#pragma once
#include<sstream>
#include<iostream>
#include<string>
#include"Process.h"
#include"ProcessController.h"
using namespace std;

class Tools {
public:
	static string toString(int i) {
		stringstream ss;
		ss << i;
		return ss.str();
	}
	static string trans_name_to_RID(string resource_name) {
		string RID;
		if (resource_name == "R1") {
			RID = "1";
		}
		else if (resource_name == "R2") {
			RID = "2";
		}
		else if (resource_name == "R3") {
			RID = "3";
		}
		else if (resource_name == "R4") {
			RID = "4";
		}
		else {
			throw "Error! Resource not exist!";
		}
		return RID;
	}
	static string trans_name_to_PID(string process_name,ProcessController pc) {
		map<string, Process>& process_map = pc.process_map;
		auto process_map_it = process_map.begin();
		while (process_map_it!=process_map.end()){
			if (process_map_it->second.get_name() == process_name) {
				return process_map_it->second.get_PID();
			}
			++process_map_it;
		}
	}
};

