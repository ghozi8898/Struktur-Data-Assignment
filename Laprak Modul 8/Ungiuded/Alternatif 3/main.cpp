#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    Queue Q;
    CreateQueue(Q);

    cout << "-----------------------------\n";
    cout << " H - T\t | Queue info\n";
    cout << "-----------------------------\n";
    printInfo(Q);

    enqueue(Q, 5);  printInfo(Q);
    enqueue(Q, 2);  printInfo(Q);
    enqueue(Q, 7);  printInfo(Q);
    enqueue(Q, 9);  printInfo(Q);
    enqueue(Q, 4);  printInfo(Q);   // penuh

    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);

    enqueue(Q, 8);  printInfo(Q);   // tail berputar
    enqueue(Q, 6);  printInfo(Q);   // tail berputar

    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);   // kembali empty

    return 0;
}
