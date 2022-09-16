#include<iostream>
#include<fstream>
#include<sstream>
#include<ctime>
#include <chrono>
#include <thread>
#include<string>
#include"hashquad.hpp"

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


  //creat table as size=40009
    HashTable table(40009);
    int testData[10000] = {NULL};
    float insert[100] = {NULL};
    float search[100] = {NULL};
    // correspond number of collisions at start and at the end
     int sc, ec;
      int insertCollisions[100] = {NULL};
    int searchCollisions[100] = {NULL};
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
        //frist get the number of collsions
        sc = table.getNumOfCollision();

        //use clock to count time when inserting
        auto start=steady_clock::now();

         //insert every 100 item coreespond to the value of i
        for(int j=0;j<100;j++)
        {
            table.insert(testData[100*i+j]);
        }
        auto end=steady_clock::now();

        //get the final collsions
        ec = table.getNumOfCollision();
        float data=(float)duration_cast<microseconds>(end-start).count()/100; 
         //record as insert[] array
        insert[i] = data;

        //get number of collision for each 100 elements, is equal the final number minus start number 
        insertCollisions[i] = ec-sc;
    }

    /*Calculate the time of searching and store the result to search array*/
    for(int i=0;i<100;i++)
    {
         //frist get the number of collsions
        sc = table.getNumOfCollision();

        //use clock to count time when searching
        auto start=steady_clock::now();

        //use rand method,search every 100 item coreespond to the value of i
        for(int j=0;j<(i+1)*100;j++)
        {
            int index = rand()%((i+1)*100);
            table.search(testData[index]);
        }

       auto end=steady_clock::now();
       //get the final collsions
        ec = table.getNumOfCollision();

      float data=(float)duration_cast<microseconds>(end-start).count()/100;  
        //record as search[] array
        search[i] = data;
        //get number of collision for each 100 elements, is equal the final number minus start number 
        searchCollisions[i] = ec-sc;
    }


      //open an out file for time
    ofstream outFile("hashtable.csv");
    for(int i=0;i<100;i++){
        outFile << insert[i]<<",";
        
    }
    outFile<<endl;
    for(int i=0;i<100;i++){
        outFile<< search[i]<<",";
    }
    outFile.close();

   //open another file of collsions
    ofstream outFile2("hashtableCollisions.csv");
    for(int i=0;i<100;i++){
        outFile2<< insertCollisions[i]<<",";
        
    }
    outFile2<<endl;
    for(int i=0;i<100;i++){
        outFile2 << searchCollisions[i]<<",";

    }
    outFile2.close();
    return 0;
    
}