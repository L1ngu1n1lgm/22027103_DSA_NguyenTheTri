#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
struct Node {
    int key;
    int value;
    Node *next = nullptr;
};
struct hashtable {
    Node *table[10] = {nullptr};
    int hashFunction(int key) {
        return key % 10;
    }
    void insert(int key, int value) {
        int idx = hashFunction(key);
        for (Node *p = table[idx]; p != nullptr; p = p->next) {
            if (p->key == key) {
                p->value = value;
                return;
            }
        }
        Node *q = new Node();
        q->key = key;
        q->value = value;
        q->next = table[idx];
        table[idx] = q;
    }
    int find(int key) {
        int idx = hashFunction(key); 
        for (Node *p = table[idx]; p != nullptr; p = p->next) {
            if (p->key == key) {
                return p->value;
            }
        }
        return -1; 
    }
    void remove(int key) {
        int idx = hashFunction(key);
        Node *p = table[idx];
        Node *pre = nullptr;
        while (p != nullptr && p->key != key) {
            pre = p;
            p = p->next;
        }

        if (p == nullptr) {
            return; 
        }

        if (pre == nullptr) {
            table[idx] = p->next; 
        } else {
            pre->next = p->next;  
        }
        delete p; 
    }
};
int main() 
{
    return 0;
}