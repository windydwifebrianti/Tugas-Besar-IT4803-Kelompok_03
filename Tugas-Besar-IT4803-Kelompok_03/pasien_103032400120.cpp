#include "Pasien.h"
#include <iostream>
using namespace std;

adr_Pasien newPasien(infotype_Pasien x){
    adr_Pasien P = new elm_Pasien;
    P->infoP = x;
    P->nextP = nullptr;
    P->prevP = nullptr;
    return P;
}

void insert_first_Pasien(list_Pasien &L, adr_Pasien P){
    if (L.firstP == nullptr) {
        L.firstP = P;
        L.lastP = P;
    } else {
        P->nextP = L.firstP;
        L.firstP->prevP = P;
        L.firstP = P;
    }
}

void delete_first_Pasien(list_Pasien &L, adr_Pasien &P){
     if (L.firstP == nullptr) {
        P = nullptr;
    } else {
        P = L.firstP;
        L.firstP = L.firstP->nextP;
        if (L.firstP != nullptr) {
            L.firstP->prevP = nullptr;
        } else {
            L.lastP = nullptr;
        }
        P->nextP = nullptr;
        P->prevP = nullptr;
    }
}

void delete_after_Pasien(list_Pasien &L, adr_Pasien Prec, adr_Pasien &P){
    if (Prec != nullptr && Prec->nextP != nullptr) {
        P = Prec->nextP;
        Prec->nextP = P->nextP;
        if (P->nextP != nullptr) {
            P->nextP->prevP = Prec;
        } else {
            L.lastP = Prec;
        }
        P->nextP = nullptr;
        P->prevP = nullptr;
    } else {
        P = nullptr;
    }
}

adr_Pasien findPasien(list_Pasien L, string idPasien, string keluhan){
    adr_Pasien P = L.firstP;
    while (P != nullptr) {
        if (P->infoP.ID_Pasien == idPasien && P->infoP.keluhan == keluhan) {
            return P;
        }
        P = P->nextP;
    }
    return nullptr;
}
