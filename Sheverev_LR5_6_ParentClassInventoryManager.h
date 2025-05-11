#ifndef SHEVEREV_LR5_6_PARENTCLASSINVENTORYMANAGER_H
#define SHEVEREV_LR5_6_PARENTCLASSINVENTORYMANAGER_H

#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_def_TheaterMember.h"

class InventoryManager {
public:
    virtual void manageInventory() = 0; // Pure virtual function
    virtual ~InventoryManager() {}
};

#endif