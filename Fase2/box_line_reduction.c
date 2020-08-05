//
// Created by Ruben Jorge on 12/01/2020.
//

#include "box_line_reduction.h"
/**
 * Função que implementa a estratégia BOX/LINE REDUCTION
 * @param tab tabuleiro onde estamos a trabalhar
 */
void box_line(TAB *tab){
   box_line_reduction(tab);
    box_line_reduction_col(tab);

}

/**
 *  Para cada numero percorre as celudas de cada linha e vefica se o numero tem 2 ou 3 ocorrencias, se estiverem na mesma box, elimina o das box adjacentes
 * @param tab tabuleiro onde estamos a trabalhar
 */
void box_line_reduction(TAB *tab) {
    CEL *firstposition = tab->pfirst;
    CEL *aux, *perclinhas;
    int num, cont = 0, tam = tab->size, col1 = 0, col2 = 0, col3 = 0;
    int tambox =(int) sqrt(tam);
    for (num = 1; num <= tam; ++num) {
        aux = firstposition;
        perclinhas = firstposition;
        cont = 0;
        for (int i = 0; i < tam; ++i) { //percorre as linhas
            aux = perclinhas;
            cont = 0;
            for (int j = 0; j < tam; ++j) {     //percorre as colunas da linha
                for (int k = 0; k < aux->nsol; ++k) {
                    if (*(aux->psol + k) == num) {
                        if (cont == 0) {
                            col1 = aux->col;
                        } else if (cont == 1) {
                            col2 = aux->col;
                        } else if (cont == 2) {
                            col3 = aux->col;
                        }
                        cont++;
                    }
                }

                aux = aux->pe;
            }
            if (cont == 2) {
                if (col1 / tambox == col2 / tambox) {
                    printf("%d -  %d %d %d\n", num, i, col1, col2);
                    limpar_numero_line_box(tab,i,col1,tambox,num);
                    alone_number(tab);
                }
            } else if (cont == 3) {
                if (col1 / tambox == col2 / tambox && col2/tambox==col3/tambox) {
                    printf("%d -  %d %d %d\n", num, i, col1, col2);
                    limpar_numero_line_box(tab,i,col1,tambox,num);
                    alone_number(tab);
                }


            }
            perclinhas = perclinhas->ps;
        }
    }
}


/**
 * elimina para cada nsoluçoes o numero em toda a box exceto na linha das ocorrencias
 * @param tab tabuleiro que estamos a percorrer
 * @param line  linha que ocorre
 * @param col   coluna que ocorre
 * @param tambox tamanho de cada box
 * @param num numero em que ocorre
 */
void limpar_numero_line_box(TAB*tab,int line,int col,int tambox,int num){

    int lineinit=((line/tambox)*tambox); //primeira posiçao na linha da box
    int colinit =((col/tambox)*tambox);  //primeira posiçao na coluna da box
    CEL *percorrelinhas=chegar_celula(lineinit,colinit,tab);
    CEL* aux;
    printf("\n%d %d\n",lineinit,colinit);
    for (int i = 0; i < tambox; ++i) {      //percorre as linhas
        aux=percorrelinhas;
        for (int j = 0; j < tambox; ++j) {
            if(aux->line!=line){
                atualizar_psol(aux,num);
            }
            aux=aux->pe;
        }

        percorrelinhas=percorrelinhas->ps;

    }
}
/**
 *
 *  Para cada numero percorre as celudas de cada coluna e vefica se o numero tem 2 ou 3 ocorrencias
 * @param tab tabuleiro onde estamos a trabalhar
 */
void box_line_reduction_col(TAB *tab){
    CEL *firstposition = tab->pfirst;
    CEL *aux, *perccols;
    int num, cont = 0, tam = tab->size, lin1 = 0, lin2 = 0, lin3 = 0;
    int tambox =(int)sqrt(tam);
    for (num = 1; num <= tam; ++num) {
        aux = firstposition;
        perccols = firstposition;
        cont = 0;
        for (int i = 0; i < tam; ++i) { //percorre as linhas
            aux = perccols;
            cont = 0;
            for (int j = 0; j < tam; ++j) {     //percorre as colunas da linha
                for (int k = 0; k < aux->nsol; ++k) {
                    if (*(aux->psol + k) == num) {
                        if (cont == 0) {
                            lin1= aux->line;
                        } else if (cont == 1) {
                            lin2 = aux->line;
                        } else if (cont == 2) {
                            lin3 = aux->line;
                        }
                        cont++;
                    }
                }

                aux = aux->ps;
            }
            if (cont == 2) {
                if (lin1 / tambox == lin2 / tambox) {
                    printf("%d -  %d %d %d\n", num, i, lin1, lin2);
                    limpar_numero_col_box(tab,lin1,i,tambox,num);
                    alone_number(tab);
                }
            } else if (cont == 3) {
                if (lin1 / tambox == lin2 / tambox && lin2/tambox==lin3/tambox) {
                    printf("%d -  %d %d %d\n", num, i, lin1, lin2);
                     limpar_numero_col_box(tab,lin1,i,tambox,num);
                    alone_number(tab);
                }

            }
            perccols = perccols->pe;
        }
    }
}

/**
 * elimina para cada nsoluçoes o numero em toda a box exceto na coluna das ocorrencias
 * @param tab tabuleiro que estamos a percorrer
 * @param line  linha que ocorre
 * @param col   coluna que ocorre
 * @param tambox tamanho de cada box
 * @param num numero em que ocorre
 */
void limpar_numero_col_box(TAB*tab,int line,int col,int tambox,int num){

    int lineinit=((line/tambox)*tambox); //primeira posiçao na linha da box
    int colinit =((col/tambox)*tambox);  //primeira posiçao na coluna da box
    CEL *percorrelinhas=chegar_celula(lineinit,colinit,tab);
    CEL* aux;
    printf("%d %d\n",lineinit,colinit);
    for (int i = 0; i < tambox; ++i) {      //percorre as linhas
        aux=percorrelinhas;
        for (int j = 0; j < tambox; ++j) {
            if(aux->col!=col){
                atualizar_psol(aux,num);
            }
            aux=aux->pe;
        }
        percorrelinhas=percorrelinhas->ps;

    }
}