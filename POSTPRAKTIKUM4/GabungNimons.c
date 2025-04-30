#include <stdio.h>
#include <stdlib.h>
#include "tester.h"

int main() {
    init() ; 
    FILE *fa = fopen("file_a.txt", "r");
    FILE *fb = fopen("file_b.txt", "r");


    int nimonidA, pisangA, nimonidB, pisangB;

    fscanf(fa, "%d %d", &nimonidA, &pisangA);
    fscanf(fb, "%d %d", &nimonidB, &pisangB);

    int i = 1;
    int arrPisang[1000];
    int arrID[1000] ; 
    while ((nimonidA != -1 && pisangA != 99) || (nimonidB != -1 && pisangB != 99)) {
        arrPisang[nimonidA] = pisangA ;
        arrID[nimonidA] = nimonidA ; 
        arrPisang[nimonidB] = pisangB ;
        arrID[nimonidB] = nimonidB ; 
        fscanf(fa, "%d %d", &nimonidA, &pisangA);
        fscanf(fb, "%d %d", &nimonidB, &pisangB);
    }

    fclose(fa);
    fclose(fb);
    for (int j = 1 ; j <= 1000 ; j++){
        if (arrID[j] == j)
            printf("%d %d\n" , arrID[j] , arrPisang[j] );
        
    }
    return 0;    
    }

    

