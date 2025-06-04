#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_InventoryManager.h"
#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_def.h"

InventoryManager::InventoryManager() : props() {}

InventoryManager::~InventoryManager() {}

vector<string> InventoryManager::getProps() const {
    return props;
}

void InventoryManager::addProp(const string& propName) {
    props.push_back(propName);
}

void InventoryManager::removeProp(const string& propName) {
    props.erase(remove(props.begin(), props.end(), propName), props.end());
}

void InventoryManager::printInventory() const {
    if (props.empty()) {
        cout << "Реквизит отсутствует" << endl;
        return;
    }
    cout << "Список реквизита:" << endl;
    for (const auto& prop : props) {
        cout << "- " << prop << endl;
    }
}