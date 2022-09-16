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
#include "store.cpp"
#include "attack.h"
//attack.cpp

void menu_game();
void menu_store();
void menu_Hunt();
void menu_Interest();
void menu_journey();
void menu_attack();
void readFile();

 attack:: attack()
{
    money=1000;
      for(int i=0;i<5;i++)
    {
        numGood[i]=50;
    }
    
}
  double attack::attackGetMoney()
{
    store::getMoney();
}  
void attack::attackBill()
{
    store::bill();
}
void attack::attackSetMoney(double pay )
{
   this->pay=pay;
    money+=pay;
}


void menu_attack()
{
   store Store;
    int choice;
   string  quote1="Unfortunately, You met an enemy on your journey.\n";
    string quote2="There is no strange things happen on you, YOU GOT LUCKY!\n";
    string quote3="Select a numerical option:\n 1.Run\n"
    " 2.Attack\n 3.Surrender\n";
    string quote4="You had safely left but left behind 1 ox, 10 lbs. of food and 1 wagon part.";
    string quote5="congratulations, you win the battle, HAHA!";
    string quote6="Sorry, you lost the battle and you need to pay for it";
    string quote7="You surrender to your enemy and be traped.";
   srand((unsigned)time(NULL));
   int n =rand()%2;
   if(n==0)
   {
       cout<<quote1<<quote3<<endl;
       cin>>choice;
       switch(choice)
       {
           case 1:
           {
           cout<<quote4<<endl;
           Store.setGoodNum(0,-1);
           Store.setGoodNum(1,-10);
           Store.setGoodNum(3,-1);
           Store.bill();
           menu_game();
           break;
           }
           
           //for case 2, win the battle or lost the battle
            case 2:
            {
                srand((unsigned)time(NULL));
                int num =rand()%3;
                int num2;
                cout<<"guess a number 1 to 3"<<endl;
                cin>>num2;
                if(num2==n)
                {
                    cout<<quote6<<endl;
                Store.setGoodNum(1,-50);
               Store.setMoney(-500);
               Store.bill();
                menu_game(); 
                }
             else
             {
                 cout<<quote5<<endl;
            Store.setGoodNum(1,50);
             Store.setMoney(500);
             Store.bill();
            menu_game(); 
             }
             break;
            }
           
            case 3:
            {
            cout<<quote7<<endl;
           Store.bill();
           menu_game();
           break;
           
           default:
           cout<<"Invalid option. Please enter your choice again."<<endl;
           cout<<quote3<<endl;
           break;
            }
           
       }
   }
   else
   {
       cout<<quote2<<endl;
       menu_game();
   }
}
