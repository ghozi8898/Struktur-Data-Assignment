#include <iostream>
#include "queue.h"
using namespace std;

const int MAX = 5;

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
    for (int i = 0; i < MAX; i++) Q.info[i] = -1;
}

bool isEmptyQueue(const Queue &Q) {
    return (Q.head == -1);
}

bool isFullQueue(const Queue &Q) {
    return (!isEmptyQueue(Q) && ((Q.tail + 1) % MAX == Q.head));
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) return;

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
        Q.info[0] = x;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) return -1;

    infotype x = Q.info[Q.head];
    Q.info[Q.head] = -1;

    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX;
    }

    return x;
}

void printInfo(const Queue &Q) {
    cout << Q.head << " - " << Q.tail << "\t| ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
        return;
    }

    for (int i = 0; i < MAX; i++) {
        if (Q.info[i] == -1) cout << "- ";
        else cout << Q.info[i] << " ";
    }
    cout << "\n";
}
