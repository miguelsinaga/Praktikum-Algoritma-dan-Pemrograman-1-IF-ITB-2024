#include <stdio.h>
#include <math.h>
int main () {
    int n ;
    
    scanf("%d" , &n) ;
    double a ;
    char awal, tujuan ;
    double hasil ;
    for (int i = 0 ; i <n ; i++) {
        scanf("%lf %c %c" , &a , &awal, &tujuan) ;
        if (awal =='C' && tujuan =='F'){
            hasil = (a *9/5) + 32 ;
        }
        else if (awal == 'C' && tujuan == 'K')
        {
            hasil = a + 273.15 ;
        }
        else if (awal == 'F' && tujuan == 'C')
        {
            hasil = (a-32) *5/9 ;
        }
        else if (awal == 'F' && tujuan == 'K')
        {
            hasil = (a-32) *5/9 + 273.15 ;
        }
        else if (awal == 'K' && tujuan == 'C')
        {
            hasil = a - 273.15 ;
        }
        else if (awal == 'K' && tujuan == 'F')
        {
            hasil =  (a - 273.15) *9/5 +32 ;
        }
        else {
            hasil = a;
        }

        printf("%.2f\n" , floor(hasil)) ; 

    } 


}