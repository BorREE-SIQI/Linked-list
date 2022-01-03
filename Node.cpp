#include "Node.h"
#include <iostream>

using namespace std;

Node::Node() {
    data = 0;
    next = nullptr;
}

void Node::setData(int val) {
    data = val;
}

int Node::getData() {
    return data;
}

void Node::setNext(Node * n) {
    next = n;
}

Node * Node::getNext() {
    return next;
}