//
// Created by Ruben Jorge on 10/01/2020.
//

#include "NakedPairs.h"
/**
 * vai percorrer o tabuleiro, até encontrar um par, depois testa para a posicao do par onde procurar o segundo par
 * @param tab
 */
void naked_pairs(TAB *tab)
{
        int size = tab->size;
        int count=0,line=0,col=0;
        CEL *linha=tab->pfirst;
        CEL *current =linha;
        CEL *firstpair=NULL;

        for(int i=0;i<size;i++)
        {
            current=linha;
            for(int j=0;j<size;j++)
            {
                //caso a celula for um par
                if(current->nsol==2)
                {
                    firstpair=current;
                    line=firstpair->line;
                    col=firstpair->col;
                    printf("\nencontrei par ho irmao! linha: %d coluna %d ",line,col);
                    if(line+col==size-1 && line==col)
                    {
                       search_second_pair_line(tab,firstpair);
                       search_second_pair_col(tab,firstpair);
                       search_second_pair_box(tab,firstpair);
                       search_second_pair_dp(tab, firstpair);
                       search_second_pair_ds(tab,firstpair);
                    }
                    else
                    {
                        if(line==col)
                        {
                            search_second_pair_line(tab,firstpair);
                            search_second_pair_col(tab,firstpair);
                            search_second_pair_box(tab,firstpair);
                            search_second_pair_dp(tab, firstpair);
                        }
                        else
                        {
                            if(line+col==size-1)
                            {
                                search_second_pair_line(tab,firstpair);
                                search_second_pair_col(tab,firstpair);
                                search_second_pair_box(tab,firstpair);
                                search_second_pair_ds(tab,firstpair);
                            }
                            else
                            {
                                search_second_pair_line(tab,firstpair);
                                search_second_pair_col(tab,firstpair);
                                search_second_pair_box(tab,firstpair);

                            }
                        }
                    }

                }
                current=current->pe;

            }
            linha=linha->ps;
        }
}
/**
 * procura o segundo par na linha
 * @param tab  tabuleiro
 * @param firstpair celula que representa o primeiro par
 */
void search_second_pair_line(TAB*tab,CEL*firstpair)
{
    int size=tab->size;
    CEL *linha=firstpair->pe;
    for(int i=((firstpair->col)+1);i<size;i++)
    {
        if(linha->nsol==2)      //encontrou outro par na linha
        {

            if(*(linha->psol+0)==*(firstpair->psol+0)&&*(linha->psol+1)==*(firstpair->psol+1))//se o par for igual
            {
                printf("\nLINHA -encontrei o irmao dele ho maninho! linha: %d coluna: %d",firstpair->line,i);
                atualizar_pair_linha(tab,firstpair,linha);
                alone_number(tab);
                return;
            }
        }
        linha=linha->pe;
    }
}
/**
 * procura o segundo par na coluna
 * @param tab  tabuleiro
 * @param firstpair celula que representa o primeiro par
 */
void search_second_pair_col(TAB *tab,CEL*firstpair)
{
    int size=tab->size;
    CEL *col=firstpair->ps;
    for(int i=firstpair->line+1;i<size;i++)
    {
        if(col->nsol==2)
        {

            if(*(col->psol+0)==*(firstpair->psol+0) && *(col->psol+1)==*(firstpair->psol+1))//ter solucoes iguais
            {
                printf("\nCOLUNA -encontrei o irmao dele ho maninho! linha: %d coluna: %d",i,firstpair->col);
                atualizar_pair_coluna(tab,firstpair,col);
                alone_number(tab);
                return;
            }

        }
        col=col->ps;
    }
}
/**
 * procura o segundo par na box
 * @param tab  tabuleiro
 * @param firstpair celula que representa o primeiro par
 */
void search_second_pair_box(TAB *tab,CEL*firstpair)
{
    int aux=(int)sqrt(tab->size);
    int li,ci; //linha e coluna iniciais da cel da submatriz
    li=(firstpair->line)-(firstpair->line%aux);
    ci=(firstpair->col)-(firstpair->col%aux);
    CEL *lines=chegar_celula(li,ci,tab); //primeira celula da box
    CEL *auxcel=NULL;
    for(int i =0;i<aux;i++)
    {
        auxcel=lines;
        for(int j=0;j<aux;j++)
        {
            if(auxcel->nsol==2)
            {
                if (auxcel == firstpair)//se tiverem o mesmo endereço
                {
                        auxcel = auxcel->pe;
                        continue;

                }
                if (*(auxcel->psol + 0) == *(firstpair->psol + 0) &&
                    *(auxcel->psol + 1) == *(firstpair->psol + 1))//ter solucoes iguais
                {
                    printf("\nBOX -encontrei o irmao dele ho maninho! linha: %d coluna: %d", auxcel->line, auxcel->col);
                    atualizar_pair_box(tab,firstpair,auxcel);
                    alone_number(tab);
                    return;
                }
            }
            auxcel=auxcel->pe;
        }
        lines=lines->ps;
    }
}
/**
 * procura o segundo par na diagonal principal
 * @param tab  tabuleiro
 * @param firstpair celula que representa o primeiro par
 */
