#include <stdio.h>

#include "time.h"

int main() {
    int n;
    scanf("%d" , &n);
    long arrMulai[n];
    long arrSelesai[n] ; 
    int j = 0 ;

 
    TIME T1, T2;


    for (int i = 0 ; i < n ; i++){
        printf("[%d]\n" , i+1);
        BacaTIME(&T1);
        BacaTIME(&T2) ; 

        if (TGT(T1,T2)){
            arrMulai[j] = TIMEToDetik(T2) ; 
            arrSelesai[j] = TIMEToDetik(T1) ; 
            j++;
            printf("%ld\n" , (TIMEToDetik(T1) - TIMEToDetik(T2)));
        }
        else if(TLT(T1,T2)){
            arrMulai[j] = TIMEToDetik(T1) ; 
            arrSelesai[j] = TIMEToDetik(T2) ; 
            j++;
            printf("%ld\n" , (TIMEToDetik(T2) - TIMEToDetik(T1)));
        }
        else if(TEQ(T1,T2)){
            arrMulai[j] = TIMEToDetik(T1) ; 
            arrSelesai[j] = TIMEToDetik(T2) ; 
            j++;
            printf("0\n");
        }
        
    }

    int min = arrMulai[0];
    int max = arrSelesai[0];
    for (int i = 0 ; i < n ; i++){
        if (arrMulai[i] < min){
            min = arrMulai[i];
        }
        if (arrSelesai[i] > max){
            max = arrSelesai[i];
        }
    }

    TulisTIME(DetikToTIME(min));
    printf("\n");
    TulisTIME(DetikToTIME(max));
    printf("\n");



}