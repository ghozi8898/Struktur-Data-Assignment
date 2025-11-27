
# <h1 align="center">Laporan Praktikum Modul Queue (8)</h1>
<p align="center">Muhammad Fathir Al Ghozi</p>

## Dasar Teori
###
Queue pada C++ adalah struktur data antrean yang mengikuti prinsip FIFO (First In First Out), artinya elemen yang pertama kali masuk adalah yang pertama kali keluar. Di C++, queue bisa diimplementasikan menggunakan struktur data seperti array atau linked list, serta menggunakan std::queue dari Standard Template Library (STL) yang menyediakan fungsi-fungsi seperti enqueue (push), dequeue (pop), pengecekan front, dan pengecekan apakah queue kosong. Operasi dasar queue meliputi create, isEmpty, isFull, enqueue, dequeue, dan clear.


## Guided 

### 1. queue.cpp

```C++
#include "queue.h"
using namespace std;

void createQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
```


### 2. queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include<string>

using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif
```

### 3. main.cpp

```C++
#include "queue.h"
#include "queue.cpp"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    createQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```
#### Output
<img width="1272" height="597" alt="image" src="https://github.com/user-attachments/assets/858ede85-72e3-4888-aa78-e06f0f7f99a7" />


## Alternatif 1 
### 1. Queue alternatif satu (head diam, tail bergerak)

### queue.cpp

```C++
#include <iostream>
#include "queue.h"
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(const Queue &Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(const Queue &Q) {
    return (Q.tail == MAXQ - 1);
}

void enqueue(Queue &Q, infotype X) {
    if (isFullQueue(Q)) {
        return;
    }
    if (isEmptyQueue(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = X;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        return -1;
    }
    infotype val = Q.info[0];
    
    for (int i = 0; i < Q.tail; ++i) {
        Q.info[i] = Q.info[i + 1];
    }
    Q.tail--;
    if (Q.tail < 0) {
        Q.head = Q.tail = -1;
    }
    return val;
}

void printInfo(const Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "-1 - -1 \t| empty queue" << endl;
        return;
    }
    cout << Q.head << " - " << Q.tail << " \t| ";
    for (int i = 0; i <= Q.tail; ++i) {
        cout << Q.info[i];
        if (i < Q.tail) cout << " ";
    }
    cout << endl;
}

```

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;
const int MAXQ = 5;

struct Queue {
    infotype info[MAXQ];
    int head;
    int tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(const Queue &Q);
bool isFullQueue(const Queue &Q);
void enqueue(Queue &Q, infotype X);
infotype dequeue(Queue &Q);
void printInfo(const Queue &Q);

#endif

```

### main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    cout << "------------------------------" << endl;
    cout << " H - T \t | Queue Info" << endl;
    cout << "------------------------------" << endl;

    Queue Q;
    CreateQueue(Q);
    printInfo(Q);

    enqueue(Q, 5); printInfo(Q);     
    enqueue(Q, 2); printInfo(Q);        
    enqueue(Q, 7); printInfo(Q);    
    dequeue(Q); printInfo(Q);       
    dequeue(Q); printInfo(Q);       
    enqueue(Q, 4); printInfo(Q);     
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);    

    return 0;
}

```
#### Output
<img width="805" height="338" alt="image" src="https://github.com/user-attachments/assets/3786c382-74ba-442a-9970-99109707e1b7" />


#### Full Screenshot
<img width="1919" height="1022" alt="image" src="https://github.com/user-attachments/assets/19820b13-9bc0-4ce0-b2c1-99046e021d55" />


## Alternatif 2
### 2. Alternatif 2 (Head bergerak, Tail bergerak)

### queue.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
    for (int i = 0; i < 5; ++i) Q.info[i] = -1;
}

bool isEmptyQueue(const Queue &Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(const Queue &Q) {
    return (Q.tail == 4);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) return;

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
        Q.info[Q.tail] = x;
    } else {
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) return -1;

    infotype x = Q.info[Q.head];
    Q.info[Q.head] = -1;
    Q.head++;

    if (Q.head > Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    }

    return x;
}

void printInfo(const Queue &Q) {
    cout << Q.head << " - " << Q.tail << "\t| ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
        return;
    }

    for (int i = 0; i < 5; i++) {
        if (Q.info[i] == -1) cout << "- ";
        else cout << Q.info[i] << " ";
    }
    cout << "\n";
}

```

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(const Queue &Q);
bool isFullQueue(const Queue &Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(const Queue &Q);

#endif

```

### main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    Queue Q;
    CreateQueue(Q);

    cout<<"-----------------------\n";
    cout<<" H - T \t | Queue info\n";
    cout<<"-----------------------\n";
    printInfo(Q);

    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,9); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}

```
#### Output
<img width="903" height="290" alt="image" src="https://github.com/user-attachments/assets/9b1292a0-ff7c-4df2-8ef8-2af82656c31b" />


#### Full Screenshot
<img width="1919" height="1022" alt="image" src="https://github.com/user-attachments/assets/ab7eb872-346c-4c9f-be20-ddf731a1d08f" />


## Alternatif 3
### 3. Alternatif ketiga (Head dan tail berputar)

### queue.cpp

```C++
#include <iostream>
#include "queue.h"
using namespace std;

