#include <iostream>
#include "queue.h"
using namespace std;

void CreateQueue2(Queue2 &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpty2(const Queue2 &Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull2(const Queue2 &Q) {
    return (Q.tail == MAXQ - 1);
}

void enqueue2(Queue2 &Q, infotype X) {
    if (isFull2(Q)) return;
    if (isEmpty2(Q)) Q.head = Q.tail = 0;
    else Q.tail++;
    Q.info[Q.tail] = X;
}

infotype dequeue2(Queue2 &Q) {
    if (isEmpty2(Q)) return -1;
    infotype val = Q.info[Q.head];
    Q.head++;
    if (Q.head > Q.tail) Q.head = Q.tail = -1;
    return val;
}

void printInfo2(const Queue2 &Q) {
    if (isEmpty2(Q)) {
        cout << "-1 - -1 \t| empty queue" << endl;
        return;
    }
    cout << Q.head << " - " << Q.tail << " \t| ";
    for (int i = Q.head; i <= Q.tail; ++i) {
        cout << Q.info[i];
        if (i < Q.tail) cout << " ";
    }
    cout << endl;
}