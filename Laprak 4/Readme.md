# <h1 align="center">Laporan Praktikum Modul Singly linked list (Bagian pertama) (4)</h1>
<p align="center">Muhammad Fathir Al Ghozi</p>

## Dasar Teori
###
Linked list
Senarai berantai (linked list) adalah salah satu struktur data linear yang fundamental dalam ilmu komputer. Berbeda dengan array yang menyimpan elemen-elemennya dalam blok memori yang berurutan (kontigu), linked list terdiri dari kumpulan elemen data yang disebut simpul (node) yang tersebar di berbagai lokasi memori (Malik, 2021).
###
Linked list (senarai berantai) adalah salah satu struktur data linear dan dinamis yang fundamental dalam ilmu komputer. Berbeda dengan array yang menyimpan elemen-elemennya dalam blok memori yang berurutan (kontigu), linked list terdiri dari kumpulan elemen yang disebut simpul (node) (Cormen et al., 2022).
###


## Guided 1

### 1. list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) { //ganti linkedlist -> linkedList
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama
                 << ", NIM : " << nodeBantu->isidata.nim
                 << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```


### 2. list.h

```C++
//header guard digunakan untuk mencegah file  header yang sama
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur; //tambahkan titik koma
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isi setiap node adaalah data & pointer next
    dataMahasiswa isidata; //disamakan dengan di list.cpp
    address next;
};

struct linkedList { //Ini linked listnya
    address first;
};

//Semua function & prosedur yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev); // ✅ parameter diperbaiki
void insertLast(linkedList &List, address nodeBaru);

#endif
```

### 3. main.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List;
    address nodeA = Nil, nodeB = Nil, nodeC = Nil, nodeD = Nil, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
#### Output
<img width="792" height="211" alt="image" src="https://github.com/user-attachments/assets/a39f9ec8-3368-4d40-86b2-c3b39cbe72b9" />


## Guided 2

### 1. list.cpp

```C++
#include "list.h"

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```


### 2. list.h

```C++
//header guar digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ //node untuk isi dari linked listnya,isi setiap node adalah data & pointer new
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```

### 3. main.cpp

```C++
#include "list.h"

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
#### Output
<img width="806" height="432" alt="image" src="https://github.com/user-attachments/assets/4af7d974-399b-47bb-bb09-2b760f07dab0" />


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
Malik, D. S. (2021). Data structures using C++ (3rd ed.). Cengage Learning.
Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). Introduction to algorithms (4th ed.). MIT Press.
