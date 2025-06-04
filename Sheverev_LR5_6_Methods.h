#ifndef SHEVEREV_LR5_6_METHODS_H
#define SHEVEREV_LR5_6_METHODS_H

#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_def.h"
#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_AbstractTheaterMember.h"

class TheaterMember;

void addTheaterMember(vector<TheaterMember*>& members);
void displayTheaterMembers(const vector<TheaterMember*>& members);
void performRoles(const vector<TheaterMember*>& members);
void editTheaterMember(vector<TheaterMember*>& members);
void deleteTheaterMember(vector<TheaterMember*>& members);
void orderProp(vector<TheaterMember*>& members);
void displayInventory(vector<TheaterMember*>& members);
void clearMemory(vector<TheaterMember*>& members);

#endif