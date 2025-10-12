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
Kode diatas adalah program yang dapat menjumlahkan, mengurangkan, dan mengalikan dua buah Matriks 3x3, dengan perulangan.

#### Output
<img width="1424" height="592" alt="image" src="https://github.com/user-attachments/assets/94f5953a-154f-4a50-b5f6-d5a0a8a91b2f" />

#### Full Screenshot
<img width="1919" height="1017" alt="image" src="https://github.com/user-attachments/assets/a947e717-f639-4931-8141-d3f1ff376506" />


### 2.  [Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel]

## Pointer

```C++
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

```
Kode diatas adalah program dari pointer sebelumnya pada guided dan dimodifikasi agar bisa menukar dengan 3 variabel yang sebelumnya menggunakan 2 variabel.

#### Output:
<img width="1332" height="390" alt="image" src="https://github.com/user-attachments/assets/557e2c50-6833-433d-8278-45724036eee8" />


#### Full code Screenshot:
<img width="1919" height="1020" alt="image" src="https://github.com/user-attachments/assets/0dd8f45c-1a97-447a-aca1-893cfc125d71" />


## Reference
```C++
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
```
Sama dengan code sebelumnya memodifikasi dari codingan Guided sebelumnya agar bisa menukar nilai dari 3 variabel

#### Output
<img width="1425" height="317" alt="image" src="https://github.com/user-attachments/assets/19477cbc-d319-4d66-ada1-1d319b85c88c" />

#### Full screenshot
<img width="1919" height="1015" alt="image" src="https://github.com/user-attachments/assets/b2ceab4a-5be0-43d8-b13f-f82b04de565a" />




### 3. [Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3]

```C++
#include <iostream>
using namespace std;

int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int cariMaksimum(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks) {
            maks = arr[i];
        }
    }
    return maks;
}

float hitungRataRata(int arr[], int n) {
    int jumlah = 0;
    for (int i = 0; i < n; i++) {
        jumlah += arr[i];
    }
    return (float)jumlah / n; 
}

int main() {
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = 10;
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata - rata\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
             case 1:
                cout << "ARRAY = {";
                for (int i = 0; i < n; i++) {
                    cout << arrA[i];
                    if (i < n - 1) cout << ", ";
                }
                cout << "}" << endl;
                break;
            case 2:
                cout << "Nilai maksimum: " << cariMaksimum(arrA, n) << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << cariMinimum(arrA, n) << endl;
                break;
            case 4:
                cout << "Nilai rata-rata: " << hitungRataRata(arrA, n) << endl;
                break;
            default:
                cout << "-";
        }
    } while (pilihan != 5);

    return 0;
}

```
Kode diatas adalah program aplikasi yang bisa memilih antara ke empat opsi yaitu menampilkan isi array, mencari nilai maksimum dan minimum, juga menghitung nilai rata-rata dari matriks yang ada pada soal yaitu {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}.

#### Output 
<img width="1431" height="785" alt="image" src="https://github.com/user-attachments/assets/a25facc0-0aaf-42f4-a331-b76a68b3431a" />

#### Full Screenshot
<img width="1919" height="1019" alt="image" src="https://github.com/user-attachments/assets/9124b734-b661-47d5-9403-d5ba2e5c3c8b" />

##

## Kesimpulan 
Modul 2 ini membahas lanjutan dasar pemrograman C++ yang berfokus pada penggunaan variabel, pointer, dan reference. Pointer diperkenalkan sebagai cara untuk mengakses alamat memori dan memanipulasi isi variabel secara langsung, sementara reference dijelaskan sebagai alternatif yang lebih sederhana dibandingkan pointer, terutama saat digunakan dalam parameter fungsi. Materi ini dilengkapi dengan contoh-contoh program sederhana seperti pertukaran nilai variabel menggunakan pointer maupun reference, sehingga mahasiswa dapat memahami perbedaan dan kegunaannya. Pada bagian akhir, disediakan latihan soal untuk memperkuat pemahaman konsep. Secara keseluruhan, modul ini menekankan pentingnya memahami cara kerja memori di C++ agar mahasiswa mampu menulis program yang lebih efisien dan efektif.

## Referensi
-
