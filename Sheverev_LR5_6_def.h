#ifndef SHEVEREV_LR5_6_DEFNAMEOFCLASS_H
#define SHEVEREV_LR5_6_DEFNAMEOFCLASS_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <numeric>
#include <algorithm> 
#include <random>
#include <map>
#include <functional>
#include <limits>
#include <fstream>

using namespace std;

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

bool UserInputStr(string input){
    if(input.empty()) return false;
    else return true;
}

function<void()> EnterNumberInt(int& varLink, string label, istream & is = cin){
    return [&varLink, label, &is](){
        string raw_input;
        cout << label << " = ";
        getline(is,raw_input);
        while (!UserInputInt(raw_input))
        {
            cout << label << " = ";
            getline(is,raw_input);
        }
        varLink = stoi(raw_input);
    };
}

function<void()> EnterString(string& varLink,string label, istream & is = cin){
    return [&varLink,label, &is](){
        string raw_input = "";
        cout << label << " = ";
        getline(is,raw_input);
        while (!UserInputStr(raw_input))
        {
            cout << label << " = ";
            getline(is,raw_input);
        }
        varLink = raw_input;
    };
}

#endif 