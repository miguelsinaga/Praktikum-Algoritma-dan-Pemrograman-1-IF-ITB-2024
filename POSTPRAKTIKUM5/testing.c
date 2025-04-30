#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int coeff[5];  
    int degree;    
} Polynomial;

int main() {
    Polynomial p;
    p.degree = 4; 

    for (int i = 0; i <= p.degree; i++) {
        scanf("%d", &p.coeff[i]);
    }

    int isFirst = 1;

    for (int i = p.degree; i >= 0; i--) {
        int c = p.coeff[i];
        if (c == 0) continue;

        
        if (!isFirst) {
            if (c > 0) printf(" + ");
            else printf(" - ");
        } else {
            if (c < 0) printf("-");
        }

        
        int absC = abs(c);

        
        if (i == 0) {
            printf("%d", absC);
        } else if (i == 1) {
            if (absC == 1) printf("x");
            else printf("%dx", absC);
        } else {
            if (absC == 1) printf("x^%d", i);
            else printf("%dx^%d", absC, i);
        }

        isFirst = 0;
    }

    printf("\n");
    return 0;
}
