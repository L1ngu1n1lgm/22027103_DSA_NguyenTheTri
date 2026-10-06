/*
Bai 4: Nhap vao hai so a, b, viet ham rut gon phan so a/b (ham kieu void).
PHAN TICH DO PHUC TAP:
Time: O(log(min(a,b))) tim UCLN bang thuat toan Euclid
Memory: O(1) dung vong lap
*/
#include <iostream>
using namespace std;
 
int ucln(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
 
void rutGonPhanSo(int a, int b) {
    if (b == 0) {
        cout << "Mau so khong the bang 0" << endl;
        return;
    }
    int d = ucln(abs(a), abs(b));
    if (d != 0) {
        a /= d;
        b /= d;
    }
    // mau so luon duong
    if (b < 0) {
        a = -a;
        b = -b;
    }
    cout << "Phan so rut gon: " << a << "/" << b << endl;
}
 
int main() {
    int a, b;
    cout << "Nhap tu so a: ";
    cin >> a;
    cout << "Nhap mau so b: ";
    cin >> b;
 
    rutGonPhanSo(a, b);
    return 0;
}
 