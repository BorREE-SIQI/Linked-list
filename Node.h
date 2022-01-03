#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
        {
        private:
            int data;
            Node * next;

        public:
            Node();
            void setData(int);
            int getData();
            void setNext(Node *);
            Node * getNext();
        };
#endif