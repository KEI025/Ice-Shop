#pragma once
#include "config.hpp"

class Star {

public :

	Star();

	void reset();

	void update();

	void draw() const;

private :

	Vec2 pos;
	double size;
	double speed;
	double first_pos;

	const double kMinSize = 0.5;
	const double kMaxSize = 2.5;

	const double kMinSpeed = 0.1;
	const double kMaxSpeed = 0.05;
};
