#pragma once

#include "Interfaces.h"

#include <vector>


class ItemModifier : public ItemModifierInterface
{
public:
	ItemModifier(std::string name, ModifierType type, double value)
		:name(name), type(type), value(value) {};
	virtual std::string getName() override;
	virtual bool checkRestriction(ItemInterface* item) override;
	virtual void applyToItem(ItemInterface* item) override;
	virtual void addRestriction(bool (*restriction)(ItemInterface* item)) override;

protected:
	std::string name;
	ModifierType type;
	double value;
	std::vector<bool (*)(ItemInterface* item)> restrictions;
};