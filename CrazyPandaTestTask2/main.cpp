#include "Interfaces.h"
#include "ItemStorage.h"
#include "Inventory.h"
#include "ItemModifier.h"

#include <iostream>

int main() {

	//This is an interface for all items available.
	//realization could differ, REST API or local database
	ItemStorageInterface& storage = ItemStorage::getInstance();
	auto item_names = storage.getAllItemsNames(); //<-- this is important, we can get the names (keys)
	std::cout << "Items available:" << std::endl;
	for (auto item_name : item_names) {
		std::cout << '\t' << item_name << std::endl;
	}

	Inventory inv;
	InventoryInterface& inventory = inv;

	//Add some items to inventory
	inventory.addItemByName(item_names[1]);
	inventory.addItemByName(item_names[2]);
	auto items_in_inventory = inventory.getItemNames();
	std::cout << std::endl << "Add some items" << std::endl;
	std::cout << "Items in inventory:" << std::endl;
	for (auto item_name : items_in_inventory) {
		std::cout << '\t' << item_name << std::endl;
	}

	//Remove items
	std::cout << std::endl << "Remove them" << std::endl;
	std::cout << "Items in inventory:" << std::endl;
	inventory.deleteItemByName(item_names[1]);
	inventory.deleteItemByName(item_names[2]);
	items_in_inventory = inventory.getItemNames();
	for (auto item_name : items_in_inventory) {
		std::cout << '\t' << item_name << std::endl;
	}

	//Create modifiers
	ItemModifier _eagle_eye("eagle_eye", ModifierType::DamageBuff, 10);
	_eagle_eye.addRestriction([](ItemInterface* item) -> bool {
		if (item->getRarity() == ItemRarity::Rare && item->getType() == ItemType::Armor) {
			return true;
		}
		return false;
	});

	ItemModifier _rage_drink("rage_drink", ModifierType::SpeedBuff, 0.4);
	_rage_drink.addRestriction([](ItemInterface* item) -> bool {
		if (item->getType() == ItemType::Range || item->getType() == ItemType::Melee) {
			return true;
		}
		return false;
		});

	ItemModifierInterface& rage_drink = _rage_drink;
	ItemModifierInterface& eagle_eye = _eagle_eye;

	std::string axe_01_name("axe_01");
	inventory.addItemByName(axe_01_name);
	ItemInterface& axe_01 = inventory.getItemByName(axe_01_name);
	
	//Apply modifiers
	ItemProperties props = axe_01.getProperties();
	std::cout << std::endl << "Properties before modifier applied" << std::endl;
	std::cout << "Axe damage: " << props.damage << std::endl;
	std::cout << "Axe speed: " << props.speed << std::endl;
	
	axe_01.addModifier(rage_drink);
	axe_01.addModifier(eagle_eye);

	props = axe_01.getProperties();
	std::cout << "Properties after modifier applied" << std::endl;
	std::cout << "Axe damage: " << props.damage << std::endl;
	std::cout << "Axe speed: " << props.speed << std::endl;


	//Check item modifiers
	auto mods = axe_01.getModifiersNames();
	std::cout << std::endl << "Modifiers on item:" << std::endl;
	for (auto& mod_name : mods) {
		std::cout << mod_name << std::endl;
	}

	return 0;
}