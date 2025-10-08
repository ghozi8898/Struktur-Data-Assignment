#include <iostream>
using namespace std;

void tukar3(int &x, int &y, int &z) {
    int temp = x;  
    x = y;         
    y = z;          
    z = temp;      
}

int main() {
    int a = 20, b = 30, c = 40;
    int& ref = a; 

    cout << "Sebelum ditukar:" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "Alamat a (&a) : " << &a << endl;
    cout << "Alamat ref (&ref): " << &ref << endl;

    ref = 50;
    cout << "\nSetelah ref = 50:" << endl;
    cout << "a = " << a << ", ref = " << ref << endl;

    tukar3(a, b, c);

    cout << "\nSetelah tukar3 dipanggil:" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}