const int MAX = 5;

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
    for (int i = 0; i < MAX; i++) Q.info[i] = -1;
}

bool isEmptyQueue(const Queue &Q) {
    return (Q.head == -1);
}

bool isFullQueue(const Queue &Q) {
    return (!isEmptyQueue(Q) && ((Q.tail + 1) % MAX == Q.head));
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) return;

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
        Q.info[0] = x;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) return -1;

    infotype x = Q.info[Q.head];
    Q.info[Q.head] = -1;

    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX;
    }

    return x;
}

void printInfo(const Queue &Q) {
    cout << Q.head << " - " << Q.tail << "\t| ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
        return;
    }

    for (int i = 0; i < MAX; i++) {
        if (Q.info[i] == -1) cout << "- ";
        else cout << Q.info[i] << " ";
    }
    cout << "\n";
}

```

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(const Queue &Q);
bool isFullQueue(const Queue &Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(const Queue &Q);

#endif

```

### main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    Queue Q;
    CreateQueue(Q);

    cout << "-----------------------------\n";
    cout << " H - T\t | Queue info\n";
    cout << "-----------------------------\n";
    printInfo(Q);

    enqueue(Q, 5);  printInfo(Q);
    enqueue(Q, 2);  printInfo(Q);
    enqueue(Q, 7);  printInfo(Q);
    enqueue(Q, 9);  printInfo(Q);
    enqueue(Q, 4);  printInfo(Q);   // penuh

    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);

    enqueue(Q, 8);  printInfo(Q);   // tail berputar
    enqueue(Q, 6);  printInfo(Q);   // tail berputar

    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);   // kembali empty

    return 0;
}

```
#### Output
<img width="712" height="343" alt="image" src="https://github.com/user-attachments/assets/cc006fa1-08ad-40d6-accf-c187b92a9ba9" />


#### Full Screenshot
<img width="1919" height="1024" alt="image" src="https://github.com/user-attachments/assets/6ec64968-0011-4a9c-bdcb-6a5c9f29b92a" />

###
#### Penjelasan

Pada ketiga alternatif, ADT Queue menggunakan array berukuran tetap serta dua indeks `head` dan `tail`. Kondisi kosong direpresentasikan dengan `head = tail = -1`, dan saat queue pertama kali diisi keduanya diatur ke `0`. Fungsi `enqueue` menambahkan elemen di posisi `tail`, `dequeue` mengambil elemen dari `head`, dan jika elemen terakhir dihapus maka queue kembali ke keadaan kosong. Perbedaan utama antarmekanisme terletak pada bagaimana `head` dan `tail` bergerak, serta bagaimana kondisi penuh ditentukan.

Pada **Alternatif 1**, `head` tidak bergerak sama sekali sehingga setiap dequeue hanya “mengosongkan” elemen tetapi tidak menggeser area yang bisa dipakai ulang. `tail` maju terus hingga ujung array, sehingga queue dapat terlihat penuh meskipun ada banyak ruang kosong di depan. **Alternatif 2** memperbaiki hal ini dengan membiarkan `head` dan `tail` sama-sama bergerak ke kanan: setelah beberapa dequeue, `head` naik sehingga ruang sebelumnya dianggap tidak relevan, tetapi `tail` tetap berhenti di ujung array; akibatnya array tetap dapat penuh sebelum benar-benar kehabisan slot secara logis.

**Alternatif 3** adalah solusi paling efisien karena menggunakan konsep **circular queue**. Baik `head` maupun `tail` bergerak menggunakan operasi modulo, sehingga ketika mencapai ujung array mereka berputar kembali ke indeks awal. Kondisi penuh didefinisikan sebagai `(tail + 1) % MAX == head`, dan kondisi kosong tetap `head = tail = -1`. Dengan cara ini, tidak ada ruang terbuang, semua slot array dapat dipakai ulang, dan kinerja operasi tetap O(1) sama seperti dua alternatif sebelumnya.


###
## Kesimpulan 
Queue merupakan struktur data linier yang mengikuti prinsip FIFO (First In First Out), di mana elemen pertama yang dimasukkan akan menjadi elemen pertama yang dikeluarkan. Di C++, queue dapat diimplementasikan dengan mudah menggunakan std::queue dari Standard Template Library yang menyediakan fungsi dasar seperti enqueue (push), dequeue (pop), pengecekan elemen depan (front), dan pengecekan apakah queue kosong (empty). Penggunaan queue di C++ sangat efisien untuk aplikasi yang membutuhkan proses antrian berurutan seperti sistem penjadwalan dan simulasi.

## Referensi[
https://id.scribd.com/doc/229972806/Laporan-Resmi-Queue-201301011
###
Krisnanta, R. (2020). Struktur Data Queue C++. Ripaldi.
###
Iswahyudi, C. Konsep QUEUE Dalam Bahasa Pemrograman C++.
