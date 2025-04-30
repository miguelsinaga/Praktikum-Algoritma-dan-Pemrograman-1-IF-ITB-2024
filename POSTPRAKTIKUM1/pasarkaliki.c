#include <stdio.h>

// Fungsi untuk menghitung kombinasi nCr
// unsigned long long factorial(int num) {
//     unsigned long long fact = 1;
//     for (int i = 1; i <= num; i++) {
//         fact *= i;
//     }
//     return fact;
// }

// unsigned long long combination(int n, int r) {
//     return factorial(n) / (factorial(r) * factorial(n - r));
// }

// int main() {
//     int N;
//     scanf("%d", &N);
//     if (N<=60) {
//         for (int i = 0; i < N; i++) {
//             for (int s = 0; s < N - i - 1; s++) {
//                 printf(" ");
//             }
            
//             for (int j = 0; j <= i; j++) {
//                 printf("%llu", combination(i, j));
//                 if (j>i) {
//                     printf(" ") ; 
//                 }
//             }
//             printf("\n");
//         }
// }
//     return 0;
// }

int main() {
    long long n ;
    scanf("%lld" , &n) ;
    if (n <=60) {
        for (int i = 0 ; i <n ; i++) {  
            for (int a  = 0 ; a < n -i-1 ; a++) {
                printf(" ");
            }
            long long num = 1 ;
            for (int j = 0 ; j<=i ; j++) {
                printf("%lld" , num) ;
                if (j<i) {
                    printf(" ") ; 
                }
                
                num = num*(i-j)/(j+1) ;
            }

            printf("\n");
        }
    }
}