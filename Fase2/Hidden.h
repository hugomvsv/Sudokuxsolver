//
// Created by Ruben Jorge on 10/01/2020.
//

#ifndef LPPROG2FI_HIDDEN_H
#define LPPROG2FI_HIDDEN_H

#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "Check.h"

void alone_number(TAB *tab);
int hidden_single_colunas(TAB *tab);
void hidden_singles(TAB*tab);
int hidden_singles_line(TAB*tab);
int hidden_singles_diag_principal(TAB *tab);
int hidden_singles_diag_secundaria(TAB *tab);
int hidden_box(TAB *tab,int li,int ci, int tam);
int hidden_singles_box(TAB *tab);
#endif //LPPROG2FI_HIDDEN_H
