#ifndef SHEVEREV_LR5_6_MULTICLASSPROPMASTER_H
#define SHEVEREV_LR5_6_MULTICLASSPROPMASTER_H

#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_AbstractClassTheaterMember.h"
#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_ParentClassInventoryManager.h"

class PropMaster : public TheaterMember, public InventoryManager {
private:
    vector<string> managedProps;
    int budget;

protected:
    virtual void printInfo(std::ostream& os) const override;
    virtual void readInfo(std::istream& is) override;

public:
    vector<string> getManagedProps() const { return managedProps; }
    void setManagedProps(const vector<string>& managedProps) { this->managedProps = managedProps; }
    int getBudget() const { return budget; }
    void setBudget(int budget) { this->budget = budget; }

    PropMaster();
    PropMaster(int memberId, const string& name, int experienceYears, const vector<string>& managedProps, int budget);
    PropMaster(const PropMaster& other);

    virtual void performRole() override;
    virtual string getMemberType() override;
    virtual bool validate() override;
    virtual void manageInventory() override;

    void orderCustomProp();

    string& operator[](int index);
};

#endif