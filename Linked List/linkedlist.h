/*
 * User defined header file for linked list.
 * How to use: Just include this header file in your cpp program and create obj of class "Linkedlist".
 * Example: Check the "custom_linkedlist.cpp" file.
*/

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

class Linkedlist {
    private:
        Node *head;
    public:
   
        Linkedlist(){
            this->head = NULL;
        }

        void insertAtTail(int data){

            Node *node = new Node(data);

            if(this->head == NULL){
                this->head = node;
                return;
            }

            Node* tmp = this->head;
            while (tmp->next != NULL){
                tmp = tmp->next;
            }

            tmp->next = node;
                
        }

        void insertAtHead(int data){
            Node* node = new Node(data);
            node->next = this->head;
            this->head = node;
        }

        void display(){

            Node *tmp = this->head;
            while(tmp != NULL){
                cout<<tmp->data<<" ";
                tmp = tmp->next;
            }
            cout<<endl;
        }

        bool search (int data){
            Node *tmp = this->head;
            while (tmp != NULL)
            {
                if(data == tmp->data)
                    return true;
                tmp = tmp->next;
            }
            return false;
        }


        void deleteNode(int data){

            if(this->head == NULL){
                return;
            }

            Node* toDelete;
            if(this->head->data == data){
                toDelete = this->head;
                this->head = this->head->next;
                delete toDelete;
                return;
            }

            Node* tmp = this->head;
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
};
