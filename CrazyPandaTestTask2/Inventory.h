#pragma once

#include "Interfaces.h"
#include "Item.h"

#include <unordered_map>

class Inventory : public InventoryInterface 
{
public:
	virtual ItemInterface& getItemByName(std::string& item_key) override;
	virtual void addItemByName(std::string& item_key) override;
	virtual void deleteItemByName(std::string& item_key) override;
	virtual std::vector<std::string> getItemNames() override;

protected:
	std::unordered_map<std::string, Item> items;
};