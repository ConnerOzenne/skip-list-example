#include<iostream>

using namespace std;

class lNode
{
public:
    int data;
    lNode *next;
};

class List
{
    lNode *head;
    lNode *tail;
    lNode *temp;
    bool isEmpty()
    {
        return head == NULL;
    }
public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int x)
    {
        temp = new lNode;
        temp->data = x;
        if(isEmpty())
        {
            temp->next = NULL;
            tail = temp;
        }
        else
            temp->next = head;
        head = temp;
    }

    void insertAtEnd(int x)
    {
        temp = new lNode;
        temp->data = x;
        temp->next = NULL;
        if(isEmpty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void remove(int x)
    {
        temp = head;
        lNode *prev;
        while(temp->next != NULL && temp->data != x)
        {
            prev = temp;
            temp = temp->next;
        }
        if(temp->data == x)
        {
            prev->next = temp->next;
            delete temp;
        }
        else if(temp->next == NULL)
        {
            cout << "Error: Number Not found..." << endl;
        }
    }

    void find(int x)
    {
        int i;
        for(i=1, temp = head;temp->next != NULL && temp->data != x;temp = temp->next, i++);
        if(temp->data == x)
        {
            //cout << "Found at position:" << i << endl;
        }
        else if(temp->next == NULL)
        {
            //cout << "Error: Number Not found..." << endl;
        }
    }

    void display()
    {
        if(!isEmpty())
        {
            for(temp = head; temp != NULL; temp=temp->next)
                cout << temp->data << " ";
            cout << endl;
        }
        else
        {
            cout << "List is Empty!" << endl;
        }
    }
};