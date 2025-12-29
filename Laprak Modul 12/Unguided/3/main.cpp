#include "circularlist.h"

address createData(string nama, string nim, char jk, float ipk) {
    infotype x;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jk;
    x.ipk = ipk;
    return alokasi(x);
}

int main() {
    List L;
    createList(L);

    address P1, P2;
    infotype x;

    P1 = createData("Celin","04",'P',4.0);
    insertFirst(L,P1);

    P1 = createData("Adam","06",'L',3.45);
    insertLast(L,P1);

    P1 = createData("Sukoco","02",'L',3.71);
    insertFirst(L,P1);

    P1 = createData("Hafiz","01",'L',3.3);
    insertFirst(L,P1);

    P1 = createData("Gendis","07",'P',3.75);
    insertLast(L,P1);

    x.nim = "07";
    P1 = findElm(L,x);
    P2 = createData("Thoriq","03",'L',3.5);
    insertAfter(L,P1,P2);

    x.nim = "02";
    P1 = findElm(L,x);
    P2 = createData("Fathir","08",'L',4);
    insertAfter(L,P1,P2);

    x.nim = "04";
    P1 = findElm(L,x);
    P2 = createData("Ela","05",'P',3.4);
    insertAfter(L,P1,P2);

    cout << "=== DATA MAHASISWA ===\n";
    printInfo(L);

    return 0;
}
