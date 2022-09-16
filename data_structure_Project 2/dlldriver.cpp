#include<iostream>
#include<fstream>
#include<sstream>
#include<ctime>
#include <chrono>
#include <thread>
#include<string>
#include"dll.hpp"

using namespace std;
using namespace std::chrono;


int main()
{
     //open data.csv
    ifstream myFile("dataSetA.csv");
     if(!myFile.is_open())
    {
        cout<<"Failed"<<endl;
        return -1;
    }


    LinkedList ll;
    //creat testdata which size is 100000
    int testData[10000] = {NULL};
    float insert[100] = {NULL};
    float search[100] = {NULL};
    string line,ID;
    
    
   //read file and use getline function put data into data array
   
   int i=0;
    while(getline(myFile,ID,','))
    {
        testData[i]=stoi(ID);
        i++;
    }
   
       //close input file
   myFile.close();


  
  //Calculate the time for inserting each 100 plot points
    for(int i=0;i<100;i++)
    {
        auto start=steady_clock::now();

        //insert every 100 item coreespond to the value of i
        for(int j=100*i;j<(100*i+100);j++)
        {
          ll.insert(testData[j]);
        }

        //use clock to count time 
        auto end=steady_clock::now();
        float data=(float)duration_cast<microseconds>(end-start).count()/100; 

    //record as insert[] array
        insert[i] = data;
        
    }

    //Calculate the time for searching each 100 plot points
     for(int i=0;i<100;i++)
    {
        auto start=steady_clock::now();

  //use rand method coreespond to the value of i
        for(int j=0;j<(i+1)*100;j++)
        {
            int num=rand()%((i+1)*100);
          ll.search(testData[num]);
        }
    //use clock to count time   
        auto end=steady_clock::now();
        float data=(float)duration_cast<microseconds>(end-start).count()/100; 

        //record as search[] array
        search[i] = data;
    }

    //open an out file, cout the data from insert,search array
    ofstream outFile("linkedlist2.csv");
    for(int i=0;i<100;i++){
        outFile << insert[i]<<",";
        
    }
    outFile<<endl;
    for(int i=0;i<100;i++){
        outFile<< search[i]<<",";
    }
    
    //close file
    outFile.close();

    return 0;
}