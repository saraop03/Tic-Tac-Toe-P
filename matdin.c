//
// Created by Sara on 5/16/2022.
//

#include "matdin.h"
#include "utils.h"

void libertaMat(char** p, int nLin){

    int i;

    for(i=0; i<nLin; i++)
        free(p[i]);
    free(p);
}

char** criaMat(int nLin, int nCol){
    char **p = NULL;
    int i, j;

    p = malloc(sizeof(char*) * nLin);
    if(p == NULL)
        return NULL;

    for(i=0; i<nLin; i++){
        p[i] = malloc(sizeof(char) * nCol);
        if(p[i] == NULL){
            libertaMat(p, i-1);
            return NULL;
        }
        for(j=0; j<nCol; j++) {
            p[i][j] = '_';
        }
    }
    return p;
}

void setPos(char **p, int x, int y, char c){
    p[x][y] = c;
}

char getPos(char **p, int x, int y){//verificar se já tem alguma jogada feita
    return p[x][y];
}

void mostraMat(char **p, int nLin, int nCol){
    int i,j;

    for(i=0; i<nLin; i++){
        if (i==3 || i==6)
            printf("\n");

        if(nCol==3) {
            for (j = 0; j < 3; j++) {
                printf("%c\t", p[i][j]);
                if (j == 2 || j == 5)
                    printf("\t");
            }
        }
        else {

            for (j = 0; j < nCol; j++) {
                printf("%c\t", p[i][j]);
                if (j == 2 || j == 5)
                    printf("|\t");
            }
        }


        putchar('\n');
    }
}

//jogar
void tabuleiroGrande(char **tabuleiroG){
    printf("\nTabuleiro grande:\n");
    mostraMat(tabuleiroG, 3, 3);
}

void mudaGrande(int *l,int *c){
    if (*l == 3)
        *l = 1;
    if (*c == 3)
        *c = 1;
    if (*l == 3 && *c == 3){
        *l = 1;
        *c = 1;
    }

    if (*l == 6)
        *l = 2;
    if (*c == 6)
        *c = 2;
    if (*l == 6 && *c == 6){
        *l = 2;
        *c = 2;
    }
}

