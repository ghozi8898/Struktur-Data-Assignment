#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    CreateList(L);

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

    printInfo(L);

    address found = findElm(L, 8);
    if (found != Nil) {
        cout << found->info << " ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    int total = sumInfo(L);
    cout << "Total info dari kelima elemen adalah " << total << endl;

    address cur = L.First;
    while (cur != Nil) {
        address next = cur->next;
        dealokasi(cur);
        cur = next;
    }
    L.First = Nil;

    return 0;
}
