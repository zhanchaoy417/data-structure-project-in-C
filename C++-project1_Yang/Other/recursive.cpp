// CS1300 Spring 2020

#include <iostream>
#include <string>
using namespace std;
//create a recursive case,take a integer as parameter
string decimalToBinaryRecursive(int number)
{
    if(number==0)    //base case
    {
      return "0";    
    }
    else if(number==1)   //base case
    {
       return "1";
    }
    else
    {
        int n=number%2;   //n is remainder
        //if the remainder is 0,character be"0",otherwise be "1". add to string.
        string str= (n ==0 ?"0":"1");  
        //recursive, doing number divided by 2
      return decimalToBinaryRecursive(number/2)+str;
    }
     
}
int main()
{
    //unit test. Expect output: 1000
    cout<<decimalToBinaryRecursive(8);
	return 0;
}

#include <iostream>
using namespace std;
//create a normal function, take integer as parameter
string decimalToBinaryIterative(int number)
{
    string str;
    if(number==0)    //if the number=0. cout "0"
    {
        str="0";   
    }
    while(number>0)   //if the number>0,count the remainder
    {
        if(number%2==0)   //could dividble by 2
        {
            str="0"+str;
        }
     else
     {
         str="1"+str;      //not dividble by 2
     }
        number /=2;        // do again until jump out the loop
    }
    return str;
}
int main()
{
    //unit test. Expect output: 1000
   cout<< decimalToBinaryIterative(8)<<endl;
 return 0;
}