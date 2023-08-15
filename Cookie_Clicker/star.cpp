#include "star.hpp"

Star::Star() {

	reset();
	pos.x = Random(0,kWindowSize.x);
}

void Star::update() {

	pos = pos.movedBy(speed,0);

	if (pos.x > kWindowSize.x) {
		reset();
	}
}

void Star::draw() const {

	RectF{ pos , size }.draw();
}

void Star::reset() {

	size = Random(kMinSize, kMaxSize);
	speed = Random(kMinSpeed, kMaxSpeed);
	pos = RandomVec2(RectF{ - 100,0,100,kWindowSize.y /2});
}
