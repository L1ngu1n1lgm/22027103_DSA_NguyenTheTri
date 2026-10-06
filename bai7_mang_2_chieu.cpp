/*
Bai 7:
PHAN TICH DO PHUC TAP:
Tong: Time O(N*M) doc het N*M phan tu, Memory O(1)
Xoa dong: dung mang con tro nen chi dich con tro cua cac dong, khong dich du lieu
Time: best O(1) xoa dong cuoi, worst O(N) xoa dong dau, average O(N)
Memory: O(1)
*/
#include <iostream>
using namespace std;

int** taoMang2Chieu(int n, int m) {
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    return matrix;
}

void giaiPhongMang2Chieu(int** matrix, int n) {
    for (int i = 0; i < n; i++) delete[] matrix[i];
    delete[] matrix;
}

void nhapMang(int** matrix, int n, int m) {
    cout << "Nhap tung phan tu cua mang " << n << "x" << m << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
}

void inMang(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }
}

long long tongMang(int** matrix, int n, int m) {
    long long tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tong += matrix[i][j];
        }
    }
    return tong;
}

// n truyen tham chieu de cap nhat so dong
void xoaDong(int** &matrix, int &n, int i) {
    if (i < 0 || i >= n) {
        cout << "Vi tri dong khong hop le" << endl;
        return;
    }
    delete[] matrix[i];

    // dich con tro cac dong phia sau len 1
    for (int k = i; k < n - 1; k++) {
        matrix[k] = matrix[k + 1];
    }
    n--;
}

int main() {
    int n, m;
    cout << "Nhap so dong N: ";
    cin >> n;
    cout << "Nhap so cot M: ";
    cin >> m;

    int** matrix = taoMang2Chieu(n, m);
    nhapMang(matrix, n, m);

    cout << "Tong cac phan tu: " << tongMang(matrix, n, m) << endl;

    int i;
    cout << "Nhap dong can xoa (i): ";
    cin >> i;
    xoaDong(matrix, n, i);

    cout << "Mang sau khi xoa dong " << i << ":\n";
    inMang(matrix, n, m);

    giaiPhongMang2Chieu(matrix, n);
    return 0;
}