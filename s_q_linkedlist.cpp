#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
struct linkedlist{
    Node *head=nullptr;
    Node *tail=nullptr;
    int size=0;

void addfirst(int v){
    Node *q=new Node();
    (*q).data=v;
    (*q).next=head;
    head=q;
    size++;
    if(tail==nullptr){
        tail=q;
    }
}
void addlast(int v){
    if(head==nullptr){
        addfirst(v);
    }
    else{
    Node *p=head;
    for(int i=1;i<size;i++){
        p=(*p).next;
    }
    Node *q=new Node();
    (*q).data=v;
    (*q).next=(*p).next;
    (*p).next=q;
    if(p==tail){
        tail=q;
    }
    size++;
    }
}
void insertAfter(int pos,int v){
    if(pos<1||pos>size){
        return;
    }
    Node *p=head;
    for(int i=1;i<pos;i++){
        p=(*p).next;
    }
    Node *q=new Node();
    (*q).data=v;
    (*q).next=(*p).next;
    (*p).next=q;
    size++;
    if(p==tail){
        tail=q;
    }
}
void insertBefore(int pos,int v){
    if(pos<1||pos>size){
        return;
    }
    if(pos == 1){
        addfirst(v);
    }
    else{
        insertAfter(pos-1,v);
    }
}
void removefirst(){
    if(head==nullptr){
        return;
    }
    Node* t=head;
    head=(*head).next;
    delete t;
    size--;
    if(head==nullptr){
        tail=nullptr;
    }
}
void removelast(){
    if(head==nullptr){
        return;
    }
    if(head==tail){
        removefirst();
    }
    else{
        Node*p=head;
        while((*p).next!=tail){
            p=(*p).next;
        }
        delete tail;
        (*p).next=nullptr;
        tail=p;
        size--;
    }
}
void remove(Node *p){
    if(p==nullptr||head==nullptr){
        return;
    }
    if(p==head){
        removefirst();
    }
    else{
        Node *pre=head;
        while(pre !=nullptr && (*pre).next!=p){
            pre=(*pre).next;
        }if(pre==nullptr){
            return;
        }
        (*pre).next=(*p).next;
        if(p==tail){
            tail=pre;
        }
        delete p;
        size--;
    }
}
};
struct stack{
    linkedlist L;
    bool isEmpty(){
        return L.size==0;
    }
    void push(int Item){
        L.addfirst(Item);
    }
    int pop(){
        if(isEmpty()){
            return-1;
        }
        int firstItem=(*L.head).data;
        L.removefirst();
        return firstItem;
    }
    int top(){
        if(isEmpty()){
            return-1;
        }
        return(*L.head).data;
    }
    int size(){
        return L.size;
    }
};
struct queue{
    linkedlist L;
    bool isEmpty(){
        return L.size==0;
    }
    void enqueue(int Item){
        L.addfirst(Item);
    }
    int dequeue(){
        if(isEmpty()){
            return -1;
        }
        int firstItem=(*L.tail).data;
        L.removelast();
        return firstItem;
    }
    int peek(){
        if(isEmpty()){
            return-1;
        }
        return (*L.tail).data;
    }
    int size(){
        return L.size;
    }
};
int main() 
{
    return 0;
}
