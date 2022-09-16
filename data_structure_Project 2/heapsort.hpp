#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP
using namespace std;

struct heapSort
{
  private:
  int heaparray;
  int n;//size of the array
  void swap(int  *x,int *y);//if need

  public:


  void heapify(int arr[],int n,int i);
   
  void heapsort(int arr[],int n);
  void heapinsert(int arr[],int n);
  int heapsearch(int arr[],int number);
  void printheapSort(int arr[],int n);
};
#endif