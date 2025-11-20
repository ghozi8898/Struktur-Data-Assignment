#include <iostream>
#include "StackMahasiswa.h"
using namespace std;

int main() {
    StackMahasiswa stack;
    createStack(stack);

    // Push data mahasiswa sesuai soal
    cout << "Memasukkan data mahasiswa..." << endl;
    Mahasiswa mhs[] = {
        {"Venti", "11111", 75.7, 82.1, 65.5},
        {"Xiao", "22222", 87.4, 88.9, 81.9},
        {"Kazuha", "33333", 92.3, 88.8, 82.4},
        {"Wanderer", "44444", 95.5, 85.5, 90.5},
        {"Lynette", "55555", 77.7, 65.4, 79.9},
        {"Chasca", "66666", 99.9, 93.6, 87.3}
    };

    for (int i = 0; i < 6; i++) {
        if (!isFull(stack)) {
            stack.Top++;
            stack.dataMahasiswa[stack.Top] = mhs[i];
        }
    }

    // Tampilkan stack
    View(stack);

    // Pop 1x
    cout << "\nMelakukan Pop 1x..." << endl;
    Pop(stack);
    View(stack);

    // Update posisi 3
    cout << "\nUpdate data posisi 3..." << endl;
    Update(stack, 3);
    View(stack);

    // Searching nilai akhir 85.5 - 95.5
    cout << "\nSearching nilai akhir 85.5 - 95.5..." << endl;
    SearchNilaiAkhir(stack, 85.5, 95.5);

    // Tambahan Bagian B: MaxNilaiAkhir
    MaxNilaiAkhir(stack);

    return 0;
}