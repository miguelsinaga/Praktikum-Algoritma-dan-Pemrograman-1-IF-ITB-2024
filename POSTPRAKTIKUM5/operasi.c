/* File: PasienNimons.h */
/* Deskripsi: ADT kompleks untuk data pasien Nimons yang mencakup data vital, lokasi, dan identitas */

#include "operasi.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


/* --- Konstruktor --- */
Vital MakeVital(int tekanan, int detak, float saturasi){
    Vital V;
    V.tekananDarah = tekanan ;
    V.detakJantung = detak;
    V.saturasiOksigen = saturasi;
    return V;

}
Lokasi MakeLokasi(int x, int y){
    Lokasi L;
    L.x = x;
    L.y = y;
    return L;

}
Pasien MakePasien(char nama[], Vital v, Lokasi l){
    Pasien p ;
    for (int i = 0 ; i <= sizeof(nama) ; i++){
        p.nama[i] = nama[i];
    }
    p.v = v;
    p.l = l;
    return p;
}

/* --- Aksesor --- */
int GetTekanan(Vital v){
    return v.tekananDarah;
}
int GetDetak(Vital v){
    return v.detakJantung;
}
float GetSaturasi(Vital v){
    return v.saturasiOksigen;
}
int GetX(Lokasi l){
    return l.x;
}
int GetY(Lokasi l){
    return l.y;
}
Vital GetVital(Pasien p){
    return p.v;
}
Lokasi GetLokasi(Pasien p){
    return p.l;
}

/* --- Mutator --- */
void SetTekanan(Vital *v, int tekanan){
    v->tekananDarah = tekanan;
}
void SetDetak(Vital *v, int detak){
    v->detakJantung = detak;
}
void SetSaturasi(Vital *v, float saturasi){
    v->saturasiOksigen = saturasi;
}
void SetX(Lokasi *l, int x){
    l->x = x;
}
void SetY(Lokasi *l, int y){
    l->y = y;
}
void SetVital(Pasien *p, Vital v){
    p->v = v;
}
void SetLokasi(Pasien *p, Lokasi l){
    p->l = l;
}

/* --- Operasi Vital --- */
bool IsSehat(Vital v){
    if((v.detakJantung >= 60 && v.detakJantung <= 100) && (v.tekananDarah >=90 && v.detakJantung <=140) && (v.saturasiOksigen>=95)){
        return true;
    }
    else{
        return false;
    }
}
/* True jika:
   90 <= tekanan darah <= 140
   60 <= detak jantung <= 100
   saturasi >= 95.0 */

void ResetVital(Vital *v){
    v->tekananDarah = 120;
    v->detakJantung = 80;
    v->saturasiOksigen = 98.0;
}
/* Mengatur kembali semua nilai vital ke default (120/80/98.0) */

int CompareVital(Vital a, Vital b){
    float totalA =  a.tekananDarah + a.detakJantung + a.saturasiOksigen;
    float totalB =  b.tekananDarah + b.detakJantung + b.saturasiOksigen;
    if (totalA < totalB) {
        return -1;
    } else if (totalA == totalB) {
        return 0;
    } else {
        return 1;
    }
}                       
/* Mengembalikan:
    0 jika sama
    1 jika a > b
*/

/* --- Operasi Lokasi --- */
void PindahPasien(Lokasi *l, int dx, int dy){
    l->x += dx;
    l->y += dy;
}
/* Memindahkan pasien ke koordinat baru berdasarkan delta */

/* --- Print --- */
void PrintVital(Vital v){   
    printf("Tekanan: %d mmHg, Detak: %d bpm, Saturasi: %.2f%%\n" , v.tekananDarah , v.detakJantung, v.saturasiOksigen);
}
/* Format: "Tekanan: xxx mmHg, Detak: xxx bpm, Saturasi: xx.xx%" */

void PrintLokasi(Lokasi l){
    printf("Lokasi: (%d, %d)\n" , l.x , l.y);
}
/* Format: "Lokasi: (x, y)" */

void PrintPasien(Pasien p){
    printf("Nama: %s\n" , p.nama);
    PrintVital(p.v);
    PrintLokasi(p.l);
}
/* Menampilkan semua info pasien:
   Nama
   Vital
   Lokasi
*/

