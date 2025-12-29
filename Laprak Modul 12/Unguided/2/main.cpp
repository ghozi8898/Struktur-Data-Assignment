#include "multilist.h"

int main() {
    listinduk L;
    CreateList(L);

    insertLast(L, alokasi(1));
    insertLast(L, alokasi(2));
    insertLast(L, alokasi(3));

    address P = findElm(L, 1);
    insertLastAnak(P->lanak, alokasiAnak(11));
    insertLastAnak(P->lanak, alokasiAnak(12));

    P = findElm(L, 2);
    insertLastAnak(P->lanak, alokasiAnak(21));

    printInfo(L);

    delPAnak(findElm(L,1)->lanak, 12);
    delP(L, 2);

    cout << "\nSetelah delete:\n";
    printInfo(L);

    return 0;
}
