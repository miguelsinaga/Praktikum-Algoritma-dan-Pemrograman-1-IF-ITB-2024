// #ifndef POINT_H
// #define POINT_H

// #include "boolean.h"  

// /* Definisi type POINT */
// typedef struct {
//     float X;  /* absis (sumbu X) */
//     float Y;  /* ordinat (sumbu Y) */
// } POINT;

// /* Macro selektor komponen */
// #define Absis(P)   (P).X
// #define Ordinat(P) (P).Y

// /* Membentuk POINT P dengan komponen X dan Y */
// void CreatePoint(POINT *P, float X, float Y);
// /* Membaca nilai POINT dari stdin: masukkan X Y */
// void BacaPOINT(POINT *P);
// /* Menulis POINT ke stdout dalam format "(X,Y)" */
// void TulisPOINT(POINT P);

// /* Mengambil / mengubah komponen X dan Y */
// float GetX(const POINT P);
// float GetY(const POINT P);
// void  SetX(POINT *P, float X);
// void  SetY(POINT *P, float Y);

// /* Mengecek lokasi POINT pada sumbu atau kuadran */
// boolean IsOrigin(POINT P);     /* true jika P = (0,0) */
// boolean IsOnSbX(POINT P);      /* true jika Y = 0 */
// boolean IsOnSbY(POINT P);      /* true jika X = 0 */
// int     Kuadran(POINT P);      /* 1..4; prekondisi: P bukan origin dan tidak di sumbu */

// /* Membandingkan dua POINT */
// boolean Equals(POINT P1, POINT P2);   /* true jika X dan Y identik */
// boolean NonEquals(POINT P1, POINT P2);/* negasi Equals */

// /* Menghitung jarak Euclidean antara P1 dan P2, Gunakan fungsi sqrtf dari math.h untuk menghitung akar kuadrat */
// float  Distance(POINT P1, POINT P2);
// /* Menghasilkan titik tengah P1 dan P2 */
// POINT  MidPoint(POINT P1, POINT P2);

// #endif  /* POINT_H */

/* File: point.h */
/* Tanggal: 3 September 2022 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef struct { 
	float X; /* absis   */
	float Y; /* ordinat */
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
void CreatePoint (POINT * P, float X, float Y);
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P); 
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P);
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQ (POINT P1, POINT P2);
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P);
/* Menghasilkan true jika P adalah titik origin */
boolean IsOnSbX (POINT P);
/* Menghasilkan true jika P terletak Pada sumbu X */
boolean IsOnSbY (POINT P);
/* Menghasilkan true jika P terletak pada sumbu Y */
int Kuadran (POINT P);
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P);
/* Mengirim salinan P dengan absis ditambah satu */              
POINT NextY (POINT P);
/* Mengirim salinan P dengan ordinat ditambah satu */
POINT PlusDelta (POINT P, float deltaX, float deltaY);
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
POINT MirrorOf (POINT P, boolean SbX);
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
float Jarak0 (POINT P);
/* Menghitung jarak P ke (0,0) */
float Panjang (POINT P1, POINT P2);
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
void Geser (POINT *P, float deltaX, float deltaY);
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
void GeserKeSbX (POINT *P);
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
void GeserKeSbY (POINT *P);
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
void Mirror (POINT *P, boolean SbX);
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
void Putar (POINT *P, float Sudut);
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */

#endif