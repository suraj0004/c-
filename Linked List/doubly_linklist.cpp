#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node *prev, *next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node* node = new Node(data);
    if(head != NULL){
        node->next = head;
        head->prev = node;
    }
    head = node;
}

void insertAtTail(Node* &head, int data){
    if(head == NULL){
       insertAtHead(head,data);
       return;
    }
    Node* node = new Node(data);
    Node* temp = head;
    while (temp->next !=NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
}

void display(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void deleteFirstNode(Node* &head){
     if(head == NULL || head->prev != NULL){
        return;
    }
    Node* toDelete = head;
    head = head->next;
    if(head != NULL){
        head->prev = NULL;
    }
    delete toDelete;
}



void deleteByValue(Node* &head, int data){
    
    if(head == NULL){
        return;
    }

    Node *toDelete, *temp = head;

    while (temp != NULL )
    {
        if(temp->data == data){

            toDelete =  temp;

            if(temp->prev == NULL){
                deleteFirstNode(head);
                return;
            }

            temp->prev->next = temp->next;
            if(temp->next != NULL){
                temp->next->prev = temp->prev;
            }

            delete toDelete;
            break;
        }
        temp = temp->next;
    } 
    
}

void deleteByPos(Node* &head, int pos){
    if(head == NULL){
        return;
    }

    Node *toDelete, *temp = head;
    int count = 1;

    while (temp != NULL )
    {
        if(count == pos){

            toDelete =  temp;

            if(temp->prev == NULL){
                deleteFirstNode(head);
                return;
            }

            temp->prev->next = temp->next;
            if(temp->next != NULL){
                temp->next->prev = temp->prev;
            }

            delete toDelete;
            break;
        }
        temp = temp->next;
        count++;
    }
}

int main(){

    Node* head = NULL;

    insertAtHead(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtHead(head, 0);
    display(head);

    deleteByValue(head, 3);
    deleteByValue(head, 0);
    deleteByValue(head, 5);
    deleteByValue(head, 1);
    deleteByValue(head, 4);
    deleteByValue(head, 2);
    deleteByValue(head, 4);
    display(head);


    insertAtHead(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    display(head);

    deleteByPos(head, 3);
    deleteByPos(head, 1);
    deleteByPos(head, 3);
    deleteByPos(head, 1);
    deleteByPos(head, 1);
    deleteByPos(head, 1);
    display(head);

    return 0;
}