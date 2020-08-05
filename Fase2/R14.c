//
// Created by Ruben Jorge on 12/01/2020.
//

#include "R14.h"

/**
 *funcao que insere para um txt as solucoes encontradas
 * @param tab
 */
void put_solution_on_Txt(TAB *tab) {
    int i = 0, j = 0;                                //auxiliares para montar o "titulo" por exemplo 1X16
    int static ntab = 0;
    char tabela[2];
    char tamanhotabela[3];
    char titulo[5];
    char auxtitulo[5];
    int num;
    CEL *aux = tab->pfirst;
    CEL *perclinhas = aux;

    strcpy(titulo, tabela);
    strcat(titulo, "x");
    strcat(titulo, tamanhotabela);


    FILE *file;
    file = fopen("C:\\Users\\Ruben Jorge\\Desktop\\hugopj\\lpprog2fi\\solucoes.txt", "a+");
    if (file == NULL) {
        printf("\nErro ao abrir txt!");
        return;
    }

    fprintf(file, "\n\n");

    for (i = 0; i < tab->size; i++)                                       //insere a matriz no txt
    {
        aux = perclinhas;
        for (j = 0; j < tab->size; j++) {
            fprintf(file, "%d ", aux->info);
            aux = aux->pe;
        }
        perclinhas = perclinhas->ps;
        fprintf(file, "\n");
    }
    fprintf(file, "\n\n");
    ntab++;
    fclose(file);

}