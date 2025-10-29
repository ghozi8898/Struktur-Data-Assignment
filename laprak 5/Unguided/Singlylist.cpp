#include "Singlylist.h"

// Inisialisasi list kosong
void CreateList(List &L) {
    L.First = Nil;
}

// Buat node baru dan kembalikan address-nya
address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

// Dealokasi node
void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}

// Cetak isi list (nilai dipisah spasi)
void printInfo(const List &L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info;
        P = P->next;
        if (P != Nil) cout << " ";
    }
    cout << endl;
}

// Insert node di awal list
void insertFirst(List &L, address P) {
    if (P == Nil) return;
    P->next = L.First;
    L.First = P;
}

// Cari elemen berdasar nilai info, kembalikan address atau Nil
address findElm(const List &L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info == x) return P;
        P = P->next;
    }
    return Nil;
}

// Hitung total semua info dalam list
int sumInfo(const List &L) {
    int total = 0;
    address P = L.First;
    while (P != Nil) {
        total += P->info;
        P = P->next;
    }
    return total;
}
