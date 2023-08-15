#pragma once
#include "config.hpp"

class Button {

public :

	Button(const Vec2,const Size,const int,const int,const String,const String,const String);

	void update();

	void draw() const;

	bool IsClick() const;

	void updateLevel(const int);

	void SetState(bool);

private:

	Vec2 pos;
	Size size;
	int level;
	String title;
	String sub_title;
	String asset_id;
	int need_ice_num = 0;
	bool can_level_up = false;
};
