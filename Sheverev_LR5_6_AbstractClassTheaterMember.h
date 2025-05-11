#ifndef SHEVEREV_LR5_6_CLASSTHEATERMEMBER_H
#define SHEVEREV_LR5_6_CLASSTHEATERMEMBER_H

#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_def_TheaterMember.h"

class TheaterMember {
private:
    int memberId;
    string name;
    int experienceYears;

protected:
    virtual void printInfo(ostream& os) const;
    virtual void readInfo(istream& is);

public:
    int getMemberId() const { return memberId; }
    void setMemberId(int memberId) { this->memberId = memberId; }
    string getName() const { return name; }
    void setName(const string& name) { this->name = name; }
    int getExperienceYears() const { return experienceYears; }
    void setExperienceYears(int experienceYears) { this->experienceYears = experienceYears; }

    TheaterMember();
    TheaterMember(int memberId, const string& name, int experienceYears);
    TheaterMember(const TheaterMember& other);
    TheaterMember(int memberId);

    virtual ~TheaterMember() {}

    virtual void performRole() = 0;
    virtual string getMemberType() = 0;

    virtual bool validate();

    bool operator==(const TheaterMember& other) const;

    friend ostream& operator<<(ostream& os, const TheaterMember& member);
    friend istream& operator>>(istream& is, TheaterMember& member);
};

#endif