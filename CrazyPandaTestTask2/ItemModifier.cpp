#include "ItemModifier.h"
#include "Item.h"

std::string ItemModifier::getName() {
	return this->name;
}

bool ItemModifier::checkRestriction(ItemInterface* item) {
	bool result = true;

	for (auto res : this->restrictions) {
		if (!res(item)) {
			return false;
		}
	}

	return result;
}

void ItemModifier::applyToItem(ItemInterface* item) {

	switch (this->type)
	{
	case ModifierType::DamageBuff:
		dynamic_cast<Item*>(item)->cached_properties.damage += this->value;
		break;

	case ModifierType::ProtectionBuff:
		dynamic_cast<Item*>(item)->cached_properties.protection += this->value;
		break;

	case ModifierType::SpeedBuff:
		dynamic_cast<Item*>(item)->cached_properties.speed += this->value;
		break;

	default:
		break;
	}
}

void ItemModifier::addRestriction(bool (*restriction)(ItemInterface* item)) {
	this->restrictions.push_back(restriction);
}
