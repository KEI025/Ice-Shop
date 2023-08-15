#pragma once
#include "config.hpp"
#include "star.hpp"
#include "yyyymmddhhmmss.hpp"
#include "save_date_loader.hpp"
#include "save_date_writer.hpp"

class Game : public App::Scene {

public:

	Game(const InitData& init);

	~Game();

	void update() override;

	void draw() const override;

private:
	double sales_time;
	double accumulator = 0.0;
	Effect effect;
	Array<Star> stars;
	SaveDateLoader loader;
	SaveDateWriter writer;
};
