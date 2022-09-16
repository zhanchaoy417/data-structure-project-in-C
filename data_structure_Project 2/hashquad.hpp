#ifndef HASHQUAD_HPP
#define HASHQUAD_HPP

using namespace std;

class HashTable
{
    private:
    int tableSize;  // No. of buckets (linked lists)
    // Pointer to an array containing buckets
    int *table;
    int numOfcolision =0;
public:
    HashTable(int bsize);  // Constructorg

    // inserts a key into hash table
    bool insert(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

   void printTable();
    int getNumOfCollision();

    int search(int key);
};

#endif