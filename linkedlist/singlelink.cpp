#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head = NULL;

// Insert at beginning
void insertfirst(int n){
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertlast(int n){
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at position
void insertpos(int n, int pos){
    Node *newNode = new Node;
    newNode->data = n;

    if(pos == 1){
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        cout<<"Invalid position\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deletefirst(){
    if(head == NULL){
        cout<<"Nothing to delete\n";
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
}

// Delete from end
void deleteEnd(){
    if(head == NULL){
        cout<<"Nothing to delete\n";
        return;
    }

    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    Node *delNode = temp->next;
    temp->next = NULL;
    delete delNode;
}

// Delete from position
void deletepos(int pos){
    if(head == NULL){
        cout<<"Nothing to delete\n";
        return;
    }

    if(pos == 1){
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *temp = head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL){
        cout<<"Invalid position\n";
        return;
    }

    Node *delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

// Traverse
void traverse(){
    Node *temp = head;
    if(temp == NULL){
        cout<<"List is empty\n";
        return;
    }

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Search
void search(int key){
    Node *temp = head;
    int pos = 1;

    while(temp != NULL){
        if(temp->data == key){
            cout<<"Found at position: "<<pos<<endl;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout<<"Element not found\n";
}

// Main
int main(){
    insertfirst(4);
    insertlast(5);
    insertpos(2,1);   // List: 2 4 5

    traverse();

    deletefirst();    // List: 4 5
    traverse();

    deleteEnd();      // List: 4
    traverse();

    insertlast(10);   // List: 4 10
    traverse();

    deletepos(2);     // List: 4
    traverse();

    search(4);
    search(100);

    return 0;
}