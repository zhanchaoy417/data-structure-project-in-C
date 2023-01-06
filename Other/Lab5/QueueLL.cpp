#include <iostream>
#include "QueueLL.hpp"

using namespace std;

QueueLL::QueueLL()
{
    queueFront = nullptr;
    queueEnd = nullptr;
}

QueueLL::~QueueLL()
{
    while( !isEmpty() )
        dequeue();
}

bool QueueLL::isEmpty()
{
    /*if(queueFront == nullptr || queueEnd == nullptr)
        return true;
    return false;*/
    return (!queueFront || !queueEnd);
}

// TODO
void QueueLL::enqueue(int key)
{
    //the queue is empty
    if(isEmpty())
    {
    Node *nn = new Node;
    nn->key = key;
    nn->next = nullptr;
    queueFront=nn;
    queueEnd=nn;  
    }
    else
    {
        Node *nn=new Node;
        nn->key=key;
        queueEnd->next=queueEnd;
        queueEnd=nn;
    }
    

    // TODO Complete this function, handle the case when you're enqueuing in an empty queue
}

//TODO
void QueueLL::dequeue()
{
    if(!isEmpty())
    {
        if(queueFront!=queueEnd)
        {
           Node* nn=new Node;
           nn=queueFront;
           queueFront=queueFront->next;
           delete nn;
        }
        //Front and End are the same
        else
        {
            Node *nn=new Node;
            nn=queueFront;
            delete nn;
            queueFront=NULL;
            queueEnd=NULL;
        }
        // TODO Complete this function, handle the case when your queue becomes empty after dequeuing
    }
    else{
        cout<<"queue is empty. can not deque"<<endl;
    }
}

int QueueLL::peek()
{
    if( !isEmpty() )
        return queueFront->key;
    else
    {
        cout<< " queue is empty. can not peek"<<endl;
        return -1;
    }
    //return 0;
}
