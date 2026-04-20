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
            int masukkiri=0;
            int masukkanan=0;

            //cara tetangga dari kiri
            for (int j=i-1; j>=0; j--) {
                if (arr[j]!=-1) {
                    kiri=arr[j];
                    masukkiri=1;
                    break;
                }
            }

            //cari tetangga valid terdekat di kanan
            for (int j=i+1; j<N; j++) {
                if (arr[j]!=-1) {
                    kanan=arr[j];
                    masukkanan=1;
                    break;
                }
            }

            //logika penggantian -1 dan lain lainnya 
            if (masukkiri && masukkanan) {
                hasil[i]=(kiri+kanan)/2; //mediannya
            } 
            else if (masukkiri) {
                hasil[i]=kiri;
            } 
            else if (masukkanan) {
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
        int sumMax = hasil[0];
        int sumBaru = hasil[0];

        for (int i=1; i<N; i++) {

            if (hasil[i]>sumBaru+hasil[i]) {
                sumBaru=hasil[i];
            } else {
                sumBaru=sumBaru+hasil[i];
            }

            if (sumBaru>sumMax) {
                sumMax=sumBaru;
            }
        }
        printf("\nMAX_SUM %d ", sumMax);
    }
    
    
}
