#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int value){
        data = value;
        prev = NULL;
        next = NULL;
    }
};

struct DoubleLL
{
    Node* head;
    DoubleLL(){
        head = NULL;
    }
    void insertend(int n){
        Node* t = new Node(n);
        if(head == NULL){
            head = t;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = t;
        t->prev = temp;
    }
    void insertpos(int n,int p){
        Node* t = new Node(n);
        if(p == 1){
            return;
        }
        Node* temp = head;
        for(int i=1;i<p-1 && temp!=NULL,i++){
            temp = temp->next;
            if
        }
    }
};
