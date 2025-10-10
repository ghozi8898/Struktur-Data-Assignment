#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;

};

void inputmhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif 
