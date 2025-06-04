#ifndef SHEVEREV_LR5_6_ACTOR_H
#define SHEVEREV_LR5_6_ACTOR_H

#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_AbstractTheaterMember.h"

class Actor : public TheaterMember {
private:
    string currentRole;
    bool isUnderstudy;

protected:
    virtual void printInfo(ostream& os) const override;
    virtual void readInfo(istream& is) override;
    virtual bool validate() override;

public:
    Actor();
    Actor(int memberId, const string& currentRole);
    Actor(const Actor& other);

    string getCurrentRole() const;
    void setCurrentRole(const string& role);
    bool getIsUnderstudy() const;
    void setIsUnderstudy(bool understudy);

    void performRole() override;
    string getMemberType() override;

    void switchToMainRole();

    Actor operator+(const Actor& other) const;
};

#endif