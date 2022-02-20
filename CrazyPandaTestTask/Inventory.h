#pragma once

#include "ItemInterface.h"
#include <vector>
#include <memory>

class Inventory {
public:
	void addItem(std::shared_ptr<const ItemInterface> item);
	void getInfo();
	std::vector<std::shared_ptr<const ItemInterface> > items;

protected:
};