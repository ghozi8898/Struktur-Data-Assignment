#include <iostream>
#include "Doublylist.h"
using namespace std;

bool isValidInput(const infotype &x) {
    return !x.nopol.empty() && !x.warna.empty() && x.thnBuat > 0;
}

int main() {
    List L;
    CreateList(L);

    // === INPUT DATA ===
    int countValid = 0;

    while (countValid < 3) {
        infotype x;

        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;

        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;

        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;
        cout << endl;

        // Cegah input tidak valid
        if (!isValidInput(x)) {
            cout << "Input tidak valid, ulangi.\n\n";
            continue;   // tidak hitung data
        }

        // Cek duplikasi SETELAH input lengkap
        if (findElm(L, x.nopol) != nullptr) {
            cout << "nomor polisi sudah terdaftar\n\n";
            continue;   // tidak hitung data
        }

        // Input VALID → tambahkan data
        insertLast(L, alokasi(x));
        countValid++;
    }

    // === TAMPILKAN LIST SETELAH D004 MASUK (DATA KE-4) ===
    cout << "DATA LIST 1\n\n";
    printInfo(L);

    // === CARI ELEMENT ===
    string cari;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> cari;

    address found = findElm(L, cari);

    if (found != nullptr) {
        cout << "\nNomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.thnBuat << endl;
    } else {
        cout << "\nData tidak ditemukan.\n";
    }

    // === DELETE DATA ===
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> cari;

    address target = findElm(L, cari);

    if (target == nullptr) {
        cout << "Data tidak ditemukan.\n";
    } else {
        address P;

        if (target == L.First) {
            deleteFirst(L, P);
        } else if (target == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(target->prev, P);
        }

        dealokasi(P);
        cout << "Data dengan nomor polisi " << cari << " berhasil dihapus.\n\n";
    }

    cout << "DATA LIST 1\n\n";
    printInfo(L);

    return 0;
}
