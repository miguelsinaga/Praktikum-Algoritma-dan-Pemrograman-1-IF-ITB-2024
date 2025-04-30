#include <stdio.h>

void rotate(int n , int arr[]) {  // prapraktikum lmao
    int temp = arr[n-1];
    for (int i = n-2 ; i>=0 ; i--) {
        arr[i+1] = arr[i] ; 
            
    }
    arr[0] = temp;

    
}

void printArr(int n, int arr[]){
    for (int i = 0 ; i<n ; i++){
        printf("%d", arr[i]);

        if (i != n-1){
            printf(" ");
        }
    }

    printf("\n");


}

int main (){
    int n,k;
    scanf("%d %d" , &n, &k);
    int arr[n];
    for (int i = 0 ; i<n ; i++){
        scanf("%d" , &arr[i]);
    }

    if (k == 0 || k == n){
        printArr(n, arr);
    }
    else{
        for (int i = 0 ; i< k ; i++){
            rotate(n,arr);
        }
        
        printArr(n, arr );
    }

}