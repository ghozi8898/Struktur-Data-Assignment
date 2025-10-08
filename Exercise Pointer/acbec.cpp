#include <iostream>
using namespace std;

struct saham{
    string nama_emiten;
    saham *next;
}*first,*last,*current;

int main() {
    current = new saham;
    current->nama_emiten = "AXI0";
    first=current;
    last=current;

    current = new saham;
    current->nama_emiten = "TLKM";
    last->next=current;
    last=current;

    current = new saham;
    current ->nama_emiten = "PIBA";
    last->next=current;
    last=current;

    current = new saham;
    current ->nama_emiten = "MDF";
    last ->next=current;
    last=current;

    current ->next=NULL;
    last->next=NULL;

    current = first;

    while(current!=NULL){
        cout << current->nama_emiten << endl;
        current=current->next;
    }
}