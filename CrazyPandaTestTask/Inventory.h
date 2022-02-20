#pragma once

#include "ItemInterface.h"
#include <vector>

class Inventory {
public:
	void addItem(const ItemInterface* item);
	void getInfo();
	std::vector<const ItemInterface*> items;

protected:
};