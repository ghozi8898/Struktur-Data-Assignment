#include "singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    address deletedNode;
    
    createList(L);
    
    // Membuat list awal: 9, 12, 8, 0, 2
    P1 = alokasi(2);
    insertFirst(L, P1);
    
    P2 = alokasi(0);
    insertFirst(L, P2);
    
    P3 = alokasi(8);
    insertFirst(L, P3);
    
    P4 = alokasi(12);
    insertFirst(L, P4);
    
    P5 = alokasi(9);
    insertFirst(L, P5);
    
    // Menghapus node 9 (first) menggunakan deleteFirst()
    deleteFirst(L, deletedNode);
    dealokasi(deletedNode);
    
    // Menghapus node 2 (last) menggunakan deleteLast()
    deleteLast(L, deletedNode);
    dealokasi(deletedNode);
    
    // Menghapus node 8 menggunakan deleteAfter()
    // Mencari node sebelum 8 (yaitu node 12)
    address Prec = L.First; // 12 adalah first sekarang
    deleteAfter(L, Prec, deletedNode);
    dealokasi(deletedNode);
    
    // Output yang diharapkan
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl << endl;
    
    // Menghapus seluruh list
    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;
    
    return 0;
}