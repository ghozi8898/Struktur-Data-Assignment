#include <iostream>
#include "queue.h"
using namespace std;

/* Create empty queue: use -1 to indicate empty (head = -1, tail = -1) */
void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(const Queue &Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(const Queue &Q) {
    return (Q.tail == MAXQ - 1);
}

/* Alternatif 1: HEAD tetap (we represent empty with head=-1),
   enqueue: append at tail (advance tail)
   dequeue: remove element at index 0 and shift elements left */
void enqueue(Queue &Q, infotype X) {
    if (isFullQueue(Q)) {
        // silently ignore (ke sesuai soal, tidak mencetak pesan ekstra)
        return;
    }
    if (isEmptyQueue(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = X;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        return -1;
    }
    infotype val = Q.info[0];
    // shift left
    for (int i = 0; i < Q.tail; ++i) {
        Q.info[i] = Q.info[i + 1];
    }
    Q.tail--;
    if (Q.tail < 0) {
        Q.head = Q.tail = -1; // become empty
    }
    return val;
}

/* Print in the exact simple format used in gambar */
void printInfo(const Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "-1 - -1 \t| empty queue" << endl;
        return;
    }
    cout << Q.head << " - " << Q.tail << " \t| ";
    for (int i = 0; i <= Q.tail; ++i) {
        cout << Q.info[i];
        if (i < Q.tail) cout << " ";
    }
    cout << endl;
}
