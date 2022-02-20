#include "ItemFilter.h"
#include <memory>

bool ItemFilter::check(std::shared_ptr<const ItemInterface> item, std::string& logs) {
	for (auto it = this->restrictions.begin(); it != this->restrictions.end(); it++) {
		if ((*it)(item, logs) == false) {
			return false;
		}
	}
	return true;
}

void ItemFilter::addRestriction(bool (*restriction)(std::shared_ptr<const ItemInterface> item, std::string& logs)) {
	this->restrictions.push_back(restriction);
}