void verificaVit(char **tabuleiro, int l, int c, char **tabuleiroG){
    //Verifica linha
    if (tabuleiro[l][c] == tabuleiro[l][c+1] && tabuleiro[l][c] == tabuleiro[l][c+2] && tabuleiro[l][c] != '_' && tabuleiro[l][c+1] != '_' && tabuleiro[l][c+2] != '_') {
        if (tabuleiro[l][c] == 'x') {
            mudaGrande(&l, &c);
            setPos(tabuleiroG, l, c, 'x');
        }
        if (tabuleiro[l][c] == 'o') {
            mudaGrande(&l, &c);
            setPos(tabuleiroG, l, c, 'o');
        }
    }
    if (tabuleiro[l+1][c] == tabuleiro[l+1][c+1] && tabuleiro[l+1][c] == tabuleiro[l+1][c+2] && tabuleiro[l+1][c] != '_' && tabuleiro[l+1][c+1] != '_' && tabuleiro[l+1][c+2] != '_') {
        if (tabuleiro[l+1][c] == 'x') {
            mudaGrande(&l, &c);
            setPos(tabuleiroG, l, c, 'x');
        }
        if (tabuleiro[l+1][c] == 'o') {
            mudaGrande(&l, &c);
            setPos(tabuleiroG, l, c, 'o');
        }
    }
    if (tabuleiro[l+2][c] == tabuleiro[l+2][c+1] && tabuleiro[l+2][c] == tabuleiro[l+2][c+2] && tabuleiro[l+2][c] != '_' && tabuleiro[l+2][c+1] != '_' && tabuleiro[l+2][c+2] != '_') {
        if (tabuleiro[l+2][c] == 'x') {
            mudaGrande(&l, &c);
            setPos(tabuleiroG, l, c, 'x');
        }
        if (tabuleiro[l+2][c] == 'o') {
            mudaGrande(&l, &c);
            setPos(tabuleiroG, l, c, 'o');
        }
    }

    //Verifica coluna
    if (tabuleiro[l][c] == tabuleiro[l+1][c] && tabuleiro[l][c] == tabuleiro[l+2][c] && tabuleiro[l][c] != '_' && tabuleiro[l+1][c] != '_' && tabuleiro[l+2][c] != '_') {
        if (tabuleiro[l][c] == 'x') {
            mudaGrande(&l, &c);
            setPos(tabuleiroG, l, c, 'x');
        }
        if (tabuleiro[l][c] == 'o') {
            mudaGrande(&l, &c);
            setPos(tabuleiroG, l, c, 'o');
        }
    }
    if (tabuleiro[l][c+1] == tabuleiro[l+1][c+1] && tabuleiro[l][c+1] == tabuleiro[l+2][c+1] && tabuleiro[l][c+1] != '_' && tabuleiro[l+1][c+1] != '_' && tabuleiro[l+2][c+1] != '_') {
        if (tabuleiro[l][c+1] == 'x') {
            mudaGrande(&l, &c);
            setPos(tabuleiroG, l, c, 'x');
        }
        if (tabuleiro[l][c+1] == 'o') {
            mudaGrande(&l, &c);
            setPos(tabuleiroG, l, c, 'o');
        }
    }
    if (tabuleiro[l][c+2] == tabuleiro[l+1][c+2] && tabuleiro[l][c+2] == tabuleiro[l+2][c+2] && tabuleiro[l][c+2] != '_' && tabuleiro[l+1][c+2] != '_' && tabuleiro[l+2][c+2] != '_') {
        if (tabuleiro[l][c+2] == 'x') {
            mudaGrande(&l, &c);
            setPos(tabuleiroG, l, c, 'x');
        }
        if (tabuleiro[l][c+2] == 'o') {
            mudaGrande(&l, &c);
            setPos(tabuleiroG, l, c, 'o');
        }
    }

    //Verifica diagonal
    if (tabuleiro[l][c] == tabuleiro[l+1][c+1] && tabuleiro[l][c] == tabuleiro[l+2][c+2] && tabuleiro[l][c] != '_' && tabuleiro[l+1][c+1] != '_' && tabuleiro[l+2][c+2] != '_') {
        if (tabuleiro[l][c] == 'x') {
            mudaGrande(&l, &c);
            setPos(tabuleiroG, l, c, 'x');
        }
        else
        if (tabuleiro[l][c] == 'o') {
            mudaGrande(&l, &c);
            setPos(tabuleiroG, l, c, 'o');
        }
    }
    if (tabuleiro[l+2][c] == tabuleiro[l+1][c+1] && tabuleiro[l+2][c] == tabuleiro[l][c+2] && tabuleiro[l+2][c] != '_' && tabuleiro[l+1][c+1] != '_' && tabuleiro[l][c+2] != '_') {
        if (tabuleiro[l+2][c] == 'x') {
            mudaGrande(&l, &c);
            setPos(tabuleiroG, l, c, 'x');
        }
        else
        if (tabuleiro[l+2][c] == 'o') {
            mudaGrande(&l, &c);
            setPos(tabuleiroG, l, c, 'o');
        }
    }
}

void existe(char **tabuleiro,int *l,int *c){
    char pos;
    do {
        pos = getPos(tabuleiro, *l, *c);//recebe a posição
        if (pos == 'x' || pos == 'o') {//para não permitir que percorra o ciclo na primeira vez
            printf("Essa posição já foi escolhida, insira uma nova coordenada!\n");
            printf("Insira uma nova coordenada:");
            scanf("%d %d", &*l, &*c);
        }
    } while (pos == 'x' || pos == 'o');//verifica se já existe alguma jogada
}

void fora(int *l, int *c){
    do{
        if(*l > 8 || *c > 8 || *l > 8 && *c > 8) {
            printf("Essas coordenadas não correspondem ao oitavo mini-tabuleiro!\n");
            printf("Insira uma coordenada para o oitavo mini-tabuleiro:");
            scanf("%d %d", &*l, &*c);
        }
    } while(*l > 8 || *c > 8 || *l > 8 && *c > 8);
}

int existeG(char **tabuleiroG,int l,int c){
    char pos;
    mudaGrande(&l,&c);

    pos = getPos(tabuleiroG, l, c);//recebe a posição
    if (pos == 'x' || pos == 'o') {//para não permitir que percorra o ciclo na primeira vez
        printf("Esse mini-tabuleiro já tem um vencedor!\n");
        return 1;
    }
    else
        return 0;
}

