adr_Dokter newDokter(Dokter data) {
  adr_Dokter P;
  P = new elm_Dokter;
  P -> info = data;
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

void deleteRelasiByDokter(list_Relasi &relasiList, string idDokter) {
  adr_Relasi P;
  P = relasiList.first;                 // mulai dari kepala daftar relasi
	while (P != nullptr) {                             // untuk setiap relasi
    adr_Relasi next = P->next;                   // simpan pointer ke node berikutnya
		// jika relasi menghubungkan ke dokter yang mau dihapus
    if (P -> nextD != nullptr && P -> nextD -> info.ID_Dokter == idDokter) {
			// perbaiki pointer prev/next sehingga P dikeluarkan dari daftar
      if (P -> prev != nullptr) {
        P -> prev -> next = P -> next;
      } else {
        relasiList.first = cur->next;        // jika P adalah kepala
      }
      
      if (P->next != nullptr) {
        P->next->prev = P->prev;
      } else {
        relasiList.last = P ->prev;         // jika P adalah tail
      }
			// tidak memanggil delete; hanya unlink supaya node tak bisa diakses lagi
			P->next = nullptr;
      P->prev = nullptr;
      P->nextD = nullptr; 
      P ->nextP = nullptr;
    }
		P = next;                                     // lanjut ke node awalnya disimpan
	}
}

// Hapus node pertama jika ID node pertama cocok dengan idDokter
void delete_first_Dokter(list_Dokter &dokterList, list_Relasi &relasiList, string idDokter) {
  if (dokterList.first == nullptr) {
    return;  // list kosong -> tidak ada yang dihapus
  }         
	if (dokterList.first->info.ID_Dokter != idDokter) {
    return; // jika ID beda -> tidak dihapus
  }  
	adr_Dokter P;
  P = dokterList.first;              // simpan node yang mau dihapus
	dokterList.first = dokterList.first-> next;        // pindah kepala ke node berikutnya
	deleteRelasiByDokter(relasiList, toDel->info.ID_Dokter); // hapus relasi yang terkait
	// Unlink saja (tidak memanggil delete) — memori tetap dialokasikan tetapi tak dapat diakses lewat list
	P -> next = nullptr;
}

adr_Dokter findDokter(list_Dokter L, string idDokter) {
  adr_Dokter P;
  P = L.first;         // mulai di node pertama
	while(P != nullptr) {            // teruskan selama ada node
    if (P->info.ID_Dokter == idDokter) // jika ID cocok {
      return P;                 // kembalikan node tersebut
    }
    P = P->next;                // lanjut ke node berikutnya
  }
	return nullptr;                    // tidak ditemukan    
}

void delete_after_Dokter(list_Dokter &dokterList, list_Relasi &relasiList, int idDokter) {
  adr_Dokter prev;
  prev = findDokter(dokterList, idDokter); // cari node yang sebelumnya
	if (prev == nullptr || prev->next == nullptr) {
    return; // jika tidak ada -> nothing to delete
  } 
	adr_Dokter P;
  P = prev->next;                      // node yang akan dihapus
	prev->next = P->next;                           // hubungkan prev -> next setelah P
	deleteRelasiByDokter(relasiList, P->info.ID_Dokter); // hapus semua relasi yang terkait dokter ini
	// Unlink saja: node tidak lagi diakses melalui daftar
	P->next = nullptr;
}
