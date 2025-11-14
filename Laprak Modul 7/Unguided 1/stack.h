#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX_STACK = 20;
typedef int infotype;

struct Stack {
    infotype info[MAX_STACK];
    int top;
};

void createStack(Stack &S);
void Push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);

#endif /
