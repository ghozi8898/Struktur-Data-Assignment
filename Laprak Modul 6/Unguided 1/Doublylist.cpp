#include "Doublylist.h"
#include <iostream>

using namespace std;

void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(const infotype &x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == x.nopol) return P;
        P = P->next;
    }
    return nullptr;
}

bool isNopolExist(const List &L, const string &nopol) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol) return true;
        P = P->next;
    }
    return false;
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

void printInfo(const List &L) {
    // print from Last to First to match sample
    address P = L.Last;
    while (P != nullptr) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl << endl;
        P = P->prev;
    }
}

// deleteFirst: removes first node and returns it in P (caller should dealokasi(P))
void deleteFirst(List &L, address &P) {
    if (L.First == nullptr) {
        P = nullptr;
        return;
    }
    P = L.First;
    if (L.First == L.Last) { // only one element
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        L.First = P->next;
        L.First->prev = nullptr;
        P->next = nullptr;
    }
}

// deleteLast: removes last node and returns it in P
void deleteLast(List &L, address &P) {
    if (L.Last == nullptr) {
        P = nullptr;
        return;
    }
    P = L.Last;
    if (L.First == L.Last) { // only one
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        L.Last = P->prev;
        L.Last->next = nullptr;
        P->prev = nullptr;
    }
}

// deleteAfter: remove node after Prec (Prec->next) and return it in P
// Note: this function doesn't update a List's Last pointer (caller must handle if needed)
void deleteAfter(address Prec, address &P) {
    if (Prec == nullptr || Prec->next == nullptr) {
        P = nullptr;
        return;
    }
    P = Prec->next;
    address S = P->next; // successor after P

    Prec->next = S;
    if (S != nullptr) S->prev = Prec;

    P->next = nullptr;
    P->prev = nullptr;
}

// convenience: find node by nopol and delete it (dealokasi done here). returns true if deleted
bool deleteByNopol(List &L, const string &nopol) {
    address P = L.First;
    while (P != nullptr && P->info.nopol != nopol) P = P->next;
    if (P == nullptr) return false;

    address Q = nullptr;
    if (P == L.First) {
        deleteFirst(L, Q);
    } else if (P == L.Last) {
        deleteLast(L, Q);
    } else {
        // delete after previous
        address Prec = P->prev;
        deleteAfter(Prec, Q);
        // Q should be equal to P
        // If P was Last it would have been handled above
    }

    if (Q != nullptr) dealokasi(Q);
    return true;
}
