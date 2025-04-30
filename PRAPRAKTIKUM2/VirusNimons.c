#include <stdio.h>
int main () {
    unsigned long long int n,t,x, sum , a;

    scanf("%llu %llu %llu" , &n , &t, &x) ;
    a = n;
    for (int i = 0 ; i<t ; i++) {
        sum = a*x + n;
        a = sum;
    }

    printf("Terdapat %llu Virus Nimons Gila pada jam ke-%llu\n" , sum, t) ;
}