
# <h1 align="center">Laporan Praktikum Modul Stack (7)</h1>
<p align="center">Muhammad Fathir Al Ghozi</p>

## Dasar Teori
###
Stack pada pemrograman C++ adalah konsep struktur data linier yang mengikuti prinsip LIFO (Last In First Out), di mana elemen terakhir yang dimasukkan ke dalam stack adalah elemen pertama yang diambil kembali. Secara umum, stack terdiri dari operasi dasar seperti push (menambahkan elemen ke puncak stack), pop (mengambil elemen dari puncak stack), serta operasi lain seperti isEmpty (memeriksa apakah stack kosong) dan isFull (memeriksa apakah stack penuh). Dalam implementasi C++, stack dapat dibuat menggunakan array atau linked list, dengan variabel penanda "top" yang menunjukkan posisi elemen teratas di stack. Contoh kode melibatkan deklarasi struktur data stack, fungsi push dan pop, serta pengecekan kondisi penuh atau kosongnya stack.


## Guided 

### 1. stack.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```


### 2. stack.h

```C++
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

### 3. main.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
#### Output
<img width="583" height="809" alt="image" src="https://github.com/user-attachments/assets/9b8e7691-be1f-4883-accb-6a8a9c736b1d" />


## Unguided 1 

### 1. ADT Stack dengan ARRAY

### stack.cpp

```C++
#include "stack.h"

void createStack(Stack &S) {
    S.top = 0;
}

void Push(Stack &S, infotype x) {
    if (S.top >= MAX_STACK) {
        cerr << "Stack overflow: tidak bisa push, stack penuh\n";
        return;
    }
    S.info[S.top++] = x;
}

infotype pop(Stack &S) {
    if (S.top <= 0) {
        cerr << "Stack underflow: tidak ada elemen untuk di-pop\n";
        return -1;
    }
    S.top--;
    return S.info[S.top];
}

void printInfo(const Stack &S) {
    cout << "[TOP] ";
    if (S.top == 0) {
        cout << "(kosong)";
    } else {
        for (int i = S.top - 1; i >= 0; --i) {
            cout << S.info[i];
            if (i > 0) cout << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    int i = 0, j = S.top - 1;
    while (i < j) {
        infotype tmp = S.info[i];
        S.info[i] = S.info[j];
        S.info[j] = tmp;
        ++i; --j;
    }
}

```

### stack.h
```C++
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX_STACK = 20;
typedef int infotype;

struct Stack {
    infotype info[MAX_STACK];
    int top;
};

void createStack(Stack &S);
void Push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);

#endif 

```

### main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);
    Push(S,3);
    Push(S,4);
    Push(S,8);
    pop(S);
    Push(S,2);
    Push(S,3);
    pop(S);
    Push(S,9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}

```
#### Output
<img width="839" height="157" alt="image" src="https://github.com/user-attachments/assets/33bd5e8a-6d36-4648-89c2-c0b632eef65f" />


#### Full Screenshot
<img width="1919" height="1022" alt="image" src="https://github.com/user-attachments/assets/b466ea32-0a9c-4eca-98c4-1b4fc29a1e78" />



## Unguided 2 

### 1. procedur pushAscending

### stack.cpp
```C++
#include "stack.h"

void createStack(Stack &S) {
    S.top = 0;
}

void Push(Stack &S, infotype x) {
    if (S.top >= MAX_STACK) {
        cerr << "Stack overflow: tidak bisa push, stack penuh\n";
        return;
    }
    S.info[S.top++] = x;
}

void pushAscending(Stack &S, infotype x) {
    if (S.top >= MAX_STACK) {
        cerr << "Stack overflow: tidak bisa pushAscending, stack penuh\n";
        return;
    }
    int i = S.top - 1;
    while (i >= 0 && S.info[i] > x) {
        S.info[i + 1] = S.info[i];
        --i;
    }
    S.info[i + 1] = x;
    S.top++;
}

infotype pop(Stack &S) {
    if (S.top <= 0) {
        cerr << "Stack underflow: tidak ada elemen untuk di-pop\n";
        return -1;
    }
    S.top--;
    return S.info[S.top];
}

void printInfo(const Stack &S) {
    cout << "[TOP] ";
    if (S.top == 0) {
        cout << "(kosong)";
    } else {
        for (int i = S.top - 1; i >= 0; --i) {
            cout << S.info[i];
            if (i > 0) cout << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    int i = 0, j = S.top - 1;
    while (i < j) {
        infotype tmp = S.info[i];
        S.info[i] = S.info[j];
        S.info[j] = tmp;
        ++i; --j;
    }
}

```

### stack.h
```C++
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX_STACK = 20;
typedef int infotype;

struct Stack {
    infotype info[MAX_STACK];
    int top;
};

void createStack(Stack &S);
void Push(Stack &S, infotype x);
void pushAscending(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);

#endif

```

### main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);
    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}

