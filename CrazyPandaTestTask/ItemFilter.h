#pragma once

#include "ItemInterface.h"
#include "vector"
#include <memory>


class ItemFilter {
public:
	bool check(std::shared_ptr<const ItemInterface> item, std::string& logs);
	void addRestriction(bool (*restriction)(std::shared_ptr<const ItemInterface> item, std::string& logs));

protected:
	std::vector<bool (*)(std::shared_ptr<const ItemInterface> item, std::string& logs)> restrictions;
};