#ifndef ALT2_QUEUE_H
#define ALT2_QUEUE_H

typedef int infotype;
const int MAXQ = 5;

struct Queue2 {
    infotype info[MAXQ];
    int head;
    int tail;
};

void CreateQueue2(Queue2 &Q);
bool isEmpty2(const Queue2 &Q);
bool isFull2(const Queue2 &Q);
void enqueue2(Queue2 &Q, infotype X);
infotype dequeue2(Queue2 &Q);
void printInfo2(const Queue2 &Q);

#endif