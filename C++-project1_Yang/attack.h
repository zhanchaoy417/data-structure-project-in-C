// CS1300 Spring 2020
// Author: Zhanchao Yang/ Haoxuan Ding
// Recitation: 104 – Dhanendra Soni/ Recitation: 106 – Sravanth Yajamanam
// Project 3 - group project 

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include <ctime>
#include<stdlib.h>
using namespace std;
//attack.h

#ifndef ATTACK_H
#define ATTACK_H 
class attack:public store 
{
    private:
    double money;
    string goodName;
    double pay;
    int numGood[5];
    
    public:
  attack();
    double attackGetMoney();
    void attackBill();   
    void attackSetMoney(double pay);
    
};


#endif 