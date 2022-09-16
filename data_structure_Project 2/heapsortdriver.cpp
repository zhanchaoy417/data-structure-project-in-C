#include<iostream>
#include<fstream>
#include<sstream>
#include<ctime>
#include <chrono>
#include <thread>
#include<string>
#include"heapsort.hpp"

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
    
 //creat testdata which size is 100000
    int testData[10000] = {NULL};
    float sort[100] = {NULL};
    
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



    //Calculate the time for each 100 plot points
    for(int i=0;i<100;i++)
    {
        heapSort hs;
        //creat temarry,first the size is 100, then is 200,300..
         int  temArr[100*(i+1)];

         //transfer data from testdata to temarray
        for(int j=0;j<100*(i)+100;++j)
          {
             temArr[j]=testData[j];
          }
          //use clock to count time when sorting
          auto start=steady_clock::now();
          hs.heapsort(temArr,100*(i+1));
        auto end=steady_clock::now();
        float data=(float)duration_cast<microseconds>(end-start).count(); 

        //record as sort[] array
        sort[i] = data;
        
    }


   //open an out file

    ofstream outFile("heapsort.csv");
    for(int i=0;i<100;i++){
        outFile << sort[i]<<",";
        
    }
    cout<<endl;

 //close out file
    outFile.close();

    return 0;
}