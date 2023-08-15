#include "save_date_loader.hpp"

SaveDateLoader::SaveDateLoader()
{
}

GameDate SaveDateLoader::Load()
{
	const JSON json = JSON::Load(kSaveDateFilePath);

	if (not json){
		throw Error{ kSaveDateFilePath+ U"が見つかりませんでした。"};
	}

	return GameDate(
		json[U"ice_num"].get<int>(),
		json[U"pr_level"].get<int>(),
		json[U"ice_level"].get<int>(),
		json[U"shop_level"].get<int>(),
		json[U"per_product_output"].get<int>(),
		json[U"last_login_time"].getString()
	);
}
