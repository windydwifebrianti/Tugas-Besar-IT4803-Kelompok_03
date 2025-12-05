#include "dokter_103032430035.h"

adr_Dokter newDokter(infotype_Dokter x) {
	adr_Dokter P;
	P = new elm_Dokter;
	P -> info = x;
	P -> next = nullptr;
	return P;
}

void insert_first_Dokter(list_Dokter &L, adr_Dokter P) {
	if(L.first == nullptr) {        // jika daftar kosong
		L.first = P;               // node baru menjadi node pertama
	} else {
		P->next = L.first;         // hubungkan node baru ke node lama paling depan
		L.first = P;               // jadikan node baru sebagai node pertama
	}
}


adr_Dokter findDokter(list_Dokter &L, string idDokter, string spesialis) {
	adr_Dokter P;
	P = L.first;         						// mulai di node pertama
	while(P != nullptr) {           	 		// teruskan selama ada node
		if (P->info.ID_Dokter == idDokter && P->info.spesialis == spesialis) { 	// jika ID cocok
			return P;                 			// kembalikan node tersebut
		}
		P = P->next;                			// lanjut ke node berikutnya
	}
	return nullptr;                    // tidak ditemukan    
}

void delete_first_Dokter(list_Dokter &L, adr_Dokter &P){
	if (L.first == nullptr) {
		P = nullptr; // List kosong, tidak ada yang dihapus
	} else {
		P = L.first;
		L.first = P -> next;
		P -> next = nullptr;
	}
}

void delete_after_Dokter(list_Dokter &L, adr_Dokter Prec, adr_Dokter &P){
	if (L.first == nullptr || Prec == nullptr || Prec->next == nullptr) {
		P = nullptr; // Tidak ada node setelah Prec atau list kosong
	} else {
		P = Prec -> next;	
		Prec -> next = P -> next;
		P -> next = nullptr;
}
