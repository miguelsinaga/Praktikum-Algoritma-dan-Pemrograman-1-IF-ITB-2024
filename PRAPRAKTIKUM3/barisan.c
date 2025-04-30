#include <stdio.h>

int carifpb(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int carikpk(int a, int b) {
    return (a / carifpb(a, b)) * b;
}

int findMax(int arr[], int n, int skipIndex) {
    if (n == 1) return arr[0] * arr[0];  // Jika hanya satu angka, hasilnya adalah dirinya sendiri dikali dirinya sendiri

    int fpb = -1, kpk = 1;
    for (int i = 0; i < n; i++) {
        if (i == skipIndex) continue;

        if (fpb == -1) fpb = arr[i];
        else fpb = carifpb(fpb, arr[i]);

        kpk = carikpk(kpk, arr[i]);
    }

    return fpb * kpk;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = findMax(arr, n, 0);
    for (int i = 1; i < n; i++) {
        int keluaran = findMax(arr, n, i);
        if (keluaran > max) {
            max = keluaran;
        }
    }

    printf("%d\n", max);
    return 0;
}
