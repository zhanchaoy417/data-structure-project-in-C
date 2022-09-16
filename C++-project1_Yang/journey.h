// CS1300 Spring 2020
// Author: Zhanchao Yang/ Haoxuan Ding
// Recitation: 104 – Dhanendra Soni/ Recitation: 106 – Sravanth Yajamanam
// Project 3 - group project

//class journey
#include <iostream>
#include<fstream>
#include<string>
#include <cstring>
#include<vector>
#include <ctime>
#include<stdlib.h>
using namespace std;

#ifndef JOURNEY_H
#define JOURNEY_H
class journey
{
    private:
  double journeydistance;
  double roadtaken;
    
    
    public: 
    journey();   //defalult function
    void setJourney(double);
    double getJourney();
    void readRiverAndFort(double);
   
};


#endif