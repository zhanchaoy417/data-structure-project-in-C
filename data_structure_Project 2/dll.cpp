#include<iostream>
#include<stdio.h>
#include "dll.hpp"
using namespace std;

 //insert function,the next items is link after the head
 void LinkedList::insert(int key)
 {
     //creat a new node
     struct Node *ll=(struct Node*) malloc(sizeof(struct Node));
     ll->key=key;
     ll->prev=NULL;
     ll->next=NULL;

//if head not found,return
     if(head==NULL)
     {
         head=ll;
         return;
     }

     //insert a new node after the head, and set its next equal NULL
     Node *temp=head;
     while(temp->next!=NULL)
     {
         temp=temp->next;
     }
     temp->next=ll;
     Node* end=ll;
     ll->prev=temp;

 }
 
 //search function 
 void LinkedList::search(int key)
 {
     //if head not found,return
     if(head==NULL)
     {
         return;
     }
     Node* temp=head;

     //transverse
     while(temp!=NULL)
     {
         if(temp->key==key)
         {
             return;
         }
        
         temp=temp->next;
     }

 }

//display
void LinkedList::printList(){
  Node* n = head;

  while(n!=NULL&&n->next != NULL){
    cout<< n->key <<"  ";
    n = n->next;
  }

  cout<<n->key<<endl;
}

