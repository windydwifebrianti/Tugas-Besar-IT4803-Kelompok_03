#include "Dokter.h"
#include <iostream>
using namespace std;

void createListDokter(list_Dokter &L){
    L.firstD = nullptr;
}

void insert_last_Dokter(list_Dokter &L, adr_Dokter P){
    if(L.firstD == nullptr){
        L.firstD = P;
    } else {
        adr_Dokter Q = L.firstD;
        while(Q->nextD != nullptr){
            Q = Q->nextD;
        }
        Q->nextD = P;
    }
}

void insert_after_Dokter(list_Dokter &L, adr_Dokter Prec, adr_Dokter P){
    P->nextD = Prec->nextD;
    Prec->nextD = P;
}

void delete_last_Dokter(list_Dokter &L, adr_Dokter &P){
    if (L.firstD == nullptr) {
        P = nullptr;
    } else if (L.firstD->nextD == nullptr) {
        P = L.firstD;
        L.firstD = nullptr;
    } else {
        adr_Dokter Q = L.firstD;
        while (Q->nextD->nextD != nullptr) {
            Q = Q->nextD;
        }
        P = Q->nextD;
        Q->nextD = nullptr;
    }
}

void showAllDokter(list_Dokter L){
    adr_Dokter P = L.firstD;
    if (P == nullptr) {
        cout << "List kosong" << endl;
    } else {
        while (P != nullptr) {
            cout << "Nama: " << P->infoD.namaD << endl;
            cout << "Spesialis: " << P->infoD.spesialis << endl;
            cout << "Jadwal: " << P->infoD.jadwalD << endl;
            cout << "ID: " << P->infoD.ID_Dokter << endl;
            cout << endl;
            P = P->nextD;
        }
    }
}
