#include <stdio.h>

int main() {
    int a,b,n =0,counter = 0;

    scanf("%d %d" , &a,&b) ;

    for (int i = a ; i<=b;i++) {
        n =0;
        for (int j = 1 ; j<=i; j++){
            if (i%j == 0) {
                n+=1;
            }
        }
        if (n == 2) {
            counter+=1;
            
        }
    }
    printf("%d\n" , counter);

}