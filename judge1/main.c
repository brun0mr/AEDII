//
// Created by bruno on 04/08/2020.
//

#include <stdio.h>
#include <stdlib.h>

struct candidato {
    int votos;
    int indice;
};


int main() {
    int eleitores, candidatos, i, j;

    scanf("%d %d", &eleitores, &candidatos);
    int MatrizEleitores[eleitores][3];
    for (i = 0; i < eleitores; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &MatrizEleitores[i][j]);
        }
    }
    int votosvalidos = 0;
    struct candidato maior;
    struct candidato segundomaior;
    struct candidato vetorcandidatos[candidatos];
    maior.votos = 0;
    segundomaior.votos = 0;
    segundomaior.indice = 0;
    //enchendo o vetor candidatos
    for (i = 0; i < candidatos; i++) {
        vetorcandidatos[i].indice = i;
        vetorcandidatos[i].votos = 0;
    }
    //separando os votos validos
    for (i = 0; i < eleitores; i++) {
        if (MatrizEleitores[i][0] <= candidatos && MatrizEleitores[i][0] > 0) {
            vetorcandidatos[MatrizEleitores[i][0]-1].votos++;
            votosvalidos++;
        }
    }
    //separando o maior voto
    for (i = 0; i < candidatos; i++) {
        if (vetorcandidatos[i].votos > maior.votos) {
            maior.votos = vetorcandidatos[i].votos;
            maior.indice = vetorcandidatos[i].indice;
        }
    }
    //separando o segundo maior voto
    for (i = 0; i < candidatos; i++) {
        if (vetorcandidatos[i].votos > segundomaior.votos && i != maior.indice ) {
            segundomaior.votos = vetorcandidatos[i].votos;
            segundomaior.indice = vetorcandidatos[i].indice;
        }
    }
    float porcentagem = (float)maior.votos/(float)votosvalidos;

    if (porcentagem >= 0.5 && votosvalidos != 0)
    {
        printf("%d %0.2f", maior.indice+1, porcentagem*100);
    }
    else if (porcentagem < 0.5 && votosvalidos != 0)
    {
        int vencedor1 = maior.indice;
        votosvalidos = 0;
        maior.votos = 0;
        segundomaior.votos = 0;

        for (i = 0; i < eleitores; i++) {
                for (j = 0; j < 3; j++) {
                    if (MatrizEleitores[i][j] - 1 == maior.indice) {
                        maior.votos++;
                        votosvalidos++;
                        break;
                    } else if (MatrizEleitores[i][j] - 1 == segundomaior.indice) {
                        segundomaior.votos++;
                        votosvalidos++;
                        break;
                    }
                }
        }

        float porcentagem1 = (float)maior.votos/(float)votosvalidos;
        float porcentagem2 = (float)segundomaior.votos/(float)votosvalidos;

        if (segundomaior.votos < maior.votos)
        {
            printf("%d %0.2f\n%d %0.2f", vencedor1+1, porcentagem*100, maior.indice+1, porcentagem1*100);
        }
        else
        {
            printf("%d %0.2f\n%d %0.2f", vencedor1+1, porcentagem*100, segundomaior.indice+1, porcentagem2*100);
        }
    }
    else
    {
        printf("0");
    }



}
