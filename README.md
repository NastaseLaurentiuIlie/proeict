Cerinta :

Se dă un tablou de N elemente aleatorii. Să se sorteze tabloul prin algoritmii Bubblesort, Shellsort și Quicksort și să se compare timpul de execuție pentru cele 3 metode.

Despre Algoritmii comparati:

Algoritmul Bubble Sort(Sortarea cu Bule/Interschimbare)
Sortarea cu bule este un algoritm simplu de sortare care trece în mod repetat prin listă pentru a fi sortate, compară fiecare pereche de elemente adiacente și le schimbă dacă sunt în ordine greșită. Trecerea prin listă se repetă până când nu sunt necesare swap-uri, ceea ce indică faptul că lista este sortată. Algoritmul, care este un fel de comparație, este numit pentru modul în care elementele mai mici sau mai mari "bule" în partea de sus a listei pe măsură ce sortarea progresează.
Cea mai veche referire cunoscută la algoritm este într-un articol de Tony Hoare în 1961, dar este probabil ca algoritmul să fi fost descoperit și folosit de alți informaticieni înainte de acel moment.

Algoritmul Shell Sort 

Shell sort este un algoritm de comparare în loc de sortare. Îmbunătățește eficiența algoritmilor de sortare și inserție a bulelor. Ideea de bază a algoritmului este de a compara elemente care sunt îndepărtate unele de altele, mai degrabă decât elemente adiacente ca în algoritmii simpli de sortare. Algoritmul începe prin compararea elementelor care sunt departe, iar cu fiecare trecere, distanța dintre elementele comparate este redusă.
Acest lucru permite valorilor mai mari să "interschimbe" la pozițiile lor corecte mai eficient.
Algoritmul de sortare Shell funcționează prin compararea elementelor care se află la o anumită distanță, numită decalaj, și apoi reducerea repetată a decalajului până când devine 1. Diferența este inițial setată la o valoare care este aproximativ jumătate din dimensiunea matricei și este apoi înjumătățită cu fiecare trecere. Elementele sunt apoi comparate și schimbate după cum este necesar, până când matricea este sortată.
Acest algoritm a fost propus de Donald Shell în 1959

Algoritmul QuickSort

Quick Sort este un algoritm de sortare eficient, pe loc, bazat pe comparație. Funcționează prin partiționarea unei matrice în două sub-matrice mai mici, una conținând elemente care sunt mai mici decât un element pivot ales, iar cealaltă conținând elemente care sunt mai mari decât pivotul. Elementul pivot se află apoi în poziția sa finală în matricea sortată și același proces se repetă pe sub-matrice până când întreaga matrice este sortată.

Procedura de bază de sortare rapidă este după cum urmează:

1.	Selectați un element pivot din matrice.
2.	Partiționați matricea în două sub-matrice, una conținând elemente mai mici decât pivotul, iar cealaltă conținând elemente mai mari decât pivotul.
3.	Repetați pașii de mai sus din sub-matrice până când întreaga matrice este sortată.
Sortarea rapidă este unul dintre cei mai eficienți algoritmi de sortare și are o complexitate medie a timpului de caz de O(n log n) și cea mai bună complexitate a timpului de caz al O(n log n) și cea mai gravă complexitate de timp a lui O(n^2)
A fost propus pentru prima dată de Tony Hoare în 1959 și este popular folosit pentru sortarea seturilor mari de date.

Codul C

1.	Algoritmul Bubble Sort:


![image](https://user-images.githubusercontent.com/115789255/212035819-8cd6c210-2e82-4485-bd1c-25f1d13c72b3.png)


2.Algoritmul Shell Sort

![image](https://user-images.githubusercontent.com/115789255/212036076-82399f6c-573a-41b9-8f01-394a7010ffd3.png)


3.Algoritmul Quick Sort


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

4.Generare numere aleatoare pentru cei 3 algoritmi

Aceasta functie creeaza prin 3 vectori lista a 1024 de numere aleatoare.
Vectorii sunt identici pentru fiecare algoritm comparat.


void gen_vect_unice(int n) //functie care genereaza vector de n elemente aleatoare
{
    int i, j, x;

    srand(time(NULL));  //foloseste timpul actual pentru generarea numerelor aleatoare
    v = (int*)malloc(sizeof(int) * n);    //alocare dinamica de memorie pentru vectorul creat
    v1 = (int*)malloc(sizeof(int) * n);
    v2 = (int*)malloc(sizeof(int) * n);
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

5. Meniu

void menu(int n, int* opt) //meniul programului
{



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


6.Functia compara timpii-Concluzie 

Prin aceasta functie am creat comparatia celor 3 algoritmi pentru a avea si o concluzie a proiectului respective algoritmul Quick Sort este cel mai rapid.


