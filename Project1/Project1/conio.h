#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <conio.h>
#include <dos.h>


int *v, *v1, *v2, parcurgeri = 0, count = 1, finished = 0;
double t1,t2,t3;

//struct tm tm = *localtime(&t);
void afis_timp(struct timeval);
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
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int low, int high)
{
    int pivot = v2[(high + low) / 2];
    while (low <= high)
    {
        while (v2[low] < pivot)
            low++;
        while (v2[high] > pivot)
            high--;
        if (low <= high)
        {
            swap(&v2[low], &v2[high]);
            low++;
            high--;
        }
    }
}

void quickSort(int s, int d)
{
    if (s < d)
    {
        int pi = partition(s, d);
        count++;
        quickSort(s, pi - 1);
        quickSort(pi, d);
    }
}
void compara_timpi(double t1, double t2, double t3)
{
    printf("\nAlgoritmul bubble sort s a executat in %.5f secunde",t1);
    printf("\nAlgoritmul shell sort s a executat in %.5f secunde\n",t2);
    printf("Algoritmul quick sort s a executat in %.5f secunde\n",t3);
}
int main()
{
    /*
    x - numarul cautat
    n - dimensiunea vectorului(implicit 1024)
    opt - optiunea meniului
    flag - folosit pentru a forta utilizatorul sa genereze vectorul inainte de toate
    */
    int x, n = 1024, opt = -1, flag = 0;

    do {

        menu(n, &opt);   //afisare meniu

        switch (opt)
        {
            case 1: //optiunea 1 de a genera vectorul
                system("CLS"); //clear screen
                gen_vect_unice(n); //genereaza vectorul
                afisare_numere(n, v);//afiseaza vectorul generat
                flag = 1; //astfel se stie ca a fost generat vectorul macar odata
                pauza();    //pauza pentru vizionare
                break;

            case 2: //optiunea 2 de a schimba dimensiunea vectorului
                printf("Introduceti numarul de elemente dorit: ");
                scanf("%d", &n);
                gen_vect_unice(n);  //se genereaza un nou vector pentru a evita cazul in care se alege un numar n mai mare

                break;

            case 3: //optiunea 3 de a face cautare liniara
                if (flag)
                {
                    system("CLS");  //eliberare ecran
                    //se afiseaza numerele disponibile
                    //schimba culoarea textului
                    printf("\n**********************\n");

                    //se retine aici timpul de inceput

                    struct timespec tstart={0,0}, tend={0,0};
                    clock_gettime(CLOCK_MONOTONIC, &tstart);
                    bubble_sort(n); //se face cautarea elementului x in vectorul v cu n elemente
                    afisare_numere(n, v); // afiseaza vectorul sortat
                    clock_gettime(CLOCK_MONOTONIC, &tend);

                           t1= ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
                           (double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec;


                    
                    printf("\n**********************\n");
                    
                    finished++;
                    pauza();
                }
                else    //cazul in care nu s-a generat un vector inainte, cautarea nu poate fi realizata
                {
                    system("CLS");
                    printf("\nGenerati mai intai vectorul de numere!\n");
                    pauza();
                }
                break;

            case 4: //optiunea 4 in care se realizeaza cautarea binara
                if (flag)
                {
                    system("CLS");
                    
                    printf("\n**********************\n");

                    struct timespec tstart={0,0}, tend={0,0};
                    clock_gettime(CLOCK_MONOTONIC, &tstart);

                    shell_sort(n);
                    afisare_numere(n, v1);

                    clock_gettime(CLOCK_MONOTONIC, &tend);

                     t2= ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
                            (double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec;


          

                    
                    printf("\n**********************\n");
                    
                    finished++;
                    pauza();
                }
                else    //cazul in care nu s-a generat vectorul
                {
                    system("CLS");
                    printf("\nGenerati mai intai vectorul de numere!\n");
                    pauza();
                }
                break;
            case 5:
                if (flag)
                {
                    system("CLS");
                    
                    printf("\n**********************\n");

                    struct timespec tstart={0,0}, tend={0,0};
                    clock_gettime(CLOCK_MONOTONIC, &tstart);

                    quickSort(0, n - 1);
                    afisare_numere(n, v2);
                    clock_gettime(CLOCK_MONOTONIC, &tend);

                     t3= ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
                            (double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec;
                    
                    printf("\n**********************\n");
                    
                    finished++;
                    pauza();
                }
                else    //cazul in care nu s-a generat vectorul
                {
                    system("CLS");
                    printf("\nGenerati mai intai vectorul de numere!\n");
                    pauza();
                }
                break;
            case 6:
                if (finished == 3)
                {
                    system("CLS");
                    
                    printf("\n**********************\n");
                    


                    compara_timpi(t1,t2,t3);
                    
                    printf("\n**********************\n");
                    

                    pauza();
                }
                else    //cazul in care nu s-a generat vectorul
                {
                    system("CLS");
                    printf("\nExecutati mai intai toti algoritmii\n");
                    pauza();
                }
                break;
            case 0:
                break;

            default:    //cazul in care se introduce un numar care nu se afla printre optiuni
                system("CLS");
                printf("Numarul introdus este");
                
                printf(" INEXISTENT\n");
                

                pauza();
        }
    } while (opt);
    free(v);
    return 0;
}




int gen_rand_num(int max) { //functie care genereaza un numar aleator z la apelare
    int x, y, z;
    x = rand();
    y = rand() + x;
    z = (rand() + y) % max;
    return z;
}

void gen_vect_unice(int n) //functie care genereaza vector de n elemente aleatoare
{
    int i, j, x;

    srand(time(NULL));  //foloseste timpul actual pentru generarea numerelor aleatoare
    v = (int *)malloc(sizeof(int) * n);    //alocare dinamica de memorie pentru vectorul creat
    v1 = (int *)malloc(sizeof(int) * n);
    v2 = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        x = gen_rand_num(n + n);    //genereaza un element aleatoare care urmeaza a fi introdus
        for (j = 0; j < i; j++)    //se evita dublurile
        {
            if (v[j] == x) {    //daca exista deja, se genereaza un nou element aleator
                j = n;
                i--;
            }

        }
        if (j < n) {    //daca nu exista in vector deja, se introduce
            v[i] = x;
            v1[i] = x;
            v2[i] = x;
        }

    }
    printf("Vectorul de numere s-a generat cu ");   //mesaj de verificare
    
    printf("SUCCES\n");
    
}

void bubble_sort(int n) //sortarea bubble
{
    int aux, i, j = 1, sorted = 0;
    while (!sorted)
    {
        sorted = 1;  //flag
        for (i = 0; i < n - j; i++)
        {
            if (v[i] > v[i + 1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                sorted = 0;
            }
        }
        j++;
    }
    printf("Vectorul a fost sortat cu ");   //mesaj verificare
    
    printf("SUCCES\n");
    
}





void afisare_numere(int n, int* g) //afisarea vectorului v in mod tabelar
{
    int i, j = 0;

    printf("Vectorul este format din urmatoarele elemente:\n\n");

    
    printf("**************************\n");
    printf("*  +   *");
    for (i = 1; i <= 10; i++)
    {
        printf("   %-2d *", i);  // cap de tabel
    }
    printf("\n");
    printf("**************************\n");
    

    for (i = 0; i < n; i++)    //afisare elemente + pozitia
    {
        j++;
        if (j == 1)
        {
            
            printf("* %-4d *", i);
            
        }

        printf(" %-4d |", g[i]);

        if (j == 10)   //dupa 10 elemente se trece pe randul urmator
        {
            printf("\n");
            j = 0;
        }

    }

    if (j < 10)
        printf("\n");

    
    printf("**************************\n");
    
}

void menu(int n, int* opt) //meniul programului
{

    system("CLS");
    
    printf("****************\n");
    printf(" 1.");
    
    printf("Generati ");
    
    printf("%d ", n);
    
    printf("numere aleatoare pentru cautare\n");
    
    printf(" 2.");
    
    printf("Schimbati marimea sirului de numere\n");
    
    printf(" 3.");
    
    printf("Sortati folosind algoritmul bubble sorrt\n");
    
    printf(" 4.");
    
    printf("Sortati folosind algoritmul shell short\n");
    
    printf(" 5.");
    
    printf("Sortati folosind algoritmul quick sort\n");


    printf(" 6.");
    
    printf("Comparati rezultate\n");
    
    printf(" 0.EXIT\n");
    
    printf("****************\n");
    printf("Optiunea dumneavoastra: ");
    scanf("%d", &*opt);
    printf("****************\n");
    
}

void pauza() // functie de press any key to ccasontinue but in ro
{
    printf("\nApasati orice tasta pentru a reveni la meniu...");
    getch();
}