# <h1 align="center">Laporan Praktikum Modul Abstract Data Type (ADT) (3)</h1>
<p align="center">Muhammad Fathir Al Ghozi</p>

## Dasar Teori
### ADT
Abstract Data Type (ADT) adalah sebuah model konseptual atau blueprint untuk tipe data yang didefinisikan oleh perilakunya (operasi yang bisa dilakukan) dari sudut pandang pengguna, bukan oleh implementasinya (bagaimana operasi itu dijalankan).
Abstraksi (Abstraction): Ini adalah prinsip menyembunyikan detail implementasi yang kompleks dan hanya menunjukkan fungsionalitas yang esensial kepada pengguna. ADT adalah bentuk abstraksi data. Kita fokus pada perilaku objek data tanpa terbebani oleh cara kerjanya di level rendah.
Enkapsulasi (Encapsulation) / Information Hiding: Ini adalah mekanisme untuk membungkus data dan metode (operasi) yang bekerja pada data tersebut menjadi satu unit tunggal. ADT secara teoretis mengenkapsulasi data dan membatasi akses langsung ke dalamnya. Pengguna hanya bisa memanipulasi data melalui operasi yang telah ditentukan secara publik. Hal ini mencegah data dari kerusakan yang tidak disengaja dan menjaga integritasnya.

## Guided 

### 1. mahasiswa.cpp 

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m){
cout << "input nama : ";
cin >> (m).nim;
cout << "input nilai : ";
cin >> (m).nilai1;
cout << "input nilai2 : ";
cin >> (m).nilai2;

}
float rata2(mahasiswa m){
 return float(m.nilai1+m.nilai2)/2;
}
```


### 2. mahasiswa.h

```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;

};

void inputmhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif 
```

### 3. main.cpp

```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main(){
    mahasiswa mhs;
    inputmhs(mhs);
    cout << "rata-rata: " << rata2(mhs);
    return 0;
}
```


## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.


```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> n;
    if (n > 10) n = 10;

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cout << "Nama   : ";
        cin >> mhs[i].nama; 
        cout << "NIM    : ";
        cin >> mhs[i].nim;
        cout << "UTS    : ";
        cin >> mhs[i].uts;
        cout << "UAS    : ";
        cin >> mhs[i].uas;
        cout << "Tugas  : ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }
    
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << mhs[i].nim << "\t" << mhs[i].nama 
             << "\t\t" << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}
```
Kode diatas adalah program yang dapat digunakan untuk menghitung nilai rata rata dari data mahasiswa maks 10, dengan cara perulangan dan array yang menyimpan nim, nama, uts, uas, dan nilai akhir dengan ketentuan 0.3*uts+0.4*uas+0.3*tugas.

#### Output
<img width="533" height="407" alt="image" src="https://github.com/user-attachments/assets/bc16b72b-1963-48a1-bcd1-263b0357c1df" />


#### Full Screenshot
<img width="1919" height="1020" alt="image" src="https://github.com/user-attachments/assets/ecafa166-8b4c-47df-97c0-b094f94ab791" />



### 2. Buat data ADT

### pelajaran.cpp

```C++
#include "pelajaran.h"

pelajaran create_pelajaran(string nama, string kode) {
    pelajaran p;
    p.namaMapel = nama;
    p.kodeMapel = kode;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```
### Full Code ss
<img width="1919" height="1018" alt="image" src="https://github.com/user-attachments/assets/cb1bb38e-7132-4aa7-89a5-0b3ee67e4160" />


### pelajaran.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <iostream>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string nama, string kode);
void tampil_pelajaran(pelajaran pel);

#endif
```
### Full code ss
<img width="1917" height="1020" alt="image" src="https://github.com/user-attachments/assets/54e68dcf-35c5-4018-afa1-83021219a28d" />


### main.cpp
```C++
#include <iostream>
#include <string>

using namespace std;

struct Pelajaran {
    string nama;
    string kode;
};

Pelajaran create_pelajaran(const string& nama, const string& kode) {
    return Pelajaran{nama, kode};
}

void tampil_pelajaran(const Pelajaran& p) {
    cout << "Nama: " << p.nama << "\nKode: " << p.kode << '\n';
}

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    auto pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
Kode diatas adalah program ADT yang memiliki 3 file yang saling ber relasi .

#### Output:
<img width="835" height="163" alt="image" src="https://github.com/user-attachments/assets/a19c2919-91ab-4d66-82c0-6d70c658a5b8" />

#### Full code Screenshot:
<img width="1919" height="1020" alt="image" src="https://github.com/user-attachments/assets/7193da2c-d205-4480-a14f-2fe6d771c1d1" />


### 3. Tukar Array

```C++
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
```
Program bekerja untuk menukar antara array a dan b dengan 2 buah pointer integer. 

#### Output 
<img width="1265" height="554" alt="image" src="https://github.com/user-attachments/assets/9b538e4a-a86c-4d80-9024-28d3f75a118e" />


#### Full Screenshot
<img width="1914" height="1020" alt="image" src="https://github.com/user-attachments/assets/3e448abe-5d26-46a7-a249-a6aed6fdb705" />

##

## Kesimpulan 
Modul 2 ini membahas lanjutan dasar pemrograman C++ yang berfokus pada penggunaan variabel, pointer, dan reference. Pointer diperkenalkan sebagai cara untuk mengakses alamat memori dan memanipulasi isi variabel secara langsung, sementara reference dijelaskan sebagai alternatif yang lebih sederhana dibandingkan pointer, terutama saat digunakan dalam parameter fungsi. Materi ini dilengkapi dengan contoh-contoh program sederhana seperti pertukaran nilai variabel menggunakan pointer maupun reference, sehingga mahasiswa dapat memahami perbedaan dan kegunaannya. Pada bagian akhir, disediakan latihan soal untuk memperkuat pemahaman konsep. Secara keseluruhan, modul ini menekankan pentingnya memahami cara kerja memori di C++ agar mahasiswa mampu menulis program yang lebih efisien dan efektif.

## Referensi
"Introduction to Algorithms, 3rd Edition" (CLRS) oleh Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein.
cppreference.com - Arrays
GeeksforGeeks - Multidimensional Arrays in C/C++
Tutorial C++ - C++ Multi-dimensional Arrays
"Data Structures and Algorithms in Java" oleh Michael T. Goodrich, Roberto Tamassia, and Michael H. Goldwasser.
