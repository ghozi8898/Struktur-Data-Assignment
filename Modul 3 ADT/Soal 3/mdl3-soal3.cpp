#include <iostream>
using namespace std;

// Fungsi untuk menampilkan array 2D 3x3
void tampilkanArray(int arr[3][3], string nama) {
    cout << "Array " << nama << ":\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Fungsi untuk menukar elemen pada posisi tertentu dari dua array 2D
void tukarElemenArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    if(baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3) {
        // Tukar manual tanpa swap
        int temp = arr1[baris][kolom];
        arr1[baris][kolom] = arr2[baris][kolom];
        arr2[baris][kolom] = temp;
        cout << "Berhasil menukar elemen [" << baris << "][" << kolom << "]\n";
    } else {
        cout << "Posisi tidak valid!\n";
    }
}

// Fungsi untuk menukar nilai yang ditunjuk oleh dua pointer
void tukarPointer(int* a, int* b) {
    // Tukar manual tanpa swap
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "Berhasil menukar nilai pointer\n";
}

int main() {
    // Deklarasi dua array 2D 3x3
    int array1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int array2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    
    // Deklarasi dua pointer
    int x = 100, y = 200;
    int* ptr1 = &x;
    int* ptr2 = &y;

    // Menampilkan array awal
    cout << "=== KEADAAN AWAL ===\n";
    tampilkanArray(array1, "Pertama");
    tampilkanArray(array2, "Kedua");

    // Menukar elemen array pada posisi (1,1)
    cout << "=== SETELAH MENUKAR ELEMEN [1][1] ===\n";
    tukarElemenArray(array1, array2, 1, 1);
    tampilkanArray(array1, "Pertama");
    tampilkanArray(array2, "Kedua");

    // Menukar elemen array pada posisi (0,2)
    cout << "=== SETELAH MENUKAR ELEMEN [0][2] ===\n";
    tukarElemenArray(array1, array2, 0, 2);
    tampilkanArray(array1, "Pertama");
    tampilkanArray(array2, "Kedua");

    // Menampilkan nilai pointer sebelum pertukaran
    cout << "=== NILAI POINTER SEBELUM PENUKARAN ===\n";
    cout << "Nilai ptr1 = " << *ptr1 << " (menunjuk ke x = " << x << ")\n";
    cout << "Nilai ptr2 = " << *ptr2 << " (menunjuk ke y = " << y << ")\n\n";

    // Menukar nilai yang ditunjuk pointer
    cout << "=== SETELAH MENUKAR NILAI POINTER ===\n";
    tukarPointer(ptr1, ptr2);

    // Menampilkan nilai pointer setelah pertukaran
    cout << "Nilai ptr1 = " << *ptr1 << " (menunjuk ke x = " << x << ")\n";
    cout << "Nilai ptr2 = " << *ptr2 << " (menunjuk ke y = " << y << ")\n";

    return 0;
}