//
// Created by Hugo Vieira on 05/01/2020.
//

#ifndef LPPROG2FI_LIBRARY_H
#define LPPROG2FI_LIBRARY_H
/**
 * struct CEL que contem a informacao de uma celula tambem como pointers para celulas perto(dependendo da celula)
 */
typedef struct cel
{
    int info;
    int line,col;
    struct cel  *pn,*ps,*pe,*po,*pne,*pno,*pse,*pso;     //aponda em volta dela
    struct cel *pnextsub;                                //aponta para cada 1º posicao das sub
    int *psol;
    int nsol;
}CEL;

/**
 * struct TAB representa um tabuleiro que contem o seu tamanho um pointer para a 1º celula
 */
typedef struct tab
{
    int size;
    CEL *pfirst;
}TAB
;
/**
 * struct TABS - contem um array dinamico de tabuleiros de n tamanhos
 */
typedef struct tabs
{
    TAB *ntabs;
    int nt;
}TABS;

#endif //LPPROG2FI_LIBRARY_H
