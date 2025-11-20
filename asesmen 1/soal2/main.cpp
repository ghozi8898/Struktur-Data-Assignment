#include "DLLplaylist.h"

Node* getNodeAt(List L, int posisi) {
    Node* P = L.head;
    int idx = 1;
    while (P != NULL && idx < posisi) {
        P = P->next;
        idx++;
    }
    return P;
}

int main() {
    List L;
    createList(L);

    // Data lagu
    Song S1 = {"Senja di Kota", "Nona Band", 210, 150, 4.2};
    Song S2 = {"Langkahmu", "Delta", 185, 320, 4.8};
    Song S3 = {"Hujan Minggu", "Arka", 240, 90, 3.9};

    insertLast(L, S1);
    insertLast(L, S2);
    insertLast(L, S3);

    viewList(L);

    // Delete Last
    Song temp;
    deleteLast(L, temp);

    // Update posisi 2
    cout << "\n=== UPDATE POSISI 2 ===\n";
    cin.ignore(); // untuk menghapus newline
    Song dummy;
    updateAtPosition(L, 2);

    viewList(L);

    // InsertBefore posisi 2
    cout << "\n=== INSERT BEFORE POSISI 2 ===\n";
    Song Snew = {"Senandung", "Mira", 175, 120, 4.0};

    Node* pos2 = getNodeAt(L, 2);
    insertBefore(L, pos2, Snew);

    viewList(L);

    // updateBefore posisi 2
    cout << "\n=== UPDATE BEFORE POSISI 2 ===\n";
    updateBefore(L, pos2);

    viewList(L);

    // deleteBefore posisi 3
    cout << "\n=== DELETE BEFORE POSISI 3 ===\n";
    Node* pos3 = getNodeAt(L, 3);
    deleteBefore(L, pos3, temp);

    viewList(L);

    // SEARCH Popularity Range
    cout << "\n=== SEARCH (150 - 300) ===\n";
    searchByPopularityRange(L, 150.0, 300.0);

    return 0;
}