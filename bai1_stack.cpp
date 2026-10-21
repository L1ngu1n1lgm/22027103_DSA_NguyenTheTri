/*
Bai 1: Cai dat Stack so nguyen bang List (mang) va Linked List
Stack hoat dong theo LIFO: phan tu vao sau thi ra truoc

PHAN TICH DO PHUC TAP:
1. Stack bang List (mang): dinh stack la cuoi mang a[n-1]
   isEmpty : O(1)
   push    : O(1) - ghi vao a[n], khong phai dich phan tu
   pop     : O(1) - chi giam n
   top     : O(1)
   size    : O(1)
   Memory: O(CAPACITY), bi gioi han so phan tu toi da

2. Stack bang Linked List: dinh stack la head
   isEmpty : O(1)
   push    : O(1) - chen vao dau danh sach
   pop     : O(1) - xoa node dau danh sach
   top     : O(1)
   size    : O(1) - luu bien dem n
   Memory: O(n), khong gioi han, moi node ton them 1 con tro next
*/
#include <iostream>
using namespace std;

const int CAPACITY = 1000;

// ===== 1. STACK BANG LIST (MANG) =====
int a[CAPACITY];
int n = 0; // so phan tu trong stack

bool isEmptyArr() { return n == 0; }

int sizeArr() { return n; }

void pushArr(int item) {
    if (n >= CAPACITY) {
        cout << "Stack day" << endl;
        return;
    }
    a[n] = item;
    n++;
}

int popArr() {
    if (isEmptyArr()) {
        cout << "Stack rong" << endl;
        return -1;
    }
    n--;
    return a[n];
}

int topArr() {
    if (isEmptyArr()) {
        cout << "Stack rong" << endl;
        return -1;
    }
    return a[n - 1];
}

// ===== 2. STACK BANG LINKED LIST =====
struct Node {
    int data;
    Node *next;
};

Node *head = NULL;
int cnt = 0; // so phan tu trong stack

bool isEmptyLL() { return head == NULL; }

int sizeLL() { return cnt; }

void pushLL(int item) {
    Node *p = new Node;
    p->data = item;
    p->next = head; // node moi tro vao dinh cu
    head = p;       // node moi thanh dinh
    cnt++;
}

int popLL() {
    if (isEmptyLL()) {
        cout << "Stack rong" << endl;
        return -1;
    }
    Node *p = head;
    int x = p->data;
    head = head->next;
    delete p;
    cnt--;
    return x;
}

int topLL() {
    if (isEmptyLL()) {
        cout << "Stack rong" << endl;
        return -1;
    }
    return head->data;
}

int main() {
    int N;
    cout << "Nhap so phan tu N: ";
    cin >> N;
    cout << "Nhap " << N << " phan tu: ";
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        pushArr(x);
        pushLL(x);
    }

    cout << "Stack bang List: size = " << sizeArr() << ", top = " << topArr() << endl;
    cout << "Pop lan luot: ";
    while (!isEmptyArr()) cout << popArr() << " ";
    cout << endl;

    cout << "Stack bang Linked List: size = " << sizeLL() << ", top = " << topLL() << endl;
    cout << "Pop lan luot: ";
    while (!isEmptyLL()) cout << popLL() << " ";
    cout << endl;

    return 0;
}
