#include <stdio.h>
#include <stdlib.h>

struct noArv {
    int info;
    struct noArv* esq;
    struct noArv* dir;
};
typedef struct noArv NoArv;

NoArv* abb_cria (void)
{
    return NULL;
}

void abb_imprime (NoArv* a)
{
    if (a != NULL) {
        abb_imprime(a->esq);
        printf("%d\n",a->info);
        abb_imprime(a->dir);
    }
}

NoArv* abb_busca (NoArv* r, int v)
{
    if (r == NULL)
        return NULL;
    else if (r->info > v)
        return abb_busca (r->esq, v);
    else if (r->info < v)
        return abb_busca (r->dir, v);
    else return r;
}

NoArv* abb_insere (NoArv* a, int v)
{
    if (a==NULL) {
        a = (NoArv*)malloc(sizeof(NoArv));
        a->info = v;
        a->esq = a->dir = NULL;
    }
    else if (v < a->info)
        a->esq = abb_insere(a->esq,v);
    else if (v > a->info)
        a->dir = abb_insere(a->dir,v);
    return a;
}

NoArv* abb_retira (NoArv* r, int v)
{
    if (r == NULL)
        return NULL;
    else if (r->info > v)
        r->esq = abb_retira(r->esq, v);
    else if (r->info < v)
        r->dir = abb_retira(r->dir, v);
    else { /* achou o nó a remover */
        /* nó sem filhos */
        if (r->esq == NULL && r->dir == NULL) {
            free (r);
            r = NULL;
        }
            /* nó só tem filho à direita */
        else if (r->esq == NULL) {
            NoArv* t = r;
            r = r->dir;
            free (t);
        }
        /* só tem filho à esquerda */
        else if (r->dir == NULL) {
            NoArv* t = r;
            r = r->esq;
            free (t);
        }
            /* nó tem os dois filhos */
        else {
            NoArv* f = r->esq;
            while (f->dir != NULL) {
                f = f->dir;
            }
            r->info = f->info; /* troca as informações */
            f->info = v;
            r->esq = abb_retira(r->esq,v);
        }
    }
    return r;
}

int maxDepth(NoArv* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->esq);
        int rDepth = maxDepth(node->dir);

        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth+1);
        else return(rDepth+1);
    }
}

int main() {
    int num=0,insere,tam=0,altura;
    struct noArv* a = NULL;
    while (num >= 0){
        scanf("%d ",&num);
        if (num >= 0) {
            a = abb_insere(a, num);
            tam++;
        }
    }
    altura = maxDepth(a);
    scanf("%d",&insere);
    printf("%d %d\n",tam,altura);
    if(abb_busca(a,insere) == NULL){
         a = abb_insere(a,insere);
         tam++;
    }
    else{
        a = abb_retira(a,insere);
        tam--;
    }
    altura = maxDepth(a);
    printf("%d %d",tam,altura);




}
