#include <iostream>
#include "Pasien.h"

using namespace std;

void createListPasien(list_Pasien &L) {
    L.firstP = nullptr;
    L.lastP = nullptr;
}

void insert_last_Pasien(list_Pasien &L, adr_Pasien P) {
  if (L.firstP == nullptr && L.lastP == nullptr) {
    L.firstP = P;
    L.lastP = P;
  } else {
    L.lastP -> nextP = P;
    P -> prevP = L.lastP;
    L.lastP = P;
  }
}

void insert_after_Pasien(list_Pasien &L, adr_Pasien Prec, adr_Pasien P) {
  if (Prec == nullptr) {
    cout << "Node Prec tidak ditemukan, tidak bisa insert after null." << endl;
    return;
  }

  if (Prec == L.lastP) {
    P -> nextP = nullptr;
    P -> prevP = Prec;
    Prec -> nextP = P;
    L.lastP = P;
  } else {
    P -> nextP = Prec -> nextP;
    P -> prevP = Prec;
    Prec -> nextP = P;
    P -> nextP -> prevP = P;
  }
}

void delete_last_Pasien(list_Pasien &L, adr_Pasien &P){
    if (L.firstP == nullptr && L.lastP == nullptr) {
      P = nullptr; // List kosong, tidak ada yang dihapus
      cout << "List kosong" << endl;
    } else if (L.firstP == L.lastP) {
        P = L.firstP;
        L.firstP = nullptr;
        L.lastP = nullptr;
    } else {
        P = L.lastP;
        L.lastP = P -> prevP;
        L.lastP -> nextP = nullptr;
        P -> prevP = nullptr;
    }
}

void showAllPasien(list_Pasien L){
    adr_Pasien P = L.firstP;
    while (P != nullptr) {
        cout << "Nama Pasien: " << P -> info.namaP << endl;
        cout << "ID Pasien: " << P -> info.ID_Pasien << endl;
        cout << "Keluhan: " << P -> info.keluhan << endl;
        cout << "------------------------" << endl;
        P = P -> nextP;
    }
}

