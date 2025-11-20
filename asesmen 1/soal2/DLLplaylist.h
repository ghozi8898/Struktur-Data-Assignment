#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <iostream>
#include <string>
using namespace std;

struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating;
};

struct Node {
    Song info;
    Node* prev;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
};

// === PROTOTYPE FUNGSI/PROSEDUR ===
bool isEmpty(List L);
void createList(List &L);
Node* allocate(Song S);
void deallocate(Node* P);

void insertFirst(List &L, Song S);
void insertLast(List &L, Song S);
void insertAfter(List &L, Node* Q, Song S);
void insertBefore(List &L, Node* Q, Song S);

void deleteFirst(List &L, Song &S);
void deleteLast(List &L, Song &S);
void deleteAfter(List &L, Node* Q, Song &S);
void deleteBefore(List &L, Node* Q, Song &S);

void updateAtPosition(List &L, int posisi);
void updateBefore(List &L, Node* Q);

float getPopularityScore(Song S);
void viewList(List L);
void searchByPopularityRange(List L, float minScore, float maxScore);

#endif