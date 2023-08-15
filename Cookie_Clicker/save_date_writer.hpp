#pragma once
#include "config.hpp"

class SaveDateWriter {

public :

	SaveDateWriter();

	void Write(const GameDate date);

private :

	const FilePath kSaveDateFilePath = U"save.json";
};
