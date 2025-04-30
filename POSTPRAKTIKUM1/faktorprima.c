#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int count, first = 1;
    for (int i = 2; i <= N; i++) {
        count = 0;
        while (N % i == 0) {
            count++;
            N /= i;
        }
        if (count > 0) {
            if (!first) {
                printf(" * ");
            }
            printf("%d", i);
            if (count > 1) {
                printf("^%d", count);
            }
            first = 0;
        }
    }
    printf("\n");
    
    return 0;
}
