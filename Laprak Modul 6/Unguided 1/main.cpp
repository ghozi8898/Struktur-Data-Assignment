#include <iostream>
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);

    int n;
    cout << "Masukkan jumlah data yang akan ditambah: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        infotype x;
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;

        if (isNopolExist(L, x.nopol)) {
            cout << "nomor polisi sudah terdaftar\n\n";
            --i;
            continue;
        }

        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;

        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;
        cout << endl;

        address P = alokasi(x);
        insertLast(L, P);
    }

    cout << "\nDATA LIST (awal)\n\n";
    printInfo(L);

    cout << "Masukkan Nomor Polisi yang dicari : ";
    infotype key;
    cin >> key.nopol;
    address found = findElm(L, key);
    if (found != nullptr) {
        cout << "\nNomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.thnBuat << endl << endl;
    } else {
        cout << "\nData tidak ditemukan.\n\n";
    }

    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    string delKey;
    cin >> delKey;

    if (deleteByNopol(L, delKey)) {
        cout << "Data dengan nomor polisi " << delKey << " berhasil dihapus.\n\n";
    } else {
        cout << "Data dengan nomor polisi " << delKey << " tidak ditemukan.\n\n";
    }

    cout << "DATA LIST (setelah penghapusan)\n\n";
    printInfo(L);

    address P;
    while (L.First != nullptr) {
        deleteFirst(L, P);
        if (P) dealokasi(P);
    }

    return 0;
}
