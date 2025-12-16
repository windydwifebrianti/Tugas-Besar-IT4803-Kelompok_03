#include "Dokter.h"
#include <iostream>
using namespace std;

adr_Dokter newDokter(infotype_Dokter x) {
	adr_Dokter P;
	P = new elm_Dokter;
	P -> infoD = x;
	P -> nextD = nullptr;
	return P;
}

void insert_first_Dokter(list_Dokter &L, adr_Dokter P) {
	if(L.firstD == nullptr) {        // jika daftar kosong
		L.firstD = P;               // node baru menjadi node pertama
	} else {
		P->nextD = L.firstD;         // hubungkan node baru ke node lama paling depan
		L.firstD = P;               // jadikan node baru sebagai node pertama
	}
}


adr_Dokter findDokter(list_Dokter &L, string idDokter, string spesialis) {
	adr_Dokter P;
	P = L.firstD;         						// mulai di node pertama
	while(P != nullptr) {           	 		// teruskan selama ada node
		if (P->infoD.ID_Dokter == idDokter && P->infoD.spesialis == spesialis) { 	// jika ID cocok
			return P;                 			// kembalikan node tersebut
		}
		P = P->nextD;                			// lanjut ke node berikutnya
	}
	return nullptr;                    // tidak ditemukan    
}

void delete_first_Dokter(list_Dokter &L, adr_Dokter &P){
	if (L.firstD == nullptr) {
		P = nullptr; // List kosong, tidak ada yang dihapus
	} else {
		P = L.firstD;
		L.firstD = P -> nextD;
		P -> nextD = nullptr;
	}
}

void delete_after_Dokter(list_Dokter &L, adr_Dokter Prec, adr_Dokter &P){
	if (L.firstD == nullptr || Prec == nullptr || Prec->nextD == nullptr) {
		P = nullptr; // Tidak ada node setelah Prec atau list kosong
	} else {
		P = Prec -> nextD;	
		Prec -> nextD = P -> nextD;
		P -> nextD = nullptr;
}