void colocaJogada(char **tabuleiro, int l, int c, int jogada){
    if (jogada == 1) {
        setPos(tabuleiro, l, c, 'x');
        jogada = 2;
    } else if (jogada == 2) {
        setPos(tabuleiro, l, c, 'o');
        jogada = 1;
    }
}

void ver(int la, int ca, int *saltar){
    if (la == 0 && ca == 0 || la == 0 && ca == 3 || la == 0 && ca == 6 || la == 3 && ca == 0 ||
        la == 3 && ca == 3 || la == 3 && ca == 6 || la == 6 && ca == 0 || la == 6 && ca == 3 ||
        la == 6 && ca == 6)
        *saltar = 0;
    if (la == 0 && ca == 1 || la == 0 && ca == 4 || la == 0 && ca == 7 || la == 3 && ca == 1 ||
        la == 3 && ca == 4 || la == 3 && ca == 7 || la == 6 && ca == 1 || la == 6 && ca == 4 ||
        la == 6 && ca == 7)
        *saltar = 1;
    if (la == 0 && ca == 2 || la == 0 && ca == 5 || la == 0 && ca == 8 || la == 3 && ca == 2 ||
        la == 3 && ca == 5 || la == 3 && ca == 8 || la == 6 && ca == 2 || la == 5 && ca == 8 ||
        la == 6 && ca == 8)
        *saltar = 2;
    if (la == 1 && ca == 0 || la == 1 && ca == 3 || la == 1 && ca == 6 || la == 4 && ca == 0 ||
        la == 4 && ca == 3 || la == 4 && ca == 6 || la == 7 && ca == 0 || la == 7 && ca == 3 ||
        la == 7 && ca == 6)
        *saltar = 3;
    if (la == 1 && ca == 1 || la == 1 && ca == 4 || la == 1 && ca == 7 || la == 4 && ca == 1 ||
        la == 4 && ca == 4 || la == 4 && ca == 7 || la == 7 && ca == 1 || la == 7 && ca == 4 ||
        la == 7 && ca == 7)
        *saltar = 4;
    if (la == 1 && ca == 2 || la == 1 && ca == 5 || la == 1 && ca == 8 || la == 4 && ca == 2 ||
        la == 4 && ca == 5 || la == 4 && ca == 8 || la == 7 && ca == 2 || la == 7 && ca == 5 ||
        la == 7 && ca == 8)
        *saltar = 5;
    if (la == 2 && ca == 0 || la == 2 && ca == 3 || la == 2 && ca == 6 || la == 5 && ca == 0 ||
        la == 5 && ca == 3 || la == 5 && ca == 6 || la == 8 && ca == 0 || la == 8 && ca == 3 ||
        la == 8 && ca == 6)
        *saltar = 6;
    if (la == 2 && ca == 1 || la == 2 && ca == 4 || la == 2 && ca == 7 || la == 5 && ca == 1 ||
        la == 5 && ca == 4 || la == 5 && ca == 7 || la == 8 && ca == 1 || la == 8 && ca == 4 ||
        la == 8 && ca == 7)
        *saltar = 7;
    if (la == 2 && ca == 2 || la == 2 && ca == 5 || la == 2 && ca == 8 || la == 5 && ca == 2 ||
        la == 5 && ca == 5 || la == 5 && ca == 8 || la == 8 && ca == 2 || la == 8 && ca == 5 ||
        la == 8 && ca == 8)
        *saltar = 8;
}

int cheio(char **tabuleiro, int l, int c){
    int contar = 0;
    for (l = 0 ; l < 9 ; l++){
        for (c = 0 ; c < 9 ; c++){
            if (getPos(tabuleiro,l,c) != '-')
                contar++;
        }
    }
    if (contar == 8)
        return 1;
    else
        return 0;
}

