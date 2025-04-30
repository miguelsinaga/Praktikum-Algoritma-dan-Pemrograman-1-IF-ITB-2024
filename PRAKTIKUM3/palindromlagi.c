#include <stdio.h>
int main (){
    char s[1001];
    scanf("%s" , s);
    int frekuensi[1001] = {0};
    int n = 0 ;
    for (int i = 0 ; s[i]!='\0' ; i++){
        n++;
    }

    for (int i = 0 ; i<n ; i++) {
        frekuensi[(int)s[i]]++;
    }

    int countergenap = 0; 
    int counterganjil = 0;

    for (int i = 0 ; i < n ; i++){

        if (frekuensi[(int)s[i]] % 2 != 0){
            counterganjil++;
        }
    }

    if ((counterganjil <= 1 ) ){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }

}