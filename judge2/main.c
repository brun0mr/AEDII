#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct{
    char nome[15];
    int idade;
}AAA[105000];

struct{
    char nome[15];
    int idade;
}AA2[105000];

void Estavel(int n){
    int w, i, j, k;
    w = 0;
    for(i=0; i<(n-1); i++){
        if(AAA[i].idade == AAA[i + 1].idade){
            for(j=0; j<n; j++){
                if(AA2[j].idade == AAA[i].idade){
                    k = strcmp(AA2[j].nome, AAA[i].nome);
                    if(k != 0){
                        w++;
                    }
                    break;
                }
                k = 0;
            }
        }
    }
    if(w == 0){
        printf("yes\n");
    }
    if(w != 0){
        printf("no\n");
    }
}

void swap(int i, int j){
    char auxnom[15];
    int auxint;
    strcpy(auxnom, AAA[i].nome);
    auxint = AAA[i].idade;
    strcpy(AAA[i].nome, AAA[j].nome);
    AAA[i].idade = AAA[j].idade;
    strcpy(AAA[j].nome, auxnom);
    AAA[j].idade = auxint;
}

int Partition(int p, int r){
    int x, i, j;
    x = AAA[r].idade;
    i = p-1;
    for(j=p; j<r; j++){
        if(AAA[j].idade <= x){
            i++;
            swap(i, j);
        }
    }
    swap(i+1, r);
    return(i+1);
}

void QuickSort(int p, int r) {
    int a, b, c, meio, q, medianaIndice, i;
    if(p<r){
        meio = (p+r)/2;
        a = AAA[p].idade;
        b = AAA[meio].idade;
        c = AAA[r].idade;
        medianaIndice = 0;
        if (a < b){
            if (b < c){
                medianaIndice = meio;
            }
            else{
                if (a < c){
                    medianaIndice = r;
                }
                else{
                    medianaIndice = p;
                }
            }
        }
        else{
            if (c < b){
                medianaIndice = meio;
            }
            else{
                if (c < a){
                    medianaIndice = r;
                }
                else{
                    medianaIndice = p;
                }
            }
        }
        swap(medianaIndice, r);
        q = Partition(p, r);
        QuickSort(p, q-1);
        QuickSort(q+1, r);
    }
}

int main (){
    int numpess, i, P, M, c, j;
    scanf ("%d", &numpess);
    for (i=0 ; i < numpess ; i++){
        scanf("%s", AAA[i].nome);
        scanf("%d", &AAA[i].idade);
    }
    for (i=0 ; i < numpess ; i++){
        strcpy(AA2[i].nome, AAA[i].nome);
        AA2[i].idade = AAA[i].idade;
    }
    scanf("%d", &P);
    scanf("%d", &M);
    P = P - 1;
    M = M - 1;
    QuickSort(0, (numpess - 1));
    Estavel(numpess);
    for(i=P ; i <= (P + M) ; i++){
        printf("%s", AAA[i].nome);
        printf(" %d\n", AAA[i].idade);
    }
}