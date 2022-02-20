#pragma once

#include <string>

struct ItemProperties {
	union {
		struct {
			double damage;
			double speed;
		};
		double protection;
	};
};

enum class ItemRarity { Common = 0, Rare, Epic};

enum class ItemType { Melee = 0, Range, Armor };

class ItemInterface {

public:
	virtual std::string getId() const = 0;
	virtual ItemRarity getRarity() const = 0;
	virtual ItemType getType() const = 0;
	virtual int getLevel() const = 0;
	virtual ItemProperties getProperties() const  = 0;
};