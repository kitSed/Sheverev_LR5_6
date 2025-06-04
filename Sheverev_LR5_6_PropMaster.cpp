#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_PropMaster.h"
#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_def.h"


PropMaster::PropMaster() : TheaterMember(), InventoryManager(), budget(50001) {}

PropMaster::PropMaster(int memberId, double budget) : TheaterMember(memberId), InventoryManager(), budget(budget) {}

PropMaster::PropMaster(const PropMaster& other) : TheaterMember(other), InventoryManager(other), budget(other.budget) {}

double PropMaster::getBudget() const {
    return budget;
}

void PropMaster::setBudget(double newBudget) {
    budget = newBudget;
}

void PropMaster::performRole() override {
    cout << "Управляет реквизитом (бюджет: " << budget << " руб.)" << endl;
    printInventory();
}

string PropMaster::getMemberType() override {
    return "Хранитель реквизита";
}

bool PropMaster::validate() override {
    return TheaterMember::validate() && budget >= 50000;
}

void PropMaster::orderCustomProp() {
    if (budget < 50000) {
        cout << "Недостаточно бюджета!" << endl;
        return;
    }
    budget *= 0.8;
    cout << "Заказ выполнен. Остаток бюджета: " << budget << " руб." << endl;
}

string PropMaster::operator[](int index) const {
    if (index < 0 || index >= props.size()) {
        throw out_of_range("Неверный индекс реквизита");
    }
    return props[index];
}

void PropMaster::printInfo(ostream& os) const {
    TheaterMember::printInfo(os);
    os << "Бюджет: " << budget << " руб." << endl;
    printInventory();
}

void PropMaster::readInfo(istream& is) {
    TheaterMember::readInfo(is);
    
    double inputBudget;
    EnterNumberInt(inputBudget, "Введите бюджет (мин. 50000): ", is)();
    while (inputBudget < 50000) {
        cout << "Бюджет должен быть ≥50000!" << endl;
        EnterNumberInt(inputBudget, "Повторите ввод: ", is)();
    }
    budget = inputBudget;
    is.ignore();

    cout << "Введите реквизит через запятую: ";
    string input;
    getline(is, input);

    props.clear();
    size_t start = 0;
    size_t end = input.find(',');
    while (end != string::npos) {
        string prop = input.substr(start, end - start);
        prop.erase(remove(prop.begin(), prop.end(), ' '), prop.end());
        if (!prop.empty()) props.push_back(prop);
        start = end + 1;
        end = input.find(',', start);
    }
    string lastProp = input.substr(start);
    lastProp.erase(remove(lastProp.begin(), lastProp.end(), ' '), lastProp.end());
    if (!lastProp.empty()) props.push_back(lastProp);
}