/*
Bai 6:
PHAN TICH DO PHUC TAP:
Xoa: dich cac phan tu phia sau k len 1 vi tri
Time: best O(1) xoa phan tu cuoi, worst O(N) xoa phan tu dau, average O(N)
Chen: dich cac phan tu tu m tro di sang phai 1 vi tri
Time: best O(1) chen vao cuoi, worst O(N) chen vao dau, average O(N)
Memory: O(1) thao tac ngay tren mang
*/
#include <iostream>
using namespace std;

const int CAPACITY = 1000;

void inMang(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

// n truyen tham chieu de cap nhat so phan tu
void xoaPhanTu(int a[], int &n, int k) {
    if (k < 0 || k >= n) {
        cout << "Vi tri khong hop le" << endl;
        return;
    }
    for (int i = k; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
}

void chenPhanTu(int a[], int &n, int m, int y) {
    if (m < 0 || m > n || n >= CAPACITY) {
        cout << "Vi tri khong hop le hoac mang da day" << endl;
        return;
    }
    // dich tu cuoi ve m de khong de mat du lieu
    for (int i = n; i > m; i--) {
        a[i] = a[i - 1];
    }
    a[m] = y;
    n++;
}

int main() {
    int n;
    cout << "Nhap so phan tu N: ";
    cin >> n;

    int a[CAPACITY];
    cout << "Nhap " << n << " phan tu: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    int k;
    cout << "Nhap vi tri can xoa k: ";
    cin >> k;
    xoaPhanTu(a, n, k);
    cout << "Day sau khi xoa: ";
    inMang(a, n);

    int m, y;
    cout << "Nhap vi tri can chen m: ";
    cin >> m;
    cout << "Nhap gia tri can chen y: ";
    cin >> y;
    chenPhanTu(a, n, m, y);
    cout << "Day sau khi chen: ";
    inMang(a, n);

    return 0;
}