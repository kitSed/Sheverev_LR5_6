#ifndef SHEVEREV_LR5_6_ABSTRACTTHEATERMEMBER_H
#define SHEVEREV_LR5_6_ABSTRACTTHEATERMEMBER_H

#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_def.h"

class TheaterMember {
private:
    int memberId;
    string name;
    int experienceYears;

protected:
    virtual void printInfo(ostream& os) const;
    virtual void readInfo(istream& is);

public:
    TheaterMember();
    TheaterMember(int memberId);
    TheaterMember(const TheaterMember& other);
    virtual ~TheaterMember() = default;

    int getMemberId() const;
    string getName() const;
    int getExperienceYears() const;

    void setMemberId(int memberId);
    void setName(const string& name);
    void setExperienceYears(int experienceYears);

    virtual void performRole() = 0;
    virtual string getMemberType() = 0;

    virtual bool validate();

    bool operator==(const TheaterMember& other) const;

    friend ostream& operator<<(ostream& os, const TheaterMember& member);
    friend istream& operator>>(istream& is, TheaterMember& member);
};

#endif