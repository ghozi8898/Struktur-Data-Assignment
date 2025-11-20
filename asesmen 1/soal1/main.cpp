#include <iostream>
#include "SLLInventory.h"
using namespace std;

int main() {
    List L;
    createList(L);

    // 1. Insert 3 produk
    Product p1 {"Pulpen", "A001", 20, 2500.0f, 0.0f};
    Product p2 {"Buku Tulis", "A002", 15, 5000.0f, 10.0f};
    Product p3 {"Penghapus", "A003", 30, 1500.0f, 0.0f};

    insertLast(L, p1);
    insertLast(L, p2);
    insertLast(L, p3);

    // 2. Tampilkan list awal
    cout << "-- List Awal --" << endl;
    viewList(L);
    cout << endl;

    // 3. deleteFirst
    Product removed;
    deleteFirst(L, removed);
    cout << "deleteFirst(): " << removed.Nama << " (" << removed.SKU << ")\n\n";

    // 4. tampilkan list setelah delete
    cout << "-- Setelah deleteFirst --" << endl;
    viewList(L);
    cout << endl;

    // 5. Update elemen pada posisi ke-2
    Product newP {"Stabilo", "A010", 40, 9000.0f, 5.0f};
    bool ok = updateAtPosition(L, 2, newP);
    if (!ok) cout << "Update gagal (posisi tidak ada)\n";

    cout << "\n-- Setelah Update Pos 2 --" << endl;
    viewList(L);
    cout << endl;

    // 6. Searching HargaAkhir dalam rentang
    cout << "-- Searching HargaAkhir [2000 - 7000] --" << endl;
    searchByFinalPriceRange(L, 2000.0f, 7000.0f);
    cout << endl;

    // 7. Menampilkan produk dengan HargaAkhir tertinggi
    MaxHargaAkhir(L);

    return 0;
}