void search_second_pair_dp(TAB *tab,CEL*firstpair)
{
    int size=tab->size;
    CEL *dp=firstpair->pse;
    for(int i=firstpair->col+1;i<size;i++)
    {
        if(dp->nsol==2)
        {
            if(dp==firstpair)
            {
                dp=dp->pse;
                continue;
            }
            if (*(dp->psol + 0) == *(firstpair->psol + 0) &&
                *(dp->psol + 1) == *(firstpair->psol + 1))//ter solucoes iguais
            {
                printf("\nDP-encontrei o irmao dele ho maninho! linha: %d coluna: %d", dp->line, dp->col);
                atualizar_pair_dp(tab,firstpair,dp);
                alone_number(tab);
                return;
            }
        }
        dp=dp->pse;
    }

}
/**
 * procura o segundo par na diagonal secundaria
 * @param tab  tabuleiro
 * @param firstpair celula que representa o primeiro par
 */
void search_second_pair_ds(TAB *tab,CEL*firstpair)
{
    int size=tab->size;
    CEL *ds=firstpair->pso;
    for(int i=firstpair->line+1;i<size;i++)
    {
        if(ds->nsol==2)
        {
            if(ds==firstpair)
            {
                ds=ds->pso;
                continue;
            }
            if (*(ds->psol + 0) == *(firstpair->psol + 0) &&
                *(ds->psol + 1) == *(firstpair->psol + 1))//ter solucoes iguais
            {
                printf("\nDS-encontrei o irmao dele ho maninho! linha: %d coluna: %d", ds->line, ds->col);
                atualizar_pair_ds(tab,firstpair,ds);
                alone_number(tab);
                return;
            }

        }
        ds=ds->pso;
    }

}

/**
 * atuliza a linha retirando as solucoes das outras celulas que sejam iguais ao firstcel e secondcel
 * @param tab tabuleiro
 * @param firstpair primeiro par
 * @param secondpair segundo par
 */
void atualizar_pair_linha(TAB *tab,CEL *firstpair, CEL *secondpair)
{
    int size=tab->size;
    CEL *linha=chegar_celula(firstpair->line,0,tab);
    for(int i=0;i<size;i++)
    {
        if (linha == firstpair || linha == secondpair|| linha->nsol==1) {
            linha=linha->pe;
            continue;
        }
        else {
            for (int j = 0; j < 2; j++)
            {
                atualizar_psol(linha, *(firstpair->psol+j));
            }
        }
        linha=linha->pe;
    }
}
/**
* atuliza a coluna retirando as solucoes das outras celulas que sejam iguais ao firstcel e secondcel
* @param tab tabuleiro
* @param firstpair primeiro par
* @param secondpair segundo par
*/
void atualizar_pair_coluna(TAB *tab, CEL *firstpair, CEL *secondpair)
{
    int size=tab->size;
    CEL *coluna=chegar_celula(0,firstpair->col,tab);
    for(int i=0;i<size;i++)
    {
        if (coluna == firstpair || coluna == secondpair|| coluna->nsol==1) {
            coluna=coluna->ps;
            continue;
        }
        else {
            for (int j = 0; j < 2; j++)
            {
                atualizar_psol(coluna, *(firstpair->psol+j));
            }
        }
        coluna=coluna->ps;
    }
}
/**
* atuliza a box retirando as solucoes das outras celulas que sejam iguais ao firstcel e secondcel
* @param tab tabuleiro
* @param firstpair primeiro par
* @param secondpair segundo par
*/
void atualizar_pair_box(TAB *tab, CEL *firstpair, CEL *secondpair)
{

    int aux=(int)sqrt(tab->size);
    int li,ci; //linha e coluna iniciais da cel da submatriz
    li=(firstpair->line)-(firstpair->line%aux);
    ci=(firstpair->col)-(firstpair->col%aux);
    CEL *lines=chegar_celula(li,ci,tab); //primeira celula da box
    CEL *auxcel=NULL;
    for(int i =0;i<aux;i++)
    {
        auxcel=lines;
        for(int j=0;j<aux;j++)
        {
                if (auxcel == firstpair || auxcel==secondpair || auxcel->nsol==1)//se tiverem o mesmo endereço
                {
                    auxcel = auxcel->pe;
                    continue;

                }
                else
                    {
                         for (int k = 0; k < 2; k++)
                            {
                                atualizar_psol(auxcel, *(firstpair->psol+k));
                            }

                    }
            auxcel=auxcel->pe;
        }
        lines=lines->ps;
    }
}
/**
* atuliza a diagonal principal as solucoes das outras celulas que sejam iguais ao firstcel e secondcel
* @param tab tabuleiro
* @param firstpair primeiro par
* @param secondpair segundo par
*/
void atualizar_pair_dp(TAB *tab, CEL *firstpair, CEL *secondpair)
{
    int size=tab->size;
    CEL *dp=tab->pfirst;
    for(int i=0;i<size;i++)
    {

            if(dp==firstpair ||dp ==secondpair ||dp->nsol==1 )
            {
                dp=dp->pse;
                continue;
            }
            else
            {
                for (int j = 0; j < 2; j++)
                {
                    atualizar_psol(dp, *(firstpair->psol+j));
                }
            }
        dp=dp->pse;
    }
}
/**
* atuliza a diagonal secundaria retirando as solucoes das outras celulas que sejam iguais ao firstcel e secondcel
* @param tab tabuleiro
* @param firstpair primeiro par
* @param secondpair segundo par
*/
void atualizar_pair_ds(TAB *tab, CEL *firstpair, CEL *secondpair)

{
    int size=tab->size;
    CEL *ds=chegar_celula(0,size-1,tab);
    for(int i=0;i<size;i++)
    {

        if(ds==firstpair ||ds ==secondpair || ds->nsol==1)
        {
            ds=ds->pso;
            continue;
        }
        else
        {
            for (int j = 0; j < 2; j++)
            {
                atualizar_psol(ds, *(firstpair->psol+j));
            }
        }
        ds=ds->pso;
    }
}



