/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : DATA MANIPULATION AND EXTERNAL FILES
 *   Hari dan Tanggal    : Senin, 20 April 2026
 *   Nama (NIM)          : 13224095
 *   Nama File           : sensor.c
 *   Deskripsi           : Memulihkan elemen array yang hilang lalu mencari jumlahnya
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int N;
    
    FILE* fsensor;

    char data[255];

 
    fgets(data, 255, stdin);

    fsensor = fopen("filesensor.txt", "w");



 
        fputs(data, fsensor);
        fputs("\n", fsensor);

    fclose(fsensor);

    fsensor = fopen("filesensor.txt", "r");

    fscanf(fsensor, "%d", &N);
   
    int arr[N];
    int number;
    

    for(int i =0; i<N; i++){

        fscanf(fsensor, "%d", &number);

        
        arr[i]=number;
    }

//--------------------------------------------------------------------------
    int hasil[N];
    for (int i=0; i<N; i++) {
        if (arr[i]!=-1) {
            hasil[i]=arr[i];
        } 
        
        else {
            int kiri=-1;
            int kanan=-1;
            int kiriada=0;
            int kananada=0;

            for (int j=i-1; j>=0; j--) {
                if (arr[j]!=-1) {
                    kiri=arr[j];
                    kiriada=1;
                    break;
                }
            }

            for (int j=i+1; j<N; j++) {
                if (arr[j]!=-1) {
                    kanan=arr[j];
                    kananada=1;
                    break;
                }
            }

            if (kiriada && kananada) {
                hasil[i]=(kiri+kanan)/2; 
            } 
            else if (kananada) {
                hasil[i]=kiri;
            } 
            else if (kiriada) {
                hasil[i]=kanan;
            } 
            else {
                hasil[i]=0;
            }
        }
    }

    printf("RECOVERED");
    for (int i=0; i<N; i++) {
        printf(" %d", hasil[i]);
    }

    if (N>0) {
        int max = hasil[0];
        int new = hasil[0];

        for (int i=1; i<N; i++) {

            if (hasil[i]>new+hasil[i]) {
                new=hasil[i];
            } else {
                new=new+hasil[i];
            }

            if (new>max) {
                max=new;
            }
        }
        printf("\nMAX_SUM %d ", max);
    }
    
    
}
