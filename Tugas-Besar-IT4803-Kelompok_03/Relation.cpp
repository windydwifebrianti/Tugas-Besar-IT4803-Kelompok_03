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

//SHOW//

void ShowPasien_from_Dokter(list_Relasi L, string ID_Dokter) {
    adr_Relasi R = L.first;
    cout << "Pasien dari Dokter " << ID_Dokter << ":\n";

    bool found = false;
    while (R != nullptr) {
        if (R->nextD->infoD.ID_Dokter == ID_Dokter) {
            cout << "- " << R->nextP->infoP.namaP
                 << " (" << R->nextP->infoP.ID_Pasien << ")\n";
            found = true;
        }
        R = R->next;
    }

    if (!found) cout << "(Tidak ada pasien)\n";
}

void ShowDokter_from_Pasien(list_Relasi L, string ID_Pasien) {
    adr_Relasi R = L.first;
    cout << "Dokter untuk Pasien " << ID_Pasien << ":\n";

    bool found = false;
    while (R != nullptr) {
        if (R->nextP->infoP.ID_Pasien == ID_Pasien) {
            cout << "- " << R->nextD->infoD.namaD
                 << " (" << R->nextD->infoD.ID_Dokter << ")\n";
            found = true;
        }
        R = R->next;
    }

    if (!found) cout << "(Tidak punya dokter)\n";
}

void ShowRelasiDokter_to_Pasien(list_Relasi L) {
    adr_Relasi R = L.first;
    cout << "List Relasi Dokter → Pasien:\n";

    while (R != nullptr) {
        cout << R->nextD->infoD.namaD
             << " → "
             << R->nextP->infoP.namaP << endl;
        R = R->next;
    }
}

void ShowRelasiPasien_to_Dokter(list_Relasi L) {
    adr_Relasi R = L.first;
    cout << "List Relasi Pasien → Dokter:\n";

    while (R != nullptr) {
        cout << R->nextP->infoP.namaP
             << " ← "
             << R->nextD->infoD.namaD << endl;
        R = R->next;
    }
}

//COUNT//

int jumPasien_to_Dokter(list_Relasi L, string ID_Dokter) {
    adr_Relasi R = L.first;
    int count = 0;

    while (R != nullptr) {
        if (R->nextD->infoD.ID_Dokter == ID_Dokter) {
            count++;
        }
        R = R->next;
    }
    return count;
}

int jumDokter_HasPasien(list_Relasi L) {
    adr_Relasi R = L.first;
    int count = 0;

    // hitung unique dokter
    while (R != nullptr) {
        string currentDokter = R->nextD->infoD.ID_Dokter;

        adr_Relasi temp = L.first;
        bool foundBefore = false;
        while (temp != R) {
            if (temp->nextD->infoD.ID_Dokter == currentDokter) {
                foundBefore = true;
                break;
            }
            temp = temp->next;
        }

        if (!foundBefore) count++;
        R = R->next;
    }
    return count;
}

int Pasien_doesntHaveDokter(list_Relasi L, list_Pasien pasienList) {
    adr_Pasien P = pasienList.firstP;
    int count = 0;

    while (P != nullptr) {
        bool has = false;
        adr_Relasi R = L.first;

        while (R != nullptr) {
            if (R->nextP->infoP.ID_Pasien == P->infoP.ID_Pasien) {
                has = true;
                break;
            }
            R = R->next;
        }

        if (!has) count++;
        P = P->nextP;
    }
    return count;
}

int Dokter_doesntHavePasien(list_Relasi L, list_Dokter dokterList) {
    adr_Dokter D = dokterList.firstD;
    int count = 0;

    while (D != nullptr) {
        bool has = false;
        adr_Relasi R = L.first;

        while (R != nullptr) {
            if (R->nextD->infoD.ID_Dokter == D->infoD.ID_Dokter) {
                has = true;
                break;
            }
            R = R->next;
        }

        if (!has) count++;
        D = D->nextD;
    }
    return count;
}
