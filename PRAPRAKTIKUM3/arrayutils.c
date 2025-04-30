#include <stdio.h>
#include "arrayutils.h"

void sort(int arr[] , int n){
    int a;
    for (int i = 0 ; i<n; i++){
        for (int i = 0 ; i <n -1 ; i++) {
            if (arr[i] > arr[i+1]){
                a = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = a;
                
            }
        }
    }
}

int find(int arr[] ,int n , int target){
    int found =0;
    int index ;
    for (int i = 0 ; i<n ; i++){
        if(arr[i] == target){
            return  i;
        }
    }
    return -1;
}

double calculateAverage(int arr[], int n){
    int sum =0;
    for (int i = 0 ; i <n ; i++){
        sum+= arr[i];
    }

    return sum/n;
}

int findMedian(int arr[], int n){
    if (n%2 == 1){
        return arr[(n)/2];
    }
    else{
        return ( (arr[(n)/2 -1] + arr[(n/2)])/2) ;
    }

}

int findMode(int arr[], int n){
    int max = 0 ; 
    int frekuensi[10001] = {0};
    int modus ;
    for (int i = 0 ; i <n ; i++){
        frekuensi[arr[i]]++;
        if (frekuensi[arr[i]] > max){
            max = frekuensi[arr[i]];
        }
        
    }  
        
    for (int i = 0 ; i<n ; i++){
        if (frekuensi[arr[i]]== max) {
            modus = arr[i];
            break;
        }
    }

    return modus;

}

int findMax(int arr[], int n){
    int max = arr[0];
    for (int i =0 ;i <n ; i++){
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMin(int arr[], int n){
    int min = arr[0];
    for (int i =0 ;i <n ; i++){
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void reverseArray(int arr[], int n){
    int kiri =0 , kanan = n-1;

    while (kiri < kanan){
        int temp = arr [kiri];
        arr[kiri] = arr[kanan] ;
        arr[kanan] = temp;

        kiri ++ ; 
        kanan -- ; 
    }
}

