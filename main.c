#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Rozmiar_Tablicy 21
#define Min 1
#define Max 13
#define Rozmiar_Histograma 11

void WypelnijTablice(int *tab, int min, int max);

int SumaTablicy(int *tab);

float SredniaTablicy(int *tab);

void GenerujHistogram(int *tab, int *hist);

void WypiszTablice(int *tab);

void WypiszStatystyki(int *tab, int suma, float srednia, int *hist);

int main() {
    int tablica[Rozmiar_Tablicy];
    int histogram[Rozmiar_Histograma];
    for (int i = 0; i < Rozmiar_Histograma; i++) {
        histogram[i] = 0;
    }
    WypelnijTablice(tablica, Min, Max);
    GenerujHistogram(tablica, histogram);
    WypiszTablice(tablica);
    WypiszStatystyki(tablica, SumaTablicy(tablica), SredniaTablicy(tablica), histogram);
    return 0;
}

void WypelnijTablice(int *tab, int min, int max) {
    srand(time(0));
    for (int i = 0; i < Rozmiar_Tablicy; i++) {
        tab[i] = Min + rand() % (Max - Min + 1);
    }
}

int SumaTablicy(int *tab) {
    int suma = 0;
    for (int i = 0; i < Rozmiar_Tablicy; i++) {
        suma = suma + tab[i];
    }
    return suma;
}

float SredniaTablicy(int *tab) {
    float srednia = 0;
    srednia = SumaTablicy(tab) / Rozmiar_Tablicy;
    return srednia;
}

void GenerujHistogram(int *tab, int *hist) {
    for (int i = 0; i < Rozmiar_Tablicy; i++) {
        hist[tab[i]] = hist[tab[i]] + 1;
    }
}

void WypiszTablice(int *tab) {
    printf("\n[");
    for (int i = 0; i < Rozmiar_Tablicy; i++) {
        printf("%d ", tab[i]);
    }
    printf("]\n");
}

void WypiszStatystyki(int *tab, int suma, float srednia, int *hist) {
    printf("Suma: %d \n", suma);
    printf("Srednia: %.2f \n", srednia);
    for (int i = 0; i < Rozmiar_Histograma; i++) {
        printf("%d -> %d \n", i, hist[i]);
    }
}

