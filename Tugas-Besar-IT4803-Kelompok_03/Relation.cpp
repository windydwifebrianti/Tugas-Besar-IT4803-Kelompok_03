#include "Relation.h"
#include <iostream>
using namespace std;

void createListRelasi(list_Relasi &L) {
    L.first = nullptr;
}

adr_Relasi newRelasi(adr_Dokter Dokter, adr_Pasien Pasien) {
    adr_Relasi R = new elm_Relasi;
    R->nextD = Dokter;
    R->nextP = Pasien;
    R->next = nullptr;
    return R;
}

void insertRelasi(list_Relasi &L, adr_Dokter Dokter, adr_Pasien Pasien) {
    adr_Relasi R = newRelasi(Dokter, Pasien);
    if (L.first == nullptr) {
        L.first = R;
    } else {
        adr_Relasi Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = R;
    }
}

void deleteRelasi(list_Relasi &L, string ID_Dokter, string ID_Pasien) {
    adr_Relasi R = findRelasi(L, ID_Dokter, ID_Pasien);
    if (R != nullptr) {
        if (R == L.first) {
            L.first = R->next;
        } else {
            adr_Relasi Q = L.first;
            while (Q->next != R) {
                Q = Q->next;
            }
            Q->next = R->next;
        }
        delete R;
    }
}

adr_Relasi findRelasi(list_Relasi L, string ID_Dokter, string ID_Pasien) {
    adr_Relasi R = L.first;
    while (R != nullptr) {
        if (R->nextD->infoD.ID_Dokter == ID_Dokter && R->nextP->infoP.ID_Pasien == ID_Pasien) {
            return R;
        }
        R = R->next;
    }
    return nullptr;
}

void editRelasi(list_Relasi &L, string ID_Pasien, string new_ID_Dokter) {
    adr_Relasi R = L.first;
    while (R != nullptr) {
        if (R->nextP->infoP.ID_Pasien == ID_Pasien) {
            R->nextD->infoD.ID_Dokter = new_ID_Dokter;
        }
        R = R->next;
    }
}
