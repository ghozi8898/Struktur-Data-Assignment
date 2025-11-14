#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3], C[3][3];
    int i, j, k;

    cout << "Masukkan elemen matriks A (3x3):\n";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Masukkan elemen matriks B (3x3):\n";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            cin >> B[i][j];
        }
    }

    cout << "\nPenjumlahan :\n";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nPengurangan :\n";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nPerkalian :\n";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            C[i][j] = 0;
            for(k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
