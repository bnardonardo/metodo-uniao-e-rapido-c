#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <sys/time.h>

#define MAX 50
//inicio uniao
void merge(int v[], int aux[], int inicio1, int inicio2, int fim2) {
int i = inicio1, j = inicio2, fim1 = inicio2 - 1, k = 0;

while ((i <= fim1) && (j <= fim2))

if (v[i] < v[j])
aux[k++] = v[i++];
else
aux[k++] = v[j++];
while (i <= fim1)
aux[k++] = v[i++];
while (j <= fim2)
aux[k++] = v[j++];
for (i = 0; i < k; i++)
v[i + inicio1] = aux[i];
}
void mergesort(int v[], int aux[], int inicio, int fim) {
int meio = (inicio + fim) / 2;

if (inicio < fim) {
mergesort(v, aux, inicio, meio); // ordena 1 parte
mergesort(v, aux, meio + 1, fim); // ordena 2 parte
merge(v, aux, inicio, meio + 1, fim); // organiza as 2
}

}
//fim uniao
//inicio quicksort
int particiona (int v[], int inicio, int finall){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = finall;
    pivo = v[inicio];
    while (esq<dir){
        while(v[esq]<= pivo)
            esq++;
        while(v[dir] > pivo)
            dir--;
        if (esq < dir){
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;

}

void QuickSort (int v[], int esq, int dir){ //i esqu elemento maior q pivo, j direira elemento menor q pivo
    int pivo;
    if (dir > esq){
        pivo = particiona(v, esq, dir);
        QuickSort(v, esq, pivo-1);
        QuickSort(v, pivo+1, dir);


    }
}
//fim qicksort
int main() {
int v[MAX], aux[MAX], n, i, inicio, finall;
n=50;
    double sum = 0;
    double add = 1;

printf("serao selecionados 50 valores aleatorios \n\n");
for (i=0; i<n; i++)
v[i] = rand()%101;
for (inicio=0; inicio<finall; inicio++)
v[inicio] = rand()%101;


 // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);


printf("ordenacao pelo metodo uniao/ merge sort:");
mergesort( v, aux, 0, n - 1);
for (i = 0; i < n; i++)
printf("%d \n", v[i]);
printf("\n");


 // Stop measuring time and calculate the elapsed time
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;

    printf("Result: %.20f\n", sum);

    printf("Time measured: %.3f seconds.\n\n", elapsed);



printf("ordenacao pelo metodo rapido/  quicksort:");
    QuickSort (v, inicio, n-1);

for (inicio = 0; inicio < finall; inicio++)
printf("%d \n", v[inicio]);
printf("\n");

return 0;
}

