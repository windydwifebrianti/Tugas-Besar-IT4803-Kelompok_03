#include "Relation.h"
#include <iostream>
using namespace std;

void createListRelasi(list_Relasi &L) {
    L.first = nullptr;
}

adr_Relasi newRelasi(adr_Dokter Dokter, adr_Pasien Pasien) {
    adr_Relasi p = new elm_Relasi;
    p->nextD = Dokter;
    p->nextP = Pasien;
    p->next = nullptr;
    return p;
}

void insertRelasi(list_Relasi &L, adr_Relasi p) {
    /*
    I.S : List relasi mungkin kosong
    F.S : Relasi baru ditambahkan ke akhir list
    */

    if(L.first == nullptr){
        L.first = p;
    } else {
        adr_Relasi q = L.first;
        while(q->next != nullptr){
            q = q->next;
        }
        q->next = p;
    }
}

void deleteFirstRelasi(list_Relasi &L, adr_Relasi &p){
    /*
    I.S : List relasi L tidak kosong

    F.S : Elemen relasi pertama dihapus dari List, address elemen yang dihapus disimpan di p
    */

    p = L.first;
    L.first = p->next;
    p->next = nullptr;
}

void deleteAfterRelasi(list_Relasi &L, adr_Relasi prec, adr_Relasi &p){
    /*
    I.S : List relasi L terdefinisi
    F.S : Elemen relasi setelah prec dilepas dari list dan address-nya disimpan ke p.
    */

    p = prec->next;
    prec->next = p->next;
    p->next = nullptr;
}

void deleteLastRelasi(list_Relasi &L, adr_Relasi &p){
    /*
    I.S : List relasi L terdefinisi dan tidak kosong.
    F.S : Elemen relasi terakhir dilepas dari list dan address-nya disimpan ke p.
    */

    if (L.first->next == NULL) {
        p = L.first;
        L.first = NULL;
    } else {
        adr_Relasi q = L.first;
        while (q->next->next != NULL) {
            q = q->next;
        }
        p = q->next;
        q->next = NULL;
    }
}

void deleteRelasi(list_Relasi &L, adr_Relasi p){
    /*
    I.S : List relasi L terdefinisi dan elemen relasi p terdapat di dalam list.
    F.S : Elemen relasi p dihapus dari list dan memorinya dibebaskan.
    */

    adr_Relasi q;

    if (p == L.first) {
        deleteFirstRelasi(L, q);
    } else if (p->next == NULL) {
        deleteLastRelasi(L, q);
    } else {
        adr_Relasi prec = L.first;
        while (prec->next != p) {
            prec = prec->next;
        }
        deleteAfterRelasi(L, prec, q);
    }
    delete q;
}

void ShowPasien_from_Dokter(list_Relasi L, string ID_Dokter){
    /*
    I.S : List relasi L terdefinisi dan mungkin berisi data relasi.
    F.S : Seluruh pasien yang berelasi dengan dokter ber-ID ID_Dokter ditampilkan ke layar.
    */

    adr_Relasi p = L.first;
    while (p != nullptr) {
        if (p->nextD->info.ID_Dokter == ID_Dokter) {
            cout << "ID Pasien : "
                 << p->nextP->info.ID_Pasien << endl;
        }
        p = p->next;
    }
}

void ShowDokter_from_Pasien(list_Relasi L, string ID_Pasien){
    /*
    I.S : List relasi L terdefinisi dan mungkin berisi data relasi.
    F.S : Dokter yang berelasi dengan pasien ber-ID ID_Pasien ditampilkan ke layar.
    */

    adr_Relasi p = L.first;
    while (p != nullptr) {
        if (p->nextP->info.ID_Pasien == ID_Pasien) {
            cout << "ID Dokter : "
                 << p->nextD->info.ID_Dokter << endl;
        }
        p = p->next;
    }
}

void ShowRelasiDokter_to_Pasien(list_Relasi L){
   /*
    I.S : List relasi L terdefinisi.
    F.S : Seluruh relasi dokter ke pasien ditampilkan ke layar.
    */

    adr_Relasi p = L.first;
    while (p != nullptr) {
        cout << p->nextD->info.ID_Dokter
             << " -> "
             << p->nextP->info.ID_Pasien << endl;
        p = p->next;
    }
}

