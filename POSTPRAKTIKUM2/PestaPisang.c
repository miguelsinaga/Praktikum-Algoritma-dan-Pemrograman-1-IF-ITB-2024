#include <stdio.h>

int TotalPisang(int a, int b, int c, int d, int e) {
    return a+b+c+d+e;
}

double Average(int a, int b, int c, int d, int e) {
    return (TotalPisang(a,b,c,d,e) /5);
}

int main () {
    int a,b,c,d,e;
    scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);
    printf("%d\n" , TotalPisang(a,b,c,d,e));
    printf("%f\n" , Average(a,b,c,d,e));
    if (Average(a,b,c,d,e) >= 10) {
        printf("Pesta Nimons Sukses!\n");
    }
    else {
        printf("Pesta Nimons Gagal, kumpulkan lebih banyak pisang!\n"); 
    }



}