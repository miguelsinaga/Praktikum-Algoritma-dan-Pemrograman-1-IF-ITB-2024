#include <stdio.h>

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    long long a[n], asort[n];
    long long sum=0, maxpinggir=0;

    for(int i=0; i<n; i++){
        scanf("%lld", &a[i]);
        asort[i]=a[i];
    }

    if(a[0]>=a[n-1]){
        maxpinggir+=a[0];
    }
    else if(a[n-1]>a[0]){
        maxpinggir+=a[n-1];
    }
    
    //ngurutin a[n] dari kecil ke besar
    long long temp, min;
    for(int i=0; i<n-1; i++){
        min=i;
        for(int j=i+1; j<n;j++){
            if(asort[min]>asort[j]){
                min=j;
            }
        }
        temp=asort[i];
        asort[i]=asort[min];
        asort[min]=temp;
    }

    if(maxpinggir==asort[n-1]){
        maxpinggir+=asort[n-2];
    }
    else if(maxpinggir<asort[n-1]){
        maxpinggir+=asort[n-1];
    }
    
    if(k>1){
        int count=k+1;
        for(int i=n-1; i>=0; i--){
            if(asort[i]<0 && count<k-1){
                break;
            }
            sum+=asort[i];
            count--;
            if(count==0) break;
        }
    }
    

    if(maxpinggir>=sum){
        printf("%lld\n", maxpinggir);
    }
    else{
        printf("%lld\n", sum);
    }
    return 0;
}