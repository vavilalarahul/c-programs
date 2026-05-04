#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};
Node *head = NULL;
void inserfirst(int n){
    Node *newNode = new Node;
    newNode -> data = n;
    newNode -> next = head;
    newNode -> prev = NULL;
    if(head != NULL){
        head->prev = newNode;   // 🔥 IMPORTANT LINE
    }
    head = newNode;
}
void insertend(int n){
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;

    // 🔥 Empty list
    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node *temp = head;

    // Go to last node
    while(temp->next != NULL){
        temp = temp->next;
    }

    // 🔥 Connect both sides
    temp->next = newNode;
    newNode->prev = temp;
}
void insertpos(int n, int pos){
    Node *newNode = new Node;
    newNode->data = n;

    // Insert at beginning
    if(pos == 1){
        newNode->prev = NULL;
        newNode->next = head;

        if(head != NULL){
            head->prev = newNode;   // 🔥 important
        }

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
    newNode->prev = temp;

    if(temp->next != NULL){
        temp->next->prev = newNode;   // 🔥 important
    }

    temp->next = newNode;
}
void deletefirst(){
    if(head == NULL){
        cout<<"Nothing to delete\n";
        return;
    }

    Node *temp = head;

    // Only one node
    if(head->next == NULL){
        head = NULL;
        delete temp;
        return;
    }

    head = head->next;
    head->prev = NULL;   // 🔥 correct assignment

    delete temp;
}
void deleteend(){
    if(head == NULL){
        cout<<"Nothing to delete\n";
        return;
    }

    // Only one node
    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;

    // Go to last node
    while(temp->next != NULL){
        temp = temp->next;
    }

    // 🔥 Use prev pointer
    temp->prev->next = NULL;

    delete temp;
}
void deletepos(int pos){
    if(head == NULL){
        cout<<"Nothing to delete\n";
        return;
    }

    // 🔥 delete first node
    if(pos == 1){
        Node *temp = head;

        if(head->next == NULL){
            head = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }

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

    Node *del = temp->next;

    temp->next = del->next;   // 🔥 forward link

    if(del->next != NULL){
        del->next->prev = temp;   // 🔥 backward link
    }

    delete del;
}
void traverseback(){
    if(head == NULL){
        cout<<"List is empty\n";
        return;
    }

    Node *temp = head;

    // Go to last node
    while(temp->next != NULL){
        temp = temp->next;
    }

    // Traverse backward
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->prev;
    }
} 