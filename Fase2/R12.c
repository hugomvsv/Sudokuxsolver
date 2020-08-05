//
// Created by Ruben Jorge on 09/01/2020.
//

#include "R12.h"
/**
 * funcao de backtraking que encontra 1 ou varias solucoes do txt
 * @param tab tabuleiro
 * @param flag quando esta a 1 apenas encontra uma solucao, quando a 0 encontra as que puder encontrar
 * @return
 */
int Backtraking_SudokuX(TAB *tab,int flag)
{   int size=tab->size;
    CEL *auxcel=NULL;
    if(!(FindBlanckCel(tab,&auxcel)))
    {
        if(flag==1)
            return 1;
        if(flag==0)
        {
            //por solucaao  no texto
            return 0;
        }
    }

    for(int num=1;num<=tab->size;num++)
    {
        if(checkConsist(*tab,*auxcel,num))
        {
            auxcel->info=num;
            if(Backtraking_SudokuX(tab,flag))
            {
                return 1;
            }
            auxcel->info=0;
        }

    }
    return 0;


}
/**
 * funcao que encontra celulas com o info a 0, (vazias)
 * @param tab tabuleiro
 * @param cel celula a modificar
 * @return
 */
int FindBlanckCel(const TAB *tab,CEL **cel)
{
    int size=tab->size;
    CEL*first=tab->pfirst;
    CEL*auxcel=NULL;

    for(int i=0;i<size;i++)
    {
        auxcel=first;
        {
            while(auxcel!=NULL)
            {
                if(auxcel->info==0)
                {
                    *cel=auxcel;
                    return 1;
                }
                auxcel=auxcel->pe;
            }
            first=first->ps;
        }
    }
    return 0;
}
