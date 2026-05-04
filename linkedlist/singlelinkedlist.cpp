#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head = NULL;
void insertFirst(int n){
    Node *newNode = new Node;
    newNode -> data = n;
    newNode -> next = head;
    head = newNode;
}
void insertEnd(int n){
    Node *newNode = new Node;
    newNode -> data = n;
    newNode -> next = NULL;
    if(head == NULL){
        head = newNode;
        return;
    }
    Node *temp  = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;

}
void insertPos(int n,int pos){
    Node *newNode = new Node;
    newNode -> data = n;
    Node *temp  = head;
    if(pos == 1){
        newNode -> next = head;
        head = newNode;
        return;
    }
    for(int i = 1;i<pos-1 && temp!=NULL;i++){
        temp = temp -> next;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
}
void deleteFirst(){
    if(head == NULL){
        cout<<"there is nothing to delete";
        return;
    }
    Node *temp = head;
    head = head -> next;
    delete temp;
    return;

}
void deleteEnd(){
    if(head == NULL){
        cout<<"there is nothing to delete";
        return;
    }
    if(head -> next == NULL){
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    delete temp -> next;
    temp -> next = NULL;
}
void deletePos(int pos){
    if(head == NULL){
        cout<<"there is nothing to delete";
        return;
    }
    if(head -> next == NULL){
        delete head;
        head = NULL;
        return;
    }
}
void display(){
    Node *temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }

}
int main(){
    insertFirst(1);
    insertFirst(3);
    insertEnd(5);
    insertPos(6,1);
    deleteFirst();
    deleteEnd();
    display();
}
