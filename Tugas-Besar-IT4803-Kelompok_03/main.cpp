#include <iostream>
#include "main.h"
#include "Relation.h"
#include "Dokter.h"
#include "Pasien.h"

using namespace std;

// ================= DUMMY DATA =================
void initDummyData()
{
    createListDokter(LD);
    createListPasien(LP);
    createListRelasi(LR);

    // ===== DOKTER =====
    infotype_Dokter d;

    d.ID_Dokter = "D01";
    d.namaD = "Andi";
    d.spesialis = "Umum";
    d.jadwalD = "Senin";
    insert_last_Dokter(LD, newDokter(d));

    d.ID_Dokter = "D02";
    d.namaD = "Sinta";
    d.spesialis = "Anak";
    d.jadwalD = "Selasa";
    insert_last_Dokter(LD, newDokter(d));

    d.ID_Dokter = "D03";
    d.namaD = "Bima";
    d.spesialis = "PenyakitDalam";
    d.jadwalD = "Rabu";
    insert_last_Dokter(LD, newDokter(d));

    d.ID_Dokter = "D04";
    d.namaD = "Alya";
    d.spesialis = "Kulit";
    d.jadwalD = "Kamis";
    insert_last_Dokter(LD, newDokter(d));

    d.ID_Dokter = "D05";
    d.namaD = "Raka";
    d.spesialis = "Saraf";
    d.jadwalD = "Jumat";
    insert_last_Dokter(LD, newDokter(d));

    // ===== PASIEN =====
    infotype_Pasien p;

    p.ID_Pasien = "P01";
    p.namaP = "Nina";
    p.keluhan = "Demam";
    insert_last_Pasien(LP, newPasien(p));

    p.ID_Pasien = "P02";
    p.namaP = "Rizky";
    p.keluhan = "Batuk";
    insert_last_Pasien(LP, newPasien(p));

    p.ID_Pasien = "P03";
    p.namaP = "Aisyah";
    p.keluhan = "AlergiKulit";
    insert_last_Pasien(LP, newPasien(p));

    p.ID_Pasien = "P04";
    p.namaP = "Dimas";
    p.keluhan = "SakitKepala";
    insert_last_Pasien(LP, newPasien(p));

    p.ID_Pasien = "P05";
    p.namaP = "Putri";
    p.keluhan = "Flu";
    insert_last_Pasien(LP, newPasien(p));

    // ===== RELASI =====
    adr_Dokter ad;
    adr_Pasien ap;

    ad = findDokter(LD, "D01", "Umum");
    ap = findPasien(LP, "P01", "Demam");
    insertRelasi(LR, newRelasi(ad, ap));

    ad = findDokter(LD, "D01", "Umum");
    ap = findPasien(LP, "P02", "Batuk");
    insertRelasi(LR, newRelasi(ad, ap));

    ad = findDokter(LD, "D02", "Anak");
    ap = findPasien(LP, "P05", "Flu");
    insertRelasi(LR, newRelasi(ad, ap));

    ad = findDokter(LD, "D04", "Kulit");
    ap = findPasien(LP, "P03", "AlergiKulit");
    insertRelasi(LR, newRelasi(ad, ap));

    ad = findDokter(LD, "D05", "Saraf");
    ap = findPasien(LP, "P04", "SakitKepala");
    insertRelasi(LR, newRelasi(ad, ap));
}

int main()
{
    initDummyData();

    int option = -99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu ============ " << endl;
        cout << "|| 1. Test Case             ||" << endl;
        cout << "|| 2. Study Case            ||" << endl;
        cout << "|| 0. exit                  ||" << endl;
        cout << "============================== " << endl;
        cout << "Choose your option : ";
        cin >> option;

        switch(option) {
           case 1:
              menuAdmin();
              break;
           case 2:
              menuUser();
              break;
        }
    }
    return 0;
}
