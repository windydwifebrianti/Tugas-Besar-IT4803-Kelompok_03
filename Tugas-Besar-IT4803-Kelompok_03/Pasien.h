#ifndef PASIEN_H_INCLUDED
#define PASIEN_H_INCLUDED

#include "Relation.h"
#include <iostream>
using namespace std;

struct Pasien
{
   string namaP;
   string ID_Pasien;
   string keluhan;
};

typedef struct elm_Pasien *adr_Pasien;

struct elm_Pasien {
    Pasien info;
    adr_Pasien next;
    adr_Pasien prev;
};

struct list_Pasien
{
    adr_Pasien first;
    adr_Pasien last;
};

void createListPasien(list_Pasien &L);
adr_Pasien newPasien(Pasien data);

void insert_first_Pasien(list_Pasien &L, adr_Pasien P);
void insert_last_Pasien(list_Pasien &L, adr_Pasien P);
void insert_after_Pasien(list_Pasien &L, adr_Pasien P);

void delete_first_Pasien(list_Pasien &pasienList, list_Relasi &relasiList, string idPasien);
void delete_last_Pasien(list_Pasien &pasienList, list_Relasi &relasiList, string idPasien);
void delete_after_Pasien(list_Pasien &pasienList, list_Relasi &relasiList, string idPasien)

adr_Pasien findPasien(list_Pasien L, string idPasien);
void showAllPasien(list_Pasien L);

#endif // PASIEN_H_INCLUDED
