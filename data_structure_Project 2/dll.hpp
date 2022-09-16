#ifndef DLL_HPP
#define DLL_HPP
struct  Node
{
   int key;
   Node* next;
   Node* prev;
};
class LinkedList
{
  private:
    Node *head;

  public:
    LinkedList(){
    	head = NULL;
    }
  
    void insert(int key);

  void search(int key);
    void printList();
};


#endif