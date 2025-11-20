#include <iostream>
#include <iomanip>
#include "SLLInventory.h"

bool isEmpty(const List &L) {
    return L.head == nullptr;
}

void createList(List &L) {
    L.head = nullptr;
}

address allocate(const Product &P) {
    address p = new Node;
    p->info = P;
    p->next = nullptr;
    return p;
}

void deallocate(address addr) {
    delete addr;
}

void insertFirst(List &L, const Product &P) {
    address p = allocate(P);
    p->next = L.head;
    L.head = p;
}

void insertLast(List &L, const Product &P) {
    address p = allocate(P);
    if (isEmpty(L)) {
        L.head = p;
        return;
    }
    address cur = L.head;
    while (cur->next != nullptr) cur = cur->next;
    cur->next = p;
}

void insertAfter(List &L, address Q, const Product &P) {
    if (Q == nullptr) return;
    address p = allocate(P);
    p->next = Q->next;
    Q->next = p;
}

void deleteFirst(List &L, Product &P) {
    if (isEmpty(L)) return;
    address p = L.head;
    P = p->info;
    L.head = p->next;
    deallocate(p);
}

void deleteLast(List &L, Product &P) {
    if (isEmpty(L)) return;
    if (L.head->next == nullptr) {
        P = L.head->info;
        deallocate(L.head);
        L.head = nullptr;
        return;
    }
    address prev = nullptr, cur = L.head;
    while (cur->next != nullptr) {
        prev = cur;
        cur = cur->next;
    }
    P = cur->info;
    prev->next = nullptr;
    deallocate(cur);
}

void deleteAfter(List &L, address Q, Product &P) {
    if (Q == nullptr || Q->next == nullptr) return;
    address p = Q->next;
    P = p->info;
    Q->next = p->next;
    deallocate(p);
}

static float HargaAkhir(const Product &P) {
    return P.HargaSatuan * (1.0f - P.DiskonPersen / 100.0f);
}

bool updateAtPosition(List &L, int posisi, const Product &P) {
    if (posisi <= 0) return false;
    address cur = L.head;
    int idx = 1;
    while (cur != nullptr && idx < posisi) {
        cur = cur->next;
        idx++;
    }
    if (cur == nullptr) return false;
    cur->info = P;
    return true;
}

bool updateAtPositionInteractive(List &L, int posisi) {
    if (posisi <= 0) return false;
    address cur = L.head;
    int idx = 1;
    while (cur != nullptr && idx < posisi) {
        cur = cur->next;
        idx++;
    }
    if (cur == nullptr) return false;
    Product P;
    cout << "Masukkan data baru untuk posisi " << posisi << "\n";
    cout << "Nama: ";
    getline(cin >> ws, P.Nama);
    cout << "SKU: ";
    getline(cin, P.SKU);
    cout << "Jumlah: ";
    cin >> P.Jumlah;
    cout << "HargaSatuan: ";
    cin >> P.HargaSatuan;
    cout << "DiskonPersen: ";
    cin >> P.DiskonPersen;
    cur->info = P;
    return true;
}

void viewList(const List &L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
        return;
    }
    address cur = L.head;
    int idx = 1;
    // Cetak sederhana, satu baris per produk
    while (cur != nullptr) {
        float ha = HargaAkhir(cur->info);
        cout << idx << ". " << cur->info.Nama
             << " (" << cur->info.SKU << ") - "
             << cur->info.Jumlah << " pcs - ";
        cout << "Harga: " << fixed << setprecision(0) << cur->info.HargaSatuan << " - ";
        cout << "Diskon: " << cur->info.DiskonPersen << "% - ";
        cout << "Akhir: " << fixed << setprecision(2) << ha << endl;
        cur = cur->next;
        idx++;
    }
}

void searchByFinalPriceRange(const List &L, float minPrice, float maxPrice) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
        return;
    }
    address cur = L.head;
    int idx = 1;
    bool found = false;
    cout << "Hasil pencarian HargaAkhir dalam rentang [" << minPrice << ", " << maxPrice << "]:" << endl;
    while (cur != nullptr) {
        float ha = HargaAkhir(cur->info);
        if (ha >= minPrice && ha <= maxPrice) {
            cout << "Posisi " << idx << ": " << cur->info.Nama << " (SKU: " << cur->info.SKU << ") - HargaAkhir = " << fixed << setprecision(2) << ha << endl;
            found = true;
        }
        cur = cur->next;
        idx++;
    }
    if (!found) cout << "Tidak ditemukan produk dalam rentang tersebut." << endl;
}

void MaxHargaAkhir(const List &L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
        return;
    }
    // first pass: find max
    address cur = L.head;
    float maxHA = HargaAkhir(cur->info);
    while (cur != nullptr) {
        float ha = HargaAkhir(cur->info);
        if (ha > maxHA) maxHA = ha;
        cur = cur->next;
    }
    // second pass: print all with maxHA
    cur = L.head;
    int idx = 1;
    cout << "Produk dengan HargaAkhir maksimum (" << fixed << setprecision(2) << maxHA << "):" << endl;
    while (cur != nullptr) {
        float ha = HargaAkhir(cur->info);
        if (abs(ha - maxHA) < 1e-3) {
            cout << "Posisi " << idx << ": " << cur->info.Nama << " (SKU: " << cur->info.SKU << ") - Jumlah: " << cur->info.Jumlah << " - HargaSatuan: " << cur->info.HargaSatuan << " - Diskon(%): " << cur->info.DiskonPersen << "\n";
        }
        cur = cur->next;
        idx++;
    }
}


