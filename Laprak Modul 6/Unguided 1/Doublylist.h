#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>

using namespace std;

struct infotype {
    string nopol;
    string warna;
    int thnBuat;
};

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(const infotype &x);
void dealokasi(address &P);

address findElm(List L, infotype x);
bool isNopolExist(const List &L, const string &nopol);

void insertLast(List &L, address P);
void printInfo(const List &L);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

bool deleteByNopol(List &L, const string &nopol);

#endif
