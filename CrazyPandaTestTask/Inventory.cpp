#include "Inventory.h"
#include <iostream>

void Inventory::addItem(std::shared_ptr<const ItemInterface> item) {
	this->items.push_back(item);
}

void Inventory::getInfo() {
	static std::string item_rarity_as_text[] = { "Common", "Rare", "Melee"};
	static std::string item_type_as_text[] = { "Melee", "Range", "Armor"};

	for (auto it = this->items.begin(); it != this->items.end(); it++) {
		std::cout << "id:\t\t"		<< (*it)->getId()		<< std::endl;
		std::cout << "type:\t\t"	<< item_type_as_text[(int)(*it)->getType()] << std::endl;
		std::cout << "rarity:\t\t"	<< item_rarity_as_text[(int)(*it)->getRarity()] << std::endl;
		std::cout << "level:\t\t"	<< (*it)->getLevel()	<< std::endl;
		ItemProperties props = (*it)->getProperties();
		switch ((*it)->getType())
		{
			case ItemType::Melee:
			case ItemType::Range:
				std::cout << "damage:\t\t"	<< props.damage << std::endl;
				std::cout << "speed:\t\t"	<< props.speed<< std::endl;
				break;
			case ItemType::Armor:
				std::cout << "protection:\t" << props.protection << std::endl;
				break;
		}
		std::cout << std::endl;
	}
}