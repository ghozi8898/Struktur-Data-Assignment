#include "QueuePengiriman.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool isEmpty(QueueEkspedisi &Q) {
    return (Q.Head == -1 && Q.Tail == -1);
}

bool isFull(QueueEkspedisi &Q) {
    return (Q.Tail == MAX - 1);
}

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

void enQueue(QueueEkspedisi &Q) {
    if (isFull(Q)) {
        cout << "Queue penuh! Tidak dapat menambah data.\n";
        return;
    }
    
    if (isEmpty(Q)) {
        Q.Head = 0;
    }
    
    Q.Tail++;
    Paket &pkt = Q.dataPaket[Q.Tail];
    
    cout << "Masukkan Kode Resi: ";
    cin.ignore();
    getline(cin, pkt.KodeResi);
    cout << "Masukkan Nama Pengirim: ";
    getline(cin, pkt.NamaPengirim);
    cout << "Masukkan Berat Barang (kg): ";
    cin >> pkt.BeratBarang;
    cout << "Masukkan Tujuan: ";
    cin.ignore();
    getline(cin, pkt.Tujuan);
    
    cout << "Data paket berhasil ditambahkan!\n";
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong! Tidak ada data untuk dihapus.\n";
        return;
    }
    
    // Geser semua elemen ke kiri
    for (int i = 0; i < Q.Tail; i++) {
        Q.dataPaket[i] = Q.dataPaket[i + 1];
    }
    
    Q.Tail--;
    
    // Jika queue menjadi kosong setelah deQueue
    if (Q.Tail == -1) {
        Q.Head = -1;
    }
    
    cout << "Data paket berhasil dihapus!\n";
}

void viewQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
        return;
    }
    
    cout << "\n=== DATA PAKET DALAM QUEUE ===\n";
    cout << "Head -> ";
    for (int i = Q.Head; i <= Q.Tail; i++) {
        cout << "[" << Q.dataPaket[i].KodeResi << "]";
        if (i < Q.Tail) cout << " -> ";
    }
    cout << " <- Tail\n";
    
    cout << "\nDetail Paket:\n";
    cout << "------------------------------------------------------------\n";
    cout << setw(10) << "Kode Resi" << setw(15) << "Pengirim" 
         << setw(8) << "Berat" << setw(12) << "Tujuan" << endl;
    cout << "------------------------------------------------------------\n";
    
    for (int i = Q.Head; i <= Q.Tail; i++) {
        Paket &p = Q.dataPaket[i];
        cout << setw(10) << p.KodeResi 
             << setw(15) << p.NamaPengirim 
             << setw(8) << p.BeratBarang 
             << setw(12) << p.Tujuan << endl;
    }
    cout << "------------------------------------------------------------\n";
}

int TotalBiayaPengiriman(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        return 0;
    }
    
    int totalBiaya = 0;
    for (int i = Q.Head; i <= Q.Tail; i++) {
        totalBiaya += Q.dataPaket[i].BeratBarang * 8250;
    }
    return totalBiaya;
}