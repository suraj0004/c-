#include <iostream>
using namespace std;

class Node {

    public:
        int data;
        Node *next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void insertAtHead(int data,Node* &head){
    Node* node = new Node(data);
    node->next = head;
    head = node;
}

void insertAtTail(int data, Node* &head){

    Node *node = new Node(data);

    if(head == NULL){
        head = node;
        return;
    }

    Node* tmp = head;
    while (tmp->next != NULL){
        tmp = tmp->next;
    }

    tmp->next = node;
        
}

void display(Node* head){
    cout<<"\nDisplaying\n";
    while(head != NULL){
        cout<<head->data<<endl;
        head = head->next;

    }
}

bool search (int data, Node* head){
    while (head != NULL)
    {
        if(data == head->data)
            return true;
        head = head->next;
    }
    return false;
}


void deleteNode(int data, Node* &head){

    Node* toDelete;
    if(head->data == data){
        toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node* tmp = head;
    while (tmp->next != NULL && tmp->next->data != data)
    {
        tmp = tmp->next;
    }

    if(tmp->next != NULL){
        toDelete =  tmp->next;
        tmp->next = tmp->next->next;
        delete toDelete;
    }
    
}

bool detectCycle(Node* head){
    Node *fastPtr, *slowPtr;
    fastPtr = slowPtr = head;

    while(fastPtr != NULL && fastPtr->next != NULL){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if(fastPtr == slowPtr){
            return true;
        }
    }
    return false;
}

void makeCycle(Node* head, int pos){
    Node *startNode;
    int count = 1;

    while (head->next != NULL)
    {
        if(count == pos){
            startNode = head;
        }

        count++;
        head = head->next;
    }

    head->next = startNode;

    
}

void removeCycle(Node* head){
    Node *fastPtr, *slowPtr;
    slowPtr = fastPtr = head;

    do
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    } while (fastPtr != slowPtr);

    fastPtr = head;
    while (fastPtr->next != slowPtr->next)
    {
        fastPtr = fastPtr->next;
        slowPtr = slowPtr->next;
    }

    slowPtr->next = NULL;
    
    
}


int main(){
    
    Node *head = NULL;

    insertAtTail(2,head);
    insertAtHead(1,head);
    insertAtTail(3,head);
    insertAtHead(0,head);
    insertAtTail(4,head);
    insertAtTail(5,head);
    makeCycle(head, 3);


    cout<<"\n Detecting Cycle = "<<detectCycle(head);

    removeCycle(head);

      cout<<"\n Detecting Cycle = "<<detectCycle(head);
    display(head);




    return 0;

}