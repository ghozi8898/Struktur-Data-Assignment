#include "stack.h"

void createStack(Stack &S) {
    S.top = 0;
}

void Push(Stack &S, infotype x) {
    if (S.top >= MAX_STACK) {
        cerr << "Stack overflow: tidak bisa push, stack penuh\n";
        return;
    }
    S.info[S.top++] = x;
}

void pushAscending(Stack &S, infotype x) {
    if (S.top >= MAX_STACK) {
        cerr << "Stack overflow: tidak bisa pushAscending, stack penuh\n";
        return;
    }
    int i = S.top - 1;
    while (i >= 0 && S.info[i] > x) {
        S.info[i + 1] = S.info[i];
        --i;
    }
    S.info[i + 1] = x;
    S.top++;
}

infotype pop(Stack &S) {
    if (S.top <= 0) {
        cerr << "Stack underflow: tidak ada elemen untuk di-pop\n";
        return -1;
    }
    S.top--;
    return S.info[S.top];
}

void printInfo(const Stack &S) {
    cout << "[TOP] ";
    if (S.top == 0) {
        cout << "(kosong)";
    } else {
        for (int i = S.top - 1; i >= 0; --i) {
            cout << S.info[i];
            if (i > 0) cout << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    int i = 0, j = S.top - 1;
    while (i < j) {
        infotype tmp = S.info[i];
        S.info[i] = S.info[j];
        S.info[j] = tmp;
        ++i; --j;
    }
}
