#pragma once
#include "config.hpp"

class SaveDateWriter {

	SaveDateWriter();

	void Write(const GameDate date);

private :

	const FilePath kSaveDateFilePath = U"save.json";
};
