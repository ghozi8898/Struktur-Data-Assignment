#include "StackMahasiswa.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool isEmpty(StackMahasiswa &StackMHS) {
    return StackMHS.Top == -1;
}

bool isFull(StackMahasiswa &StackMHS) {
    return StackMHS.Top == MAX - 1;
}

void createStack(StackMahasiswa &StackMHS) {
    StackMHS.Top = -1;
}

void Push(StackMahasiswa &StackMHS) {
    if (isFull(StackMHS)) {
        cout << "Stack penuh! Tidak dapat menambah data.\n";
        return;
    }
    
    Mahasiswa mhs;
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, mhs.Nama);
    cout << "Masukkan NIM: ";
    getline(cin, mhs.NIM);
    cout << "Masukkan Nilai Tugas: ";
    cin >> mhs.NilaiTugas;
    cout << "Masukkan Nilai UTS: ";
    cin >> mhs.NilaiUTS;
    cout << "Masukkan Nilai UAS: ";
    cin >> mhs.NilaiUAS;
    
    StackMHS.Top++;
    StackMHS.dataMahasiswa[StackMHS.Top] = mhs;
}

void Pop(StackMahasiswa &StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong! Tidak ada data untuk di-pop.\n";
        return;
    }
    StackMHS.Top--;
}

void Update(StackMahasiswa &StackMHS, int posisi) {
    if (posisi < 0 || posisi > StackMHS.Top) {
        cout << "Posisi tidak valid!\n";
        return;
    }
    
    Mahasiswa &mhs = StackMHS.dataMahasiswa[posisi];
    cout << "Update data mahasiswa posisi " << posisi << ":\n";
    cout << "Nama (" << mhs.Nama << "): ";
    cin.ignore();
    getline(cin, mhs.Nama);
    cout << "NIM (" << mhs.NIM << "): ";
    getline(cin, mhs.NIM);
    cout << "Nilai Tugas (" << mhs.NilaiTugas << "): ";
    cin >> mhs.NilaiTugas;
    cout << "Nilai UTS (" << mhs.NilaiUTS << "): ";
    cin >> mhs.NilaiUTS;
    cout << "Nilai UAS (" << mhs.NilaiUAS << "): ";
    cin >> mhs.NilaiUAS;
}

void View(StackMahasiswa &StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong!\n";
        return;
    }
    
    cout << "\nData Mahasiswa dalam Stack:\n";
    cout << setw(10) << "Posisi" << setw(15) << "Nama" << setw(10) << "NIM"
         << setw(12) << "Tugas" << setw(8) << "UTS" << setw(8) << "UAS" 
         << setw(14) << "Nilai Akhir" << endl;
    
    for (int i = StackMHS.Top; i >= 0; i--) {
        Mahasiswa &m = StackMHS.dataMahasiswa[i];
        float nilaiAkhir = 0.2 * m.NilaiTugas + 0.4 * m.NilaiUTS + 0.4 * m.NilaiUAS;
        cout << setw(10) << i 
             << setw(15) << m.Nama 
             << setw(10) << m.NIM
             << setw(12) << m.NilaiTugas 
             << setw(8) << m.NilaiUTS 
             << setw(8) << m.NilaiUAS
             << setw(14) << fixed << setprecision(2) << nilaiAkhir << endl;
    }
}

void SearchNilaiAkhir(StackMahasiswa &StackMHS, float NilaiAkhirMin, float NilaiAkhirMax) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong! Tidak dapat melakukan pencarian.\n";
        return;
    }
    
    cout << "\nHasil Pencarian (Nilai Akhir antara " << NilaiAkhirMin << " - " << NilaiAkhirMax << "):\n";
    bool found = false;
    for (int i = StackMHS.Top; i >= 0; i--) {
        Mahasiswa &m = StackMHS.dataMahasiswa[i];
        float nilaiAkhir = 0.2 * m.NilaiTugas + 0.4 * m.NilaiUTS + 0.4 * m.NilaiUAS;
        if (nilaiAkhir >= NilaiAkhirMin && nilaiAkhir <= NilaiAkhirMax) {
            cout << "Ditemukan pada posisi " << i << ": " << m.Nama 
                 << " (Nilai Akhir: " << fixed << setprecision(2) << nilaiAkhir << ")\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Tidak ada data yang sesuai.\n";
    }
}

void MaxNilaiAkhir(StackMahasiswa &StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong! Tidak dapat mencari nilai tertinggi.\n";
        return;
    }
    
    int maxPos = StackMHS.Top;
    float maxNilai = 0.2 * StackMHS.dataMahasiswa[maxPos].NilaiTugas + 
                     0.4 * StackMHS.dataMahasiswa[maxPos].NilaiUTS + 
                     0.4 * StackMHS.dataMahasiswa[maxPos].NilaiUAS;
    
    for (int i = StackMHS.Top - 1; i >= 0; i--) {
        Mahasiswa &m = StackMHS.dataMahasiswa[i];
        float nilaiAkhir = 0.2 * m.NilaiTugas + 0.4 * m.NilaiUTS + 0.4 * m.NilaiUAS;
        if (nilaiAkhir > maxNilai) {
            maxNilai = nilaiAkhir;
            maxPos = i;
        }
    }
    
    Mahasiswa &m = StackMHS.dataMahasiswa[maxPos];
    cout << "\nMahasiswa dengan Nilai Akhir Tertinggi:\n";
    cout << "Posisi: " << maxPos << endl;
    cout << "Nama: " << m.Nama << endl;
    cout << "NIM: " << m.NIM << endl;
    cout << "Nilai Akhir: " << fixed << setprecision(2) << maxNilai << endl;
}