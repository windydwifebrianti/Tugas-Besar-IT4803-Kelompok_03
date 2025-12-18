#include <iostream>
#include "main.h"
#include "Relation.h"
#include "Dokter.h"
#include "Pasien.h"
using namespace std;

list_Dokter LD;
list_Pasien LP;
list_Relasi LR;

void menuAdmin(){
    int option=-99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu Admin ==============" << endl;
        cout << "|| 1. Parent (Dokter)               ||" << endl;
        cout << "|| 2. Child (Pasien)                ||" << endl;
        cout << "|| 3. Relasi Dokter-Pasien          ||" << endl;
        cout << "|| 0. back                          ||" << endl;
        cout << "====================================== " << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
            case 1:
                menuParent();
                break;
            case 2:
                menuChild();
                break;
            case 3:
                menuRelasi();
                break;
        }
    }
}

void menuParent(){
    int option = -99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu Dokter ============\n";
        cout << "|| 1. Insert First Dokter          ||\n";
        cout << "|| 2. Insert Last Dokter           ||\n";
        cout << "|| 3. Insert After Dokter          ||\n";
        cout << "|| 4. Delete First Dokter          ||\n";
        cout << "|| 5. Delete Last Dokter           ||\n";
        cout << "|| 6. Delete After Dokter          ||\n";
        cout << "|| 7. Find Dokter                  ||\n";
        cout << "|| 8. Show All Dokter              ||\n";
        cout << "|| 0. Back                         ||\n";
        cout << "====================================\n";
        cout << "Choose your option : ";
        cin >> option;

        adr_Dokter P, Prec;
        infotype_Dokter x;
        string id, spesialis;

        switch(option) {
            case 1:
                cout << "ID Dokter     : "; cin >> x.ID_Dokter;
                cout << "Nama Dokter   : "; cin >> x.namaD;
                cout << "Spesialis     : "; cin >> x.spesialis;
                cout << "Jadwal        : "; cin >> x.jadwalD;
                insert_first_Dokter(LD, newDokter(x));
                break;

            case 2:
                cout << "ID Dokter     : "; cin >> x.ID_Dokter;
                cout << "Nama Dokter   : "; cin >> x.namaD;
                cout << "Spesialis     : "; cin >> x.spesialis;
                cout << "Jadwal        : "; cin >> x.jadwalD;
                insert_last_Dokter(LD, newDokter(x));
                break;

            case 3:
                cout << "ID Dokter Acuan : "; cin >> id;
                cout << "Spesialis       : "; cin >> spesialis;
                Prec = findDokter(LD, id, spesialis);
                if (Prec != nullptr) {
                    cout << "ID Dokter Baru : "; cin >> x.ID_Dokter;
                    cout << "Nama Dokter    : "; cin >> x.namaD;
                    cout << "Spesialis      : "; cin >> x.spesialis;
                    cout << "Jadwal         : "; cin >> x.jadwalD;
                    insert_after_Dokter(LD, Prec, newDokter(x));
                }
                break;

            case 4:
                delete_first_Dokter(LD, P);
                break;

            case 5:
                delete_last_Dokter(LD, P);
                break;

            case 6:
                cout << "ID Dokter Acuan : "; cin >> id;
                cout << "Spesialis       : "; cin >> spesialis;
                Prec = findDokter(LD, id, spesialis);
                delete_after_Dokter(LD, Prec, P);
                break;

            case 7:
                cout << "ID Dokter : "; cin >> id;
                cout << "Spesialis : "; cin >> spesialis;
                P = findDokter(LD, id, spesialis);
                if (P != nullptr)
                    cout << "Dokter ditemukan: " << P->infoD.namaD << endl;
                else
                    cout << "Dokter tidak ditemukan\n";
                system("pause");
                break;

            case 8:
                showAllDokter(LD);
                system("pause");
                break;
        }
    }
}


