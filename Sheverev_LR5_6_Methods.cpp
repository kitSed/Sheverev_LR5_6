#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_Methods.h"
#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_AbstractTheaterMember.cpp"
#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_Actor.cpp"
#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_StageDirector.cpp"
#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_PropMaster.cpp"

void addTheaterMember(vector<TheaterMember*>& members) {
    cout << "\nДобавление участника:\n"
         << "1. Актёр\n2. Режиссёр\n3. Хранитель реквизита\n";
    
    int choice;
    EnterNumberInt(choice, "Выберите тип (1-3)")();
    cin.ignore();

    TheaterMember* member = nullptr;
    switch (choice) {
        case 1: member = new Actor(); break;
        case 2: member = new StageDirector(); break;
        case 3: member = new PropMaster(); break;
        default: cout << "Неверный выбор!\n"; return;
    }

    cin >> *member;
    if (member->validate()) {
        members.push_back(member);
        cout << "Успешно добавлен!\n";
    } else {
        delete member;
        cout << "Ошибка валидации данных!\n";
    }
}

void displayTheaterMembers(const vector<TheaterMember*>& members) {
    if (members.empty()) {
        cout << "Список участников пуст!\n";
        return;
    }
    
    cout << "\nСписок участников (" << members.size() << "):\n";
    for (size_t i = 0; i < members.size(); ++i) {
        cout << i+1 << ".\n" << *members[i] << "----------\n";
    }
}

void performRoles(const vector<TheaterMember*>& members) {
    if (members.empty()) {
        cout << "Нет участников для выполнения ролей!\n";
        return;
    }
    
    cout << "\nВыполнение ролей:\n";
    for (const auto& member : members) {
        cout << member->getMemberType() << " " << member->getName() << ": ";
        member->performRole();
    }
}

void editTheaterMember(vector<TheaterMember*>& members) {
    if (members.empty()) {
        cout << "Нет участников для редактирования!\n";
        return;
    }
    
    int id;
    EnterNumberInt(id, "Введите ID участника")();
    cin.ignore();

    auto it = find_if(members.begin(), members.end(), 
        [id](TheaterMember* m) { return m->getMemberId() == id; });
    
    if (it == members.end()) {
        cout << "Участник не найден!\n";
        return;
    }

    cout << "Редактирование:\n" << **it << "\n";
    cout << "Введите новые данные:\n";
    cin >> **it;
    
    if (!(*it)->validate()) {
        cout << "Ошибка валидации! Изменения не сохранены.\n";
        return;
    }
    
    cout << "Изменения сохранены!\n";
}

void deleteTheaterMember(vector<TheaterMember*>& members) {
    if (members.empty()) {
        cout << "Нет участников для удаления!\n";
        return;
    }
    
    int id;
    EnterNumberInt(id, "Введите ID участника")();
    cin.ignore();

    auto it = find_if(members.begin(), members.end(), 
        [id](TheaterMember* m) { return m->getMemberId() == id; });
    
    if (it == members.end()) {
        cout << "Участник не найден!\n";
        return;
    }

    delete *it;
    members.erase(it);
    cout << "Участник удалён!\n";
}

void orderProp(vector<TheaterMember*>& members) {
    int id;
    EnterNumberInt(id, "Введите ID хранителя реквизита")();
    cin.ignore();

    for (auto member : members) {
        if (member->getMemberId() == id) {
            if (PropMaster* pm = dynamic_cast<PropMaster*>(member)) {
                cout << "Введите название реквизита: ";
                string prop;
                getline(cin, prop);
                pm->addProp(prop);
                cout << "Реквизит добавлен!\n";
                return;
            }
        }
    }
    cout << "Хранитель реквизита с таким ID не найден!\n";
}

void displayInventory(vector<TheaterMember*>& members) {
    int id;
    EnterNumberInt(id, "Введите ID хранителя реквизита")();
    cin.ignore();

    for (auto member : members) {
        if (member->getMemberId() == id) {
            if (PropMaster* pm = dynamic_cast<PropMaster*>(member)) {
                pm->printInventory();
                return;
            }
        }
    }
    cout << "Хранитель реквизита с таким ID не найден!\n";
}

void clearMemory(vector<TheaterMember*>& members) {
    for (auto member : members) {
        delete member;
    }
    members.clear();
}