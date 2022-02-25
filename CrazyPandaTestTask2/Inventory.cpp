#include "Inventory.h"
#include "ItemStorage.h"

ItemInterface& Inventory::getItemByName(std::string& item_key) {
	return this->items.at(item_key); // <-- EXCEPTION !!!
}

void Inventory::addItemByName(std::string& item_key) {
	//this->items[item_key] = dynamic_cast<Item&>(ItemStorage::getInstance().getItemByName(item_key));
	this->items.insert({ item_key , dynamic_cast<Item&>(ItemStorage::getInstance().getItemByName(item_key)) });
}

void Inventory::deleteItemByName(std::string& item_key) {
	this->items.erase(item_key);
}

std::vector<std::string> Inventory::getItemNames() {
	std::vector<std::string> result;
	result.reserve(this->items.size());

	for (auto& item : this->items) {
		result.push_back(item.first);
	}
	
	return result;
}
