#include <stdio.h>

int kabisat(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int jumlahhari (int d, int m ,int y){
    int total =0;
    for (int i = 1; i < y-1; i++){
        total += kabisat(y) ? 366 : 365;
    }

    for (int i =1 ; i <m ; i++){
        switch (i) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                total += 31;
                break;
            case 4: case 6: case 9: case 11:
                total += 30;
                break;
            case 2:
                total += kabisat(y) ? 29 : 28;
                break;
        }
    
    }
    total += d;
    return total;

}




int Valid(int day, int month, int year) {
    if (year < 1) {
        return 0;
    }
    if (month < 1 || month > 12) {
        return 0;
    }
    int totalhari;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            totalhari = 31;
            break;
        case 4: case 6: case 9: case 11:
            totalhari = 30;
            break;
        case 2:
            totalhari = kabisat(year) ? 29 : 28;
            break;
        default:
            return 0;
    }
    if (day < 1 || day > totalhari) {
        return 0;
    }
    return 1;
}

int main() {
    int d1, m1, y1,d2,m2,y2;
    while (1)
    {
        scanf("%d %d %d", &d1, &m1, &y1);
        if (Valid(d1, m1, y1)) {
            break;
        }
        else{
            printf("Tanggal tidak valid\n");                                                            
        }
}

    while (1)
    {
        scanf("%d %d %d", &d2, &m2, &y2);
        if (Valid(d2, m2, y2)) {
            int hari1 = jumlahhari(d1,m1,y1);
            int hari2 = jumlahhari(d2,m2,y2);
            if (hari2 >= hari1) {
                break;
            }
            else {
                printf("Tanggal kedua lebih dulu\n");
            }
        }
        else{
            printf("Tanggal tidak valid\n");
        }
}
    int hari1 = jumlahhari(d1,m1,y1) ;
    int hari2 = jumlahhari(d2,m2,y2) ;
    int selisih = hari2-hari1;
    printf("%d\n" , selisih);   
    

}

