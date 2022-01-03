#include "LinkedList.h"
#include <iostream>
#include <array>

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
}


void LinkedList::addFront(int newItem) {
    Node * curr = new Node();
    curr->setData(newItem);
    curr->setNext(head);
    head = curr;
}

void LinkedList::addEnd(int newItem) {
    Node * curr = new Node();
    curr->setData(newItem);
    curr->setNext(nullptr);

    if(head == nullptr)
    {
        head = curr;
    }
    else
    {
        Node * temp = head;

        while(temp ->getNext() != nullptr)
        {

            temp = temp->getNext();

        }

        temp->setNext(curr);
    }
}

void LinkedList::addAtPosition(int position, int newItem) {

    if(position < 1)
    {
        addFront(newItem);
    }

    Node * temp = head;
    int count = 1;

    while(temp->getNext() != nullptr)
    {
        if(count+1 == position)
        {
            Node * curr = new Node();
            curr->setData(newItem);
            curr->setNext(temp->getNext());
            temp->setNext(curr);
            return;
        }
        else
        {
            temp = temp->getNext();
            count++;
        }
    }

    addEnd(newItem);
}

int LinkedList::search(int item) {
    Node * temp = head;
    int count = 1;

    while(temp->getData() != item)
    {
        if(temp->getNext() == nullptr)
        {
            cout<<0<<" ";
            return 0;
        }
        else
        {
            temp = temp->getNext();
            count++;
        }
    }

    cout<<"This element in "<<count<<" ";
    return count;
}

void LinkedList::deleteFront() {
    Node *temp = head;
    head->setData((temp->getNext())->getData());
    head->setNext((temp->getNext())->getNext());
    delete temp;
}

void LinkedList::deleteEnd() {
    if(head == nullptr)
    {
        delete head;
    }

    if(head->getNext() == nullptr)
    {
        head = nullptr;
    }
    else
    {
        Node *temp = head;
        while((temp->getNext())->getNext() != nullptr)
        {
            temp = temp->getNext();
        }

        temp->setNext(nullptr);
        temp = temp->getNext();
        delete temp;
    }
}

void LinkedList::deletePosition(int position) {
    if(position < 1)
    {
        cout<<"outside of range"<<endl;
    }

//    if(position == 1)
//    {
//        deleteFront();
//    }

    Node * temp = head;
    int count = 1;

    while(temp->getNext() != nullptr)
    {
        cout<<"temp is"<<temp->getData()<<endl;
        if(count+1 == position)
        {

            temp->setNext(temp->getNext()->getNext());
            cout<<"temp1 before delete: "<<temp->getData()<<endl;
            cout<<"temp2 before delete: "<<temp->getData()<<endl;
            delete temp->getNext();
            return;
        }

        temp = temp->getNext();
        count++;
    }
    cout<<"outside of range"<<endl;
}

void LinkedList::printItems() {
    Node * curr = head;
    if(curr != nullptr)
    {
        while(curr != nullptr)
        {
            cout<<curr->getData()<<" ";
            curr = curr->getNext();
        }
    }
    else
    {
        cout<<"This list is empty"<<endl;
    }
}

LinkedList::LinkedList(int *array, int size) {
    LinkedList list;
    for(int i=0;i<size;i++)
    {
        list.addEnd(array[i]);

    }
}

int LinkedList::getItem(int position) {
    Node * temp = head;
    int count = 1;

    while(temp->getNext() != nullptr)
    {
        if(count==position)
        {
            return temp->getData();
        }
    }
    return 0;
}

LinkedList::~LinkedList()
{

}



