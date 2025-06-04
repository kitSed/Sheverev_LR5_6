#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_Methods.h"
#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_AbstractTheaterMember.h"
#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_Actor.h"
#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_StageDirector.h"
#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_PropMaster.h"
#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_def.h"

struct MenuItem {
    string title;
    function<void(vector<TheaterMember*>&)> action;
};

int main() {
    vector<TheaterMember*> theaterMembers;
    
    map<int, MenuItem> menu = {
        {1, {"Add Theater Member", addTheaterMember}},
        {2, {"Display Theater Members", displayTheaterMembers}},
        {3, {"Perform Roles", performRoles}},
        {4, {"Edit Theater Member", editTheaterMember}},
        {5, {"Delete Theater Member", deleteTheaterMember}},
        {6, {"Order Prop", orderProp}},
        {7, {"Display Inventory", displayInventory}}
    };

    while (true) {
        cout << "Menu:" << endl;
        for (const auto& item : menu) {
            cout << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Exit" << endl;

        int choice;
        EnterNumberInt(choice, "Enter the choice: ")();

        if (choice == 0) {
            cout << "@ 2025 Sheverev" << endl;
            clearMemory(theaterMembers);
            break;
        }

        cout << endl;

        if (menu.find(choice) != menu.end()) {
            menu[choice].action(theaterMembers);
        } else {
            cout << "Incorrect input." << endl;
        }

        cout << endl << endl;
    }
    return 0;
}