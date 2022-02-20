#pragma once

#include "ItemInterface.h"

class Item: public ItemInterface {

public:
	Item(std::string id, ItemType type, int level, ItemRarity rarity, ItemProperties properties):
		id(id), type(type), level(level), rarity(rarity), properties(properties) {};

	std::string getId() const override;
	ItemRarity getRarity() const override;
	ItemType getType() const override;
	int getLevel() const override;
	virtual ItemProperties getProperties() const override;

protected:
	std::string id;
	ItemRarity rarity;
	ItemType type;
	ItemProperties properties;
	int level;
};