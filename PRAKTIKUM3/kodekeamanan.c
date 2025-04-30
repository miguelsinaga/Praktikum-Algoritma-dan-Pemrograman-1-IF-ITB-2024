#include <stdio.h>
int main(){
    int n;
    scanf("%d" , &n);
    int arr[n];
    int kode;
    for (int i =0 ; i<n; i++){
        scanf("%d" , &arr[i]);
    }

    scanf("%d" , &kode);

    int index1;
    int index2;
    int found = 0;
    for (int i = 0 ; i < n && found != 1;i++){
        for (int j = i+ 1 ; j<n && found != 1; j++){
            if (arr[i] + arr[j] == kode){
                index1 = i;
                index2 = j;
                found = 1;
            }
        }
    }

    printf("[%d, %d]\n" , index1 , index2);
}