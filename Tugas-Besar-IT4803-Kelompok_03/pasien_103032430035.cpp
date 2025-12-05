#include <iostream>
#include "Pasien.h"

using namespace std;

void createListPasien(list_Pasien &L) {
    L.first = nullptr;
    L.last = nullptr;
}

void insert_last_Pasien(list_Pasien &L, adr_Pasien P) {
  if (L.first == nullptr && L.last == nullptr) {
    L.first = P;
    L.last = P;
  } else {
    L.last -> next = P;
    P -> prev = L.last;
    L.last = P;
  }
}

void insert_after_Pasien(list_Pasien &L, adr_Pasien Prec, adr_Pasien P) {
  if (Prec == nullptr) {
    cout << "Node Prec tidak ditemukan, tidak bisa insert after null." << endl;
    return;
  }

  if (Prec == L.last) {
    P -> next = nullptr;
    P -> prev = Prec;
    Prec -> next = P;
    L.last = P;
  } else {
    P -> next = Prec -> next;
    P -> prev = Prec;
    Prec -> next = P;
    P -> next -> prev = P;
  }
}

void delete_last_Pasien(list_Pasien &L, adr_Pasien &P){
    if (L.first == nullptr && L.last == nullptr) {
      P = nullptr; // List kosong, tidak ada yang dihapus
      cout << "List kosong" << endl;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        P = L.last;
        L.last = P -> prev;
        L.last -> next = nullptr;
        P -> prev = nullptr;
    }
}

void showAllPasien(list_Pasien L){
    adr_Pasien P = L.first;
    while (P != nullptr) {
        cout << "Nama Pasien: " << P -> info.namaP << endl;
        cout << "ID Pasien: " << P -> info.ID_Pasien << endl;
        cout << "Keluhan: " << P -> info.keluhan << endl;
        cout << "------------------------" << endl;
        P = P -> next;
    }
}
