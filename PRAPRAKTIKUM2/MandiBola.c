#include <stdio.h>
#include "MandiBola.h"

void HandleNimonsHunting(long long input_2) {
    int counter=0;
    long long num = input_2;
    long long first ;
    int langkah=1;
    while (num != 0) 
    {
        num/=10;
        if (num <=10){
            first =num;
        }
        counter++;
    }
    int listinput[counter];
    
    for (int i = counter-1 ; i >=0 ; i--) {
        listinput[i]= input_2%10;
        input_2/=10;

    }
    long harga, jmlharta = listinput[counter-2], jmllubang = listinput[n-1], jmlpergerakan = listinput[counter];
    
    printf("----------------------------------------\nSelamat datang di Treasure Hunting Nimons!\n\nJumlah pergerakan Nimons di dalam kolam: %ld\nJumlah lubang yang ada di kolam: %ld\nJumlah harta karun yang ada di kolam: %ld\n", jmlpergerakan, jmllubang, jmlharta);
    
    //Buat nyari ketutup berapa, ketemu berapa, langkahnya berapa, langkah ke berapa, nah buat kebrp = itu misalkan nih kan dia i nya per 3 angka DARI BELAKANG ya (misal 115 = 1 tutup 1 temu 5 langkah) nah i itu cuma ngambil yang paling belakang which is langkah, yang lain? berarti dikurang 1 dari si i
    long tutup = 0, temu = 0, langkah = 0, langkahke = 0, kebrp;
    for (long i = n-3; i >= 2; i = i-3)
    {
        langkahke++;
        printf("Langkah ke-%ld\n", langkahke);
        
        kebrp = i;
        if (listinput[kebrp] > 0)
        {
            printf("Nimons bergerak sejauh %ld langkah\n", listinput[kebrp]);
            langkah = langkah + matrix[kebrp];
        } else{
            printf("Nimons tidak bergerak\n");
        }
         
        kebrp--;
        if (listinput[kebrp] == 1)
        {
            printf("Nimons menemukan harta karun!\n");
            temu++;
        }
        
        kebrp--;
        if (listinput[kebrp] == 1)
        {
            printf("Nimons menutup lubang!\n");
            tutup++;
        }
        
        if (langkahke == jmlpergerakan) 
        {
            break;
            
        }
        
    }

    long pengkali = 1;
    for (long i = 1; i < kebrp-1 ; i++) 
    {
        pengkali *= 10;
    }
    
    temp = 0; 
    for (long i = 1; i < kebrp; i++)
    {
        if (i == 1) 
        {
            harga = listinput[1]*pengkali;
            temp = harga;
        } else
        {
        pengkali /= 10; 
        harga = temp + (listinput[i]*pengkali);
        temp = harga;
        }
    }
    
    printf("\nTotal lubang yang ditutup: %ld dari %ld lubang\n", tutup, jmllubang);
    printf("Total harta karun yang ditemukan: %ld\n", temu);
    printf("Total harga harta karun yang ditemukan: %ld\n", (temu*harga*5));
    printf("Total langkah yang ditempuh: %ld\n", langkah);
    printf("Total biaya ganti rugi Pak Gro: %ld\n", (harga*tutup));
    printf("Total keuntungan Nimons dan Pak Gro: %ld\n", ((temu*harga*5) - (harga*tutup)));

}

void SelamatDatang(int input){
    int anak, dewasa, lansia;
    lansia = input%10;
    dewasa = (input/10)%10;
    anak = (input/100);
    printf("----------------------------------------\n") ; 
    printf("Selamat datang di Wahana Mandi Bola!\n");
    printf("\n") ;
    printf("Silakan beli tiket terlebih dahulu untuk masuk ke wahana ini.\n") ;
    printf("Harga tiket:\n");
    printf("- Anak-anak (usia 0-12 tahun): Rp 10000\n- Dewasa (usia 13-64 tahun): Rp 20000\n- Lansia (usia 65 tahun ke atas): Rp 15000\n");
    printf("\n") ;
    printf("Jumlah anak: %d\n" , anak) ;
    printf("\nJumlah dewasa: %d\n" , dewasa) ;
    printf("\nJumlah lansia: %d\n", lansia) ;

    long long total;
    printf("\nTiket berhasil dibeli!\n") ;
    total = 10000*anak + 20000*dewasa + 15000*lansia ;
    printf("Rincian:\n- Jumlah anak-anak: %d\n- Jumlah dewasa: %d\n- Jumlah lansia: %d\n- Total biaya: %lld\n" , anak, dewasa, lansia, total);
    
}


int main() {
    int input_1;
    long long input_2;
    scanf("%d", &input_1);
    scanf("%lld", &input_2);
    SelamatDatang(input_1);
    HandleNimonsHunting(input_2);
    return 0;
}