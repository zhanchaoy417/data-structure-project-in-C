#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP
using namespace std;

class bubble
{
private:
  int bubblearray;
  int n;//size of the array
  void swap(int  *x,int *y);//if need

  public:
 

  void bubblesort(int arr[],int n);
  void bubbleinsert(int arr[],int n);
  int bubblesearch(int arr[],int number);
  void printbubbleSort(int arr[],int n);
  
};
#endif