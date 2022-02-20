#include "ItemModifier.h"
#include "ItemInterface.h"
#include <iostream>
#include "Item.h"
#include <string>

std::shared_ptr<const ItemInterface> ItemModifier::tryApplyBaff(std::shared_ptr<const ItemInterface> item, std::string name, BuffType type, double buff_value, ItemFilter& filter) {
	std::string logs = "";
	if (filter.check(item, logs)) {
		return std::shared_ptr<const ItemInterface>(new ItemModifier(item, name, type, buff_value));
	}
	else {
		std::cout << "Can't apply modifier \"" << name << "\" to item \"" << item->getId() << "\"\n\r";
		std::cout << logs << std::endl;
		return item;
	}
	return item;
}

std::string ItemModifier::getId() const {
	return this->name + "_" + this->item->getId();
}

ItemRarity ItemModifier::getRarity() const {
	return this->item->getRarity();
}

ItemType ItemModifier::getType() const {
	return this->item->getType();
}

int ItemModifier::getLevel() const {
	return this->item->getLevel();
}

ItemProperties ItemModifier::getProperties() const {
	ItemProperties tmp = this->item->getProperties();
	switch (type)
	{
		case DamageBuff:
			tmp.damage += this->buff_value;
			break;
		case ProtectionBuff:
			tmp.protection += this->buff_value;
			break;
		case SpeedBuff:
			tmp.speed += this->buff_value;
			break;
		default:
			break;
	}

	return tmp;
}