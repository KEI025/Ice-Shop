#pragma once
#include "config.hpp"
#include "star.hpp"
#include "save_date_loader.hpp"

class Game : public App::Scene {

public:

	Game(const InitData& init);

	void update() override;

	void draw() const override;

private:
	Array<Star> stars;
	SaveDateLoader loader;
};
