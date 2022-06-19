//
// Created by Sara on 5/16/2022.
//

#include "matdin.h"

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


