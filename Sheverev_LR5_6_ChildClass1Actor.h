#ifndef SHEVEREV_LR5_6_CHILDCLASS1ACTOR_H
#define SHEVEREV_LR5_6_CHILDCLASS1ACTOR_H

#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_AbstractClassTheaterMember.h"

class Actor : public TheaterMember {
private:
    string currentRole;
    bool isUnderstudy;

protected:
    virtual void printInfo(ostream& os) const override;
    virtual void readInfo(istream& is) override;

public:
    string getCurrentRole() const { return currentRole; }
    void setCurrentRole(const string& currentRole) { this->currentRole = currentRole; }
    bool getIsUnderstudy() const { return isUnderstudy; }
    void setIsUnderstudy(bool isUnderstudy) { this->isUnderstudy = isUnderstudy; }

    Actor();
    Actor(int memberId, const string& name, int experienceYears, const string& currentRole, bool isUnderstudy);
    Actor(const Actor& other);
    Actor(int memberId, const string& currentRole);

    virtual void performRole() override;
    virtual string getMemberType() override;
    virtual bool validate() override;

    void switchToMainRole();

    Actor operator+(const Actor& other) const;
};

#endif