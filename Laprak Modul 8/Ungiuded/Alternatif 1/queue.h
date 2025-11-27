#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;
const int MAXQ = 5;

struct Queue {
    infotype info[MAXQ];
    int head;
    int tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(const Queue &Q);
bool isFullQueue(const Queue &Q);
void enqueue(Queue &Q, infotype X);
infotype dequeue(Queue &Q);
void printInfo(const Queue &Q);

#endif
