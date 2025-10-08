#include <iostream>
using namespace std;

struct saham {
    int nama_emiten;
    saham *next;
}*first, *last, *next, *current;

int main() {
    current = new saham;
    current->nama_emiten = 45;
    first=current;
    last=current;

    current = new saham;
    current->nama_emiten= 55;
    last->next=current;
    last=current;

    current = new saham;
    current->nama_emiten= 60;
    last->next=current;
    last=current;

    current = new saham;
    current->nama_emiten= 70;
    last->next=current;
    last=current;

    
    current = new saham;
    current->nama_emiten= 90;
    last->next=current;
    last=current;
    
    current = new saham;
    current->nama_emiten= 100;
    last->next=current;
    last=current;
    
    current = new saham;
    current->nama_emiten= 120;
    last->next=current;
    last=current;

    current->next=NULL;
    last->next=NULL;

    current=first;

    while(current!=NULL) {
        cout<< current->nama_emiten << endl;
        current=current->next;
    }
}