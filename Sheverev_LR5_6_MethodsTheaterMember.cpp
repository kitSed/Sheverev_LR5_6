#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_ChildClass1Actor.h"
#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_ChildClass2StageDirector.h"
#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_MultiClassPropMaster.h"

vector<TheaterMember*> theaterMembers;

bool UserInputInt(string input){
    if(input.empty()) return false;

    try
    {
        int number = stoi(input);
        if (number < 0) return false;
        
    }
    catch(const std::exception& e)
    { return false;}

    return true;
}

function<void()> EnterNumberInt(int& varLink, string label){
    return [&varLink, label](){
        string raw_input;
        cout << label << " = ";
        getline(cin,raw_input);
        while (!UserInputInt(raw_input))
        {
            cout << label << " = ";
            getline(cin,raw_input);
        }
        varLink = stoi(raw_input);
    };
}

bool UserInputStr(string input){
    if(input.empty()) return false;
    else return true;
}

function<void()> EnterString(string& varLink,string label){
    return [&varLink,label](){
        string raw_input = "";
        cout << label << " = ";
        getline(cin,raw_input);
        while (!UserInputStr(raw_input))
        {
            cout << label << " = ";
            getline(cin,raw_input);
        }
        varLink = raw_input;
    };
}

void addActor() {
    int memberId;
    EnterNumberInt(memberId, "Enter member ID: ");
    string name;
    EnterString(name, "Enter actor name: ");
    int experienceYears;
    EnterNumberInt(experienceYears, "Enter experience years: ");
    string currentRole;
    EnterString(currentRole, "Enter current role: ");
    bool isUnderstudy = false;

    Actor* newActor = new Actor(memberId, name, experienceYears, currentRole, isUnderstudy);
    if (newActor->validate()) {
        theaterMembers.push_back(newActor);
        cout << "Actor added successfully.\n";
    } else {
        cout << "Invalid actor data. Actor not added.\n";
        delete newActor;
    }
}

void addStageDirector() {
    int memberId;
    EnterNumberInt(memberId, "Enter member ID: ");
    string name;
    EnterString(name, "Enter actor name: ");
    int experienceYears;
    EnterNumberInt(experienceYears, "Enter experience years: ");
    int productionsCount;
    EnterNumberInt(productionsCount, "Enter productions count: ");
    string artisticStyle;
    EnterString(artisticStyle, "Enter artistic style: ");

    StageDirector* newDirector = new StageDirector(memberId, name, experienceYears, productionsCount, artisticStyle);
    if (newDirector->validate()) {
        theaterMembers.push_back(newDirector);
        cout << "Stage director added successfully.\n";
    } else {
        cout << "Invalid director data. Director not added.\n";
        delete newDirector;
    }
}

void addPropMaster() {
    int memberId;
    EnterNumberInt(memberId, "Enter member ID: ");
    string name;
    EnterString(name, "Enter actor name: ");
    int experienceYears;
    EnterNumberInt(experienceYears, "Enter experience years: ");

    cout << "Enter managed props (comma-separated): ";
    string propsInput;
    EnterString(propsInput, "");
    stringstream ss(propsInput);
    string prop;
    vector<string> managedProps;
    while (getline(ss, prop, ',')) {
        managedProps.push_back(prop);
    }

    int budget;
    EnterNumberInt(budget, "Enter budget for props: ");

    PropMaster* newPropMaster = new PropMaster(memberId, name, experienceYears, managedProps, budget);
    if (newPropMaster->validate()) {
        theaterMembers.push_back(newPropMaster);
        cout << "Prop master added successfully.\n";
    } else {
        cout << "Invalid prop master data. Prop master not added.\n";
        delete newPropMaster;
    }
}

void displayAllMembers() {
    if (theaterMembers.empty()) {
        cout << "No theater members to display.\n";
        return;
    }

    for (TheaterMember* member : theaterMembers) {
        cout << *member << "\n";
    }
}

void performRoles() {
    if (theaterMembers.empty()) {
        cout << "No theater members to perform roles.\n";
        return;
    }

    cout << "Demonstrating dynamic polymorphism:\n";
    for (TheaterMember* member : theaterMembers) {
        cout << "-----------------------------\n";
        cout << "Member: " << member->getName() << "\n";
        cout << "Type: " << member->getMemberType() << "\n";
        cout << "Performing role: ";
        member->performRole(); // Dynamic polymorphism in action!
        cout << "\n";
        cout << "-----------------------------\n";
    }
}
TheaterMember::TheaterMember() : memberId(0), name("Unknown"), experienceYears(0) {}

TheaterMember::TheaterMember(int memberId, const string& name, int experienceYears) :
    memberId(memberId), name(name), experienceYears(experienceYears) {}

TheaterMember::TheaterMember(const TheaterMember& other) :
    memberId(other.memberId), name(other.name), experienceYears(other.experienceYears) {}

TheaterMember::TheaterMember(int memberId) : memberId(memberId), name("Unknown"), experienceYears(0) {}

bool TheaterMember::validate() {
    return experienceYears >= 0;
}

void TheaterMember::printInfo(ostream& os) const {
    os << "Member ID: " << memberId << "\n";
    os << "Name: " << name << "\n";
    os << "Experience Years: " << experienceYears << "\n";
}

void TheaterMember::readInfo(istream& is) {
    cout << "Enter member ID: ";
    is >> memberId;
    cout << "Enter name: ";
    is.ignore();
    getline(is, name);
    cout << "Enter experience years: ";
    is >> experienceYears;
}

