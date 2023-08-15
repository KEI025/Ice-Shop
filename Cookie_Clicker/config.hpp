#pragma once
#include<Siv3D.hpp>

const Size kWindowSize = { 800,600 };
const String kWindowName = U"Sweet Shop";
const double kShopScaled = 1.2;
const int kGameSceneStarNum = 100;

enum class Scenes {
	Game
};

struct GameDate
{
	int ice_num;
	int pr_level;
	int ice_level;
	int shop_level;
	long long per_product_output;
	String last_login_time;
};

using App = SceneManager<Scenes,GameDate>;
