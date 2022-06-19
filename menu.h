//
// Created by Sara on 19/06/2022.
//

#ifndef MAIN_C_MENU_H
#define MAIN_C_MENU_H

typedef struct jogadass jogadas, *pjogadas;

struct jogadass{
    int jogador , l , c;
    pjogadas prox;
};

//menu

void menuJ(pjogadas jogo, int njogadas, int *sair);

void verJogadas(int njogadas, pjogadas p);

pjogadas insere_final (pjogadas p, int jogador, int l, int c);

void preenche(pjogadas p, int jogador, int l, int c);

void leDados(pjogadas *p, int *njogadas);

void grava_lista_bin(pjogadas p, int njogadas);

void teste(pjogadas p);

#endif //MAIN_C_MENU_H
