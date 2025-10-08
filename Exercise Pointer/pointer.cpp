#include <iostream>
using namespace std;

// Fungsi untuk menukar 3 variabel
void tukar3(int *x, int *y, int *z) {
    int temp = *x;   // simpan nilai x
    *x = *y;         // x = y
    *y = *z;         // y = z
    *z = temp;       // z = nilai awal x
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "Sebelum ditukar:\n";
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    tukar3(&a, &b, &c);

    cout << "\nSetelah ditukar:\n";
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}
