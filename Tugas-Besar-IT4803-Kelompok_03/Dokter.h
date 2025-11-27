#ifndef DOKTER_H_INCLUDED
#define DOKTER_H_INCLUDED

#include "Relation.h"
#include <iostream>
using namespace std;

struct Dokter {
    string namaD;
    string spesialis;
    string jadwalD;
    string ID_Dokter;
};

typedef struct elm_Dokter *adr_Dokter;

struct elm_Dokter {
    Dokter info;
    adr_Dokter next;
};

struct list_Dokter {
    adr_Dokter first;
};

void createListDokter(list_Dokter &L);
adr_Dokter newDokter(Dokter data);

void insert_first_Dokter(list_Dokter &L, adr_Dokter P);
void insert_last_Dokter(list_Dokter &L, adr_Dokter P);
void insert_after_Dokter(list_Dokter &L, adr_Dokter P);

void delete_first_Dokter(list_Dokter &dokterList, list_Relasi &relasiList, string idDokter);
void delete_last_Dokter(list_Dokter &dokterList, list_Relasi &relasiList, string idDokter);
void delete_after_Dokter(list_Dokter &dokterList, list_Relasi &relasiList, string idDokter);

adr_Dokter findDokter(list_Dokter L, string idDokter);
void showAllDokter(list_Dokter L);

#endif // DOKTER_H_INCLUDED
