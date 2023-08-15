#pragma once
#include "config.hpp"

class SaveDateLoader {

public :

	SaveDateLoader();

	GameDate Load();

private :

	const FilePath kSaveDateFilePath = U"save.json";
};
