// CS1300 Spring 2020
// Author: Zhanchao Yang/ Haoxuan Ding
// Recitation: 104 – Dhanendra Soni/ Recitation: 106 – Sravanth Yajamanam
// Project 3 - group project

#include <iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include <ctime>
#include<stdlib.h>

using namespace std;
void menu_game();
void menu_store();
void menu_Hunt();
void menu_Interest();
void menu_journey();
void menu_attack();
void readFile();



void menu_Hunt()
{
   store Store;
    int choice;
     string greeting="Do you want to hunt or escape?\n Select a numerical option:\n 1. Hunt it\n 2. leave temporarily\n";
    srand((unsigned)time(NULL));
    int  n=rand()%20;
   
    if(n<10)
    {
        cout<<"YOU GOT LUCKY! You meet a cute rabbit."; cout<<greeting<<endl;
        cout<<" Enter you choice :"<<endl;
        cin>>choice;
        if(choice==1)
        {
            cout<<"You has successful hunt it. You gain 2 lbs of food and You used 10 bulltes "<<endl;
            Store.setGoodNum(2,-10);
            Store.setGoodNum(1,2);
             Store.bill();
        }
        if(choice==2)
        {
            cout<<"You have safely left."<<endl;
        }
       
    }
   else if(n>=10&&n<14)
    {
        cout<<"YOU GOT LUCKY! You meet a cute rabbit."; cout<<greeting<<endl;
        cout<<" Enter you choice :"<<endl;
        cin>>choice;
        if(choice==1)
        {
            cout<<"You has successful hunt it. You gain 2 lbs of food and You used 10 bulltes "<<endl;
            Store.setGoodNum(2,-8);
            Store.setGoodNum(1,5);
            Store.bill();
        }
        if(choice==2)
        {
            cout<<"You have safely left."<<endl;
        }
       
    }
    else if(n>=14&&n<17)
    {
        cout<<"YOU GOT LUCKY! You meet a cute rabbit."; cout<<greeting<<endl;
        cout<<" Enter you choice :"<<endl;
        cin>>choice;
        if(choice==1)
        {
            cout<<"You has successful hunt it. You gain 2 lbs of food and You used 10 bulltes "<<endl;
            Store.setGoodNum(2,-5);
            Store.setGoodNum(1,50);
             Store.bill();
        }
        if(choice==2)
        {
            cout<<"You have safely left."<<endl;
            
        }
       
    }
    else if(n>=17&&n<19)
    {
        cout<<"YOU GOT LUCKY! You meet a cute rabbit."; cout<<greeting<<endl;
        cout<<" Enter you choice :"<<endl;
        cin>>choice;
        if(choice==1)
        {
            cout<<"You has successful hunt it. You gain 2 lbs of food and You used 10 bulltes "<<endl;
            Store.setGoodNum(2,-10);
            Store.setGoodNum(1,300);
             Store.bill();
        }
        if(choice==2)
        {
            cout<<"You have safely left."<<endl;
        }
       
    }
    else
    {
        cout<<"YOU GOT LUCKY! You meet a cute rabbit."; cout<<greeting<<endl;
        cout<<" Enter you choice :"<<endl;
        cin>>choice;
        if(choice==1)
        {
            cout<<"You has successful hunt it. You gain 2 lbs of food and You used 10 bulltes "<<endl;
            Store.setGoodNum(2,-12);
            Store.setGoodNum(1,500);
             Store.bill();
        }
        if(choice==2)
        {
            cout<<"You have safely left."<<endl;
        }
       
    }
    cout<<endl;
     menu_game();  //return main menu
}
//end of menu_Hunt function

void menu_Interest()
{
    double stock=1000;
   double bank=0;
    string greeting="Let's start your own business. \n Select a numerical option:\n 1. Deposit\n 2. Investment\n 3. leave temporarily\n";
    int choice;
    cout<<greeting;
    cin>>choice;
    
    if(choice==1)
    {
        cout<<"How much you wanna put in the band: ";
        double deposit;
        cin>>deposit;
        bank+=deposit;
        cout<<"currently you have "<<stock<<" dollars and the amount in bank is "<<bank<<" dollars "<<endl;
    }
   else if(choice==2)
    {
        string greeting2="Select a numerical option:\n 1. Apple\n 2. Amazon\n 3. Warmart\n 4. Nike\n 5. Google\n";
        int choice2;
        double investingMoney;
        cout<<greeting2;
        cin>>choice2;
        cout<<"Enter your investing Money for this time: "<<endl;
        cin>>investingMoney;
        
            srand((unsigned)time(NULL));
            int a=rand()%5;
       
            if(a==0)
            {
                stock+=investingMoney*3.0;
                cout<<"You are successful this time. And you earn "<<investingMoney<<endl;
            }
            else
            {
                cout<<"Unfortunately,you lose all your investing money."<<endl;
            }
    }
    
   else if(choice==3)
    {
        cout<<"Welcom for next time."<<endl;
         menu_game();
    }
    else
    {
       cout<<"Invalid option. Please enter your choice again."<<endl;
       cout<<greeting;
    }
    cout<<endl;
     menu_game();
     
}
//end of menu_interest function

//define write file
void readFile()
{
    ofstream myfile("userInfo.txt",ios_base::app);
    int age;
    double score=1000;
    string Fname;
    string Lname;
    cout<<"Please enter your first name:"<<endl;
    cin>>Fname;
    cout<<"Please enter your last name:"<<endl;
    cin>>Lname;
cout<<"age:"<<endl;
    cin>>age;
    
 myfile<<"playerName: "<<Fname<<" "<<Lname<<" Age: "<<age<<" score: "<<score<<endl;
}
