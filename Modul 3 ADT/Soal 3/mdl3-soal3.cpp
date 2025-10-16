#include <iostream>
using namespace std;

void tampil(int arr[3][3], string nama) {
    cout << "Array " << nama << ":\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void tukarArray(int a[3][3], int b[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int temp = a[i][j];
            a[i][j] = b[i][j];
            b[i][j] = temp;
        }
    }
}

void tukarPtr(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int arr1[3][3] = {{3,3,3}, {3,3,3}, {3,3,3}};
    int arr2[3][3] = {{4,4,4}, {4,4,4}, {4,4,4}};
    int a = 100, b = 200;
    int* ptr1 = &a;
    int* ptr2 = &b;

    tampil(arr1, "1");
    tampil(arr2, "2");

    tukarArray(arr1, arr2);
    tampil(arr1, "1");
    tampil(arr2, "2");

    cout << "Sebelum: a=" << a << " b=" << b << endl;
    tukarPtr(ptr1, ptr2);
    cout << "Sesudah: a=" << a << " b=" << b << endl;

    return 0;
}