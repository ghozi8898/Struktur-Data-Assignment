
# <h1 align="center">Laporan Praktikum Modul Doubly Linked List (6)</h1>
<p align="center">Muhammad Fathir Al Ghozi</p>

## Dasar Teori
###
Doubly Linked List pada C++ adalah struktur data linier yang terdiri dari serangkaian node, di mana setiap node memiliki tiga bagian utama: data, pointer ke node berikutnya (next), dan pointer ke node sebelumnya (prev). Berbeda dengan singly linked list, doubly linked list memungkinkan traversing data dua arah, yakni maju dan mundur, sehingga memudahkan operasi penambahan, penghapusan, dan pencarian elemen di tengah-tengah list. Implementasi dalam C++ biasanya menggunakan struct atau class dengan pointer prev dan next, serta operasi dasar seperti insert, delete, dan traversal.

## Guided 

### 1. listmakanan.cpp

```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```


### 2. listmakanan.h

```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```

### 3. main.cpp

```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```
#### Output
<img width="970" height="695" alt="image" src="https://github.com/user-attachments/assets/1f7e948d-0a6c-4fcb-ba38-aba482d41294" />
<img width="589" height="631" alt="image" src="https://github.com/user-attachments/assets/865396e7-97bd-494d-92c4-72032d3cd45d" />
<img width="583" height="559" alt="image" src="https://github.com/user-attachments/assets/49815f26-508c-41e4-a02b-1e43c0cbc057" />

## 
### 1. Doubly linked list Menambahkan, Mencari, dan Menghapus

### Doublylist.cpp

```C++
#include "Doublylist.h"
#include <iostream>

void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.First;
    while (P != nullptr) {
        cout << "no polisi : " << P->info.nopol << "\n";
        cout << "warna     : " << P->info.warna << "\n";
        cout << "tahun     : " << P->info.thnBuat << "\n\n";
        P = P->next;
    }
}

address findElm(List L, string nopol) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol) return P;
        P = P->next;
    }
    return nullptr;
}

void deleteFirst(List &L, address &P) {
    if (L.First == nullptr) {
        P = nullptr;
    } else if (L.First == L.Last) {
        P = L.First;
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        P = L.First;
        L.First = P->next;
        L.First->prev = nullptr;
        P->next = nullptr;
    }
}

void deleteLast(List &L, address &P) {
    if (L.Last == nullptr) {
        P = nullptr;
    } else if (L.First == L.Last) {
        P = L.Last;
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        P = L.Last;
        L.Last = P->prev;
        L.Last->next = nullptr;
        P->prev = nullptr;
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec == nullptr || Prec->next == nullptr) {
        P = nullptr;
        return;
    }
    P = Prec->next;
    Prec->next = P->next;
    if (P->next != nullptr)
        P->next->prev = Prec;
    P->next = nullptr;
    P->prev = nullptr;
}

```

### Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;

struct ElmList {
    infotype info;
    ElmList *next;
    ElmList *prev;
};

typedef ElmList* address;

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address P);

void insertLast(List &L, address P);
void printInfo(List L);

address findElm(List L, string nopol);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif

```

### main.cpp
```C++
#include <iostream>
#include "Doublylist.h"
using namespace std;

bool isValidInput(const infotype &x) {
    return !x.nopol.empty() && !x.warna.empty() && x.thnBuat > 0;
}

int main() {
    List L;
    CreateList(L);

    int countValid = 0;

    while (countValid < 3) {
        infotype x;

        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;

        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;

        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;
        cout << endl;

        if (!isValidInput(x)) {
            cout << "Input tidak valid, ulangi.\n\n";
            continue;   // tidak hitung data
        }

        if (findElm(L, x.nopol) != nullptr) {
            cout << "nomor polisi sudah terdaftar\n\n";
            continue;   // tidak hitung data
        }

        insertLast(L, alokasi(x));
        countValid++;
    }

    cout << "DATA LIST 1\n\n";
    printInfo(L);

    string cari;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> cari;

    address found = findElm(L, cari);

    if (found != nullptr) {
        cout << "\nNomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.thnBuat << endl;
    } else {
        cout << "\nData tidak ditemukan.\n";
    }

    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> cari;

    address target = findElm(L, cari);

    if (target == nullptr) {
        cout << "Data tidak ditemukan.\n";
    } else {
        address P;

        if (target == L.First) {
            deleteFirst(L, P);
        } else if (target == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(target->prev, P);
        }

        dealokasi(P);
        cout << "Data dengan nomor polisi " << cari << " berhasil dihapus.\n\n";
    }

    cout << "DATA LIST 1\n\n";
    printInfo(L);

    return 0;
}

```
#### Output
<img width="885" height="427" alt="image" src="https://github.com/user-attachments/assets/5e9b41cf-b33b-4036-a27c-00dc29c73a1a" />
<img width="325" height="305" alt="image" src="https://github.com/user-attachments/assets/42538596-75a0-45c7-8c99-13aeca02c5de" />
<img width="497" height="405" alt="image" src="https://github.com/user-attachments/assets/96cce4a5-2e5e-44fd-ba66-127ce789d234" />

#### Full Screenshot
<img width="1919" height="1020" alt="image" src="https://github.com/user-attachments/assets/3671ccc6-b9ab-4aa4-aa35-0c38c4970c75" />

###
#### Penjelasan

Program ini menggunakan ADT Doubly Linked List yang terdiri dari `infotype` (data kendaraan), node `ElmList` dengan pointer `next` dan `prev`, serta `List` yang menyimpan pointer `First` dan `Last`. Fungsi dasar seperti `CreateList`, `alokasi`, `dealokasi`, `insertLast`, `printInfo`, `findElm`, dan operasi penghapusan (deleteFirst/Last/After) mengelola struktur list, menambahkan node baru, mencari elemen berdasarkan nomor polisi, serta menjaga konsistensi pointer agar list tetap tersambung dengan benar.

Pada `main.cpp`, program melakukan **empat percobaan input**, bukan empat data valid. Setiap percobaan meminta nomor polisi, warna, dan tahun; setelah ketiga data diisi, barulah dicek apakah nomor polisi sudah ada. Jika duplikat, program hanya menampilkan pesan dan melanjutkan ke percobaan berikutnya tanpa memasukkan node baru. Hasilnya, jumlah data dalam list adalah jumlah input unik (contoh soal: D001, D003, D001(duplikat), D004 → hanya tiga data). Setelah empat percobaan selesai, list langsung ditampilkan menggunakan `printInfo`.


###
## Kesimpulan 
Doubly linked list di C++ adalah struktur data yang fleksibel dan efektif untuk pengelolaan data secara berurutan dengan kemampuannya untuk memanage dua arah, keunggulan signifikan dalam operasi penyisipan dan penghapusan dibandingkan singly linked list. Implementasi doubly linked list membutuhkan manajemen pointer yang cermat untuk menghindari kebocoran memori dan kesalahan akses.

## Referensi[
###
https://www.simplilearn.com/tutorials/data-structure-tutorial/types-of-linked-list
###
https://www.educative.io/answers/what-is-a-linked-list
###
https://www.teachmesoft.com/2019/03/double-link-list-c-disertai-contoh.html
