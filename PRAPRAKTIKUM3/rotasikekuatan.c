#include <stdio.h>


void rotate(int n , int list[] , int a ) {
    int lmaopisan[n];
    for (int i =0 ; i<n ; i++) {
        lmaopisan[i] = list[i];
    }
    for (int j = 1 ; j <=a ; j++) {
        int temp = lmaopisan[n-1];
        for (int i = n-2 ; i>=0 ; i--) {
            lmaopisan[i+1] = lmaopisan[i] ; 
            
        }
        lmaopisan[0] = temp;
    }


    
    
    printf("[");
    
    for (int i = 0; i < n; i++)
    {
        printf("%d" , lmaopisan[i]);
        if (i != n-1) {
            printf(", ") ;
        }
    }
    printf("]\n");
    
}


int main () {
    int n;
    scanf("%d" , &n);
    int array[n];
    int r;
    scanf("%d" , &r);

    for (int i = 0 ; i <n ; i++) {
        scanf("%d" , &array[i] );
    }

    int rotation[r];
    for (int i =0 ; i <r ; i++){
        scanf("%d" , &rotation[i] );
    }

    for(int i = 0 ; i<r;i++) {
        rotate(n , array, rotation[i]) ;    
    }
}