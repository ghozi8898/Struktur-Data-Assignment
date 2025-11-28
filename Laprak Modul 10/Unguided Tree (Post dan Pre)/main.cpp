#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    address root = Nil;
    int pilih, nilai;

    do {
        cout << "\n===== MENU BST =====\n";
        cout << "1. Insert Node\n";
        cout << "2. Tampilkan PreOrder\n";
        cout << "3. Tampilkan PostOrder\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilih;

        switch (pilih) {
        case 1:
            cout << "Masukkan nilai: ";
            cin >> nilai;
            insertNode(root, nilai);
            break;

        case 2:
            cout << "PreOrder : ";
            preOrder(root);
            cout << endl;
            break;

        case 3:
            cout << "PostOrder: ";
            postOrder(root);
            cout << endl;
            break;

        case 0:
            cout << "Keluar...\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilih != 0);

    return 0;
}
