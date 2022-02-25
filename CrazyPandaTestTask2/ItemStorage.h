#pragma once

#include "Interfaces.h"
#include "Item.h"
#include <unordered_map>

class ItemStorage : public ItemStorageInterface
{
public:
	static ItemStorage& getInstance();
	virtual ItemInterface& getItemByName(std::string& item_key) override;
	virtual std::vector<std::string> getAllItemsNames() override;

	void operator=(ItemStorage& other) = delete;
	ItemStorage(const ItemStorage& other) = delete;

protected:
	ItemStorage();
	static ItemStorage* instance;
	std::unordered_map<std::string, Item> items;
};