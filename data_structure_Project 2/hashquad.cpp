#include<iostream>
#include "hashquad.hpp"

using namespace std;

//default
HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new int[this->tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = NULL;
}
//use mod method to sort
unsigned int HashTable::hashFunction(int key)
{
    return (key % this->tableSize);
}

//search key, if find,return the key
int HashTable::search(int key)
{
    int index = hashFunction(key);
   
        for(int i=0;i<this->tableSize;++i)
        {
            if(table[(index+i*i)%this->tableSize]==key)
            {
                this->numOfcolision+=i;
                return key;
                break;
            }
            
        }
        //not found
       
    return -1;
}

//using the quadric probing to insert
bool HashTable::insert(int key)
{

        int index=hashFunction(key);
       for(int i=0;i<this->tableSize;i++)
       {
           if( table[(index+i*i)%this->tableSize]==NULL)
           {
               table[(index+i*i)%this->tableSize]=key;
                return true;
                break;
           }
           this->numOfcolision+=i;
       }
        return false;


}
//display the data from array
void HashTable::printTable()
{
    for (int i = 0; i < this->tableSize; i++) {

        if(table[i]!=NULL)
        {
            cout<<table[i]<<" ";
        }
        cout<<endl;
    }

}

//get collsions
 int HashTable::getNumOfCollision()
 {
    return this->numOfcolision;
 }