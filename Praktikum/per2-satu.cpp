#include <iostream>
using namespace std;

int main() {
    float a, b;
    cout << "Masukkan dua bilangan float: ";
    cin >> a >> b;
    cout << "Penjumlahan: " << a + b << endl;
    cout << "Pengurangan: " << a - b << endl;
    cout << "Perkalian: " << a * b << endl;
    if (b != 0)
        cout << "Pembagian: " << a / b << endl;
    else
        cout << "Pembagian: tidak dapat dilakukan (pembagi nol)" << endl;
    return 0;
}