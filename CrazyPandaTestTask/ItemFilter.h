#pragma once

#include "ItemInterface.h"
#include "vector"

class ItemFilter {
public:
	bool check(const ItemInterface* item, std::string& logs);
	void addRestriction(bool (*restriction)(const ItemInterface* item, std::string& logs));

protected:
	std::vector<bool (*)(const ItemInterface* item, std::string& logs)> restrictions;
};