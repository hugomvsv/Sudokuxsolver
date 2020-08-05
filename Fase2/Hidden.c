//
// Created by Ruben Jorge on 10/01/2020.
//

#include "Hidden.h"
/**
 * todos as celulas que tem apenas uma solucao
 * @param tab
 */
void alone_number(TAB *tab) {

    CEL *aux = tab->pfirst;
    CEL *perclinhas = aux;
    CEL *save=aux;
    int line=0;
    int col=0;
    int size=tab->size;
    int mods=1;
    while(mods!=0)
    {
        mods=0;
        aux=save;
        perclinhas=save;
        for (int i = 0; i < tab->size; ++i)
        {
            aux = perclinhas;
            for (int j = 0; j < tab->size; ++j)
            {
                if (aux->nsol == 1) {
                    printf("\nENCONTREI UM SOSINHO LINHA: %d COLUNA: %d", i, j);
                    if (checkConsist(*tab, *aux, *aux->psol))
                    {
                        aux->info = *aux->psol;
                        mods++;
                        atualizar_mascara(tab, aux);
                        aux->nsol = 0;
                    }
                    else
                        {
                        printf("\nTabuleiro nao e resolvivel!");
                        return;
                    }
                }
                aux = aux->pe;
            }
            perclinhas = perclinhas->ps;
        }
    }
}
/**
 * funcao main dos hidden
 * Objetivo: percorre as linhas colunas box dp e ds e vê se existe uma celula que uma das solucoes seja unica
 * @param tab ->tabuleiro
 */
void hidden_singles(TAB *tab)        //percorre as celulas e vê se
{
    int x=0;

        x = x + hidden_singles_line(tab);
        x = x + hidden_single_colunas(tab);
        x = x + hidden_singles_box(tab);
        x = x + hidden_singles_diag_principal(tab);
       x = x + hidden_singles_diag_secundaria(tab);
        printf("Modificoes do HIDDEN = %d", x);

}

/**
 * percorre colunas e vê se para cada celula uma das suas solucoes seja unica para a coluna
 * se sim atualiza.
 * @param tab tabuleiro
 * @return numero de modificaçoes
 */
int hidden_single_colunas(TAB *tab) {
    CEL *cel = tab->pfirst;
    CEL *avancacol = cel;
    CEL *aux = NULL;
    int cont = 0, mod =0;
    int num;
    for (int i = 0; i < tab->size; ++i) { // avançar colunas
        cel = avancacol;
        for (num = 1; num <= tab->size; ++num) {//numero
            cont = 0;
            cel = avancacol;
            for (int j = 0; j < tab->size; ++j) {     //avançar linhas
                for (int k = 0; k < cel->nsol; ++k) {
                    if (*(cel->psol + k) == num) {
                        aux = cel;
                        cont++;
                        break;
                    }
                }
                cel = cel->ps;
            }
            if (cont == 1)
                if (checkConsist(*tab, *aux, num))
                {
                    printf("Hidden_single_col %d %d\n", aux->line, aux->col);
                    aux->info = num;
                    mod++;
                   for(int p=0;p<aux->nsol;p++)
                   {
                       free(aux->psol+p);
                   }
                    aux->nsol = 0;
                    atualizar_mascara(tab,aux);
                    alone_number(tab);

                }
        }
        avancacol = avancacol->pe;
    }
    return mod;
}

/**
 * percorre linhas e vê se para cada celula uma das suas solucoes seja unica para a coluna
 * se sim atualiza.
 * @param tab tabuleiro
 * @return numero de modificaçoes
 */
int hidden_singles_line(TAB *tab) {
    CEL *cel = tab->pfirst;
    CEL *avancacol = cel;
    CEL *aux = NULL;
    int cont = 0, mod = 0;
    int num;
    for (int i = 0; i < tab->size; ++i) { // avançar linha
        cel = avancacol;
        for (num = 1; num <= tab->size; ++num) {//numero
            cont = 0;
            cel = avancacol;
            for (int j = 0; j < tab->size; ++j) {     //avançar colunas
                for (int k = 0; k < cel->nsol; ++k) {
                    if (*(cel->psol + k) == num) {
                        aux = cel;
                        cont++;
                        break;
                    }
                }
                cel = cel->pe;
            }
            if (cont == 1)
                if (checkConsist(*tab, *aux, num)) {
                    printf("Hidden_single_lin %d %d\n", aux->line, aux->col);
                    aux->info = num;
                    mod++;
                    for(int p=0;p<aux->nsol;p++)
                    {
                        free(aux->psol+p);
                    }
                    aux->nsol = 0;
                    atualizar_mascara(tab,aux);
                    alone_number(tab);

                }
        }
        avancacol = avancacol->ps;
    }
    return mod;
}
/**
 * percorre diagonal principal e vê se para cada celula uma das suas solucoes seja unica para a coluna
 * se sim atualiza.
 * @param tab tabuleiro
 * @return numero de modificaçoes
 */

