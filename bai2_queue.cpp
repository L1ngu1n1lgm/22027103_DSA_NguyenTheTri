/*
Bai 2: Cai dat Queue so nguyen bang List (mang) va Linked List
Queue hoat dong theo FIFO: phan tu vao truoc thi ra truoc
Them vao cuoi (rear), lay ra o dau (front)

PHAN TICH DO PHUC TAP:
1. Queue bang List (mang): dau queue la a[0], cuoi queue la a[n-1]
   isEmpty     : O(1)
   enqueue     : O(1) - ghi vao a[n]
   dequeue     : O(n) - lay a[0] roi dich ca mang sang trai 1 vi tri
   peek/front  : O(1)
   size        : O(1)
   Memory: O(CAPACITY)
   (Cai tien: dung mang vong, chi tang chi so front thay vi dich -> dequeue O(1))

2. Queue bang Linked List: giu ca head (front) va tail (rear)
   isEmpty     : O(1)
   enqueue     : O(1) - chen cuoi nho co tail
   dequeue     : O(1) - xoa node dau
   peek/front  : O(1)
   size        : O(1) - luu bien dem
   Memory: O(n), khong gioi han
*/
#include <iostream>
using namespace std;

const int CAPACITY = 1000;

// ===== 1. QUEUE BANG LIST (MANG) =====
int a[CAPACITY];
int n = 0; // so phan tu trong queue

bool isEmptyArr() { return n == 0; }

int sizeArr() { return n; }

void enqueueArr(int item) {
    if (n >= CAPACITY) {
        cout << "Queue day" << endl;
        return;
    }
    a[n] = item;
    n++;
}

int dequeueArr() {
    if (isEmptyArr()) {
        cout << "Queue rong" << endl;
        return -1;
    }
    int x = a[0];
    for (int i = 0; i < n - 1; i++) a[i] = a[i + 1]; // dich sang trai
    n--;
    return x;
}

int peekArr() {
    if (isEmptyArr()) {
        cout << "Queue rong" << endl;
        return -1;
    }
    return a[0];
}

// ===== 2. QUEUE BANG LINKED LIST =====
struct Node {
    int data;
    Node *next;
};

Node *head = NULL; // front
Node *tail = NULL; // rear
int cnt = 0;

bool isEmptyLL() { return head == NULL; }

int sizeLL() { return cnt; }

void enqueueLL(int item) {
    Node *p = new Node;
    p->data = item;
    p->next = NULL;
    if (tail == NULL) {
        head = tail = p; // queue dang rong
    } else {
        tail->next = p;
        tail = p;
    }
    cnt++;
}

int dequeueLL() {
    if (isEmptyLL()) {
        cout << "Queue rong" << endl;
        return -1;
    }
    Node *p = head;
    int x = p->data;
    head = head->next;
    if (head == NULL) tail = NULL; // queue rong thi tail cung phai NULL
    delete p;
    cnt--;
    return x;
}

int peekLL() {
    if (isEmptyLL()) {
        cout << "Queue rong" << endl;
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
        enqueueArr(x);
        enqueueLL(x);
    }

    cout << "Queue bang List: size = " << sizeArr() << ", front = " << peekArr() << endl;
    cout << "Dequeue lan luot: ";
    while (!isEmptyArr()) cout << dequeueArr() << " ";
    cout << endl;

    cout << "Queue bang Linked List: size = " << sizeLL() << ", front = " << peekLL() << endl;
    cout << "Dequeue lan luot: ";
    while (!isEmptyLL()) cout << dequeueLL() << " ";
    cout << endl;

    return 0;
}