```
#### Output
<img width="841" height="156" alt="image" src="https://github.com/user-attachments/assets/e372bbaf-30b6-49d7-ab4d-31c874dc138f" />


#### Full Screenshot
<img width="1919" height="1019" alt="image" src="https://github.com/user-attachments/assets/32105a74-17ac-4a41-a8bc-eb3bc541c233" />


## Unguided 3

### 1. ADT Stack dengan ARRAY

### stack.cpp

```C++
#include "stack.h"
#include <cctype>

void createStack(Stack &S) {
    S.top = 0; 
}

void Push(Stack &S, infotype x) {
    if (S.top >= MAX_STACK) {
        cerr << "Stack overflow: tidak bisa push, stack penuh\n";
        return;
    }
    S.info[S.top++] = x;
}

void pushAscending(Stack &S, infotype x) {
    if (S.top >= MAX_STACK) {
        cerr << "Stack overflow: tidak bisa pushAscending, stack penuh\n";
        return;
    }
    int i = S.top - 1;
    while (i >= 0 && S.info[i] > x) {
        S.info[i + 1] = S.info[i];
        --i;
    }
    S.info[i + 1] = x;
    S.top++;
}

infotype pop(Stack &S) {
    if (S.top <= 0) {
        cerr << "Stack underflow: tidak ada elemen untuk di-pop\n";
        return -1;
    }
    S.top--;
    return S.info[S.top];
}

void printInfo(const Stack &S) {
    cout << "[TOP] ";
    if (S.top == 0) {
        cout << "(kosong)";
    } else {
        for (int i = S.top - 1; i >= 0; --i) {
            cout << S.info[i];
            if (i > 0) cout << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    int i = 0, j = S.top - 1;
    while (i < j) {
        infotype tmp = S.info[i];
        S.info[i] = S.info[j];
        S.info[j] = tmp;
        ++i; --j;
    }
}

void getInputStream(Stack &S) {
    int ch;
    while ((ch = cin.get()) != EOF && ch != '\n') {
        if (S.top >= MAX_STACK) {
            cerr << "\nStack penuh, sisa input diabaikan.\n";
                        while (ch != EOF && ch != '\n') ch = cin.get();
            break;
        }
        if (isdigit(ch)) {
            Push(S, ch - '0'); 
        } else {}
    }
}

```

### stack.h
```C++
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX_STACK = 20;
typedef int infotype;

struct Stack {
    infotype info[MAX_STACK];
    int top;
};

void createStack(Stack &S);
void Push(Stack &S, infotype x);
void pushAscending(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);
void getInputStream(Stack &S);

#endif

```

### main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}

```
#### Output
<img width="872" height="182" alt="image" src="https://github.com/user-attachments/assets/be115dbb-275a-434a-99aa-92247a1fe0dc" />


#### Full Screenshot
<img width="1919" height="1012" alt="image" src="https://github.com/user-attachments/assets/9f83665a-e822-4a7d-bb45-29f197aa0f01" />


Program ini membuat stack yang menggunakan array untuk menyimpan maksimal 20 elemen, dengan variabel "top" untuk menunjukkan jumlah elemen saat ini. Ada fungsi createStack untuk mengosongkan stack, Push untuk menambah elemen, pop untuk menghapus elemen paling atas, dan printInfo untuk menampilkan isi stack. Fungsi pushAscending menambah nilai baru secara otomatis sehingga stack tetap terurut. 

Prosedur getInputStream membaca karakter dari keyboard untuk memasukkan angka ke dalam stack. Input berhenti saat pengguna menekan Enter. Di bagian utama, program menampilkan pesan, membuat stack baru, dan menerima input, lalu menampilkan serta membalik isi stack. Program ini menunjukkan implementasi stack dengan operasi dasar dan pengurutan sederhana.

###
## Kesimpulan 
stack merupakan struktur data linier yang mengikuti prinsip LIFO (Last In First Out), di mana elemen terakhir yang dimasukkan akan menjadi elemen pertama yang diambil kembali. Operasi dasar pada stack meliputi push (menambahkan elemen), pop (menghapus elemen teratas), serta pengecekan kondisi seperti isEmpty dan isFull. Implementasi stack dalam C++ bisa menggunakan array atau linked list dengan variabel penanda top sebagai indeks elemen teratas. Stack sangat berguna dalam berbagai aplikasi pemrograman seperti evaluasi ekspresi, fungsi undo/redo, dan rekursi.

## Referensi
https://id.scribd.com/document/410649209/Stack-Makalah-Struktur-Data
###
https://id.scribd.com/document/367995436/PENERAPAN-STACK-MENGGUNAKAN-BAHASA-PEMROGRAMAN-C-Copy
