#include <stdio.h>

int main () {
    int n , count = 1;
    scanf("%d" , &n) ;
    for (int i = 2 ; i <=n ; i++) {
        if (n % (i*i) == 0) {
            count++ ; 
        }
    }
    printf("%d\n" , count) ;
}