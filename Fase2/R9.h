//
// Created by Hugo Vieira on 05/01/2020.
//

#ifndef LPPROG2FI_R9_H
#define LPPROG2FI_R9_H
#include <stdlib.h>
#include <stdio.h>
#include "library.h"
#include <time.h>
#include <math.h>
//inicializacao
TABS* init_tabs(int size);
void inicializar_tabuleiro(TAB *tab);
void init_tab_rand(int n, TAB *tab);
//mascara
void verifica_possibilidades(TAB *tab,CEL *aux);
void get_mascara(TAB *tab);
void print_mascara(TAB *tab);
void atualizar_mascara(TAB *tab, CEL *cel);
void atualizar_linha(TAB *tab,CEL *cel,int num);
void atualizar_coluna(TAB*tab,CEL *cel,int num);
void atualizar_box(TAB *tab,CEL *cel,int num);
void atualizar_principal(TAB *tab, CEL *cel,int num);
void atualizar_secundaria(TAB*tab, CEL *cel,int num);
void atualizar_psol(CEL *cel,int num);
//txt
TABS* get_tabuleiros_from_txt();
//aux
void imprimir_tabuleiro(TAB tab);
CEL* chegar_celula(int line, int col, TAB *tab);


#endif //LPPROG2FI_R9_H
