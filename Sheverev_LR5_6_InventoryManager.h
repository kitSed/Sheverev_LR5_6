#ifndef SHEVEREV_LR5_6_INVENTORYMANAGER_H
#define SHEVEREV_LR5_6_INVENTORYMANAGER_H

#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_def.h"

class InventoryManager {
protected:
    vector<string> props;

public:
    InventoryManager();
    virtual ~InventoryManager();

    vector<string> getProps() const;
    void addProp(const string& propName);
    void removeProp(const string& propName);
    void printInventory() const;
};

#endif