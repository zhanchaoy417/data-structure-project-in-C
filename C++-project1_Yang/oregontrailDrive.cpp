// CS1300 Spring 2020
// Author: Zhanchao Yang/ Haoxuan Ding
// Recitation: 104 – Dhanendra Soni/ Recitation: 106 – Sravanth Yajamanam
// Project 3 - group project


//drive cpp. All the function will combine on here and to implement
#include <iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include <ctime>
#include<stdlib.h>
using namespace std;
#include "attack.cpp"

//declare all function
void menu_game();
void menu_store();
void menu_Hunt();
void menu_Interest();
void menu_journey();
void menu_attack();
void readFile();


int main()
{
    readFile();     //get player information
    menu_game();    //start game
    return 0;
}