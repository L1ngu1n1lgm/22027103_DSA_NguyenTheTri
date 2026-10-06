/*
Bai 3: Nhap vao mot so n, tinh n!
PHAN TICH DO PHUC TAP:
Time: O(N) n lan nhan
Memory: O(1) chi dung 1 bien luu ket qua (de quy thi la O(N) do stack)
*/
#include <iostream>
using namespace std;
 
unsigned long long tinhGiaiThua(int n) {
    unsigned long long ketQua = 1;
    for (int i = 1; i <= n; i++) {
        ketQua *= i;
    }
    return ketQua;
}
 
int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
 
    if (n < 0) {
        cout << "n phai la so tu nhien (n >= 0)" << endl;
        return 0;
    }
    if (n > 20) {
        cout << "Canh bao: n > 20 co the gay tran so (overflow) voi unsigned long long" << endl;
    }
 
    cout << n << "! = " << tinhGiaiThua(n) << endl;
    return 0;
}
 