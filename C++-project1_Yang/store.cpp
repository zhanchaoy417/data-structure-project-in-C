// CS1300 Spring 2020
// Author: Zhanchao Yang/ Haoxuan Ding
// Recitation: 104 – Dhanendra Soni/ Recitation: 106 – Sravanth Yajamanam
// Project 3 - group project

 // for menu function
#include "store.h"
#include "hunt.cpp"
#include "journey.cpp"
//declare all menu function
void menu_game();
void menu_store();
void menu_Hunt();
void menu_Interest();
void menu_journey();
void menu_attack();
void readFile();


store::store()
{
     money=1200;
    
       numGood[0]=2;
       numGood[1]=100;
       numGood[2]=1;
       numGood[3]=1;
       numGood[4]=1;
    
}
 void store::setMoney(double pay)
 {
    this->pay=pay;
    money+=pay;
 }
double store:: getMoney()
 {
        return money;
  }
void store:: setGoodName(string name)
{
    goodName=name;
}
string store::getGoodName()
{
    return goodName;
}
void store:: setGoodNum(int index,int num)
{
   numGood[index]+=num;
}
int store:: getGoodNum0()
{
   return numGood[0];
}
int store:: getGoodNum1()
{
   return numGood[1];
}
int store:: getGoodNum2()
{
   return numGood[2];
}
int store:: getGoodNum3()
{
   return numGood[3];
}
int store:: getGoodNum4()
{
   return numGood[4];
}
void store::bill()
{
     int i=0;
    while(i<5)
    {
        cout<<"the amount of "<<nameGood[i]<<": "<< numGood[i]<<endl;
        i++;
    }
}
void store_info()
{
    ifstream myfile("store_info.txt");
    if(!myfile)
    {
        cout<<"file does not exist."<<endl;
    }
    char words;
    string line;
    while(!myfile.eof())
    {
        getline(myfile,line);
        cout<<line;
    }
    cout<<endl;
    cout<<endl;
}

  
void menu_store()
{
      store Store;
    bool done=true;
    string greeting="Select a numerical option:\n ===store.menu===\n 1.Buy Oxen\n"
    " 2.Buy Food\n 3.Buy Bullets\n 4.Buy Miscellaneous Supplies\n 5.Return Menu\n";
    cout<<greeting;
    string name;
    int choice;
    cout<<"enter the your choice:";
    while(done)
    {
        cin>>choice;
        switch(choice)
   {
        case 1:
        {
            if(Store.getMoney()<40)
            {
                return menu_store();
            }
            double money_Oxen=0;
             int amount;
            cout<<"You must spend between $100 and $200 dollars on oxen.\n"
            <<"There are 2 oxen in a yoke and the price of each yoke is $40."<<endl;
            cout <<"Enter the amount of yokes for purchase:"<<endl;
            cin >> amount;
            money_Oxen+=40*amount;
             if(money_Oxen>200)
            {
                cout <<"You spend exceed 200 dollars on Oxen. This payment is failed. Please do following action."<<endl;
                return menu_store();
            }
            
             double payment=-(40*amount);
            Store.setMoney(payment);
            Store.setGoodNum(0,amount*2);
            cout<<"currently you have "<<Store.getMoney()<< " dollars and you have bought "<<
            Store.getGoodNum0()<<" oxens"<<endl;
            Store.bill();
           if(money_Oxen<100)
           {
            cout <<"You haven't spend 100 dollars on Oxen. Enter the amount of yokes for purchase:"<<endl;
            cin >> amount;
             double payment=-(40*amount);
            Store.setMoney(payment);
            Store.setGoodNum(0,amount*2);
            cout<<"currently you have "<<Store.getMoney()<< " dollars and you have bought "<<
            Store.getGoodNum0()<<" oxens"<<endl;
            Store.bill();
           }
            cout<<greeting;
            break;
        }  
            case 2:
            {
                if(Store.getMoney()<0.5)
            {
                return menu_store();
               
            }
                int amount;
            cout<<"I recommend you purchase at least 200 lbs.of food per person, at 50 cents per pound.\n"<<endl;
            cout<<"Enter the amount of pround of food for purchase:"<<endl;
            cin>>amount;
            double payment=-(0.5*amount);
            Store.setMoney(payment);
            Store.setGoodNum(1,amount);
            cout<<"currently you have "<<Store.getMoney()<< " dollars and you have bought "<<
            Store.getGoodNum1()<<" prounds of food"<<endl;
            Store.bill();
            cout<<endl<<greeting;
            break;
            }   
            
            case 3:
            {
                if(Store.getMoney()<2)
            {
                return menu_store();
               
            }
            int amount;
           cout<<"A box of 20 bullets costs $2.\n"<<"Enter the amount of boxes of bullets for purchase:"<<endl;
            cin>>amount;
             double payment=-(2*amount);
            Store.setMoney(payment);
            Store.setGoodNum(2,amount);
            cout<<"currently you have "<<Store.getMoney()<< " dollars and you have bought "<<
            Store.getGoodNum2()<<" boxes of bullets"<<endl;
            Store.bill();
            cout <<greeting;
            break;
            }
            
            case 4:
            {
                if(Store.getMoney()<20)
            {
                return menu_store();

            }
            int amount,amount1;
            cout<<"we have many wagon part: wheels, axles, tongues, each costs $20.\n"<<endl;
            cout<<"Enter the amount of wagon for purchase:"<<endl;
            cin>>amount;
             double payment=-(20*amount);
            Store.setMoney(payment);
            Store.setGoodNum(3,amount);
            cout<<"currently you have "<<Store.getMoney()<< " dollars and you have bought "<<
            Store.getGoodNum3()<<" wagon parts"<<endl;
            Store.bill();
            cout<<"medical aid maybe necessary for your journey\n"<<"Enter the amount of medical aid for purchase:"<<endl;
            cin>>amount1;
             double payment1=-(25*amount);
            Store.setMoney(payment1);
            Store.setGoodNum(4,amount1);
            cout<<"currently you have "<<Store.getMoney()<< " dollars and you have bought "<<
            Store.getGoodNum4()<<" medical kids"<<endl;
            Store.bill();
            cout <<greeting;
            break;
            }
            
            case 5:  //exit 
            {
            cout<<"Welcome next time visit store!"<<endl;
            cout<<endl;
            done=false;
            cout<<endl;
            menu_game();
            break;
            }
            
            default:
            {
            cout<<"Invalid option."<<endl;
            cout<<greeting;  //keep asking
            }
   }
    
    }
}

void menu_game()
{
   bool done=true;
    string greeting3="Select a numerical option:\n ===Oregon Trail.menu===\n 1.Visit store\n"
    " 2.Journey\n 3.Hunt\n 4.attack mode\n 5.business\n 6.Quit";
    cout<<greeting3<<endl;
    int choice;
    while(done)
    {
        cin>>choice;
        switch(choice)
        {
            case 1:
            menu_store();
            break;
            
            case 2:
            menu_journey();
            break;
            
            case 3:
            menu_Hunt();
            break;
            
            case 4:
            menu_attack();
            break;
            
            case 5:
            menu_Interest();
            break;
            
           case 6:
           cout<<"You can take the journey anytime. Good Bye!"<<endl;
           done=false;
           break;
    
           default:
           cout<<"Invalid option.Please enter again."<<endl;
           cout<<greeting3<<endl;
           cout<<endl;
           break;
        }
    }
}
