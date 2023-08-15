#pragma once
#include "config.hpp"

class YYYYMMSSHHMMSS {

public :

	YYYYMMSSHHMMSS() {

	}

	String get() {

		String time;
		const DateTime t = DateTime::Now();

		time = 
			U"{:0>4}"_fmt(ToString(t.year)) +
			U"{:0>2}"_fmt(ToString(t.month)) +
			U"{:0>2}"_fmt(ToString(t.day)) +
			U"{:0>2}"_fmt(ToString(t.hour)) +
			U"{:0>2}"_fmt(ToString(t.minute)) +
			U"{:0>2}"_fmt(ToString(t.second));

		return time;
	}
};