bool TheaterMember::operator==(const TheaterMember& other) const {
    return memberId == other.memberId;
}

ostream& operator<<(ostream& os, const TheaterMember& member) {
    member.printInfo(os);
    return os;
}

istream& operator>>(istream& is, TheaterMember& member) {
    member.readInfo(is);
    return is;
}

Actor::Actor() : TheaterMember(), currentRole("Unknown"), isUnderstudy(false) {}

Actor::Actor(int memberId, const string& name, int experienceYears, const string& currentRole, bool isUnderstudy) :
    TheaterMember(memberId, name, experienceYears), currentRole(currentRole), isUnderstudy(isUnderstudy) {}

Actor::Actor(const Actor& other) :
    TheaterMember(other), currentRole(other.currentRole), isUnderstudy(other.isUnderstudy) {}

Actor::Actor(int memberId, const string& currentRole) : TheaterMember(memberId), currentRole(currentRole), isUnderstudy(false) {}

void Actor::performRole() {
    cout << "Playing role: " << currentRole;
}

string Actor::getMemberType() {
    return "Actor";
}

bool Actor::validate() {
    return TheaterMember::validate() && currentRole != "Not assigned";
}

void Actor::printInfo(ostream& os) const {
    TheaterMember::printInfo(os);
    os << "Current Role: " << currentRole << "\n";
    os << "Is Understudy: " << (isUnderstudy ? "Yes" : "No") << "\n";
}

void Actor::readInfo(istream& is) {
    TheaterMember::readInfo(is);
    cout << "Enter current role: ";
    is.ignore();
    getline(is, currentRole);
    cout << "Is understudy (0 - No, 1 - Yes): ";
    is >> isUnderstudy;
}

void Actor::switchToMainRole() {
    isUnderstudy = false;
}

Actor Actor::operator+(const Actor& other) const {
    Actor result = *this;
    result.currentRole = this->currentRole + " and " + other.currentRole;
    return result;
}

StageDirector::StageDirector() : TheaterMember(), productionsCount(0), artisticStyle("Unknown") {}

StageDirector::StageDirector(int memberId, const string& name, int experienceYears, int productionsCount, const string& artisticStyle) :
    TheaterMember(memberId, name, experienceYears), productionsCount(productionsCount), artisticStyle(artisticStyle) {}

StageDirector::StageDirector(const StageDirector& other) :
    TheaterMember(other), productionsCount(other.productionsCount), artisticStyle(other.artisticStyle) {}

void StageDirector::performRole() {
    cout << "Directing a play in style: " << artisticStyle;
}

string StageDirector::getMemberType() {
    return "Stage Director";
}

bool StageDirector::validate() {
    return TheaterMember::validate() && productionsCount >= 1;
}

void StageDirector::printInfo(ostream& os) const {
    TheaterMember::printInfo(os);
    os << "Productions Count: " << productionsCount << "\n";
    os << "Artistic Style: " << artisticStyle << "\n";
}

void StageDirector::readInfo(istream& is) {
    TheaterMember::readInfo(is);
    cout << "Enter productions count: ";
    is >> productionsCount;
    cout << "Enter artistic style: ";
    is.ignore();
    getline(is, artisticStyle);
}

void StageDirector::addSceneRevision() {
    cout << "Adding scene revision...\n";
}

StageDirector& StageDirector::operator+=(int count) {
    productionsCount += count;
    return *this;
}

PropMaster::PropMaster() : TheaterMember(), InventoryManager(), managedProps({}), budget(50000) {}

PropMaster::PropMaster(int memberId, const string& name, int experienceYears, const vector<string>& managedProps, int budget) :
    TheaterMember(memberId, name, experienceYears), InventoryManager(), managedProps(managedProps), budget(budget) {}

PropMaster::PropMaster(const PropMaster& other) :
    TheaterMember(other), InventoryManager(), managedProps(other.managedProps), budget(other.budget) {}

void PropMaster::performRole() {
    cout << "Managing props: ";
    for (const auto& prop : managedProps) {
        cout << prop << " ";
    }
}

string PropMaster::getMemberType() {
    return "Prop Master";
}

bool PropMaster::validate() {
    return TheaterMember::validate() && budget > 50000;
}

void PropMaster::manageInventory() {
    cout << "Managing inventory...\n";
}

void PropMaster::printInfo(ostream& os) const {
    TheaterMember::printInfo(os);
    os << "Managed Props: ";
    for (const auto& prop : managedProps) {
        os << prop << " ";
    }
    os << "\n";
    os << "Budget: " << budget << "\n";
}

void PropMaster::readInfo(istream& is) {
    TheaterMember::readInfo(is);
    cout << "Enter managed props (comma-separated): ";
    string propsInput;
    is.ignore();
    getline(is, propsInput);
    stringstream ss(propsInput);
    string prop;
    while (getline(ss, prop, ',')) {
        managedProps.push_back(prop);
    }
    cout << "Enter budget: ";
    is >> budget;
}

void PropMaster::orderCustomProp() {
    budget *= 0.8;
    cout << "Ordering custom prop. Remaining budget: " << budget << "\n";
}

string& PropMaster::operator[](int index) {
    if (index >= 0 && index < managedProps.size()) {
        return managedProps[index];
    }
    throw out_of_range("Index out of range");
}