void menuChild(){
    int option = -99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu Pasien ============\n";
        cout << "|| 1. Insert First Pasien          ||\n";
        cout << "|| 2. Insert Last Pasien           ||\n";
        cout << "|| 3. Insert After Pasien          ||\n";
        cout << "|| 4. Delete First Pasien          ||\n";
        cout << "|| 5. Delete Last Pasien           ||\n";
        cout << "|| 6. Delete After Pasien          ||\n";
        cout << "|| 7. Find Pasien                  ||\n";
        cout << "|| 8. Show All Pasien              ||\n";
        cout << "|| 0. Back                         ||\n";
        cout << "====================================\n";
        cout << "Choose your option : ";
        cin >> option;

        adr_Pasien P, Prec;
        infotype_Pasien x;
        string id, keluhan;

        switch(option) {
            case 1:
                cout << "ID Pasien : "; cin >> x.ID_Pasien;
                cout << "Nama      : "; cin >> x.namaP;
                cout << "Keluhan   : "; cin >> x.keluhan;
                insert_first_Pasien(LP, newPasien(x));
                break;

            case 2:
                cout << "ID Pasien : "; cin >> x.ID_Pasien;
                cout << "Nama      : "; cin >> x.namaP;
                cout << "Keluhan   : "; cin >> x.keluhan;
                insert_last_Pasien(LP, newPasien(x));
                break;

            case 3:
                cout << "ID Pasien Acuan : "; cin >> id;
                cout << "Keluhan         : "; cin >> keluhan;
                Prec = findPasien(LP, id, keluhan);
                if (Prec != nullptr) {
                    cout << "ID Pasien Baru : "; cin >> x.ID_Pasien;
                    cout << "Nama           : "; cin >> x.namaP;
                    cout << "Keluhan        : "; cin >> x.keluhan;
                    insert_after_Pasien(LP, Prec, newPasien(x));
                }
                break;

            case 4:
                delete_first_Pasien(LP, P);
                break;

            case 5:
                delete_last_Pasien(LP, P);
                break;

            case 6:
                cout << "ID Pasien Acuan : "; cin >> id;
                cout << "Keluhan         : "; cin >> keluhan;
                Prec = findPasien(LP, id, keluhan);
                delete_after_Pasien(LP, Prec, P);
                break;

            case 7:
                cout << "ID Pasien : "; cin >> id;
                cout << "Keluhan   : "; cin >> keluhan;
                P = findPasien(LP, id, keluhan);
                if (P != nullptr)
                    cout << "Pasien ditemukan: " << P->infoP.namaP << endl;
                else
                    cout << "Pasien tidak ditemukan\n";
                system("pause");
                break;

            case 8:
                showAllPasien(LP);
                system("pause");
                break;
        }
    }
}

void menuRelasi(){
    int option = -99;
    string idDokter, spesialis;
    string idPasien, keluhan;

    adr_Dokter d;
    adr_Pasien p;
    adr_Relasi r;

    while(option != 0){
        system("cls");
        cout << "========= Menu Relasi =========\n";
        cout << "|| 1. Tambah Relasi          ||\n";
        cout << "|| 2. Hapus Relasi           ||\n";
        cout << "|| 3. Edit Pasien dari Dokter||\n";
        cout << "|| 4. Edit Dokter dari Pasien||\n";
        cout << "|| 0. Back                   ||\n";
        cout << "===============================\n";
        cout << "Choose your option : ";
        cin >> option;

        switch(option){

        // ===== INSERT RELASI =====
        case 1:
            cout << "ID Dokter   : "; cin >> idDokter;
            cout << "Spesialis   : "; cin >> spesialis;
            cout << "ID Pasien   : "; cin >> idPasien;
            cout << "Keluhan     : "; cin >> keluhan;

            d = findDokter(LD, idDokter, spesialis);
            p = findPasien(LP, idPasien, keluhan);

            if(d != nullptr && p != nullptr){
                r = newRelasi(d, p);
                insertRelasi(LR, r);
                cout << "Relasi berhasil ditambahkan\n";
            } else {
                cout << "Dokter atau Pasien tidak ditemukan\n";
            }
            system("pause");
            break;

        // ===== DELETE RELASI =====
        case 2:
            cout << "ID Dokter   : "; cin >> idDokter;
            cout << "Spesialis   : "; cin >> spesialis;
            cout << "ID Pasien   : "; cin >> idPasien;
            cout << "Keluhan     : "; cin >> keluhan;

            d = findDokter(LD, idDokter, spesialis);
            p = findPasien(LP, idPasien, keluhan);

            if(d != nullptr && p != nullptr){
                r = LR.first;
                while(r != nullptr){
                    if(r->nextD == d && r->nextP == p){
                        deleteRelasi(LR, r);
                        cout << "Relasi berhasil dihapus\n";
                        break;
                    }
                    r = r->next;
                }
            } else {
                cout << "Relasi tidak ditemukan\n";
            }
            system("pause");
            break;

        // ===== EDIT CHILD DARI PARENT =====
        case 3:
            cout << "ID Dokter        : "; cin >> idDokter;
            cout << "Spesialis        : "; cin >> spesialis;
            cout << "ID Pasien Baru   : "; cin >> idPasien;
            cout << "Keluhan Pasien   : "; cin >> keluhan;

            p = findPasien(LP, idPasien, keluhan);
            if(p != nullptr){
                EditChild_fromParent(LR, idDokter, p);
            } else {
                cout << "Pasien tidak ditemukan\n";
            }
            system("pause");
            break;

        // ===== EDIT PARENT DARI CHILD =====
        case 4:
            cout << "ID Pasien        : "; cin >> idPasien;
            cout << "Keluhan          : "; cin >> keluhan;
            cout << "ID Dokter Baru   : "; cin >> idDokter;
            cout << "Spesialis        : "; cin >> spesialis;

            d = findDokter(LD, idDokter, spesialis);
            if(d != nullptr){
                EditParent_fromChild(LR, idPasien, d);
            } else {
                cout << "Dokter tidak ditemukan\n";
            }
            system("pause");
            break;
        }
    }
}
