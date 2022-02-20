#include <iostream>
#include "ItemInterface.h"
#include "Item.h"
#include "ItemFilter.h"
#include "ItemModifier.h"
#include "Inventory.h"


int main()
{
	auto axe_01 = std::shared_ptr<const Item>(new Item("axe_01", ItemType::Melee, 3, ItemRarity::Common, {12.0, 0.9}));
	auto revolver_01 = std::shared_ptr<const ItemInterface>(new Item("revolver_01", ItemType::Range, 5, ItemRarity::Common, { 42.0, 2.0 }));
	auto revolver_02 = std::shared_ptr<const ItemInterface>(new Item("revolver_02", ItemType::Range, 3, ItemRarity::Rare, { 50.0, 2.1 }));
	auto machinegun_01 = std::shared_ptr<const ItemInterface>(new Item("machinegun_01", ItemType::Range, 5, ItemRarity::Epic, { 83.1, 10.0 }));
	auto jacket_01 = std::shared_ptr<const ItemInterface>(new Item("jacket_01", ItemType::Armor, 2, ItemRarity::Common, { 2.0 }));
	auto bulletprof_vest_01 = std::shared_ptr<const ItemInterface>(new Item("bulletprof_vest_01", ItemType::Armor, 5, ItemRarity::Rare, {30.0}));


	Inventory inventory;
	inventory.addItem(axe_01);
	inventory.addItem(revolver_01);
	inventory.addItem(revolver_02);
	inventory.addItem(machinegun_01);
	inventory.addItem(jacket_01);
	inventory.addItem(bulletprof_vest_01);

	inventory.getInfo();

	ItemFilter eagle_eye_filter;
	eagle_eye_filter.addRestriction([](std::shared_ptr<const ItemInterface> item, std::string& logs) -> bool {
		if (item->getLevel() >= 4 && item->getType() == ItemType::Range) {
			return true;
		}
		logs += "Item level must be greater or equal to 4\n\rItem type must be Range\n\r";
		return false;
		});

	ItemFilter donatium_steel_filter;
	donatium_steel_filter.addRestriction([](std::shared_ptr<const ItemInterface> item, std::string& logs) -> bool {
		if (item->getRarity() == ItemRarity::Rare && item->getType() == ItemType::Armor) {
			return true;
		}
		logs += "Item rarity must be Rare\n\rItem type must be Armor\n\r";
		return false;
		});

	ItemFilter rage_drink_filter;
	rage_drink_filter.addRestriction([](std::shared_ptr<const ItemInterface> item, std::string& logs) -> bool {
		if (item->getType() == ItemType::Range || item->getType() == ItemType::Melee) {
			return true;
		}
		logs += "Item type must be Melee or Range\n\r";
		return false;
	});

	for (auto it = inventory.items.begin(); it != inventory.items.end(); it++) {
		*it = ItemModifier::tryApplyBaff(*it, "eagle_eye", DamageBuff, 10, eagle_eye_filter);
		*it = ItemModifier::tryApplyBaff(*it, "donatium_steel", ProtectionBuff, 15, donatium_steel_filter);
		*it = ItemModifier::tryApplyBaff(*it, "rage_drink", SpeedBuff, 0.4, rage_drink_filter);
	}

	inventory.getInfo();
	
	return 0;
}
