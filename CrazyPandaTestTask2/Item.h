#pragma once

#include "Interfaces.h"
#include "ItemModifier.h"

#include "vector"
#include "unordered_map"


class Item : public ItemInterface
{
public:
	Item(std::string name, ItemType type, ItemRarity rarity, int level, ItemProperties properties) 
		:name(name), type(type), rarity(rarity), level(level), properties(properties), cached_properties(properties), cache_is_valid(true) {};
	virtual std::string getName() override;
	virtual ItemRarity getRarity() override;
	virtual ItemType getType() override;
	virtual int getLevel() override;
	virtual ItemProperties getProperties() override;
	virtual void addModifier(ItemModifierInterface& modifier) override;
	virtual void deleteModifierByName(std::string& modifier_name) override;
	virtual std::vector<std::string> getModifiersNames() override;

protected:
	std::unordered_map<std::string, ItemModifier> modifiers;
	std::string name;
	ItemType type;
	ItemRarity rarity;
	int level;
	bool cache_is_valid;
	ItemProperties properties;
	ItemProperties cached_properties;

	void calculateProperties();

	friend class ItemModifier;
};