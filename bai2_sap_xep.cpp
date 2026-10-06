/*
Bai 2: Nhap vao mot day gom N phan tu, viet ham sap xep day theo thu tu tang dan (ham kieu void).
PHAN TICH DO PHUC TAP:
Time: best O(N) day da sap xep, worst O(N^2) day nguoc, average O(N^2)
Memory: O(1) sap xep ngay tren mang, khong tao mang moi
*/
#include <iostream>
using namespace std;
 
void sapXepTangDan(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool daDoiCho = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                daDoiCho = true;
            }
        }
        // khong doi cho lan nao thi day da sap xep xong
        if (!daDoiCho) break;
    }
}
 
void inMang(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}
 
int main() {
    int n;
    cout << "Nhap so phan tu N: ";
    cin >> n;
 
    int* a = new int[n];
    cout << "Nhap " << n << " phan tu: ";
    for (int i = 0; i < n; i++) cin >> a[i];
 
    sapXepTangDan(a, n);
 
    cout << "Day sau khi sap xep tang dan: ";
    inMang(a, n);
 
    delete[] a;
    return 0;
}
 