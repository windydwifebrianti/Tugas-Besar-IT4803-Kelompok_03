#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
using namespace std;

#include "Dokter.h"
#include "Pasien.h"
#include "Relation.h"

extern list_Dokter LD;
extern list_Pasien LP;
extern list_Relasi LR;

// ===== MENU =====
void menuAdmin();
void menuParent();
void menuChild();
void menuRelasi();

void menuUser();

// ===== DUMMY DATA =====
void initDummyData();

#endif // MAIN_H_INCLUDED
