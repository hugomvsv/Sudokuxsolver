//
// Created by Hugo Vieira on 09/01/2020.
//

#include "R13.h"
/**
 * funcao que resolve o tabuleiro
 * @param tab tabuleiro
 */
void get_solution_by_us(TAB *tab)
{ int count=0;
    while(findblanckcel(tab))
    {
        count++;
        alone_number(tab);
        hidden_singles(tab);
        percorre_pointing_pair(tab);
        box_line_reduction(tab);
        naked_pairs(tab);
        if(count==3)
        {
            break;
        }
    }
    if(Backtraking_SudokuX(tab,1))
    {
        imprimir_tabuleiro(*tab);
        put_solution_on_Txt(tab);

    }
    else
    {
        printf("Não existe solucao!");
    }
    printf("SEFINI!");

}
/**
 * funcao que encontra celulas vazias no tabuleiro
 * @param tab ->tabuleiro
 * @return
 */
int findblanckcel(TAB *tab)
{
    int size=tab->size;
    CEL *linha=tab->pfirst;
    CEL*current=linha;

    for(int i=0;i<size;i++)
    {

        current=linha;
        for(int j=0;j<size;j++)
        {
            if(current->info==0)
            {
                return 1;
            }
            current=current->pe;
        }
        linha=linha->ps;
    }
    return  0;
}

