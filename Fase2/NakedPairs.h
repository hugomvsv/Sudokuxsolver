//
// Created by Ruben Jorge on 10/01/2020.
//

#ifndef LPPROG2FI_NAKEDPAIRS_H
#define LPPROG2FI_NAKEDPAIRS_H
#include <stdlib.h>
#include <stdio.h>
#include "library.h"
#include "R9.h"
#include "Hidden.h"
//main
void naked_pairs(TAB *tab);
//pesquisa do segundo par
void search_second_pair_line(TAB*tab,CEL*firstpair);
void search_second_pair_col(TAB *tab,CEL*firstpair);
void search_second_pair_box(TAB *tab,CEL*firstpair);
void search_second_pair_dp(TAB *tab,CEL*firstpair);
void search_second_pair_ds(TAB *tab,CEL*firstpair);
//atualizaçao do par
void atualizar_pair_linha(TAB *tab, CEL *firstpair, CEL *secondpair);
void atualizar_pair_coluna(TAB *tab, CEL *firstpair, CEL *secondpair);
void atualizar_pair_box(TAB *tab, CEL *firstpair, CEL *secondpair);
void atualizar_pair_dp(TAB *tab, CEL *firstpair, CEL *secondpair);
void atualizar_pair_ds(TAB *tab, CEL *firstpair, CEL *secondpair);
#endif //LPPROG2FI_NAKEDPAIRS_H
