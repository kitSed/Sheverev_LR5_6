#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_AbstractTheaterMember.h"
#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_def.h"
 
TheaterMember::TheaterMember() : memberId(0), name(""), experienceYears(0) {}
TheaterMember::TheaterMember(int memberId) : memberId(memberId), name(""), experienceYears(0) {}
TheaterMember::TheaterMember(const TheaterMember& other): memberId(other.memberId), name(other.name), experienceYears(other.experienceYears) {}

int TheaterMember::getMemberId() const { 
    return memberId; 
}

string TheaterMember::getName() const { 
    return name; 
}

int TheaterMember::getExperienceYears() const { 
    return experienceYears; 
}

void TheaterMember::setMemberId(int memberId) { 
    this->memberId = memberId; 
}

void TheaterMember::setName(const string& name) { 
    this->name = name; 
}

void TheaterMember::setExperienceYears(int experienceYears) { 
    this->experienceYears = experienceYears; 
}

bool TheaterMember::validate() {
    return experienceYears >= 0;
}

bool TheaterMember::operator==(const TheaterMember& other) const {
    return memberId == other.memberId;
}

void TheaterMember::printInfo(ostream& os) const {
    os << "ID: " << memberId << "\n"
       << "Name: " << name << "\n"
       << "Experience: " << experienceYears << " years\n";
}

void TheaterMember::readInfo(istream& is) {
    EnterNumberInt(memberId, "Enter member ID", is)();
    EnterString(name, "Enter name", is)();
    EnterNumberInt(experienceYears, "Enter experience years", is)();
}

ostream& operator<<(ostream& os, const TheaterMember& member) {
    member.printInfo(os);
    return os;
}

istream& operator>>(istream& is, TheaterMember& member) {
    member.readInfo(is);
    return is;
}