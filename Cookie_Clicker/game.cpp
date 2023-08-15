#include "game.hpp"

Game::Game(const InitData& init)
	: IScene{ init }
	{
		for (auto i : step(kGameSceneStarNum)) {
			stars.emplace_back(Star());
		}

		GameDate save = loader.Load();

		getData().ice_num = save.ice_num;
		getData().pr_level = save.pr_level;
		getData().ice_level = save.ice_level;
		getData().shop_level = save.shop_level;
		getData().per_product_output = save.per_product_output;
		getData().last_login_time = save.last_login_time;

		sales_time = 60.0 / getData().per_product_output;

		//TODO : 最終ログイン日時からの経過時間に応じて放置報酬を与える
		//TODO : GameDateのlast_login_timeをDate型に変換して計算
		//TODO : 放置報酬を表示するclassを別に作って実装する(geme classが複雑化するため)
		{

		}
}

void Game::update() {

	accumulator += Scene::DeltaTime();

	for (auto& star : stars) {
		star.update();
	}

	if (sales_time <= accumulator) {
		accumulator -= sales_time;
		getData().ice_num += getData().per_product_output / 60;
	}

	if (pr_update_btn.IsClick()) {
		getData().pr_level++;
		pr_update_btn.updateLevel(getData().pr_level);
	}
	if (ice_update_btn.IsClick()) {
		getData().ice_level++;
		ice_update_btn.updateLevel(getData().ice_level);
	}
	if (shop_update_btn.IsClick()) {
		getData().shop_level++;
		shop_update_btn.updateLevel(getData().shop_level);
	}

	pr_update_btn.update();
	ice_update_btn.update();
	shop_update_btn.update();
}

void Game::draw() const {


	//夜空のグラデーションと星描画
	{
		RectF{ 0, 0, kWindowSize.x,kWindowSize.y }.draw(Arg::top = Color{ U"#051637" }, Arg::bottom = Color{ U"#5c658b" });

		for (const auto& star : stars) {
			star.draw();
		}
	}
	//画面左上から7割,WindowSizeの下辺に合わせて配置する
	TextureAsset(U"shop").scaled(kShopScaled).draw(kWindowSize.x * 0.07, kWindowSize.y - (256.0 * kShopScaled));

	//合計生産数と分あたりの生産数表示
	{
		FontAsset(U"70")(getData().ice_num).drawAt({ kWindowSize.x * 0.25 , kWindowSize.y * 0.3 });
		FontAsset(U"25")(U"アイスの販売数 : " + ToString(getData().per_product_output) + U"個/分").drawAt({kWindowSize.x * 0.25 , kWindowSize.y * 0.45});
	}

	pr_update_btn.draw();
	ice_update_btn.draw();
	shop_update_btn.draw();
}
Game::~Game()
{
	YYYYMMSSHHMMSS time;

	getData().last_login_time = time.get();

	writer.Write(getData());
}
