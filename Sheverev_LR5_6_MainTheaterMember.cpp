#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_MethodsTheaterMember.cpp"

struct MenuItem {
    string title;
    function<void()> action;
};
int main(){
    map<int,MenuItem> menu = {
        {1, {"Add Actor", addActor}},
        {2, {"Add Stage Director", addStageDirector}},
        {3, {"Add Prop Master", addPropMaster}},
        {4, {"Display All Members", displayAllMembers}},
        {5, {"Perform Roles", performRoles}}
    };
    int choice = 0;

    while(true) {
        cout << "Menu:" << endl;
        for (const auto& item : menu) {
            cout << "Task " << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Exit" << endl;
        
        EnterNumberInt(choice, "Enter number task: ")();
        
        if(choice == 0) {
            cout << "@ 2025 Sheverev" << endl;
            break;
        }
        cout << endl;

        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            cout << "Incorrect input.";
        }
        cout << endl << endl;
    }
return 0;
}