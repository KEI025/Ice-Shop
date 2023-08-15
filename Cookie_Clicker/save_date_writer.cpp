#include "save_date_writer.hpp"

void SaveDateWriter::Write(const GameDate date){

	JSON json;

	json[U"ice_num"] = date.ice_num;
	json[U"pr_level"] = date.pr_level;
	json[U"ice_level"] = date.ice_level;
	json[U"shop_level"] = date.shop_level;
	json[U"per_product_output"] = date.per_product_output;
	json[U"last_login_time"] = date.last_login_time;

	if (not FileSystem::IsFile(kSaveDateFilePath)) {
		throw Error { kSaveDateFilePath + U"が存在しません。"};
	}

	json.save(kSaveDateFilePath);
}
