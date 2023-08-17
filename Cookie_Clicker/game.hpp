#pragma once
#include "config.hpp"
#include "star.hpp"
#include "button.hpp"
#include "buff_item.hpp"
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
	BuffItem pr_item{ U"宣伝",U"PR活動をする" };
	BuffItem pr_item{ U"研究",U"アイスの研究をする" };
	BuffItem pr_item{ U"生産",U"生産設備を拡張する" };
	Button pr_update_btn { Vec2{ kWindowSize.x * 0.55 , kWindowSize.y * 0.1 },Size{ 300,120 },getData().pr_level,300,U"宣伝",U"PR活動をする",U""};
	Button ice_update_btn{ Vec2{ kWindowSize.x * 0.55 , kWindowSize.y * 0.35 },Size{ 300,120 },getData().pr_level,300,U"研究",U"アイスを研究する",U"" };;
	Button shop_update_btn{ Vec2{ kWindowSize.x * 0.55 , kWindowSize.y * 0.6 },Size{ 300,120 },getData().pr_level,300,U"生産",U"生産設備を拡張する",U"" };;
};
