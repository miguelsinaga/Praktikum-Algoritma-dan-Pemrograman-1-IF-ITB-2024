#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int arr[N][N];
    int value = 1;
    
    for (int col = 0; col < N; col++) {
        int i = 0, j = col;
        while (j >= 0) {
            arr[i][j] = value++;
            i++;
            j--;
        }
    }
    
    for (int row = 1; row < N; row++) {
        int i = row, j = N - 1;
        while (i < N) {
            arr[i][j] = value++;
            i++;
            j--;
        }
    }
    

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", arr[i][j]);
            if (j <N -1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
