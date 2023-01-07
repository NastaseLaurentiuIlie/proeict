#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <dos.h>
#include <dir.h>

int* v, * v1, * v2, parcurgeri = 0, count = 1, finished = 0;
SYSTEMTIME start, start1, start2, final, final1, final2;
void SetColor(int);
SYSTEMTIME afis_timp(SYSTEMTIME);
int gen_rand_num(int);
void gen_vect_unice(int);
void bubble_sort(int);
void caut_lin(int, int);
void caut_bin(int, int, int);
void afisare_numere(int, int*);
void menu(int, int*);
void pauza();
void shell_sort(int n) {
    printf("Se sorteaza folosind algoritmul shell sort");
    int i, j, aux, l, k;
    int h[3] = { 3, 2, 1 };
    for (l = 0; l < 3; l++) {
        k = h[l];
        for (i = k; i < n; i++) {
            aux = v1[i];
            j = i - k;
            while (j >= 0 && aux < v1[j]) {
                v1[j + k] = v1[j];
                j = j - k;
            }
            v1[j + k] = aux;
        }
        printf("Trecerea %d: ", l + 1);
    }
}