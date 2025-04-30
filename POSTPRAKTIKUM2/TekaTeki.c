#include <stdio.h>
#include "TekaTeki.h"




long long kombinasi(int n,int k){
    if (k > n - k) k = n - k;  
    long long sum = 1;
    for (int i = 0; i < k; i++) {   
        sum = sum * (n - i) / (i + 1);
    }
    return sum;
}

long long catalan(int n){
    return kombinasi(2*n,n)/(n+1) ;
}