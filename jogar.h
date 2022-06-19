//
// Created by Sara on 19/06/2022.
//

#ifndef MAIN_C_JOGAR_H
#define MAIN_C_JOGAR_H

/*typedef struct jogadass jogadas, *pjogadas;

struct jogadass{
    int jogador , l , c;
    pjogadas prox;
};*/


//jogar
void tabuleiroGrande(char **tabuleiroG);

void mudaGrande(int *l,int *c);

void verificaVit(char **tabuleiro, int l, int c, char **tabuleiroG);

void existe(char **tabuleiro,int *l,int *c);

void fora(int *l, int *c);

int existeG(char **tabuleiroG,int l,int c);

void colocaJogada(char **tabuleiro, int l, int c, int jogada);

void ver(int la, int ca, int *saltar);

int cheio(char **tabuleiro, int l, int c);

int verificaVitG(char **tabuleiroG, int l, int c);

void existeC(char **tabuleiro,int *l,int *c);

void foraC(char **tabuleiro, int *l, int *c);

int cheioC(char **tabuleiro, int l, int c);

int grava_lista(pjogadas p, char* nome);

#endif //MAIN_C_JOGAR_H
