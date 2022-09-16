// CS1300 Spring 2020
// Author: Zhanchao Yang/ Haoxuan Ding
// Recitation: 104 – Dhanendra Soni/ Recitation: 106 – Sravanth Yajamanam
// Project 3 - group project

//store.h

#include <iostream>
#include <string>
#include<fstream>
#include<cstring>
#include<vector>
#ifndef STORE_H
#define STORE_H

using namespace std;

class store
{
    private:
    string goodName;
   int numGood[5];
  string nameGood[5]={"Oxen","Food","Bullets","Wagon","Kid"};
    double money;
    double pay;
    
    public:
    store();
    void setGoodName(string goodName);
    string getGoodName();
    void setGoodNum(int,int);
   int getGoodNum0();
   int  getGoodNum1();
   int  getGoodNum2();
   int  getGoodNum3();
   int  getGoodNum4();
    void setMoney(double pay);
    double getMoney();
    void bill();                //read bill
            
};





#endif