int verificaVitG(char **tabuleiroG, int l, int c){
    //Verifica linha
    if (tabuleiroG[l][c] == tabuleiroG[l][c+1] && tabuleiroG[l][c] == tabuleiroG[l][c+2] && tabuleiroG[l][c] != '_' && tabuleiroG[l][c+1] != '_' && tabuleiroG[l][c+2] != '_') {
        if (tabuleiroG[l][c] == 'x')
            return 1;
        if (tabuleiroG[l][c] == 'o')
            return 1;
    }
    if (tabuleiroG[l+1][c] == tabuleiroG[l+1][c+1] && tabuleiroG[l+1][c] == tabuleiroG[l+1][c+2] && tabuleiroG[l+1][c] != '_' && tabuleiroG[l+1][c+1] != '_' && tabuleiroG[l+1][c+2] != '_') {
        if (tabuleiroG[l+1][c] == 'x')
            return 1;
        if (tabuleiroG[l+1][c] == 'o')
            return 1;
    }
    if (tabuleiroG[l+2][c] == tabuleiroG[l+2][c+1] && tabuleiroG[l+2][c] == tabuleiroG[l+2][c+2] && tabuleiroG[l+2][c] != '_' && tabuleiroG[l+2][c+1] != '_' && tabuleiroG[l+2][c+2] != '_') {
        if (tabuleiroG[l+2][c] == 'x')
            return 1;
        if (tabuleiroG[l+2][c] == 'o')
            return 1;
    }

    //Verifica coluna
    if (tabuleiroG[l][c] == tabuleiroG[l+1][c] && tabuleiroG[l][c] == tabuleiroG[l+2][c] && tabuleiroG[l][c] != '_' && tabuleiroG[l+1][c] != '_' && tabuleiroG[l+2][c] != '_') {
        if (tabuleiroG[l][c] == 'x')
            return 1;
        if (tabuleiroG[l][c] == 'o')
            return 1;
    }
    if (tabuleiroG[l][c+1] == tabuleiroG[l+1][c+1] && tabuleiroG[l][c+1] == tabuleiroG[l+2][c+1] && tabuleiroG[l][c+1] != '_' && tabuleiroG[l+1][c+1] != '_' && tabuleiroG[l+2][c+1] != '_') {
        if (tabuleiroG[l][c+1] == 'x')
            return 1;
        if (tabuleiroG[l][c+1] == 'o')
            return 1;
    }
    if (tabuleiroG[l][c+2] == tabuleiroG[l+1][c+2] && tabuleiroG[l][c+2] == tabuleiroG[l+2][c+2] && tabuleiroG[l][c+2] != '_' && tabuleiroG[l+1][c+2] != '_' && tabuleiroG[l+2][c+2] != '_') {
        if (tabuleiroG[l][c+2] == 'x')
            return 1;
        if (tabuleiroG[l][c+2] == 'o')
            return 1;
    }

    //Verifica diagonal
    if (tabuleiroG[l][c] == tabuleiroG[l+1][c+1] && tabuleiroG[l][c] == tabuleiroG[l+2][c+2] && tabuleiroG[l][c] != '_' && tabuleiroG[l+1][c+1] != '_' && tabuleiroG[l+2][c+2] != '_') {
        if (tabuleiroG[l][c] == 'x')
            return 1;
        if (tabuleiroG[l][c] == 'o')
            return 1;
    }
    if (tabuleiroG[l+2][c] == tabuleiroG[l+1][c+1] && tabuleiroG[l+2][c] == tabuleiroG[l][c+2] && tabuleiroG[l+2][c] != '_' && tabuleiroG[l+1][c+1] != '_' && tabuleiroG[l][c+2] != '_') {
        if (tabuleiroG[l + 2][c] == 'x')
            return 1;
        if (tabuleiroG[l + 2][c] == 'o')
            return 1;
    }
    return 0;
}

void existeC(char **tabuleiro,int *l,int *c){
    char pos;
    do {
        pos = getPos(tabuleiro, *l, *c);//recebe a posição
        if (pos == 'x' || pos == 'o') {//para não permitir que percorra o ciclo na primeira vez
            *l = intUniformRnd(0, 9);
            *c = intUniformRnd(0, 9);
        }
    } while (pos == 'x' || pos == 'o');//verifica se já existe alguma jogada
}

void foraC(char **tabuleiro, int *l, int *c){
    *l = intUniformRnd(0, 8);
    *c = intUniformRnd(0, 8);
    existeC(tabuleiro, l, c);
}

int cheioC(char **tabuleiro, int l, int c){
    int contar = 0;
    for (l = 0 ; l < 9 ; l++){
        for (c = 0 ; c < 9 ; c++){
            if (getPos(tabuleiro,l,c) != '-')
                contar++;
        }
    }
    if (contar == 8)
        return 1;
    else
        return 0;
}

//menu
