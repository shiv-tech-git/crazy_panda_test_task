#include "ItemFilter.h"

bool ItemFilter::check(const ItemInterface* item, std::string& logs) {
	for (auto it = this->restrictions.begin(); it != this->restrictions.end(); it++) {
		if ((*it)(item, logs) == false) {
			return false;
		}
	}
	return true;
}

void ItemFilter::addRestriction(bool (*restriction)(const ItemInterface* item, std::string& logs)) {
	this->restrictions.push_back(restriction);
}