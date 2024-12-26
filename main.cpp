#include <iostream>

using namespace std;

template<class t>

class linkedQueue{
private:
    struct Node
    {
        t item;
        Node *next;
    };
    Node *frontPtr;
    Node *rearPtr;
    int length;

public:
    linkedQueue()
    {
        frontPtr=rearPtr=NULL;
        length=0;

    }
    bool isEmpty(){
    return length==0;
    }
    void enqueue(t element)
    {
        if(isEmpty())
        {
            frontPtr=new Node;
            frontPtr->item=element;
            frontPtr->next=NULL;
            rearPtr=frontPtr;
            length++;
        }
        else{
            Node *newPtr=new Node;
            newPtr->item=element;
            newPtr->next=NULL;
            rearPtr->next=newPtr;
            rearPtr=newPtr;
            length++;
        }
    }
    void dequeue(){
    if(isEmpty())
    {
        cout<<"Empty Queue, Cannot Dequeue...!";
    }
    else{
        Node *tempPtr=frontPtr;
        if(frontPtr==rearPtr)
        {
            frontPtr=NULL;
            rearPtr=NULL;
            length--;
        }
        else{
                length--;
            frontPtr=frontPtr->next;
            tempPtr->next=NULL;
            delete tempPtr;

        }
    }
    }

    t getFront()
    {
        return frontPtr->item;
    }
    t getRear()
    {
        return rearPtr->item;
    }

    int getSize()
    {
        return length;
    }

    void display()
    {
        Node *curPtr=frontPtr;
        cout<<"Items in the queue: [";

        while(curPtr !=NULL)
        {
            cout<<curPtr->item<<" ";
            curPtr=curPtr->next;

        }
        cout<<" ]\n";
    }

    void clearQueue()
    {
        Node *current;
        while (frontPtr!=NULL)
        {
            current=frontPtr;
            frontPtr=frontPtr->next;
            delete current;
        }
        rearPtr=NULL;
        length=0;
    }



};

int main()
{
    linkedQueue <int> q1;

    q1.enqueue(100);
    q1.enqueue(200);
    q1.enqueue(300);
    q1.display();

    q1.dequeue();
    q1.display();

    return 0;
}
