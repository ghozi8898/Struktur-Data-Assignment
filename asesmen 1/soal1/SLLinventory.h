#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H

#include <string>
using namespace std;

struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;
};

struct Node;
typedef Node* address;

struct Node {
    Product info;
    address next;
};

struct List {
    address head;
};

bool isEmpty(const List &L);
void createList(List &L);
address allocate(const Product &P);
void deallocate(address addr);

void insertFirst(List &L, const Product &P);
void insertLast(List &L, const Product &P);
void insertAfter(List &L, address Q, const Product &P); // insert after node Q

void deleteFirst(List &L, Product &P);
void deleteLast(List &L, Product &P);
void deleteAfter(List &L, address Q, Product &P);

// Update by replacing the whole Product at position
bool updateAtPosition(List &L, int posisi, const Product &P); // returns true if updated
bool updateAtPositionInteractive(List &L, int posisi); // prompts user for product

void viewList(const List &L);
void searchByFinalPriceRange(const List &L, float minPrice, float maxPrice);

// Additional
void MaxHargaAkhir(const List &L);

#endif