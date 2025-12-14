#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

#include <iostream>
#include "Dokter.h"
#include "Pasien.h"
using namespace std;

typedef struct elm_Relasi *adr_Relasi;

struct elm_Relasi{
    adr_Dokter nextD;
    adr_Pasien nextP;
    adr_Relasi next;
};

struct list_Relasi{
    adr_Relasi first;
};

void createListRelasi(list_Relasi &L);
adr_Relasi newRelasi(adr_Dokter Dokter, adr_Pasien Pasien);

void insertRelasi(list_Relasi &L, adr_Relasi p);

void deleteFirstRelasi(list_Relasi &L, adr_Relasi &p);
void deleteAfterRelasi(list_Relasi &L, adr_Relasi prec, adr_Relasi &p);
void deleteLastRelasi(list_Relasi &L, adr_Relasi &p);
void deleteRelasi(list_Relasi &L, adr_Relasi p);

void ShowPasien_from_Dokter(list_Relasi L, string ID_Dokter);
void ShowDokter_from_Pasien(list_Relasi L, string ID_Pasien);
void ShowRelasiDokter_to_Pasien(list_Relasi L);
void ShowRelasiPasien_to_Dokter(list_Relasi L);

adr_Relasi findElmRelasiByChild(list_Relasi L, adr_Pasien Pasien);
adr_Relasi findElmRelasiByChild(list_Relasi L, adr_Dokter Dokter);

void editRelasiDokter(list_Relasi &L, string ID_Pasien, adr_Dokter dokterBaru);

int jumPasien_to_Dokter(list_Relasi L, string ID_Dokter);
int jumDokter_HasPasien(list_Relasi L);
int Pasien_doesntHaveDokter(list_Relasi L, list_Pasien pasienList);
int Dokter_doesntHavePasien(list_Relasi L, list_Dokter dokterList);

#endif // RELATION_H_INCLUDED