int hidden_singles_diag_principal(TAB *tab) {
    CEL *cel = tab->pfirst;
    CEL *aux = NULL;
    int cont = 0, mod = 0;
    int num;


    for (num = 1; num <= tab->size; ++num) {//numero
        cont = 0;
        cel = tab->pfirst;
        for (int j = 0; j < tab->size; ++j) {     //avançar posiçao
            for (int k = 0; k < cel->nsol; ++k) {
                if (*(cel->psol + k) == num) {
                    aux = cel;
                    cont++;
                    break;
                }
            }
            cel = cel->pse;
        }
        if (cont == 1)
            if (checkConsist(*tab, *aux, num)) {
                printf("Hidden_single_diag_princ %d %d\n", aux->line, aux->col);
                aux->info = num;
                mod++;
                for(int p=0;p<aux->nsol;p++)
                {
                    free(aux->psol+p);
                }
                aux->nsol = 0;
                atualizar_mascara(tab,aux);
                alone_number(tab);

            }
    }
    return mod;
}
/**
 * percorre diagonal secundaria e vê se para cada celula uma das suas solucoes seja unica para a coluna
 * se sim atualiza.
 * @param tab tabuleiro
 * @return numero de modificaçoes
 */
int hidden_singles_diag_secundaria(TAB *tab) {
    CEL *cel = tab->pfirst;
    CEL *primeirapos = cel;
    CEL *aux = NULL;
    int cont = 0, mod = 0;
    int num;
    for (int k = 0; k < tab->size - 1; ++k) {
        primeirapos = primeirapos->pe;
    }

    for (num = 1; num <= tab->size; ++num) {//numero
        cont = 0;
        cel = primeirapos;
        for (int j = 0; j < tab->size; ++j) {     //avançar posiçao
            for (int k = 0; k < cel->nsol; ++k) {
                if (*(cel->psol + k) == num) {
                    aux = cel;
                    cont++;
                    break;
                }
            }
            cel = cel->pso;
        }
        if (cont == 1)
            if (checkConsist(*tab, *aux, num)) {
                printf("Hidden_single_diag_sec %d %d\n", aux->line, aux->col);
                aux->info = num;
                mod++;
                for(int p=0;p<aux->nsol;p++)
                {
                    free(aux->psol+p);
                }
                aux->nsol = 0;
                atualizar_mascara(tab,aux);
                alone_number(tab);
            }
    }
    return mod;
}
/**
 * percorre as box
 * @param tab
 * @return
 */
int hidden_singles_box(TAB *tab) {
    int tam=(int)sqrt(tab->size);
    int li=0,ci=0;
    int mod=0;
    for (int i = 0; i <tam; ++i) {
        ci=0;
        for (int j = 0; j <tam ; ++j) {

            mod=hidden_box(tab,li,ci,tam);
            ci+=tam;
        }
        li+=tam;
    }
}
/**
 * percorre a box e vê se para cada celula uma das suas solucoes seja unica para a coluna
 * se sim atualiza.
 * @param tab tabuleiro
 * @return numero de modificaçoes
 */
int hidden_box(TAB *tab,int li,int ci, int tam){
    CEL *cel= chegar_celula(li,ci,tab);
    CEL *primeirapos=cel;
    CEL *perclinhas=cel;
    CEL *aux=NULL;
    int num, cont=0,mod=0;
    for (num = 1; num <= tab->size; ++num) {//numero
        cont = 0;
        cel=primeirapos;
        perclinhas=primeirapos;
        for (int i = 0; i < tam; ++i) {
            cel=perclinhas;
            for (int j = 0; j <tam ; ++j) {
                for (int k = 0; k < cel->nsol; ++k) {
                    if (*(cel->psol + k) == num) {
                        aux = cel;
                        cont++;
                        break;
                    }
                }
                cel=cel->pe;
            }
            perclinhas=perclinhas->ps;

        }
        if (cont == 1)
            if (checkConsist(*tab, *aux, num)) {
                printf("Hidden_single_box %d %d %d\n", aux->line, aux->col,num);
                aux->info = num;
                mod++;
                for(int p=0;p<aux->nsol;p++)
                {
                    free(aux->psol+p);
                }
                aux->nsol = 0;
                atualizar_mascara(tab,aux);
                alone_number(tab);
            }


    }
    return mod;}