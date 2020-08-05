#include <stdio.h>
#include "Fase2/library.h"
#include "Fase2/R9.h"
#include "Fase2/R13.h"
#include "Fase2/R12.h"
#include "Fase2/box_line_reduction.h"
#include "Fase2/PointingPairs.h"
#include <string.h>
void teste(char str[]);

int main() {
    TABS *tabs=get_tabuleiros_from_txt();
    TAB *T1=tabs->ntabs+0;

    imprimir_tabuleiro(*T1);
    get_mascara(T1);
    printf("\n");
    print_mascara(T1);
    //Backtraking_SudokuX(T1,1);
    get_solution_by_us(T1);
    //box_line_reduction_col(T1);
    imprimir_tabuleiro(*T1);
    printf("\n");
    print_mascara(T1);


}
