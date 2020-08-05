//
// Created by Ruben Jorge on 12/01/2020.
//

#ifndef LPPROG2FI_BOX_LINE_REDUCTION_H
#define LPPROG2FI_BOX_LINE_REDUCTION_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "library.h"
#include "R9.h"
#include "Hidden.h"
void box_line_reduction(TAB *tab);
void box_line_reduction_col(TAB *tab);
void limpar_numero_col_box(TAB*tab,int line,int col,int tambox,int num);
void limpar_numero_line_box(TAB*tab,int line,int col,int tambox,int num);
#endif //LPPROG2FI_BOX_LINE_REDUCTION_H
