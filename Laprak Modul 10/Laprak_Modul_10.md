
# <h1 align="center">Laporan Praktikum Modul Tree (10)</h1>
<p align="center">Muhammad Fathir Al Ghozi</p>

## Dasar Teori
###
Tree pada C++ adalah struktur data non linear yang merepresentasikan hubungan terstruktur antara elemen-elemen. Tree terdiri dari node dengan satu node khusus sebagai root (akar) dan node-node lain sebagai anak (child), membentuk cabang-cabang subtree. Pada implementasinya, node biasanya berisi data dan dua pointer yang menunjuk ke anak kiri dan kanan, sehingga membentuk binary tree. Operasi utama pada tree adalah traversal, yaitu mengunjungi node dengan cara PreOrder (root-left-right), InOrder (left-root-right), dan PostOrder (left-right-root). Penambahan node biasanya dilakukan secara rekursif berdasarkan perbandingan nilai data agar tree tetap terstruktur secara urut.
## Guided 

### 1. bst.cpp

```C++
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}

```


### 2. bst.h

```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;    

typedef struct BST *node;

struct BST {
    int angka;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```

### 3. main.cpp

```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```
#### Output
<img width="613" height="702" alt="image" src="https://github.com/user-attachments/assets/90540214-9bab-4f8a-9572-5c62b261f12e" />
#### Full screenshot
<img width="1919" height="1022" alt="image" src="https://github.com/user-attachments/assets/20cb3380-292c-4765-901e-1db0355a44a4" />



## Unguided  1 
### 1. Unguided 
### bstree.cpp

```C++
#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    }
    else if (x < root->info) {
        insertNode(root->left, x);
    }
    else if (x > root->info) {
        insertNode(root->right, x);
    }
}

void InOrder(address root) {
    if (root != Nil) {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

int hitungNode(address root) {
    if (root == Nil) return 0;
    return 1 + hitungNode(root->left) + hitungNode(root->right);
}

int hitungTotal(address root) {
    if (root == Nil) return 0;
    return root->info + hitungTotal(root->left) + hitungTotal(root->right);
}

int hitungKedalaman(address root, int start) {
    if (root == Nil) return start - 1;

    int kiri  = hitungKedalaman(root->left,  start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);

    return (kiri > kanan ? kiri : kanan);
}

```

### bstree.h
```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
void InOrder(address root);

int hitungNode(address root);
int hitungTotal(address root);
int hitungKedalaman(address root, int start);

#endif

```

### main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;
    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    InOrder(root);
    cout << "\n";

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah Node : " << hitungNode(root) << endl;
    cout << "total : " << hitungTotal(root) << endl;

    return 0;
}

```
#### Output
<img width="860" height="180" alt="image" src="https://github.com/user-attachments/assets/7aa5d34d-155e-46e3-98d5-aa30c5faa51a" />

#### Full Screenshot
<img width="1919" height="1017" alt="image" src="https://github.com/user-attachments/assets/0dc17b29-cfd2-44e9-b271-5ec37c9c22ca" />


## Unguided 2
### 2. Unguided (tree post-order and pre-order)

### bstree.cpp
```C++
#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } 
    else if (x < root->info) {
        insertNode(root->left, x);
    } 
    else if (x > root->info) {
        insertNode(root->right, x);
    }
}

void preOrder(address root) {
    if (root != Nil) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(address root) {
    if (root != Nil) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}

```

### bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

// Fungsi & Prosedur BST
address alokasi(infotype x);
void insertNode(address &root, infotype x);
void preOrder(address root);
void postOrder(address root);

#endif

```

### main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    address root = Nil;
    int pilih, nilai;

    do {
        cout << "\n===== MENU BST =====\n";
        cout << "1. Insert Node\n";
        cout << "2. Tampilkan PreOrder\n";
        cout << "3. Tampilkan PostOrder\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilih;

        switch (pilih) {
        case 1:
            cout << "Masukkan nilai: ";
            cin >> nilai;
            insertNode(root, nilai);
            break;

        case 2:
            cout << "PreOrder : ";
            preOrder(root);
            cout << endl;
            break;

        case 3:
            cout << "PostOrder: ";
            postOrder(root);
            cout << endl;
            break;

        case 0:
            cout << "Keluar...\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilih != 0);

    return 0;
}

```
#### Output
<img width="458" height="493" alt="image" src="https://github.com/user-attachments/assets/73d4ce76-abd7-4c99-920c-cc0c70388c55" />


#### Full Screenshot
<img width="1919" height="1017" alt="image" src="https://github.com/user-attachments/assets/b66a82da-c3de-4795-a0c8-dad82c4245b0" />



###
#### Penjelasan
Kode ini membangun Binary Search Tree sederhana dengan tipe `address` (pointer ke `Node`) dan konstanta `Nil` sebagai `NULL`. Fungsi `alokasi(x)` membuat node baru di heap dengan nilai `info = x`; `insertNode(root, x)` menaruh `x` ke posisi yang benar secara rekursif: jika `x` lebih kecil ke cabang kiri, lebih besar ke cabang kanan, dan jika sama maka diabaikan (tidak menyisipkan duplikat). `InOrder(root)` melakukan traversal in-order (kiri → akar → kanan) sehingga mencetak nilai terurut menaik. `main()` mengisi pohon dengan beberapa nilai, memanggil `InOrder()` untuk menampilkan isi pohon, lalu mencetak tiga metrik yang dihitung secara rekursif oleh fungsi berikut.

Fungsi pembantu untuk analisis pohon bersifat rekursif dan sederhana: `hitungNode(root)` mengembalikan jumlah node dengan rumus `1 + hitungNode(kiri) + hitungNode(kanan)`; `hitungTotal(root)` mengembalikan jumlah semua `info` di pohon dengan penjumlahan serupa; `hitungKedalaman(root, start)` mengukur kedalaman maksimum dengan mengoper parameter `start` sebagai kedalaman saat ini (pada pemanggilan awal biasanya `0`), mengembalikan `start-1` untuk subtree kosong dan mengambil maksimum antara kedalaman cabang kiri dan kanan untuk menentukan kedalaman pohon (jadi hasilnya adalah jarak maksimum dari akar ke daun menurut cara penghitungan berbasis `start`). Secara keseluruhan kode ini memanfaatkan alokasi dinamik, rekursi untuk operasi dasar BST, dan menghasilkan keluaran terurut plus metrik ringkas tanpa manajemen memori penghapusan (`delete`).


###
## Kesimpulan 
Kesimpulan dari teori tree pada C++ adalah tree merupakan struktur data non linear yang bagus untuk mewakili data yang tertata dan digunakan secara luas dalam pemrograman untuk operasi search, insert, dan pengurutan data yang efisien. Implementasi tree di C++ biasanya memakai node dengan pointer anak kiri dan kanan, serta traversal sebagai operasi utama. Tree menggunakan cara yang efisien untuk mengelola dan mengakses data yang berstruktur.

## Referensi
Prasetyo, D. Tree C++.
###
https://kaazima.blogspot.com/2013/12/contoh-program-c-program-tree-c-sederhana.html
###
https://www.nblognlife.com/2014/12/tree-pada-c-tree-awal.html
###
Iswahyudi, C. Konsep QUEUE Dalam Bahasa Pemrograman C++.
###
https://www.petanikode.com/cpp-struct/
