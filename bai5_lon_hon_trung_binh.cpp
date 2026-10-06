/*
Bai 5: Nhap vao mot day so thuc co do dai N. In ra tat ca nhung gia tri lon hon hoac bang gia tri trung binh cua day.
PHAN TICH DO PHUC TAP:
Time: O(N) duyet 2 lan (tinh tong, roi in), 2N van la O(N)
Memory: O(N) phai luu day de duyet lan 2
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap so phan tu N: ";
    cin >> n;

    double* a = new double[n];
    cout << "Nhap " << n << " so thuc: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    // tinh trung binh
    double tong = 0;
    for (int i = 0; i < n; i++) tong += a[i];
    double trungBinh = tong / n;

    // in cac gia tri >= trung binh
    cout << "Trung binh = " << trungBinh << endl;
    cout << "Cac gia tri >= trung binh: ";
    for (int i = 0; i < n; i++) {
        if (a[i] >= trungBinh) cout << a[i] << " ";
    }
    cout << endl;

    delete[] a;
    return 0;
}