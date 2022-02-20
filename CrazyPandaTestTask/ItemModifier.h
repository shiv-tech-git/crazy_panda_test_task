#pragma once

#include "ItemInterface.h"
#include "ItemFilter.h"
#include <memory>
#include <iostream>


enum BuffType {DamageBuff, ProtectionBuff, SpeedBuff};

class ItemModifier: public ItemInterface {

public:
	static std::shared_ptr<const ItemInterface> tryApplyBaff(std::shared_ptr<const ItemInterface> item, std::string name, BuffType type, double buff_value, ItemFilter& filter);
	std::string getId() const  override;
	ItemRarity getRarity() const override;
	ItemType getType() const override;
	int getLevel() const override;
	ItemProperties getProperties() const override;

	ItemModifier(std::shared_ptr<const ItemInterface> item, std::string name, BuffType type, double buff_value)
		: item(item), name(name), type(type), buff_value(buff_value) {};

protected:
	std::string name;
	std::shared_ptr<const ItemInterface> item;
	double buff_value;
	BuffType type;

};


