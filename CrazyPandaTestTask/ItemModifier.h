#pragma once

#include "ItemInterface.h"
#include "ItemFilter.h"

enum BuffType {DamageBuff, ProtectionBuff, SpeedBuff};

class ItemModifier: public ItemInterface {

public:
	static const ItemInterface* tryApplyBaff(const ItemInterface* item, std::string name, BuffType type, double buff_value, ItemFilter& filter);
	std::string getId() const  override;
	ItemRarity getRarity() const override;
	ItemType getType() const override;
	int getLevel() const override;
	ItemProperties getProperties() const override;

protected:
	std::string name;
	const ItemInterface* item;
	double buff_value;
	BuffType type;

	ItemModifier(const ItemInterface* item, std::string name, BuffType type, double buff_value) 
		: item(item), name(name), type(type), buff_value(buff_value) {};
};

