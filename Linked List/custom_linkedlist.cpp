/*
* How to use User defined header file in C++.
*/
#include<iostream>
#include"linkedlist.h" // important to included header file.
using namespace std;

int main(){

    Linkedlist list;

    list.insertAtHead(1);
    list.insertAtTail(2);
    list.insertAtTail(4);

    list.display();

    list.deleteNode(2); // delete node where data is '2'.
    list.deleteNode(90); // trying to delete non existing node .
    list.deleteNode(1);
    list.deleteNode(4);
    list.deleteNode(2); // try to delete on empty list.

    list.display();
    return 0;
}