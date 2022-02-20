#include "Item.h"

std::string Item::getId() const {
	return this->id;
}

ItemRarity Item::getRarity() const {
	return this->rarity;
}

ItemType Item::getType() const {
	return this->type;
}

int Item::getLevel() const {
	return this->level;
}

ItemProperties Item::getProperties() const {
	return this->properties;
}
