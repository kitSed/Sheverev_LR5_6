#ifndef SHEVEREV_LR5_6_PROPMASTER_H
#define SHEVEREV_LR5_6_PROPMASTER_H

#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_AbstractTheaterMember.h"
#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_InventoryManager.h"

class PropMaster : public TheaterMember, public InventoryManager {
private:
    double budget;

protected:
    virtual void printInfo(std::ostream& os) const override;
    virtual void readInfo(std::istream& is) override;
    virtual bool validate() override;

public:
    PropMaster();
    PropMaster(int memberId, double budget);
    PropMaster(const PropMaster& other);

    double getBudget() const;
    void setBudget(double budget);

    void performRole() override;
    string getMemberType() override;
    void orderCustomProp();
    string operator[](int index) const;
};

#endif