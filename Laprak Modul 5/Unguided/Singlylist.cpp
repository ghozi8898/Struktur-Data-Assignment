#include "Singlylist.h"

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}

void printInfo(const List &L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info;
        P = P->next;
        if (P != Nil) cout << " ";
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    if (P == Nil) return;
    P->next = L.First;
    L.First = P;
}

address findElm(const List &L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info == x) return P;
        P = P->next;
    }
    return Nil;
}

int sumInfo(const List &L) {
    int total = 0;
    address P = L.First;
    while (P != Nil) {
        total += P->info;
        P = P->next;
    }
    return total;
}
