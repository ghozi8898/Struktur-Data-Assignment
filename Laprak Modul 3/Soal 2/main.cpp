#include <iostream>
#include <string>

using namespace std;

struct Pelajaran {
    string nama;
    string kode;
};

Pelajaran create_pelajaran(const string& nama, const string& kode) {
    return Pelajaran{nama, kode};
}

void tampil_pelajaran(const Pelajaran& p) {
    cout << "Nama: " << p.nama << "\nKode: " << p.kode << '\n';
}

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    auto pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