void ShowRelasiPasien_to_Dokter(list_Relasi L){
    /*
    I.S : List relasi L terdefinisi.
    F.S : Seluruh relasi pasien ke dokter ditampilkan ke layar.
    */

    adr_Relasi p = L.first;
    while (p != nullptr) {
        cout << p->nextP->info.ID_Pasien
             << " -> "
             << p->nextD->info.ID_Dokter << endl;
        p = p->next;
    }
}

adr_Relasi findElmRelasiByChild(list_Relasi L, adr_Pasien Pasien){
    /*
    I.S : List relasi L terdefinisi.
    F.S : Mengembalikan address elemen relasi yang memiliki pasien tertentu atau NIL jika tidak ditemukan.
    */

    adr_Relasi p = L.first;
    while (p != nullptr) {
        if (p->nextP == Pasien) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

adr_Relasi findElmRelasiByChild(list_Relasi L, adr_Dokter Dokter){
    /*
    I.S : List relasi L terdefinisi.
    F.S : Mengembalikan address elemen relasi yang memiliki dokter tertentu atau NIL jika tidak ditemukan.
    */

    adr_Relasi p = L.first;
    while (p != nullptr) {
        if (p->nextD == Dokter) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}


void editRelasi(list_Relasi &L, string ID_Pasien, string new_ID_Dokter){
    /*
    I.S : List relasi L terdefinisi dan terdapat relasi dengan pasien ber-ID ID_Pasien.
    F.S : Relasi pasien tersebut terhubung dengan dokter baru.
    */

    adr_Relasi p = L.first;
    while (p != nullptr) {
        if (p->nextP->info.ID_Pasien == ID_Pasien) {
            p->nextD = dokterBaru;
            return;
        }
        p = p->next;
    }
}


int jumPasien_to_Dokter(list_Relasi L, string ID_Dokter){
    /*
    I.S : List relasi L terdefinisi.
    F.S : Mengembalikan jumlah pasien yang berelasi dengan dokter ber-ID ID_Dokter.
    */

    int count = 0;
    adr_Relasi p = L.first;

    while (p != NULL) {
        if (p->nextD->info.ID_Dokter == ID_Dokter) {
            count++;
        }
        p = p->next;
    }
    return count;
}

int jumDokter_HasPasien(list_Relasi L){
    /*
    I.S : List relasi L terdefinisi.
    F.S : Mengembalikan jumlah dokter yang memiliki minimal satu pasien.
    */

    int count = 0;
    adr_Relasi p = L.first;

    while (p != nullptr) {
        bool found = false;
        adr_Relasi q = L.first;
        while (q != p) {
            if (q->nextD == p->nextD) {
                found = true;
                break;
            }
            q = q->next;
        }
        if (!found){
            count++;
        }
        p = p->next;
    }
    return count;

}

int Pasien_doesntHaveDokter(list_Relasi L, list_Pasien pasienList){
    /*
    I.S : List pasien dan list relasi terdefinisi.
    F.S : Mengembalikan jumlah pasien yang tidak memiliki relasi dengan dokter manapun.
    */

    int count = 0;
    adr_Pasien p = pasienList.first;

    while (p != nullptr) {
        bool found = false;
        adr_Relasi r = L.first;
        while (r != nullptr) {
            if (r->nextP == p) {
                found = true;
                break;
            }
            r = r->next;
        }
        if (!found){
            count++;
        }
        p = p->next;
    }
    return count;
}

int Dokter_doesntHavePasien(list_Relasi L, list_Dokter dokterList){
    /*
    I.S : List dokter dan list relasi terdefinisi.
    F.S : Mengembalikan jumlah dokter yang tidak memiliki relasi dengan pasien manapun.
    */

    int count = 0;
    adr_Dokter d = dokterList.first;

    while (d != NULL) {
        bool found = false;
        adr_Relasi r = L.first;
        while (r != NULL) {
            if (r->nextD == d) {
                found = true;
                break;
            }
            r = r->next;
        }
        if (!found){
            count++;
        }
        d = d->next;
    }
    return count;
}
