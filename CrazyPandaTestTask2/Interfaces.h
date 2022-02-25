#pragma once

#include <string>
#include <vector>

enum class ItemRarity { Common = 0, Rare, Epic };

enum class ItemType { Melee = 0, Range, Armor };

enum ModifierType { DamageBuff, ProtectionBuff, SpeedBuff };

struct ItemProperties {
	union {
		struct {
			double damage;
			double speed;
		};
		double protection;
	};
};

class ItemStorageInterface;
class ItemInterface;
class ItemModifierInterface;

class ItemStorageInterface
{
public:
	virtual ItemInterface& getItemByName(std::string& item_key) = 0;
	virtual std::vector<std::string> getAllItemsNames() = 0;
};


class ItemInterface
{
public:
	virtual std::string getName() = 0;
	virtual ItemRarity getRarity() = 0;
	virtual ItemType getType() = 0;
	virtual int getLevel() = 0;
	virtual ItemProperties getProperties() = 0;
	virtual void addModifier(ItemModifierInterface& modifier) = 0;
	virtual void deleteModifierByName(std::string& modifier_name) = 0;
	virtual std::vector<std::string> getModifiersNames() = 0;
};

class ItemModifierInterface
{
public:
	virtual std::string getName() = 0;
	virtual bool checkRestriction(ItemInterface* item) = 0;
	virtual void applyToItem(ItemInterface* item) = 0;
	virtual void addRestriction(bool (*restriction)(ItemInterface* item)) = 0;
};

class InventoryInterface
{
public:
	virtual ItemInterface& getItemByName(std::string& item_key) = 0;
	virtual void addItemByName(std::string& item_key) = 0;
	virtual void deleteItemByName(std::string& item_key) = 0;
	virtual std::vector<std::string> getItemNames() = 0;
};
