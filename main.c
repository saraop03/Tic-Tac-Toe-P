#include <stdio.h>
#include "matdin.h"
#include "utils.h"

typedef struct jogadass jogadas, *pjogadas;

struct jogadass{
    int jogador , l , c;
    pjogadas prox;
};

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

pjogadas insere_final (pjogadas p, int jogador, int l, int c) {
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

void verJogadas(int njogadas, pjogadas p){
    pjogadas novo;
    int conta_total = 0 , conta_sub = 0 , pos = 0, i = njogadas;

    novo = p;
    if (novo == NULL)
        printf("nulo");

    while(novo->prox != NULL){
        conta_total++;
        novo = novo->prox;

    }
    novo = p;

    conta_sub = conta_total - njogadas;
    if (novo == NULL)
        printf("Nulo\n");
    while (novo != NULL){
        if (pos > conta_sub) {
            if (novo->jogador == 1)
                printf("\nO jogador 2 inseriu as coordenadas (%d,%d)\n", novo->l, novo->c);
            else
                printf("\nO jogador 1 inseriu as coordenadas (%d,%d)\n", novo->l, novo->c);
        }
        pos++;
        novo = novo->prox;
    }
}

int main() {
    pjogadas jogo = NULL;
    char **tabuleiro, **tabuleiroG;
    int l , c , la = 0 , ca = 0 , jogada , njogadal = 0 , saltar = 0 , sucesso = 0 , jogador = 1 , col , lin , vitoria = 0;
    int verJ , menu , op , realizar;

    initRandom();

    printf("-----------------------------\n");
    printf("Menu:\n");
    printf("1- Jogar contra pessoa\n");
    printf("2- Jogar contra computador\n");
    printf("-----------------------------\n\n");
    printf("Opção:");
    scanf("%d",&op);

    if(op == 1) {
        printf("Está a jogar contra uma pessoa\n");

        tabuleiro = criaMat(9, 9);
        tabuleiroG = criaMat(3,3);

        do {
            if (jogador == 1) {
                printf("\nPrima 0 se pretende aceder ao menu:");
                scanf("%d", &menu);
                if (menu == 0) {
                    printf("0- Continuar jogo\n");
                    printf("1- Verificar jogadas\n");
                    printf("2- Sair\n");
                    printf("O que pretende realizar?");
                    scanf("%d", &realizar);
                    if ( realizar == 1) {
                        printf("Quantas jogadas pretende visualizar?");
                        scanf("%d",&verJ);
                        verJogadas(verJ, jogo);
                    }
                    if (realizar == 2)
                        break;
                }
                printf("\nJogador 1 pode realizar a sua jogada\n");

                jogada = 1;
                jogador = 2;
            } else if (jogador == 2) {
                printf("\nPrima 0 se pretende aceder ao menu:");
                scanf("%d", &menu);
                if (menu == 0) {
                    printf("0- Continuar jogo\n");
                    printf("1- Verificar jogadas\n");
                    printf("2- Sair\n");
                    printf("O que pretende realizar?");
                    scanf("%d", &realizar);
                    if ( realizar == 1) {
                        printf("Quantas jogadas pretende visualizar?");
                        scanf("%d",&verJ);
                        verJogadas(verJ, jogo);
                    }
                    if (realizar == 2)
                        break;
                }
                printf("\nJogador 2 pode realizar a sua jogada\n");

                jogada = 2;
                jogador = 1;
            }

            do {
                sucesso = 0;
                ver(l,c,&saltar);
                if (saltar == 0) {
                    if (existeG(tabuleiroG, 0, 0) == 1){
                        saltar = 1;
                        la=0;
                        ca=4;
                    }
                    else {
                        if (la == 0 && ca == 0 || la == 0 && ca == 3 || la == 0 && ca == 6 || la == 3 && ca == 0 ||
                            la == 3 && ca == 3 || la == 3 && ca == 6 || la == 6 && ca == 0 || la == 6 && ca == 3 ||
                            la == 6 && ca == 6) {
                            printf("Insira uma coordenada para o primeiro mini-tabuleiro:");
                            scanf("%d %d", &l, &c);

                            if (cheio(tabuleiro, l, c) == 1) {
                                saltar = 1;
                                la = 0;
                                ca = 4;
                            } else {
                                existe(tabuleiro, &l, &c);
                                fora(&l, &c);

                                while (l > 2 || c > 2 || l > 2 && c > 2) {
                                        printf("Essas coordenadas não correspondem ao primeiro mini-tabuleiro!\n");
                                        printf("Insira uma coordenada para o primeiro mini-tabuleiro:");
                                        scanf("%d %d", &l, &c);
                                        existe(tabuleiro, &l, &c);
                                        fora(&l, &c);
                                    }

                                lin = 0;
                                col = 0;

                                la = l;
                                ca = c;
                                sucesso = 1;
                            }
                        }else
                            saltar = 1;
                        }
                }
                if (saltar == 1) {
                    if (existeG(tabuleiroG, 0, 1) == 1) {
                        saltar = 2;
                        la = 0;
                        ca = 8;
                    }
                    else {
                        if (la == 0 && ca == 1 || la == 0 && ca == 4 || la == 0 && ca == 7 || la == 3 && ca == 1 ||
                            la == 3 && ca == 4 || la == 3 && ca == 7 || la == 6 && ca == 1 || la == 6 && ca == 4 ||
                            la == 6 && ca == 7) {
                            printf("Insira uma coordenada para o segundo mini-tabuleiro:");
                            scanf("%d %d", &l, &c);

                            if (cheio(tabuleiro, l, c) == 1) {
                                saltar = 2;
                                la = 0;
                                ca = 8;
                            } else {
                                existe(tabuleiro, &l, &c);
                                fora(&l, &c);

                                while (l > 2 || c < 3 || c > 5 || l > 2 && c < 3 || l > 2 && c > 5) {
                                        printf("Essas coordenadas não correspondem ao segundo mini-tabuleiro!\n");
                                        printf("Insira uma coordenada para o segundo mini-tabuleiro:");
                                        scanf("%d %d", &l, &c);
                                        existe(tabuleiro, &l, &c);
                                        fora(&l, &c);
                                    }

                                lin = 0;
                                col = 3;

                                la = l;
                                ca = c;
                                sucesso = 1;
                            }
                        }else
                            saltar = 2;
                        }
                }
                if (saltar == 2) {
                    if (existeG(tabuleiroG, 0, 2) == 1) {
                        saltar = 3;
                        la = 4;
                        ca = 0;
                    }
                    else {
                        if (la == 0 && ca == 2 || la == 0 && ca == 5 || la == 0 && ca == 8 || la == 3 && ca == 2 ||
                            la == 3 && ca == 5 || la == 3 && ca == 8 || la == 6 && ca == 2 || la == 5 && ca == 8 ||
                            la == 6 && ca == 8) {
                            printf("Insira uma coordenada para o terceiro mini-tabuleiro:");
                            scanf("%d %d", &l, &c);

                            if (cheio(tabuleiro, l, c) == 1) {
                                saltar = 3;
                                la = 4;
                                ca = 0;
                            } else {
                                existe(tabuleiro, &l, &c);
                                fora(&l, &c);

                                while (l > 2 || c < 6 || c > 8 || l > 2 && c < 6 || l > 2 && c > 8) {
                                        printf("Essas coordenadas não correspondem ao terceiro mini-tabuleiro!\n");
                                        printf("Insira uma coordenada para o terceiro mini-tabuleiro:");
                                        scanf("%d %d", &l, &c);
                                        existe(tabuleiro, &l, &c);
                                        fora(&l, &c);
                                    }

                                lin = 0;
                                col = 6;

                                la = l;
                                ca = c;
                                sucesso = 1;
                            }
                        }else
                            saltar = 3;
                        }
                }
                if (saltar == 3) {
                    if (existeG(tabuleiroG, 1, 0) == 1) {
                        saltar = 4;
                        la = 4;
                        ca = 4;
                    }
                    else {
                        if (la == 1 && ca == 0 || la == 1 && ca == 3 || la == 1 && ca == 6 || la == 4 && ca == 0 ||
                            la == 4 && ca == 3 || la == 4 && ca == 6 || la == 7 && ca == 0 || la == 7 && ca == 3 ||
                            la == 7 && ca == 6) {
                            printf("Insira uma coordenada para o quarto mini-tabuleiro:");
                            scanf("%d %d", &l, &c);

                            if (cheio(tabuleiro, l, c) == 1) {
                                saltar = 4;
                                la = 4;
                                ca = 4;
                            } else {
                                existe(tabuleiro, &l, &c);
                                fora(&l, &c);

                                while (l < 3 || l > 5 || c > 2 || l < 3 && c > 2 || l > 5 && c > 2) {
                                        printf("Essas coordenadas não correspondem ao quarto mini-tabuleiro!\n");
                                        printf("Insira uma coordenada para o quarto mini-tabuleiro:");
                                        scanf("%d %d", &l, &c);
                                        existe(tabuleiro, &l, &c);
                                        fora(&l, &c);
                                    }

                                lin = 3;
                                col = 0;

                                la = l;
                                ca = c;
                                sucesso = 1;
                            }
                        }else
                            saltar = 4;
                    }
                }
                if (saltar == 4) {
                    if (existeG(tabuleiroG, 1, 1) == 1) {
                        saltar = 5;
                        la = 4;
                        ca = 8;
                    }
                    else {
                        if (la == 1 && ca == 1 || la == 1 && ca == 4 || la == 1 && ca == 7 || la == 4 && ca == 1 ||
                            la == 4 && ca == 4 || la == 4 && ca == 7 || la == 7 && ca == 1 || la == 7 && ca == 4 ||
                            la == 7 && ca == 7) {
                            printf("Insira uma coordenada para o quinto mini-tabuleiro:");
                            scanf("%d %d", &l, &c);

                            if (cheio(tabuleiro, l, c) == 1) {
                                saltar = 5;
                                la = 4;
                                ca = 8;
                            } else {
                                existe(tabuleiro, &l, &c);
                                fora(&l, &c);

                                while (l < 3 || l > 5 || c < 3 || c > 5 || l < 3 && c < 3 || l < 3 && c > 5 ||
                                        l > 5 && c < 3 ||
                                        l > 5 && c > 5) {
                                        printf("Essas coordenadas não correspondem ao quinto mini-tabuleiro!\n");
                                        printf("Insira uma coordenada para o quinto mini-tabuleiro:");
                                        scanf("%d %d", &l, &c);
                                        existe(tabuleiro, &l, &c);
                                        fora(&l, &c);
                                    }

                                lin = 3;
                                col = 3;

                                la = l;
                                ca = c;
                                sucesso = 1;
                            }
                        }else
                            saltar = 5;
                    }
                }
                if (saltar == 5) {
                    if (existeG(tabuleiroG, 1, 2) == 1) {
                        saltar = 6;
                        la = 8;
                        ca = 0;
                    }
                    else {
                        if (la == 1 && ca == 2 || la == 1 && ca == 5 || la == 1 && ca == 8 || la == 4 && ca == 2 ||
                            la == 4 && ca == 5 || la == 4 && ca == 8 || la == 7 && ca == 2 || la == 7 && ca == 5 ||
                            la == 7 && ca == 8) {
                            printf("Insira uma coordenada para o sexto mini-tabuleiro:");
                            scanf("%d %d", &l, &c);

                            if (cheio(tabuleiro, l, c) == 1) {
                                saltar = 6;
                                la = 8;
                                ca = 0;
                            } else {
                                existe(tabuleiro, &l, &c);
                                fora(&l, &c);

                                while (l < 3 || l > 5 || c < 6 || c > 8 || l < 3 && c < 6 || l < 3 && c > 8 ||
                                        l > 5 && c < 6 || l > 5 && c > 8) {
                                        printf("Essas coordenadas não correspondem ao sexto mini-tabuleiro!\n");
                                        printf("Insira uma coordenada para o sexto mini-tabuleiro:");
                                        scanf("%d %d", &l, &c);
                                        existe(tabuleiro, &l, &c);
                                        fora(&l, &c);
                                    }

                                lin = 3;
                                col = 6;

                                la = l;
                                ca = c;
                                sucesso = 1;
                            }
                        }else
                            saltar = 6;
                    }
                }
                if (saltar == 6) {
                    if (existeG(tabuleiroG, 2, 0) == 1) {
                        saltar = 7;
                        la = 8;
                        ca = 4;
                    }
                    else {
                        if (la == 2 && ca == 0 || la == 2 && ca == 3 || la == 2 && ca == 6 || la == 5 && ca == 0 ||
                            la == 5 && ca == 3 || la == 5 && ca == 6 || la == 8 && ca == 0 || la == 8 && ca == 3 ||
                            la == 8 && ca == 6) {
                            printf("Insira uma coordenada para o sétimo mini-tabuleiro:");
                            scanf("%d %d", &l, &c);

                            if (cheio(tabuleiro, l, c) == 1) {
                                saltar = 7;
                                la = 8;
                                ca = 4;
                            } else {
                                existe(tabuleiro, &l, &c);
                                fora(&l, &c);

                                while (l < 6 || l > 8 || c > 2 || l < 6 && c > 2 || l > 8 && c > 2) {
                                        printf("Essas coordenadas não correspondem ao sétimo mini-tabuleiro!\n");
                                        printf("Insira uma coordenada para o sétimo mini-tabuleiro:");
                                        scanf("%d %d", &l, &c);
                                        existe(tabuleiro, &l, &c);
                                        fora(&l, &c);
                                    }

                                lin = 6;
                                col = 0;

                                la = l;
                                ca = c;
                                sucesso = 1;
                            }
                        }else
                            saltar = 7;
                    }
                }
                if (saltar == 7) {
                    if (existeG(tabuleiroG, 2, 1) == 1) {
                        saltar = 8;
                        la = 8;
                        ca = 8;
                    }
                    else {
                        if (la == 2 && ca == 1 || la == 2 && ca == 4 || la == 2 && ca == 7 || la == 5 && ca == 1 ||
                            la == 5 && ca == 4 || la == 5 && ca == 7 || la == 8 && ca == 1 || la == 8 && ca == 4 ||
                            la == 8 && ca == 7) {
                            printf("Insira uma coordenada para o oitavo mini-tabuleiro:");
                            scanf("%d %d", &l, &c);

                            if (cheio(tabuleiro, l, c) == 1) {
                                saltar = 8;
                                la = 8;
                                ca = 8;
                            } else {
                                existe(tabuleiro, &l, &c);
                                fora(&l, &c);

                                while (l < 6 || l > 8 || c < 3 || c > 5 || l < 6 && c < 3 || l < 6 && c > 5) {
                                        printf("Essas coordenadas não correspondem ao oitavo mini-tabuleiro!\n");
                                        printf("Insira uma coordenada para o oitavo mini-tabuleiro:");
                                        scanf("%d %d", &l, &c);
                                        existe(tabuleiro, &l, &c);
                                        fora(&l, &c);
                                    }

                                lin = 6;
                                col = 3;

                                la = l;
                                ca = c;
                                sucesso = 1;
                            }
                        }else
                            saltar = 8;
                    }
                }
                if (saltar == 8) {
                    if (existeG(tabuleiroG, 2, 2) == 1) {
                        saltar = 0;
                        la = 0;
                        ca = 0;
                    }
                    else {
                        if (la == 2 && ca == 2 || la == 2 && ca == 5 || la == 2 && ca == 8 || la == 5 && ca == 2 ||
                            la == 5 && ca == 5 || la == 5 && ca == 8 || la == 8 && ca == 2 || la == 8 && ca == 5 ||
                            la == 8 && ca == 8) {
                            printf("Insira uma coordenada para o nono mini-tabuleiro:");
                            scanf("%d %d", &l, &c);

                            if (cheio(tabuleiro, l, c) == 1) {
                                saltar = 0;
                                la = 0;
                                ca = 0;
                            } else {
                                existe(tabuleiro, &l, &c);
                                fora(&l, &c);

                                while (l < 6 || l > 8 || c < 6 || c > 8 || l < 6 && c < 6 || l < 6 && c > 8) {
                                        printf("Essas coordenadas não correspondem ao nono mini-tabuleiro!\n");
                                        printf("Insira uma coordenada para o nono mini-tabuleiro:");
                                        scanf("%d %d", &l, &c);
                                        existe(tabuleiro, &l, &c);
                                        fora(&l, &c);
                                    }

                                lin = 6;
                                col = 6;

                                la = l;
                                ca = c;
                                sucesso = 1;
                            }
                        }else
                            saltar = 0;
                    }
                }
            } while (sucesso != 1);
                colocaJogada(tabuleiro,l,c,jogada);
                njogadal++;
                printf("\n");
                mostraMat(tabuleiro, 9, 9);
                verificaVit(tabuleiro, lin, col, tabuleiroG);
                tabuleiroGrande(tabuleiroG);
                jogo = insere_final(jogo, jogador, l, c);

                if (verificaVitG(tabuleiroG,0,0) == 1)
                {
                    printf("Fim do jogo");
                    vitoria = 1;
                }
                else
                    vitoria = 0;

        } while (vitoria != 1);
        //Guardar em ficheiro de texto
    }
    else if(op == 2) {
        printf("Está a jogar contra o computador");

            tabuleiro = criaMat(9, 9);
            tabuleiroG = criaMat(3,3);

            do {
                if (jogador == 1) {
                    printf("\nPrima 0 se pretende aceder ao menu:");
                    scanf("%d", &menu);
                    if (menu == 0) {
                        printf("0- Continuar jogo\n");
                        printf("1- Verificar jogadas\n");
                        printf("2- Sair\n");
                        printf("O que pretende realizar?");
                        scanf("%d", &realizar);
                        if ( realizar == 1) {
                            printf("Quantas jogadas pretende visualizar?");
                            scanf("%d",&verJ);
                            verJogadas(verJ, jogo);
                        }
                        if (realizar == 2)
                            break;
                    }
                    printf("\nJogador 1 pode realizar a sua jogada\n");

                    jogada = 1;
                } else if (jogador == 2) {
                    printf("\nJogada do computador\n");
                    jogada = 2;
                }

                do {
                    sucesso = 0;
                    ver(l,c,&saltar);
                    if (saltar == 0) {
                        if (existeG(tabuleiroG, 0, 0) == 1) {
                            saltar = 1;
                            la = 0;
                            ca = 4;
                        } else {
                            if (jogador == 1) {
                                if (la == 0 && ca == 0 || la == 0 && ca == 3 || la == 0 && ca == 6 || la == 3 && ca == 0 ||
                                    la == 3 && ca == 3 || la == 3 && ca == 6 || la == 6 && ca == 0 || la == 6 && ca == 3 ||
                                    la == 6 && ca == 6) {
                                    printf("Insira uma coordenada para o primeiro mini-tabuleiro:");
                                    scanf("%d %d", &l, &c);

                                    if (cheio(tabuleiro, l, c) == 1) {
                                        saltar = 1;
                                        la = 0;
                                        ca = 4;
                                    } else {
                                        existe(tabuleiro, &l, &c);
                                        fora(&l, &c);

                                        while (l != 0 && (c != 0 && c != 1 && c != 2) || l != 1 && (c != 0 && c != 1 && c != 2) || l != 2 && (c != 0 && c != 1 && c != 2) ||
                                               c != 0 && (l != 0 && l != 1 && l != 2) || c != 1 && (l != 0 && l != 1 && l != 2) || c != 2 && (l != 0 && l != 1 && l != 2)) {
                                                printf("Essas coordenadas não correspondem ao primeiro mini-tabuleiro!\n");
                                                printf("Insira uma coordenada para o primeiro mini-tabuleiro:");
                                                scanf("%d %d", &l, &c);
                                                existe(tabuleiro, &l, &c);
                                                fora(&l, &c);
                                            }

                                        lin = 0;
                                        col = 0;
                                        la = l;
                                        ca = c;
                                        sucesso = 1;
                                    }
                                } else
                                    saltar = 1;
                            }
                            if (jogador == 2) {
                                if (la == 0 && ca == 0 || la == 0 && ca == 3 || la == 0 && ca == 6 || la == 3 && ca == 0 ||
                                    la == 3 && ca == 3 || la == 3 && ca == 6 || la == 6 && ca == 0 || la == 6 && ca == 3 ||
                                    la == 6 && ca == 6) {

                                    l = intUniformRnd(0, 8);
                                    c = intUniformRnd(0, 8);

                                    if (cheioC(tabuleiro, l, c) == 1) {
                                        saltar = 1;
                                        la = 0;
                                        ca = 4;
                                    } else {
                                        existeC(tabuleiro, &l, &c);

                                        while (l != 0 && (c != 0 && c != 1 && c != 2) || l != 1 && (c != 0 && c != 1 && c != 2) || l != 2 && (c != 0 && c != 1 && c != 2) ||
                                               c != 0 && (l != 0 && l != 1 && l != 2) || c != 1 && (l != 0 && l != 1 && l != 2) || c != 2 && (l != 0 && l != 1 && l != 2))
                                            foraC(tabuleiro, &l, &c);

                                        lin = 0;
                                        col = 0;
                                        la = l;
                                        ca = c;
                                        sucesso = 1;
                                    }
                                } else
                                    saltar = 1;
                            }
                        }
                    }
                    if (saltar == 1) {
                        if (existeG(tabuleiroG, 0, 1) == 1) {
                            saltar = 2;
                            la = 0;
                            ca = 8;
                        }
                        else {
                            if (jogador == 1) {
                                if (la == 0 && ca == 1 || la == 0 && ca == 4 || la == 0 && ca == 7 || la == 3 && ca == 1 ||
                                    la == 3 && ca == 4 || la == 3 && ca == 7 || la == 6 && ca == 1 || la == 6 && ca == 4 ||
                                    la == 6 && ca == 7) {
                                    printf("Insira uma coordenada para o segundo mini-tabuleiro:");
                                    scanf("%d %d", &l, &c);

                                    if (cheio(tabuleiro, l, c) == 1) {
                                        saltar = 2;
                                        la = 0;
                                        ca = 8;
                                    } else {
                                        existe(tabuleiro, &l, &c);
                                        fora(&l, &c);

                                        while (l != 0 && (c != 3 && c != 4 && c != 5) || l != 1 && (c != 3 && c != 4 && c != 5) || l != 2 && (c != 3 && c != 4 && c != 5) ||
                                               c != 3 && (l != 0 && l != 1 && l != 2) || c != 4 && (l != 0 && l != 1 && l != 2) || c != 5 && (l != 0 && l != 1 && l != 2)) {
                                                printf("Essas coordenadas não correspondem ao segundo mini-tabuleiro!\n");
                                                printf("Insira uma coordenada para o segundo mini-tabuleiro:");
                                                scanf("%d %d", &l, &c);
                                                existe(tabuleiro, &l, &c);
                                                fora(&l, &c);
                                            }

                                        lin = 0;
                                        col = 3;
                                        la = l;
                                        ca = c;
                                        sucesso = 1;
                                    }
                                } else
                                    saltar = 2;
                            }
                            if (jogador == 2) {
                                if (la == 0 && ca == 1 || la == 0 && ca == 4 || la == 0 && ca == 7 || la == 3 && ca == 1 ||
                                    la == 3 && ca == 4 || la == 3 && ca == 7 || la == 6 && ca == 1 || la == 6 && ca == 4 ||
                                    la == 6 && ca == 7) {

                                    l = intUniformRnd(0, 8);
                                    c = intUniformRnd(0, 8);

                                    if (cheioC(tabuleiro, l, c) == 1) {
                                        saltar = 2;
                                        la = 0;
                                        ca = 8;
                                    } else {
                                        existeC(tabuleiro, &l, &c);

                                        while (l != 0 && (c != 3 && c != 4 && c != 5) || l != 1 && (c != 3 && c != 4 && c != 5) || l != 2 && (c != 3 && c != 4 && c != 5) ||
                                             c != 3 && (l != 0 && l != 1 && l != 2) || c != 4 && (l != 0 && l != 1 && l != 2) || c != 5 && (l != 0 && l != 1 && l != 2))
                                            foraC(tabuleiro, &l, &c);

                                        lin = 0;
                                        col = 3;
                                        la = l;
                                        ca = c;
                                        sucesso = 1;
                                    }
                                } else
                                    saltar = 2;
                            }
                        }
                    }
                    if (saltar == 2) {
                        if (existeG(tabuleiroG, 0, 2) == 1) {
                            saltar = 3;
                            la = 4;
                            ca = 0;
                        }
                        else {
                            if (jogador == 1) {
                                if (la == 0 && ca == 2 || la == 0 && ca == 5 || la == 0 && ca == 8 || la == 3 && ca == 2 ||
                                    la == 3 && ca == 5 || la == 3 && ca == 8 || la == 6 && ca == 2 || la == 5 && ca == 8 ||
                                    la == 6 && ca == 8) {
                                    printf("Insira uma coordenada para o terceiro mini-tabuleiro:");
                                    scanf("%d %d", &l, &c);

                                    if (cheio(tabuleiro, l, c) == 1) {
                                        saltar = 3;
                                        la = 4;
                                        ca = 0;
                                    } else {
                                        existe(tabuleiro, &l, &c);
                                        fora(&l, &c);

                                        while (l != 0 && (c != 6 && c != 7 && c != 8) || l != 1 && (c != 6 && c != 7 && c != 8) || l != 2 && (c != 6 && c != 7 && c != 8) ||
                                               c != 6 && (l != 0 && l != 1 && l != 2) || c != 7 && (l != 0 && l != 1 && l != 2) || c != 8 && (l != 0 && l != 1 && l != 2)) {
                                                printf("Essas coordenadas não correspondem ao terceiro mini-tabuleiro!\n");
                                                printf("Insira uma coordenada para o terceiro mini-tabuleiro:");
                                                scanf("%d %d", &l, &c);
                                                existe(tabuleiro, &l, &c);
                                                fora(&l, &c);
                                            }

                                        lin = 0;
                                        col = 6;
                                        la = l;
                                        ca = c;
                                        sucesso = 1;
                                    }
                                } else
                                    saltar = 3;
                            }
                            if (jogador == 2) {
                                if (la == 0 && ca == 2 || la == 0 && ca == 5 || la == 0 && ca == 8 || la == 3 && ca == 2 ||
                                    la == 3 && ca == 5 || la == 3 && ca == 8 || la == 6 && ca == 2 || la == 5 && ca == 8 ||
                                    la == 6 && ca == 8) {

                                    l = intUniformRnd(0, 8);
                                    c = intUniformRnd(0, 8);

                                    if (cheioC(tabuleiro, l, c) == 1) {
                                        saltar = 3;
                                        la = 4;
                                        ca = 0;
                                    } else {
                                        existeC(tabuleiro, &l, &c);

                                        while (l != 0 && (c != 6 && c != 7 && c != 8) || l != 1 && (c != 6 && c != 7 && c != 8) || l != 2 && (c != 6 && c != 7 && c != 8) ||
                                               c != 6 && (l != 0 && l != 1 && l != 2) || c != 7 && (l != 0 && l != 1 && l != 2) || c != 8 && (l != 0 && l != 1 && l != 2))
                                            foraC(tabuleiro, &l, &c);

                                        lin = 0;
                                        col = 6;
                                        la = l;
                                        ca = c;
                                        sucesso = 1;
                                    }
                                } else
                                    saltar = 3;
                            }
                        }
                    }
                    if (saltar == 3) {
                        if (existeG(tabuleiroG, 1, 0) == 1) {
                            saltar = 4;
                            la = 4;
                            ca = 4;
                        }
                        else {
                            if (jogador == 1) {
                                if (la == 1 && ca == 0 || la == 1 && ca == 3 || la == 1 && ca == 6 || la == 4 && ca == 0 ||
                                    la == 4 && ca == 3 || la == 4 && ca == 6 || la == 7 && ca == 0 || la == 7 && ca == 3 ||
                                    la == 7 && ca == 6) {
                                    printf("Insira uma coordenada para o quarto mini-tabuleiro:");
                                    scanf("%d %d", &l, &c);

                                    if (cheio(tabuleiro, l, c) == 1) {
                                        saltar = 4;
                                        la = 4;
                                        ca = 4;
                                    } else {
                                        existe(tabuleiro, &l, &c);
                                        fora(&l, &c);

                                        while (l != 3 && (c != 0 && c != 1 && c != 2) || l != 4 && (c != 0 && c != 1 && c != 2) || l != 5 && (c != 0 && c != 1 && c != 2) ||
                                               c != 0 && (l != 3 && l != 4 && l != 5) || c != 1 && (l != 3 && l != 4 && l != 5) || c != 2 && (l != 3 && l != 4 && l != 5)) {
                                                printf("Essas coordenadas não correspondem ao quarto mini-tabuleiro!\n");
                                                printf("Insira uma coordenada para o quarto mini-tabuleiro:");
                                                scanf("%d %d", &l, &c);
                                                existe(tabuleiro, &l, &c);
                                                fora(&l, &c);
                                            }

                                        lin = 3;
                                        col = 0;
                                        la = l;
                                        ca = c;
                                        sucesso = 1;
                                    }
                                } else
                                    saltar = 4;
                            }
                            if (jogador == 2) {
                                if (la == 1 && ca == 0 || la == 1 && ca == 3 || la == 1 && ca == 6 || la == 4 && ca == 0 ||
                                    la == 4 && ca == 3 || la == 4 && ca == 6 || la == 7 && ca == 0 || la == 7 && ca == 3 ||
                                    la == 7 && ca == 6) {

                                    l = intUniformRnd(0, 8);
                                    c = intUniformRnd(0, 8);

                                    if (cheioC(tabuleiro, l, c) == 1) {
                                        saltar = 4;
                                        la = 4;
                                        ca = 4;
                                    } else {
                                        existeC(tabuleiro, &l, &c);

                                        while (l != 3 && (c != 0 && c != 1 && c != 2) || l != 4 && (c != 0 && c != 1 && c != 2) || l != 5 && (c != 0 && c != 1 && c != 2) ||
                                               c != 0 && (l != 3 && l != 4 && l != 5) || c != 1 && (l != 3 && l != 4 && l != 5) || c != 2 && (l != 3 && l != 4 && l != 5))
                                            foraC(tabuleiro, &l, &c);

                                        lin = 3;
                                        col = 0;
                                        la = l;
                                        ca = c;
                                        sucesso = 1;
                                    }
                                } else
                                    saltar = 4;
                            }
                        }
                    }
                    if (saltar == 4) {
                        if (existeG(tabuleiroG, 1, 1) == 1) {
                            saltar = 5;
                            la = 4;
                            ca = 8;
                        }
                        else {
                            if (jogador == 1) {
                                if (la == 1 && ca == 1 || la == 1 && ca == 4 || la == 1 && ca == 7 || la == 4 && ca == 1 ||
                                    la == 4 && ca == 4 || la == 4 && ca == 7 || la == 7 && ca == 1 || la == 7 && ca == 4 ||
                                    la == 7 && ca == 7) {
                                    printf("Insira uma coordenada para o quinto mini-tabuleiro:");
                                    scanf("%d %d", &l, &c);

                                    if (cheio(tabuleiro, l, c) == 1) {
                                        saltar = 5;
                                        la = 4;
                                        ca = 8;
                                    } else {
                                        existe(tabuleiro, &l, &c);
                                        fora(&l, &c);

                                        while (l != 3 && (c != 3 && c != 4 && c != 5) || l != 4 && (c != 3 && c != 4 && c != 5) || l != 5 && (c != 3 && c != 4 && c != 5) ||
                                               c != 3 && (l != 3 && l != 4 && l != 5) || c != 4 && (l != 3 && l != 4 && l != 5) || c != 5 && (l != 3 && l != 4 && l != 5)) {
                                                printf("Essas coordenadas não correspondem ao quinto mini-tabuleiro!\n");
                                                printf("Insira uma coordenada para o quinto mini-tabuleiro:");
                                                scanf("%d %d", &l, &c);
                                                existe(tabuleiro, &l, &c);
                                                fora(&l, &c);
                                            }

                                        lin = 3;
                                        col = 3;
                                        la = l;
                                        ca = c;
                                        sucesso = 1;
                                    }
                                } else
                                    saltar = 5;
                            }
                            if (jogador == 2) {
                                if (la == 1 && ca == 1 || la == 1 && ca == 4 || la == 1 && ca == 7 || la == 4 && ca == 1 ||
                                    la == 4 && ca == 4 || la == 4 && ca == 7 || la == 7 && ca == 1 || la == 7 && ca == 4 ||
                                    la == 7 && ca == 7) {

                                    l = intUniformRnd(0, 8);
                                    c = intUniformRnd(0, 8);

                                    if (cheioC(tabuleiro, l, c) == 1) {
                                        saltar = 5;
                                        la = 4;
                                        ca = 8;
                                    } else {
                                        existeC(tabuleiro, &l, &c);

                                        while (l != 3 && (c != 3 && c != 4 && c != 5) || l != 4 && (c != 3 && c != 4 && c != 5) || l != 5 && (c != 3 && c != 4 && c != 5) ||
                                               c != 3 && (l != 3 && l != 4 && l != 5) || c != 4 && (l != 3 && l != 4 && l != 5) || c != 5 && (l != 3 && l != 4 && l != 5))
                                            foraC(tabuleiro, &l, &c);

                                        lin = 3;
                                        col = 3;
                                        la = l;
                                        ca = c;
                                        sucesso = 1;
                                    }
                                } else
                                    saltar = 5;
                            }
                        }
                    }
                    if (saltar == 5) {
                        if (existeG(tabuleiroG, 1, 2) == 1) {
                            saltar = 6;
                            la = 8;
                            ca = 0;
                        }
                        else {
                            if (jogador == 1) {
                                if (la == 1 && ca == 2 || la == 1 && ca == 5 || la == 1 && ca == 8 || la == 4 && ca == 2 ||
                                    la == 4 && ca == 5 || la == 4 && ca == 8 || la == 7 && ca == 2 || la == 7 && ca == 5 ||
                                    la == 7 && ca == 8) {
                                    printf("Insira uma coordenada para o sexto mini-tabuleiro:");
                                    scanf("%d %d", &l, &c);

                                    if (cheio(tabuleiro, l, c) == 1) {
                                        saltar = 6;
                                        la = 8;
                                        ca = 0;
                                    } else {
                                        existe(tabuleiro, &l, &c);
                                        fora(&l, &c);

                                        while (l != 3 && (c != 6 && c != 7 && c != 8) || l != 4 && (c != 6 && c != 7 && c != 8) || l != 5 && (c != 6 && c != 7 && c != 8) ||
                                               c != 6 && (l != 3 && l != 4 && l != 5) || c != 7 && (l != 3 && l != 4 && l != 5) || c != 8 && (l != 3 && l != 4 && l != 5)) {
                                                printf("Essas coordenadas não correspondem ao sexto mini-tabuleiro!\n");
                                                printf("Insira uma coordenada para o sexto mini-tabuleiro:");
                                                scanf("%d %d", &l, &c);
                                                existe(tabuleiro, &l, &c);
                                                fora(&l, &c);
                                            }

                                        lin = 3;
                                        col = 6;
                                        la = l;
                                        ca = c;
                                        sucesso = 1;
                                    }
                                } else
                                    saltar = 6;
                            }
                            if (jogador == 2) {
                                if (la == 1 && ca == 2 || la == 1 && ca == 5 || la == 1 && ca == 8 || la == 4 && ca == 2 ||
                                    la == 4 && ca == 5 || la == 4 && ca == 8 || la == 7 && ca == 2 || la == 7 && ca == 5 ||
                                    la == 7 && ca == 8) {

                                    l = intUniformRnd(0, 8);
                                    c = intUniformRnd(0, 8);

                                    if (cheioC(tabuleiro, l, c) == 1) {
                                        saltar = 6;
                                        la = 8;
                                        ca = 0;
                                    } else {
                                        existeC(tabuleiro, &l, &c);

                                        while (l != 3 && (c != 6 && c != 7 && c != 8) || l != 4 && (c != 6 && c != 7 && c != 8) || l != 5 && (c != 6 && c != 7 && c != 8) ||
                                               c != 6 && (l != 3 && l != 4 && l != 5) || c != 7 && (l != 3 && l != 4 && l != 5) || c != 8 && (l != 3 && l != 4 && l != 5))
                                            foraC(tabuleiro, &l, &c);

                                        lin = 3;
                                        col = 6;
                                        la = l;
                                        ca = c;
                                        sucesso = 1;
                                    }
                                } else
                                    saltar = 6;
                            }
                        }
                    }
                    if (saltar == 6) {
                        if (existeG(tabuleiroG, 2, 0) == 1) {
                            saltar = 7;
                            la = 8;
                            ca = 4;
                        }
                        else {
                            if (jogador == 1) {
                                if (la == 2 && ca == 0 || la == 2 && ca == 3 || la == 2 && ca == 6 || la == 5 && ca == 0 ||
                                    la == 5 && ca == 3 || la == 5 && ca == 6 || la == 8 && ca == 0 || la == 8 && ca == 3 ||
                                    la == 8 && ca == 6) {
                                    printf("Insira uma coordenada para o sétimo mini-tabuleiro:");
                                    scanf("%d %d", &l, &c);

                                    if (cheio(tabuleiro, l, c) == 1) {
                                        saltar = 7;
                                        la = 8;
                                        ca = 4;
                                    } else {
                                        existe(tabuleiro, &l, &c);
                                        fora(&l, &c);

                                        while (l != 6 && (c != 0 && c != 1 && c != 2) || l != 7 && (c != 0 && c != 1 && c != 2) || l != 8 && (c != 0 && c != 1 && c != 2) ||
                                               c != 0 && (l != 6 && l != 7 && l != 8) || c != 1 && (l != 6 && l != 7 && l != 8) || c != 2 && (l != 6 && l != 7 && l != 8)) {
                                                printf("Essas coordenadas não correspondem ao sétimo mini-tabuleiro!\n");
                                                printf("Insira uma coordenada para o sétimo mini-tabuleiro:");
                                                scanf("%d %d", &l, &c);
                                                existe(tabuleiro, &l, &c);
                                                fora(&l, &c);
                                            }

                                        lin = 6;
                                        col = 0;
                                        la = l;
                                        ca = c;
                                        sucesso = 1;
                                    }
                                } else
                                    saltar = 7;
                            }
                            if (jogador == 2) {
                                if (la == 2 && ca == 0 || la == 2 && ca == 3 || la == 2 && ca == 6 || la == 5 && ca == 0 ||
                                    la == 5 && ca == 3 || la == 5 && ca == 6 || la == 8 && ca == 0 || la == 8 && ca == 3 ||
                                    la == 8 && ca == 6) {

                                    l = intUniformRnd(0, 8);
                                    c = intUniformRnd(0, 8);

                                    if (cheioC(tabuleiro, l, c) == 1) {
                                        saltar = 7;
                                        la = 8;
                                        ca = 4;
                                    } else {
                                        existeC(tabuleiro, &l, &c);

                                        while (l != 6 && (c != 0 && c != 1 && c != 2) || l != 7 && (c != 0 && c != 1 && c != 2) || l != 8 && (c != 0 && c != 1 && c != 2) ||
                                                c != 0 && (l != 6 && l != 7 && l != 8) || c != 1 && (l != 6 && l != 7 && l != 8) || c != 2 && (l != 6 && l != 7 && l != 8))
                                            foraC(tabuleiro, &l, &c);

                                        lin = 6;
                                        col = 0;
                                        la = l;
                                        ca = c;
                                        sucesso = 1;
                                    }
                                } else
                                    saltar = 7;
                            }
                        }
                    }
                    if (saltar == 7) {
                        if (existeG(tabuleiroG, 2, 1) == 1) {
                            saltar = 8;
                            la = 8;
                            ca = 8;
                        }
                        else {
                            if (jogador == 1) {
                                if (la == 2 && ca == 1 || la == 2 && ca == 4 || la == 2 && ca == 7 || la == 5 && ca == 1 ||
                                    la == 5 && ca == 4 || la == 5 && ca == 7 || la == 8 && ca == 1 || la == 8 && ca == 4 ||
                                    la == 8 && ca == 7) {
                                    printf("Insira uma coordenada para o oitavo mini-tabuleiro:");
                                    scanf("%d %d", &l, &c);

                                    if (cheio(tabuleiro, l, c) == 1) {
                                        saltar = 8;
                                        la = 8;
                                        ca = 8;
                                    } else {
                                        existe(tabuleiro, &l, &c);
                                        fora(&l, &c);

                                        while (l != 6 && (c != 3 && c != 4 && c != 5) || l != 7 && (c != 3 && c != 4 && c != 5) || l != 8 && (c != 3 && c != 4 && c != 5) ||
                                               c != 3 && (l != 6 && l != 7 && l != 8) || c != 4 && (l != 6 && l != 7 && l != 8) || c != 5 && (l != 6 && l != 7 && l != 8)) {
                                                printf("Essas coordenadas não correspondem ao oitavo mini-tabuleiro!\n");
                                                printf("Insira uma coordenada para o oitavo mini-tabuleiro:");
                                                scanf("%d %d", &l, &c);
                                                existe(tabuleiro, &l, &c);
                                                fora(&l, &c);
                                            }

                                        lin = 6;
                                        col = 3;
                                        la = l;
                                        ca = c;
                                        sucesso = 1;
                                    }
                                } else
                                    saltar = 8;
                            }
                            if (jogador == 2) {
                                if (la == 2 && ca == 1 || la == 2 && ca == 4 || la == 2 && ca == 7 || la == 5 && ca == 1 ||
                                    la == 5 && ca == 4 || la == 5 && ca == 7 || la == 8 && ca == 1 || la == 8 && ca == 4 ||
                                    la == 8 && ca == 7) {

                                    l = intUniformRnd(0, 8);
                                    c = intUniformRnd(0, 8);

                                    if (cheioC(tabuleiro, l, c) == 1) {
                                        saltar = 8;
                                        la = 8;
                                        ca = 8;
                                    } else {
                                        existeC(tabuleiro, &l, &c);

                                        while (l != 6 && (c != 3 && c != 4 && c != 5) || l != 7 && (c != 3 && c != 4 && c != 5) || l != 8 && (c != 3 && c != 4 && c != 5) ||
                                               c != 3 && (l != 6 && l != 7 && l != 8) || c != 4 && (l != 6 && l != 7 && l != 8) || c != 5 && (l != 6 && l != 7 && l != 8))
                                            foraC(tabuleiro, &l, &c);

                                        lin = 6;
                                        col = 3;
                                        la = l;
                                        ca = c;
                                        sucesso = 1;
                                    }
                                } else
                                    saltar = 8;
                            }
                        }
                    }
                    if (saltar == 8) {
                        if (existeG(tabuleiroG, 2, 2) == 1) {
                            saltar = 0;
                            la = 0;
                            ca = 0;
                        }
                        else {
                            if (jogador == 1) {
                                if (la == 2 && ca == 2 || la == 2 && ca == 5 || la == 2 && ca == 8 || la == 5 && ca == 2 ||
                                    la == 5 && ca == 5 || la == 5 && ca == 8 || la == 8 && ca == 2 || la == 8 && ca == 5 ||
                                    la == 8 && ca == 8) {
                                    printf("Insira uma coordenada para o nono mini-tabuleiro:");
                                    scanf("%d %d", &l, &c);

                                    if (cheio(tabuleiro, l, c) == 1) {
                                        saltar = 0;
                                        la = 0;
                                        ca = 0;
                                    } else {
                                        existe(tabuleiro, &l, &c);
                                        fora(&l, &c);

                                        while (l != 6 && (c != 6 && c != 7 && c != 8) || l != 7 && (c != 6 && c != 7 && c != 8) || l != 8 && (c != 6 && c != 7 && c != 8) ||
                                               c != 6 && (l != 6 && l != 7 && l != 8) || c != 7 && (l != 6 && l != 7 && l != 8) || c != 8 && (l != 6 && l != 7 && l != 8)) {
                                                printf("Essas coordenadas não correspondem ao nono mini-tabuleiro!\n");
                                                printf("Insira uma coordenada para o nono mini-tabuleiro:");
                                                scanf("%d %d", &l, &c);
                                                existe(tabuleiro, &l, &c);
                                                fora(&l, &c);
                                            }

                                        lin = 6;
                                        col = 6;
                                        la = l;
                                        ca = c;
                                        sucesso = 1;
                                    }
                                } else
                                    saltar = 0;
                            }
                            if (jogador == 2) {
                                if (la == 2 && ca == 2 || la == 2 && ca == 5 || la == 2 && ca == 8 || la == 5 && ca == 2 ||
                                    la == 5 && ca == 5 || la == 5 && ca == 8 || la == 8 && ca == 2 || la == 8 && ca == 5 ||
                                    la == 8 && ca == 8) {

                                    l = intUniformRnd(0, 8);
                                    c = intUniformRnd(0, 8);

                                    if (cheioC(tabuleiro, l, c) == 1) {
                                        saltar = 0;
                                        la = 0;
                                        ca = 0;
                                    } else {
                                        existeC(tabuleiro, &l, &c);

                                        while (l != 6 && (c != 6 && c != 7 && c != 8) || l != 7 && (c != 6 && c != 7 && c != 8) || l != 8 && (c != 6 && c != 7 && c != 8) ||
                                               c != 6 && (l != 6 && l != 7 && l != 8) || c != 7 && (l != 6 && l != 7 && l != 8) || c != 8 && (l != 6 && l != 7 && l != 8))
                                            foraC(tabuleiro, &l, &c);

                                        lin = 6;
                                        col = 6;
                                        la = l;
                                        ca = c;
                                        sucesso = 1;
                                    }
                                } else
                                    saltar = 0;
                            }
                        }
                    }
                } while (sucesso != 1);
                colocaJogada(tabuleiro,l,c,jogada);
                njogadal++;

                printf("\n");
                mostraMat(tabuleiro, 9, 9);
                verificaVit(tabuleiro, lin, col, tabuleiroG);
                tabuleiroGrande(tabuleiroG);
                jogo = insere_final(jogo, jogador, l, c);

                if (jogador == 1)
                    jogador = 2;
                else if (jogador == 2)
                    jogador = 1;

                if (verificaVitG(tabuleiroG,0,0) == 1)
                {
                    printf("Fim do jogo");
                    vitoria = 1;
                }
                else
                    vitoria = 0;

            } while (vitoria != 1);
            //Guardar em ficheiro de texto
        }
    }