#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <windows.h>
int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int x[]={0, 1, 0, 1, 1}; //11 вариант
    int y[]={1, 0, 0, 1, 0}; //11+7=18
    int randmass[31]={0}; //послед Голда

    for (int i=0; i<31; i++) {

        int xlast=0;
        int ylast=0;

        if (x[0] != x[2]) {
        xlast=1;
        }

        if (y[1] != y[3]) {
        ylast=1;
        }

        for (int j=5; j>0; j--) {
        x[j]=x[j-1];
        y[j]=y[j-1];
        }

        x[0]=xlast;
        y[0]=ylast;
        int vivod=0;

        if (x[4] != y[4]) {

        vivod=1;

        }

        randmass[i]=vivod; //массив вывода
        printf("%2d : x[]={%d %d %d %d %d} y[]={%d %d %d %d %d} vivod=%d\n", i, x[0], x[1], x[2], x[3], x[4], y[0], y[1], y[2], y[3], y[4], vivod);

    }
    for (int l=0; l<31; l++) {
        printf("%d", randmass[l]);
    }
    printf("\n");

    int x1[]={0, 1, 1, 0, 0}; //11+1=12
    int y1[]={0, 1, 1, 0, 1}; //18-5=13
    int randmass1[31]={0};

    for (int i=0; i<31; i++) { //2 послед Голда

        int xlast=0;
        int ylast=0;

        if (x1[0] != x1[2]) {
            xlast=1;
        }

        if (y1[1] != y1[3]) {
            ylast=1;
        }

        for (int j=5; j>0; j--) {
            x1[j]=x1[j-1];
            y1[j]=y1[j-1];
        }

        x1[0]=xlast;
        y1[0]=ylast;
        int vivod=0;

        if (x1[4] != y1[4]) {
            vivod=1;
        }

        randmass1[i]=vivod; //вывод
        printf("%2d : x1[]={%d %d %d %d %d} y1[]={%d %d %d %d %d} vivod=%d\n", i, x1[0], x1[1], x1[2], x1[3], x1[4], y1[0], y1[1], y1[2], y1[3], y1[4], vivod);
    }
    for (int l=0; l<31; l++) {
        printf("%d", randmass1[l]);
    }
    printf("\n");

    printf("                                                                 Corr x, shift x\n");
    printf(" С| B1| B2| B3| B4| B5| B6| B7| B8| B9|B10|B11|B12|B13|B14|B15|B16|B17|B18|B19|B20|B21|B22|B23|B24|B25|B26|B27|B28|B29|B30|B31|А.Kор\n");

    int vivodlast[31]={0};
    int randmassforcor[31] = {0};
    for (int m=0; m<31; m++) {
        vivodlast[m]=randmass[m];
    }
    for (int m=0; m<31; m++) {
        randmassforcor[m]=randmass[m];
    }
    for (int k=0; k<36; k++) {
        printf("%2d", k);
        if (k != 0) {
            int lastvivod=randmassforcor[30];
            for (int n=1; n<31; n++) {
                randmassforcor[31-n]=randmassforcor[31-n-1];
            }
            randmassforcor[0]=lastvivod;
        }
        float sumcorr=0.0;
        float sumuncorr=0.0;
        for (int l=0; l<31; l++) {
            printf("|%3d", randmassforcor[l]);
            if (randmassforcor[l]==vivodlast[l]) {
                sumcorr += 1.0;
            }
            else {
                sumuncorr += 1.0;
            }
            }
        float autocorr=(1/31.0)*(sumcorr-sumuncorr);
        printf("|%.2f\n", autocorr);
    }


    printf("                                                                 Corr x1, shift x1\n");
    printf(" С| B1| B2| B3| B4| B5| B6| B7| B8| B9|B10|B11|B12|B13|B14|B15|B16|B17|B18|B19|B20|B21|B22|B23|B24|B25|B26|B27|B28|B29|B30|B31|А.Kор\n");
    int vivodlast1[31]={0};
    int randmassforcor1[31] = {0};
    for (int m=0; m<31; m++) {
        vivodlast1[m]=randmass1[m];
    }
    for (int m=0; m<31; m++) {
        randmassforcor1[m]=randmass1[m];
    }
    for (int k=0; k<36; k++) {
        printf("%2d", k);
        if (k != 0) {
            int lastvivod=randmassforcor1[30];
            for (int n=1; n<31; n++) {
                randmassforcor1[31-n]=randmassforcor1[31-n-1];
            }
            randmassforcor1[0]=lastvivod;
        }
        float sumcorr=0.0;
        float sumuncorr=0.0;
        for (int l=0; l<31; l++) {
            printf("|%3d", randmassforcor1[l]);
            if (randmassforcor1[l]==vivodlast1[l]) {
                sumcorr += 1.0;
            }
            else {
                sumuncorr += 1.0;
            }
            }
        float autocorr=(1/31.0)*(sumcorr-sumuncorr);
        printf("|%.2f\n", autocorr);
    }


    //Корреляция между последов Голда
    float doublecor = 0.00;

    for (int i=0; i<=30; i++) {
          doublecor += randmass[i]*randmass1[i];
    }
    printf("корреляция двух последовательностей=%.f\n", doublecor);
    return 0;
}
