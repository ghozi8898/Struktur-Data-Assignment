# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Arvinanto Bahtiar</p>

## Dasar Teori

Modul ini membahas tentang Beberapa fungsi penting dalam bahasa pemograman C++ 

## Array
Array merupakan kumpulan data dengan nama yang sama dan setiap elemen bertipe data sama.
Untuk mengakses setiap komponen / elemen array berdasarkan indeks dari setiap elemen.

## Pointer
Variabel pointer merupakan dasar tipe variabel yang berisi integer dalam format heksadesimal. Pointer
digunakan untuk menyimpan alamat memori variabel lain sehingga pointer dapat mengakses nilai dari
variabel yang alamatnya ditunjuk.

## Prosedur
Dalam bahasa pemrograman C++, prosedur adalah istilah yang sering digunakan untuk merujuk pada
fungsi yang tidak mengembalikan nilai. Dalam istilah C++, prosedur ini dikenal sebagai fungsi void.
Fungsi-fungsi ini melakukan tugas tertentu tetapi tidak memberikan nilai balik (return value) kepada
pemanggilnya. Sebaliknya, fungsi yang mengembalikan nilai, seperti int atau double, memberikan
hasil yang dapat digunakan lebih lanjut dalam program.



## Guided 

### 1. [Array]

```C++
#include <iostream>
using namespace std;

int main() {
    // --- Array 1 Dimensi ---
    int arr[5] = {10, 20, 30, 40, 50};
    cout << "Array 1 Dimensi:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Element ke-" << i << ": " << arr[i] << endl;
    }
    cout << endl;

    // --- Array 2 Dimensi ---
    int arr2D[2][3] = {
        {1, 2, 3},
        {4, 5, 6},
    };
    cout << "Array 2 Dimensi:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "arr2D[" << i << "][" << j << "]: " << arr2D[i][j]
            << " ";
        }
        cout << endl;
    }
    // --- Array Multi Dimensi (3D) ---
    int arr3D[2][2][3] = {
        { {1, 2, 3}, {4, 5, 6} },
        { {7, 8, 9}, {10, 11, 12} },
    };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                cout << "arr3D[" << i << "][" << j << "]["
                << k << "]: " << arr3D[i][j][k] << endl;
            }
        }
    }

    return 0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 1. [Pointer]

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

main () {
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value a : " << a << endl;
    cout << "Address a : " << &a << endl;
    cout << "Value stored in otr (address of a) : " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;


tukar(&a, &b);
cout << "After swapping, value of a : " << a << " and b=" << b << endl;

return 0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.


## Unguided 

### 1. [Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3]

```C++
#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3], C[3][3];
    int i, j, k;

    cout << "Masukkan elemen matriks A (3x3):\n";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Masukkan elemen matriks B (3x3):\n";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            cin >> B[i][j];
        }
    }

    cout << "\nPenjumlahan :\n";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nPengurangan :\n";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nPerkalian :\n";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            C[i][j] = 0;
            for(k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

```
#### Output:
<img width="1600" height="690" alt="image" src="https://github.com/user-attachments/assets/8f5c3799-6338-4771-ac47-a9df9faafd20" />


#### Full code Screenshot:
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/d6a6325d-2673-4baf-bab7-2b25af1df451" />



## Kesimpulan 
Modul 2 ini membahas lanjutan dasar pemrograman C++ yang berfokus pada penggunaan variabel, pointer, dan reference. Pointer diperkenalkan sebagai cara untuk mengakses alamat memori dan memanipulasi isi variabel secara langsung, sementara reference dijelaskan sebagai alternatif yang lebih sederhana dibandingkan pointer, terutama saat digunakan dalam parameter fungsi. Materi ini dilengkapi dengan contoh-contoh program sederhana seperti pertukaran nilai variabel menggunakan pointer maupun reference, sehingga mahasiswa dapat memahami perbedaan dan kegunaannya. Pada bagian akhir, disediakan latihan soal untuk memperkuat pemahaman konsep. Secara keseluruhan, modul ini menekankan pentingnya memahami cara kerja memori di C++ agar mahasiswa mampu menulis program yang lebih efisien dan efektif.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
