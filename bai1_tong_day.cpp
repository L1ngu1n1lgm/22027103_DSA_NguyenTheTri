/*
Bai 1: Nhap vao mot day gom N phan tu, tinh tong cac phan tu trong day.
PHAN TICH DO PHUC TAP:
Time: O(N) doc N phan tu: O(N)
Memory: O(N) can luu mang de chua N phan tu nhap vao
 */
#include <iostream>
using namespace std;

int tongDay(int a[], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i];
    }
    return tong;
}

int main() {
    int n;
    cout << "Nhap so phan tu N: ";
    cin >> n;

    int* a = new int[n];
    cout << "Nhap " << n << " phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Tong cac phan tu: " << tongDay(a, n) << endl;

    delete[] a;
    return 0;
}