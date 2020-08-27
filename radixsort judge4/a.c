//
// Created by bruno on 27/08/2020.
//

#include "stdio.h"

typedef struct oi {
    char name[15];
} nomes;

int maior(nomes A[], int n)
{
    int i, j, d = 0;
    for (i = 0; i < n; i++) {
        for (j = 1; A[i].name[j - 1] != 0; j++) {
            if (A[i].name[j - 1] < 97)
                A[i].name[j - 1] += 32;
            if (j > d)
                d = j;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < d; j++) {
            if (A[i].name[j] == 0) {
                A[i].name[j]        = 32;
                A[i].name[j + 1] = 0;
            }
        }
    }
    return d;
}

void print(nomes A[], int start, int end)
{
    int i;
    for (i = start; i < end; i++)
        printf("%s\n", A[i].name);
}

void printC(int C[])
{
    int i;
    for (i = 0; i < 27; i++)
        printf("%d ", C[i]);
    printf("\n");
}

void countingSort(nomes A[], int pos, int tamA)
{
    int i, C[27] = {0};
    nomes B[tamA];

    for (i = 0; i < tamA; i++) {
        if (A[i].name[pos] == 32)
            C[0]++;
        else
            C[A[i].name[pos] - 96]++;
    }

    for (i = 1; i < 27; i++)
        C[i] += C[i - 1];

    printC(C);

    for (i = tamA - 1; i >= 0; i--) {
        if (A[i].name[pos] == 32) {
            B[C[0] - 1] = A[i];
            C[0]--;
        } else {
            B[C[A[i].name[pos] - 96] - 1] = A[i];
            C[A[i].name[pos] - 96]--;
        }
    }

    for (i = 0; i < tamA; i++)
        A[i] = B[i];
}

void radixSort(nomes A[], int tmax, int tamA)
{
    int i;
    for (i = tmax - 1; i >= 0; i--)
        countingSort(A, i, tamA);
}



int main()
{
    int i, tam, start, end;
    scanf("%d", &tam);
    nomes A[tam];
    for (i = 0; i < tam; i++)
        scanf("%s", A[i].name);
    scanf("%d %d", &start, &end);
    radixSort(A, maior(A, tam), tam);
    print(A, start - 1, end + start - 1);
}