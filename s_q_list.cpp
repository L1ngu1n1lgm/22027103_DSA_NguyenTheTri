//vibe code ac hon nua, thuan toolbox

#include <iostream>
using namespace std;
const int max=1000;
struct list{
    int data[max];
    int size=0;

    bool Empty(){
        return size==0;
    }
    bool Full(){
        return size==max;
    } 
    void addFirst(int v){
        if(Full()){
            return;
        }
        for(int i=size;i>0;i--){
            data[i]=data[i-1];
        }
        data[0]=v;
        size++;
    }
    void addLast(int v){
        if(Full()){
            return;
        }
        data[size]=v;
        size++;
    }
    void insertAfter(int pos, int v){
        if(Full()){
            return;
        }
        if(pos<1||pos>size){
            return;
        }
        for(int i=size;i>pos;i--){
            data[i]=data[i-1];
        }
        data[pos]=v;
        size++;
    }
    void insertBefore(int pos, int v){
        if(Full()){
            return;
        }
        if(pos<1||pos>size){
            return;
        }
        if(pos==1){
            addFirst(v);
        }
        else{
            insertAfter(pos-1,v);
        }
    }
    void deleteFirst(){
        if(Empty()){
            return;
        }
        for(int i=0;i<size-1;i++){
            data[i]=data[i+1];
        }
        size--;
    }
    void deleteLast(){
        if(Empty()){
            return;
        }
        size--;
    }
    void deleteAt(int pos){
        if(Empty()){
            return;
        }
        if(pos<1||pos>size){
            return;
        }
        for(int i=pos-1;i<size-1;i++){
            data[i]=data[i+1];
        }
        size--;
    }
};
struct Stack {
    list L;
    bool isEmpty(){
        return L.Empty();
    }
    void push(int Item){
        L.addLast(Item);
    }
    int pop(){
        if(isEmpty()){
            return-1;
        }
        int lastItem=L.data[L.size-1];
        L.deleteLast();
        return lastItem;
    }
    int size(){
        return L.size;
    }
    int top(){
       if(isEmpty()){
            return-1;
        }
        return L.data[L.size-1]; 
    }
};
struct Queue {
    list L;
    bool isEmpty(){
        return L.Empty();
    }
    void enqueue(int Item){
        L.addLast(Item);
    }
    int dequeue(){
        if(isEmpty()){
            return-1;
        }
        int firstItem=L.data[0];
        L.deleteFirst();
        return firstItem;
        
    }
    int peek(){
        if(isEmpty()){
            return-1;
        }
        return L.data[0];
    }
    int size(){
        return L.size;
    }
};
int main() 
{
   
    return 0;
}
