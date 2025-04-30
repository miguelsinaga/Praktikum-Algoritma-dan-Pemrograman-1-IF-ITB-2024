#include <stdio.h>
int main () {
    int n , a , first = 0 , last;
    int i = 0;
    scanf("%d" , &n) ;
    a =n ;
    while(a!= 0) {
        last = a%10;
        first = first*10 + last%10 ; 
        a = a/10 ; 
         
    }
    if (first == n) {
        printf("1\n") ;
    }
    else {
        printf("0\n") ;
    }
}