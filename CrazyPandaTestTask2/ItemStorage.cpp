#include "ItemStorage.h"
#include "Item.h"


ItemStorage* ItemStorage::instance = nullptr;

ItemStorage::ItemStorage() {
	auto axe_01 = Item("axe_01", ItemType::Melee, ItemRarity::Common, 3, { 12.0, 0.9 });
	auto revolver_01 = Item("revolver_01", ItemType::Range, ItemRarity::Common, 5, { 42.0, 2.0 });
	auto revolver_02 = Item("revolver_02", ItemType::Range, ItemRarity::Rare, 3, { 50.0, 2.1 });
	auto machinegun_01 = Item("machinegun_01", ItemType::Range, ItemRarity::Epic, 5, { 83.1, 10.0 });
	auto jacket_01 = Item("jacket_01", ItemType::Armor, ItemRarity::Common, 2, { 2.0 });
	auto bulletprof_vest_01 = Item("bulletprof_vest_01", ItemType::Armor, ItemRarity::Rare, 5, { 30.0 });

	//yeah there are a lot of copying!
	//but this code will never run in production
	//this is just a plug for ItemBase
	this->items.insert({ "axe_01" , axe_01 });
	this->items.insert({ "revolver_01" , revolver_01 });
	this->items.insert({ "revolver_02" , revolver_02 });
	this->items.insert({ "machinegun_01" , machinegun_01 });
	this->items.insert({ "jacket_01" , jacket_01 });
	this->items.insert({ "bulletprof_vest_01" , bulletprof_vest_01 });
}

ItemStorage& ItemStorage::getInstance() {
	if (instance == nullptr) {
		instance = new ItemStorage();
	}
	return *instance;
}

ItemInterface& ItemStorage::getItemByName(std::string& item_key) {
	return this->items.at(item_key); // <-- EXCEPTION !!!
}

std::vector<std::string> ItemStorage::getAllItemsNames() {
	std::vector<std::string> result;

	for (auto &item : this->items)  {
		result.push_back(item.first);
	}

	return result;
}