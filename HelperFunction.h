#pragma once
#include<fstream>
#include<iostream>
#include <string>
#include<Windows.h>
#include<iostream>
using namespace std;
class HelperFunction
{
public:
    void failInput();
    void selectedBox(int& val);
    void mainMenu();
    void sucessBox(char operation[25]);
    void failBox(char operation[25]);
};

