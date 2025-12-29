#include "circularlist.h"

/* ===== CREATE ===== */
void createList(List &L) {
    L.First = Nil;
}

/* ===== ALOKASI ===== */
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = P;   // circular
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

/* ===== INSERT ===== */
void insertFirst(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
    } else {
        address last = L.First;
        while (last->next != L.First)
            last = last->next;

        P->next = L.First;
        last->next = P;
        L.First = P;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        insertFirst(L, P);
    } else {
        address last = L.First;
        while (last->next != L.First)
            last = last->next;

        last->next = P;
        P->next = L.First;
    }
}

void insertAfter(List &L, address Prec, address P) {
    P->next = Prec->next;
    Prec->next = P;
}

/* ===== DELETE ===== */
void deleteFirst(List &L, address &P) {
    if (L.First != Nil) {
        address last = L.First;
        while (last->next != L.First)
            last = last->next;

        P = L.First;
        if (P->next == P) {
            L.First = Nil;
        } else {
            L.First = P->next;
            last->next = L.First;
        }
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First != Nil) {
        address last = L.First;
        address prec = Nil;

        while (last->next != L.First) {
            prec = last;
            last = last->next;
        }

        P = last;
        if (prec == Nil) {
            L.First = Nil;
        } else {
            prec->next = L.First;
        }
        P->next = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    P = Prec->next;
    Prec->next = P->next;
    P->next = Nil;
}

/* ===== FIND ===== */
address findElm(List L, infotype x) {
    if (L.First == Nil) return Nil;

    address P = L.First;
    do {
        if (P->info.nim == x.nim)
            return P;
        P = P->next;
    } while (P != L.First);

    return Nil;
}

/* ===== PRINT ===== */
void printInfo(List L) {
    if (L.First == Nil) {
        cout << "List kosong\n";
        return;
    }

    address P = L.First;
    do {
        cout << P->info.nama << " | "
             << P->info.nim << " | "
             << P->info.jenis_kelamin << " | "
             << P->info.ipk << endl;
        P = P->next;
    } while (P != L.First);
}
