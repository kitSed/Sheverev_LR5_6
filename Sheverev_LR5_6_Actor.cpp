#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_Actor.h"
#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_def.h"

Actor::Actor() : TheaterMember(), currentRole("Не назначена"), isUnderstudy(false) {}

Actor::Actor(int memberId, const string& currentRole) : TheaterMember(memberId), currentRole(currentRole), isUnderstudy(false) {}

Actor::Actor(const Actor& other): TheaterMember(other), currentRole(other.currentRole), isUnderstudy(other.isUnderstudy) {}

string Actor::getCurrentRole() const { return currentRole; }

void Actor::setCurrentRole(const string& role) { 
    currentRole = role; 
}

bool Actor::getIsUnderstudy() const { 
    return isUnderstudy; 
}

void Actor::setIsUnderstudy(bool understudy) { 
    isUnderstudy = understudy; 
}

void Actor::performRole() override {
    cout << "Играет роль: " << currentRole;
    if (isUnderstudy) {
        cout << " (дублер)";
    }
    cout << endl;
}

string Actor::getMemberType() override {
    return "Актер";
}

bool Actor::validate() override {
    return TheaterMember::validate() && 
           currentRole != "Не назначена" && 
           !currentRole.empty();
}

void Actor::switchToMainRole() {
    isUnderstudy = false;
    cout << getName() << " переведён на основную роль: " << currentRole << endl;
}

Actor Actor::operator+(const Actor& other) const {
    Actor result(*this);
    result.currentRole = currentRole + " и " + other.currentRole;
    return result;
}

void Actor::printInfo(ostream& os) const {
    TheaterMember::printInfo(os);
    os << "Текущая роль: " << currentRole << "\n" << "Дублер: " << (isUnderstudy ? "Да" : "Нет") << "\n";
}

void Actor::readInfo(istream& is) {
    TheaterMember::readInfo(is);
    
    EnterString(currentRole, "Введите текущую роль", is)();
    
    int understudy;
    EnterNumberInt(understudy, "Дублер? (1 - Да, 0 - Нет)", is)();
    isUnderstudy = (understudy != 0);
}