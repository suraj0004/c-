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

Node* reverseByItration(Node* head){
   Node *prev, *curr, *next;
   prev = NULL;
       
   curr = head;

   while (curr != NULL)
   {
       next = curr->next;
       curr->next = prev;
       prev = curr;
       curr = next;
   }

   return prev;
   
}

Node* reverseByRecursion(Node* head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* newhead = reverseByRecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}


Node* reverseK(Node* &head, int k){
    Node *prev, *curr, *next;
    prev = NULL;
    curr = head;

    int count =1;
    while(curr != NULL && count <= k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL){
        head->next = reverseK(next, k);
    }

    return prev;
}
int main(){
    
    Node *head = NULL;

    insertAtTail(2,head);
    insertAtHead(1,head);
    insertAtTail(3,head);
    insertAtHead(0,head);
    insertAtTail(4,head);
    insertAtTail(5,head);


    // deleteNode(7,head);

    display(head);
    
    // head = reverseByItration(head);

    // display(head);

    // head = reverseByRecursion(head);

    // display(head);


    head = reverseK(head,2);

    display(head);




    return 0;

}