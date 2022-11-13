//
// Created by Sara on 19/06/2022.
//

#include "matdin.h"
#include "utils.h"
#include "menu.h"
#include "jogar.h"
#include <stdio.h>

//menu

void preenche(pjogadas p, int jogador, int l, int c){
    if(jogador==1)
        jogador=2;
    else
        jogador=1;
    p->jogador = jogador;
    p->l = l;
    p->c = c;
    p->prox = NULL;
}

pjogadas insere_final (pjogadas p, int jogador, int l, int c) { //guarda na lista ligada a jogada realizada
    pjogadas novo, aux;
    novo = malloc(sizeof(jogadas));
    if (novo == NULL){
        printf("Erro na alocação de memória");
        return p;
    }
    preenche(novo,jogador,l,c);
    if(p == NULL){
        p = novo;
    }
    else{
        aux = p;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return p;
}

void verJogadas(int njogadas, pjogadas p){//mostra o numero de jogadas anteriores que o utilizador pretende ver
    pjogadas novo;
    int conta_total = 0 , conta_sub = 0 , pos = 0;

    novo = p;

    while(novo->prox != NULL){
        conta_total++;
        novo = novo->prox;
    }
    novo = p;

    conta_sub = conta_total - njogadas;

    printf("-------------------------------------------------------");
    while (novo != NULL){
        if (pos > conta_sub) {
            if (novo->jogador


            == 1)
                printf("\nO jogador 2 inseriu as coordenadas (%d,%d)\n", novo->l, novo->c);
            else
                printf("\nO jogador 1 inseriu as coordenadas (%d,%d)\n", novo->l, novo->c);
        }
        pos++;
        novo = novo->prox;
    }
    printf("-------------------------------------------------------");
}

void menuJ(pjogadas jogo, int njogadas, int *sair){//menu que aparece antes de cada jogada
    int verJ , menu , realizar;
    printf("\nPrima 0 se pretende aceder ao menu:");
    scanf("%d", &menu);
    if (menu == 0) {
        printf("0- Continuar jogo\n");
        printf("1- Verificar jogadas\n");
        printf("2- Sair\n");
        printf("\nO que pretende realizar?");
        scanf("%d", &realizar);
        if ( realizar == 1) {
            printf("\nQuantas jogadas pretende visualizar?");
            scanf("%d",&verJ);
            verJogadas(verJ, jogo);
        }
        if (realizar == 2) {
            printf("Sair...");
            grava_lista_bin(jogo, njogadas);
            *sair = 1;
        }
    }
}

void leDados(pjogadas *p, int *njogadas){//le os dados guardados no ficheiro binario
    FILE *f;
    jogadas lista ;
    *njogadas = 0;
    f = fopen("jogo.bin", "rb");
    if(f==NULL)
    {
        printf("Erro no acesso ao ficheiro\n");
        return ;
    }
    //fread(njogadas, sizeof(jogadas), 1, f);

    while(fread(&lista, sizeof(jogadas), 1, f)) {
        *p = insere_final(*p, lista.jogador, lista.l, lista.c);
    }
    fclose(f);

}

void grava_lista_bin(pjogadas p, int njogadas){//grava o ficheiro binario

    FILE *f;
    f = fopen("jogo.bin", "wb");
    if(f==NULL){
        printf("erro");
        return;
    }
    printf("%d",njogadas);
    while(p!=NULL) {
        fwrite(p, sizeof(jogadas), 1, f);
        p = p->prox;
    }

    fclose(f);
}

