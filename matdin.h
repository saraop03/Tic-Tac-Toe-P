//
// Created by Sara on 5/16/2022.
//

#ifndef TP_MATDIN_H
#define TP_MATDIN_H

#include <stdlib.h>
#include <stdio.h>

// Liberta uma matriz dinâmica de caracteres com nLin linhas
void libertaMat(char** p, int nLin);

// Cria uma matriz dinâmica de caracteres  com nLin linhas e nCol colunas
// Devolve endereço inicial da matriz
char** criaMat(int nLin, int nCol);

// Imprime o conteúdo de uma matriz dinâmica de caracteres
void mostraMat(char **p, int nLin, int nCol);

// Coloca o caracter c na posição (x, y) de uma matriz dinâmica de caracteres
void setPos(char **p, int x, int y, char c);

// Obtém o caracter armazenado na posição (x, y) de uma matriz de caracteres
char getPos(char **p, int x, int y);

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

//menu

typedef struct jogadass jogadas, *pjogadas;

struct jogadass{
    int jogador , l , c;
    pjogadas prox;
};

void menuJ(pjogadas jogo);

void verJogadas(int njogadas, pjogadas p);

pjogadas insere_final (pjogadas p, int jogador, int l, int c);

void preenche(pjogadas p, int jogador, int l, int c);


#endif