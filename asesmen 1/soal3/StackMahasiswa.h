#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <string>
using namespace std;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

const int MAX = 6;

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

bool isEmpty(StackMahasiswa &StackMHS);
bool isFull(StackMahasiswa &StackMHS);
void createStack(StackMahasiswa &StackMHS);
void Push(StackMahasiswa &StackMHS);
void Pop(StackMahasiswa &StackMHS);
void Update(StackMahasiswa &StackMHS, int posisi);
void View(StackMahasiswa &StackMHS);
void SearchNilaiAkhir(StackMahasiswa &StackMHS, float NilaiAkhirMin, float NilaiAkhirMax);
void MaxNilaiAkhir(StackMahasiswa &StackMHS);

#endif