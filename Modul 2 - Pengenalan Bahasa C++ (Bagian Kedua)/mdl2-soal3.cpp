#include <iostream>
using namespace std;

int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int cariMaksimum(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks) {
            maks = arr[i];
        }
    }
    return maks;
}

float hitungRataRata(int arr[], int n) {
    int jumlah = 0;
    for (int i = 0; i < n; i++) {
        jumlah += arr[i];
    }
    return (float)jumlah / n; 
}

int main() {
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = 10;
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata - rata\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
             case 1:
                cout << "ARRAY = {";
                for (int i = 0; i < n; i++) {
                    cout << arrA[i];
                    if (i < n - 1) cout << ", ";
                }
                cout << "}" << endl;
                break;
            case 2:
                cout << "Nilai maksimum: " << cariMaksimum(arrA, n) << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << cariMinimum(arrA, n) << endl;
                break;
            case 4:
                cout << "Nilai rata-rata: " << hitungRataRata(arrA, n) << endl;
                break;
            default:
                cout << "-";
        }
    } while (pilihan != 5);

    return 0;
}
