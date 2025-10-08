#include <iostream>
using namespace std;

void tukar3(int *x, int *y, int *z) {
    int temp = *x;    
    *x = *y;          
    *y = *z;          
    *z = temp;       
}

int main () {
    int a = 20, b = 30, c = 40;
    int *ptr;

    ptr = &a;

    cout << "Sebelum ditukar:" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    cout << "\nValue a : " << a << endl;
    cout << "Address a : " << &a << endl;
    cout << "Value stored in ptr (address of a) : " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    tukar3(&a, &b, &c);

    cout << "\nSetelah ditukar:" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}
