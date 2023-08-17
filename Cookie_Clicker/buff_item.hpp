#pragma once
#include "config.hpp"

class BuffItem {

public:

	BuffItem(const String title, const String sub_title, const int now_level, const int need_ice_num)
		: title{ title }
		, sub_title{ sub_title }
		, now_level{ now_level }
		, need_ice_num{ need_ice_num }{}

private :

	String title;
	String sub_title;
	int now_level;
	int need_ice_num;
};
