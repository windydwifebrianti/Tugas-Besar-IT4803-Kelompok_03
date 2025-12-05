#ifndef PASIEN_H_INCLUDED
#define PASIEN_H_INCLUDED

#include <iostream>
using namespace std;

struct Pasien{
   string namaP;
   string ID_Pasien;
   string keluhan;
};

typedef Pasien infotype_Pasien;
typedef struct elm_Pasien *adr_Pasien;

struct elm_Pasien {
    infotype_Pasien infoP;
    adr_Pasien nextP;
    adr_Pasien prevP;
};

struct list_Pasien
{
    adr_Pasien firstP;
    adr_Pasien lastP;
};

void createListPasien(list_Pasien &L);
adr_Pasien newPasien(infotype_Pasien x);

void insert_first_Pasien(list_Pasien &L, adr_Pasien P);
void insert_last_Pasien(list_Pasien &L, adr_Pasien P);
void insert_after_Pasien(list_Pasien &L, adr_Pasien Prec, adr_Pasien P);

void delete_first_Pasien(list_Pasien &L, adr_Pasien &P);
void delete_last_Pasien(list_Pasien &L, adr_Pasien &P);
void delete_after_Pasien(list_Pasien &L, adr_Pasien Prec, adr_Pasien &P);

adr_Pasien findPasien(list_Pasien L, string idPasien, string keluhan);
void showAllPasien(list_Pasien L);

#endif // PASIEN_H_INCLUDED
