#include <iostream>
#include "main.h"
#include "Relation.h"
#include "Dokter.h"
#include "Pasien.h"
using namespace std;

extern list_Dokter LD;
extern list_Pasien LP;
extern list_Relasi LR;


void menuUser(){
    int option = -99;
    string id, keluhan, spesialis;
    adr_Pasien P;
    adr_Dokter D;
    adr_Relasi R;

    while (option != 0) {
        system("cls");
        cout << "================ Menu Studi Kasus =====================\n";
        cout << "|| 1. Tampilkan Pasien dari Dokter tertentu          ||\n";
        cout << "|| 2. Tampilkan Dokter dari Pasien tertentu          ||\n";
        cout << "|| 3. Tampilkan Relasi Dokter ke Pasien              ||\n";
        cout << "|| 4. Tampilkan Relasi Pasien ke Dokter              ||\n";
        cout << "|| 5. Jumlah Pasien dari Dokter tertentu             ||\n";
        cout << "|| 6. Jumlah Dokter dari Pasien tertentu             ||\n";
        cout << "|| 7. Jumlah Pasien yang tidak memiliki Dokter       ||\n";
        cout << "|| 8. Jumlah Dokter yang tidak memiliki Pasien       ||\n";
        cout << "|| 9. Cek Relasi Pasien                              ||\n";
        cout << "||10. Cek Relasi Dokter                              ||\n";
        cout << "|| 0. Back                                           ||\n";
        cout << "=======================================================\n";
        cout << "Choose your option : ";
        cin >> option;

        switch(option) {

            case 1:
                cout << "ID Dokter : ";
                cin >> id;
                ShowPasien_from_Dokter(LR, id);
                system("pause");
                break;

            case 2:
                cout << "ID Pasien : ";
                cin >> id;
                ShowDokter_from_Pasien(LR, id);
                system("pause");
                break;

            case 3:
                ShowRelasiDokter_to_Pasien(LR);
                system("pause");
                break;

            case 4:
                ShowRelasiPasien_to_Dokter(LR);
                system("pause");
                break;

            case 5:
                cout << "ID Dokter : ";
                cin >> id;
                cout << "Jumlah Pasien : "
                     << jumPasien_to_Dokter(LR, id) << endl;
                system("pause");
                break;

            case 6: {
            string idPasien;
            cout << "ID Pasien : ";
            cin >> idPasien;

            cout << "Jumlah Dokter : "
                 << jumDokter_to_Pasien(LR, idPasien) << endl;

            system("pause");
            break;
}

            case 7:
                cout << "Jumlah Pasien tanpa Dokter : "
                     << Pasien_doesntHaveDokter(LR, LP) << endl;
                system("pause");
                break;

            case 8:
                cout << "Jumlah Dokter tanpa Pasien : "
                     << Dokter_doesntHavePasien(LR, LD) << endl;
                system("pause");
                break;

            case 9:
                cout << "ID Pasien : ";
                cin >> id;
                cout << "Keluhan   : ";
                cin >> keluhan;

                P = findPasien(LP, id, keluhan);
                if (P != nullptr) {
                    R = findElmRelasiByPasien(LR, P);
                    if (R != nullptr)
                        cout << "Pasien memiliki relasi dengan dokter "
                             << R->nextD->infoD.ID_Dokter << endl;
                    else
                        cout << "Pasien belum memiliki relasi dokter\n";
                } else {
                    cout << "Pasien tidak ditemukan\n";
                }
                system("pause");
                break;

            case 10:
                cout << "ID Dokter  : ";
                cin >> id;
                cout << "Spesialis  : ";
                cin >> spesialis;

                D = findDokter(LD, id, spesialis);
                if (D != nullptr) {
                    R = findElmRelasiByDokter(LR, D);
                    if (R != nullptr)
                        cout << "Dokter memiliki relasi dengan pasien "
                             << R->nextP->infoP.ID_Pasien << endl;
                    else
                        cout << "Dokter belum memiliki pasien\n";
                } else {
                    cout << "Dokter tidak ditemukan\n";
                }
                system("pause");
                break;
        }
    }
}
