#include <iostream>
using namespace std;
struct Entry{
    int key;
    int value;
    bool used=false;
};
struct hashtable{
    Entry table[10];
    int hashFuction(int key){
        return key % 10;
    }
    void insert(int key;int value){
        int idx = hashFuction(key);
        while (table[idx].used && table[idx].key!=key){
            idx = (idx + 1) % 10;
        }
        table[idx].key = key;
        table[idx].value = value;
        table[idx].used = true;
    }
    int find(int key){
        int idx = hashFuction(key);
        for(int i=0;i<10;i++){
            int curr=(idx + i) % 10;
            if(table[curr].used && table[curr].key == key){
                return table[curr].value;
            }
        }
        return -1;
    }
    void remove(int key){
        int idx = hashFuction(key);
        for(int i=0;i<10;i++){
            int curr = (idx + i) % 10;
            if(table[curr].used && table[curr].key == key){
                table[curr].used=false;
                return;
            }
        }
    }
};
int main() 
{

    return 0;
}