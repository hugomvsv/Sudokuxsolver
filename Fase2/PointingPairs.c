//
// Created by Ruben Jorge on 11/01/2020.
//

#include "PointingPairs.h"

/**
 * percorre todas as box
 * @param tab tabuleiro que está a ser utilizado
 */
void percorre_pointing_pair(TAB *tab) {
    int tam = (int) sqrt(tab->size);
    int li = 0, ci = 0;
    int mod = 0;
    for (int i = 0; i < tam; ++i) {
        ci = 0;
        for (int j = 0; j < tam; ++j) {

            pointing_pairs(tab, li, ci, tam);
            ci += tam;
        }
        li += tam;
    }

}
/**
 * percorre a box e verifica se um num tem 2 ocorrencias, depois verifica se estao na mesma linha ou coluna, se existir elimina de toda a linha/coluna menos os da box que estamos a utilizar
 * @param tab tabuleiro que esta a ser utilizado
 * @param li linha inicial da box
 * @param ci coluna inicial da box
 * @param tam tamanho da box
 */
void pointing_pairs(TAB *tab, int li, int ci, int tam) {
    CEL *cel = chegar_celula(li, ci, tab);     //primeira posiçao da box
    CEL *primeirapos = cel;
    CEL *perclinhas = cel;
    CEL *aux = NULL;
    int line1 = 0, line2 = 0, col1 = 0, col2 = 0;
    int num, cont;
    for (num = 1; num <= tab->size; ++num) {//numero
        cont = 0;
        cel = primeirapos;
        perclinhas = primeirapos;
        for (int i = 0; i < tam; ++i) {
            cel = perclinhas;

            for (int j = 0; j < tam; ++j) {

                for (int k = 0; k < cel->nsol; ++k) {
                    if (*(cel->psol + k) == num) {
                        if (cont == 0) {
                            line1 = cel->line;
                            col1 = cel->col;
                        }
                        if (cont == 1) {
                            line2 = cel->line;
                            col2 = cel->col;
                        }
                        cont++;

                    }
                }
                cel = cel->pe;
            }
            perclinhas = perclinhas->ps;

        }
        if (cont == 2) {

            if (line1 == line2) {
                printf("%d -%d %d- %d %d\n", num, line1, col1, line2, col2);
                aux = chegar_celula(line1, 0, tab);
                for (int i = 0; i < tab->size; i++) {
                    if (i != col1 && i != col2) {
                        atualizar_psol(aux, num);
                        alone_number(tab);
                    }
                    aux = aux->pe;
                }
            }
            else  if (col1 == col2) {
                printf("%d -%d %d- %d %d\n", num, line1, col1, line2, col2);
                aux = chegar_celula(0, col1, tab);
                for (int i = 0; i < tab->size; i++) {
                    if (i != line1 && i != line2) {
                        atualizar_psol(aux, num);
                        alone_number(tab);
                    }
                    aux = aux->ps;
                }
            }
        }
    }
}