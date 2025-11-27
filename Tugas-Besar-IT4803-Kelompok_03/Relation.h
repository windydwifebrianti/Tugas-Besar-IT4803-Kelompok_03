#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

#include <iostream>

using namespace std;

struct Dokter;
typedef struct elm_Dokter *adr_Dokter;
struct Pasien;
typedef struct elm_Pasien *adr_Pasien;

typedef struct elm_Relasi *adr_Relasi;

struct elm_Relasi
{
    adr_Dokter nextD;
    adr_Pasien nextP;
    adr_Relasi next;
    adr_Relasi prev; 
};

struct list_Relasi
{
    adr_Relasi first;
    adr_Relasi last;
};

void createListRelasi(list_Relasi &L);
adr_Relasi newRelasi(adr_Dokter Dokter, adr_Pasien Pasien);

void ShowPasien_from_Dokter(list_Relasi L, string ID_Dokter);
void ShowDokter_from_Pasien(list_Relasi L, string ID_Pasien);
void ShowRelasiDokter_to_Pasien(list_Relasi L);
void ShowRelasiPasien_to_Dokter(list_Relasi L);

void insertRelasi(list_Relasi &L, adr_Dokter Dokter, adr_Pasien Pasien);
void deleteRelasi(list_Relasi &L, string ID_Dokter, string ID_Pasien);
adr_Relasi findRelasi(list_Relasi L, string ID_Dokter, string ID_Pasien);
void editRelasi(list_Relasi &L, string ID_Pasien, string new_ID_Dokter);

int jumPasien_to_Dokter(list_Relasi L, string ID_Dokter);
int jumDokter_HasPasien(list_Relasi L);
int Pasien_doesntHaveDokter(list_Relasi L, list_Pasien pasienList);
int Dokter_doesntHavePasien(list_Relasi L, list_Dokter dokterList);

#endif // RELATION_H_INCLUDED
