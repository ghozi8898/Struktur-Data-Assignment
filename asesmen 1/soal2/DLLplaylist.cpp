#include "DLLplaylist.h"

// Mengecek apakah list kosong
bool isEmpty(List L) {
    return (L.head == NULL && L.tail == NULL);
}

// Membuat list kosong
void createList(List &L) {
    L.head = NULL;
    L.tail = NULL;
}

// Alokasi node baru
Node* allocate(Song S) {
    Node* P = new Node;
    P->info = S;
    P->prev = NULL;
    P->next = NULL;
    return P;
}

// Dealokasi node
void deallocate(Node* P) {
    delete P;
}

// INSERT FIRST
void insertFirst(List &L, Song S) {
    Node* P = allocate(S);
    if (isEmpty(L)) {
        L.head = P;
        L.tail = P;
    } else {
        P->next = L.head;
        L.head->prev = P;
        L.head = P;
    }
}

// INSERT LAST
void insertLast(List &L, Song S) {
    Node* P = allocate(S);
    if (isEmpty(L)) {
        L.head = P;
        L.tail = P;
    } else {
        L.tail->next = P;
        P->prev = L.tail;
        L.tail = P;
    }
}

// INSERT AFTER NODE Q
void insertAfter(List &L, Node* Q, Song S) {
    if (Q != NULL) {
        Node* P = allocate(S);
        P->next = Q->next;
        P->prev = Q;
        if (Q->next != NULL) {
            Q->next->prev = P;
        } else {
            L.tail = P;
        }
        Q->next = P;
    }
}

// INSERT BEFORE NODE Q
void insertBefore(List &L, Node* Q, Song S) {
    if (Q != NULL) {
        if (Q == L.head) {
            insertFirst(L, S);
        } else {
            Node* P = allocate(S);
            P->next = Q;
            P->prev = Q->prev;
            Q->prev->next = P;
            Q->prev = P;
        }
    }
}

// DELETE FIRST
void deleteFirst(List &L, Song &S) {
    if (!isEmpty(L)) {
        Node* P = L.head;
        S = P->info;

        if (L.head == L.tail) {
            L.head = NULL;
            L.tail = NULL;
        } else {
            L.head = L.head->next;
            L.head->prev = NULL;
        }

        deallocate(P);
    }
}

// DELETE LAST
void deleteLast(List &L, Song &S) {
    if (!isEmpty(L)) {
        Node* P = L.tail;
        S = P->info;

        if (L.head == L.tail) {
            L.head = NULL;
            L.tail = NULL;
        } else {
            L.tail = L.tail->prev;
            L.tail->next = NULL;
        }

        deallocate(P);
    }
}

// DELETE AFTER Q
void deleteAfter(List &L, Node* Q, Song &S) {
    if (Q != NULL && Q->next != NULL) {
        Node* P = Q->next;
        S = P->info;

        Q->next = P->next;
        if (P->next != NULL) {
            P->next->prev = Q;
        } else {
            L.tail = Q;
        }

        deallocate(P);
    }
}

// DELETE BEFORE Q
void deleteBefore(List &L, Node* Q, Song &S) {
    if (Q != NULL && Q->prev != NULL) {
        Node* P = Q->prev;
        S = P->info;

        if (P->prev != NULL) {
            P->prev->next = Q;
            Q->prev = P->prev;
        } else {
            L.head = Q;
            Q->prev = NULL;
        }

        deallocate(P);
    }
}

// UPDATE AT POSITION (INPUT DATA BARU)
void updateAtPosition(List &L, int posisi) {
    Node* P = L.head;
    int idx = 1;

    while (P != NULL && idx < posisi) {
        P = P->next;
        idx++;
    }

    if (P != NULL) {
        Song S;
        cout << "Masukkan Title baru: ";
        getline(cin, S.Title);
        cout << "Masukkan Artist baru: ";
        getline(cin, S.Artist);
        cout << "Masukkan Duration: ";
        cin >> S.DurationSec;
        cout << "Masukkan PlayCount: ";
        cin >> S.PlayCount;
        cout << "Masukkan Rating: ";
        cin >> S.Rating;
        cin.ignore();

        P->info = S;
    }
}

// UPDATE BEFORE Q
void updateBefore(List &L, Node* Q) {
    if (Q != NULL && Q->prev != NULL) {
        Node* P = Q->prev;
        Song S;

        cout << "Masukkan Title baru: ";
        getline(cin, S.Title);
        cout << "Masukkan Artist baru: ";
        getline(cin, S.Artist);
        cout << "Masukkan Duration: ";
        cin >> S.DurationSec;
        cout << "Masukkan PlayCount: ";
        cin >> S.PlayCount;
        cout << "Masukkan Rating: ";
        cin >> S.Rating;
        cin.ignore();

        P->info = S;
    }
}

// PopularityScore
float getPopularityScore(Song S) {
    return 0.8 * S.PlayCount + 20.0 * S.Rating;
}

// VIEW LIST
void viewList(List L) {
    Node* P = L.head;
    int pos = 1;

    cout << "\n=== PLAYLIST ===\n";
    while (P != NULL) {
        cout << pos << ". " << P->info.Title << " | "
             << P->info.Artist << " | Dur: " << P->info.DurationSec
             << " | Play: " << P->info.PlayCount
             << " | Rating: " << P->info.Rating
             << " | Popularity: " << getPopularityScore(P->info)
             << endl;

        P = P->next;
        pos++;
    }
}

// SEARCH Popularity Range
void searchByPopularityRange(List L, float minScore, float maxScore) {
    Node* P = L.head;
    int pos = 1;

    cout << "\n=== HASIL SEARCH ===\n";

    while (P != NULL) {
        float score = getPopularityScore(P->info);
        if (score >= minScore && score <= maxScore) {
            cout << pos << ". " << P->info.Title 
                 << " | Popularity: " << score << endl;
        }
        P = P->next;
        pos++;
    }
}