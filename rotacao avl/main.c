//Bruno Maciel Rotondaro
//RA: 140579

#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
    TChave Chave;
    /* outros componentes */
} TItem;

typedef struct SNo *TArvBin;

typedef struct SNo {
    TItem Item;
    TArvBin Esq, Dir;
} TNo;

TArvBin Carrega()
{
    char c;
    TArvBin No;
    scanf("%c", &c);
    if (c == '(') {
        scanf("%c", &c);
        if (c == 'C') {
            No = (TArvBin) malloc(sizeof(TNo));
            scanf("%d", &No->Item.Chave);
            No->Esq = Carrega();
            No->Dir = Carrega();
            scanf("%c", &c);
        }
        else if (c == ')')
            No = NULL;
    }
    return No;
}

void Imprime(TArvBin No)
{
    if (No != NULL) {
        printf("(C%d", No->Item.Chave);
        Imprime(No->Esq);
        Imprime(No->Dir);
        printf(")");
    }
    else
        printf("()");
}

int maxDepth(TArvBin node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->Esq);
        int rDepth = maxDepth(node->Dir);

        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth+1);
        else return(rDepth+1);
    }
}

int balanco(TArvBin node){
    return (maxDepth(node->Esq)-maxDepth(node->Dir));
}

TArvBin balancear(TArvBin node){
    TArvBin pB;
    TArvBin pA = node;
    TArvBin pC;
    int A,ESQ,DIR;
    A = balanco(node);
    ESQ = balanco(node->Esq);
    DIR = balanco(node->Dir);
    //LL
    if (A > 1 && ESQ > 0) {
        pB = pA->Esq;
        pA->Esq = pB->Dir;
        pB->Dir = pA;
        pA = pB;
        printf("LL\n");
    }
    //RR
    else if (A < -1 && DIR < 0){
        pB = pA->Dir;
        pA->Dir = pB->Esq;
        pB->Esq = pA;
        pA = pB;
        printf("RR\n");
    }
    //LR
    else if (A > 1 && ESQ < 0){
        pB = pA->Esq;
        pC = pB->Dir;
        pB->Dir = pC->Esq;
        pC->Esq = pB;
        pA->Esq = pC->Dir;
        pC->Dir = pA;
        pA = pC;
        printf("LR\n");
    }
    //RL
    else if (A < -1 && DIR > 0){
        pB = pA->Dir;
        pC = pB->Esq;
        pB->Esq = pC->Dir;
        pC->Dir = pB;
        pA->Dir = pC->Esq;
        pC->Esq = pA;
        pA = pC;
        printf("RL\n");
    }

    return (pA);
}


int main()
{
    TArvBin Raiz;
    TItem x;
    int altura;
    Raiz = Carrega(); //le arvore binaria inicial com parenteses aninhados
    altura = maxDepth(Raiz);
    printf("%d\n",altura-1);
    Imprime(Raiz);
    printf("\n");
    Raiz = balancear(Raiz);
    //imprime rotacao
    altura = maxDepth(Raiz);
    printf("%d\n",altura-1);
    Imprime(Raiz);


    return 0;
}


