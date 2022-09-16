// CS1300 Spring 2020
// Author: Zhanchao Yang/ Haoxuan Ding
// Recitation: 104 – Dhanendra Soni/ Recitation: 106 – Sravanth Yajamanam
// Project 3 - group project

#include "journey.h"

void menu_game();
void menu_store();
void menu_Hunt();
void menu_Interest();
void menu_journey();
void menu_attack();
void readFile();




  journey::journey()  //defalult function
   {
       journeydistance=0;
   } 
    void journey::setJourney(double roadtaken)
 {
    this->roadtaken=roadtaken;
    journeydistance+=roadtaken;
 }
double journey:: getJourney()
 {
        return journeydistance;
  }
void journey:: readRiverAndFort(double D)//D is distance have took
    {
        vector <string> riverName(0);
        vector <string> riverDistance(0);
        	ifstream myfile("river.txt");
            if(!myfile)
       {
        cout<<"file does not exist"<<endl;
        exit(1);
       }
      string name;
      int c=0;
     while(!myfile.eof())
     {
       if(c%2==0)
       {
           getline(myfile,name);
           riverName.push_back(name);
       }
        else
      {
        getline(myfile,name);
        riverDistance.push_back(name);
      }
       c++;
       
      }
      //end of readRiver
         vector <string> fortName(0);
         vector <string> fortDistance(0);
          ifstream myfile1("fort.txt");
         if(!myfile1)
    {
        cout<<"file does not exist"<<endl;
        exit(1);
    }
    string name1;
   int c1=0;
   while(!myfile1.eof())
   {
       if(c1%2==0)
       {
           getline(myfile1,name1);
           fortName.push_back(name1);
       }
        else
      {
        getline(myfile1,name1);
        fortDistance.push_back(name1);
       }
        c1++;
       
   }//end of readFort
     if(D>=1863)
            {
                cout<<"You has passed the final Fort "<<fortName[5]<<endl;
            }
        else if(D>=1648)
            {
                cout<<"You has passed "<<fortName[4]<<" and You has crossed the last dangerous river"<<riverName[3]<<endl;
            }
         else if(D>=1395)
            {
                cout<<"You has passed "<<fortName[3]<<" and You has crossed "<<riverName[2]<<endl;
            }
        else if(D>=989)
            {
                cout<<"You has passed "<<fortName[2]<<endl;
            }
         else  if(D>=640)
            {
                cout<<"You has passed "<<fortName[1]<<endl;
            }
          else  if(D>=304)
            {
                cout<<"You has reached the first Fort"<<fortName[0]<<" and You has crossed "<<riverName[1]<<endl;
            }
            else if(D>=102)
            {
                cout<<"You has crossed "<<riverName[0]<<endl;
            }
            else
            {
                cout<<"You has not see any fort or river so far"<<endl;
            }
  
    }
    
    
void menu_journey()
{
    journey Jour;
    bool done=true;
    string greeting="Select a numerical option:\n ===journey.menu===\n 1.take journey\n"
    " 2.Rest \n 3.return menu\n";
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
            
            srand((unsigned)time(NULL));
            int n=rand()%4;
          if(n==0)
          {
             cout<<"You travel 30 miles this time."<<endl;
             double roadtaken=30;
             Jour.setJourney(roadtaken);
             cout<<"You have been traveled "<<Jour.getJourney()<<" miles."<<endl;
          }
        else if(n==1)
         {
            cout<<"You travel 50 miles this time."<<endl;
             double roadtaken=50;
             Jour.setJourney(roadtaken);
             cout<<"You have been traveled "<<Jour.getJourney()<<" miles."<<endl;
        }
         else if(n==2)
        {
              cout<<"You travel 80 miles this time."<<endl;
             double roadtaken=80;
             Jour.setJourney(roadtaken);
             cout<<"You have been traveled "<<Jour.getJourney()<<" miles."<<endl;
        }
        else if(n==3)
        {
             cout<<"You travel 100 miles this time."<<endl;
             double roadtaken=100;
             Jour.setJourney(roadtaken);
             cout<<"You have been traveled "<<Jour.getJourney()<<" miles."<<endl;
         }
         //for n==4
         else
         {
             cout<<"You travel 140 miles this time."<<endl;
             double roadtaken=140;
             Jour.setJourney(roadtaken);
             cout<<"You have been traveled "<<Jour.getJourney()<<" miles."<<endl;
         }
            Jour.readRiverAndFort(Jour.getJourney());
            cout<<endl;
            
         
         
            cout<<greeting;
            break;
        }  
            case 2:
            {
               cout<<"Today you didn't trave but have a good sleep!"<<endl;
                cout<<endl<<greeting;
            break;
            }   
            
            case 3:  //exit 
            {
            cout<<"exit travel so far!"<<endl;
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
