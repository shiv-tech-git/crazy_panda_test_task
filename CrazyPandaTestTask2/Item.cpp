#include "Item.h"

std::string Item::getName() {
	return this->name;
}

ItemRarity Item::Item::getRarity() {
	return this->rarity;
}

ItemType Item::getType() {
	return this->type;
}

int Item::getLevel() {
	return this->level;
}

ItemProperties Item::getProperties() {
	if (!this->cache_is_valid) {
		calculateProperties();
		this->cache_is_valid = true;
	}
	return this->cached_properties;
}

void Item::addModifier(ItemModifierInterface& modifier) {
	if (modifier.checkRestriction(this)) {
		//this->modifiers[modifier.getName()] = dynamic_cast<ItemModifier&>(modifier);
		this->modifiers.insert({ modifier.getName() , dynamic_cast<ItemModifier&>(modifier) });
		this->cache_is_valid = false;
	}
}

void Item::deleteModifierByName(std::string& modifier_name) {
	if (this->modifiers.erase(modifier_name) != 0) {
		this->cache_is_valid = false;
	}
}

std::vector<std::string> Item::getModifiersNames() {
	std::vector<std::string> result;
	result.reserve(this->modifiers.size());
	for (auto &mod : modifiers)
	{
		result.push_back(mod.first);
	}
	return result;
}

void Item::calculateProperties() {
	for (auto& mod : this->modifiers) {
		mod.second.applyToItem(this);
	}
}
