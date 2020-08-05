#include "Check.h"
/**
 *  funcao que cheka se um determinado numero é consistente e se pode ser inserido no tabuleiro
 * @param tab  tabuleiro onde estamos a trabalhar
 * @param cel  celula onde vai testar a consistencia
 * @param n    numero que vai ter de testar
 * @return
 */
int checkConsist( TAB tab,CEL cel,int n) {
    if ((cel.line == cel.col) && (cel.line + cel.col == tab.size-1)) //caso esteja no centro (mat impares)
    {
        //testar para todos os checks
        if(checklin(&cel,n) &&checkcol(&cel,n) && checkdiaprin(&cel,n) &&checkdiasec(&cel,n) && checkbox(&tab,&cel,n,tab.size))
            return 1;
    }
    else {
        if (cel.line == cel.col)       //caso esteja na diagonal principal
        {
            if(checklin(&cel,n) &&checkcol(&cel,n) && checkdiaprin(&cel,n) && checkbox(&tab,&cel,n,tab.size))
                return 1;
        }
        else {
            if (cel.line + cel.col == tab.size-1)     //caso esteja na diagonal secundária
            {
                if(checklin(&cel,n) &&checkcol(&cel,n) &&checkdiasec(&cel,n) && checkbox(&tab,&cel,n,tab.size))
                    return 1;
            }
            else
            {//vai testar linhas col e box

                if(checklin(&cel,n)&&checkcol(&cel,n)&&checkbox(&tab,&cel,n,tab.size))
                    return 1;
            }
        }
    }
    return 0;
}

/**
 * funcao que percorre a linha e testa o numero
 * @param cel celula onde estamos a testar o numero
 * @param n   numero a ser testado
 * @return  retorna 1 caso de sucesso e 0 no caso de erro
 */
int checklin(CEL *cel,int n) //temos de andar para 'Este' e ou para 'Oeste'
{
    int number=n;
    CEL *auxcel=cel;


    if(cel->po==NULL)//ser a primeira celula da linha
    {
        //testar só para este
        while(auxcel->pe!=NULL)
        {
            if(auxcel->pe->info==number)
                return 0;
            auxcel=auxcel->pe;
        }
        return 1;

    }
    else
    {
        if(cel->pe==NULL) //ser a ultima celula da linha
        {
            //testar só para oeste
            while(auxcel->po!=NULL)
            {
                if(auxcel->po->info==number)
                    return 0;
                auxcel=auxcel->po;
            }
            return 1;

        }
        else
        {   //ser uma celula a meio da linha
            //testar para os dois lados
            CEL *first=auxcel;
            while(auxcel->pe!=NULL)
            {
                if(auxcel->pe->info==number)
                    return 0;
                auxcel=auxcel->pe;
            }
            auxcel=first;
            while(auxcel->po!=NULL)
            {
                if(auxcel->po->info==number)
                    return 0;
                auxcel=auxcel->po;
            }
            return 1;
        }
    }

}
/**
 * funcao que percorre a coluna e testa o numero
 * @param cel celula onde estamos a testar o numero
 * @param n   numero a ser testado
 * @return  retorna 1 caso de sucesso e 0 no caso de erro
 */
int checkcol(CEL *cel,int n)//temos de andar para 'Norte' e ou par 'Sul'
{
    int number=n;
    CEL *auxcel=cel;
    if(cel->pn==NULL)       //ser a primeira celula da coluna
    {
        //testar para sul
        while(auxcel->ps!=NULL)
        {
            if(auxcel->ps->info==number)
                return 0;
            auxcel=auxcel->ps;
        }
        return 1;
    }
    else
    {
        if(cel->ps==NULL)
        {
            //testar para norte
            while(auxcel->pn!=NULL)
            {
                if(auxcel->pn->info==number)
                    return 0;
                auxcel=auxcel->pn;
            }
            return 1;
        }
        else
        {
            //testar para sul
            CEL *first=auxcel;
            while(auxcel->ps!=NULL)
            {
                if(auxcel->ps->info==number)
                    return 0;
                auxcel=auxcel->ps;
            }
            auxcel=first;
            //testar para norte
            while(auxcel->pn!=NULL)
            {
                if(auxcel->pn->info==number)
                    return 0;
                auxcel=auxcel->pn;
            }
            return 1;
        }
    }
}
/**
 * funcao que percorre a diagonal principal e testa o numero
 * @param cel celula onde estamos a testar o numero
 * @param n   numero a ser testado
 * @return  retorna 1 caso de sucesso e 0 no caso de erro
 */
int checkdiaprin(CEL *cel,int n) //temos de andar para 'Noroeste' e 'Sudeste'
{

    int number=n;
    CEL *auxcel=cel;
    CEL *first=cel;

    if(auxcel->pno==NULL) //primeira celula da diagonal principal
    {
        //testar para pse
        while(auxcel->pse!=NULL)
        {
            if(auxcel->pse->info==number)
                return 0;
            auxcel=auxcel->pse;
        }
        return 1;
    }
    else
    {
        if(auxcel->pse==NULL)//ultima celula da diagonal principal
        {
            //testar só para pno
            while(auxcel->pno!=NULL)
            {
                if(auxcel->pno->info==number)
                    return 0;
                auxcel=auxcel->pno;
            }
            return 1;

        }
        else
        {
            //celula no meio da diagonal
            //testamos para os dois lados
            while(auxcel->pse!=NULL)
            {
                if(auxcel->pse->info==number)
                    return 0;
                auxcel=auxcel->pse;
            }
            auxcel=first;
            while(auxcel->pno!=NULL)
            {
                if(auxcel->pno->info==number)
                    return 0;
                auxcel=auxcel->pno;
            }
            return 1;
        }
    }
}
/**
 * funcao que percorre a diagonal principal e testa o numero
 * @param cel celula onde estamos a testar o numero
 * @param n   numero a ser testado
 * @return  retorna 1 caso de sucesso e 0 no caso de erro
 */
int checkdiasec(CEL *cel,int n) //temos de andar para 'Nordeste' e ou 'Sudoeste'
{
    int number=n;
    CEL *auxcel=cel;
    CEL *first=cel;

    if(auxcel->pne==NULL) //andar só para pso
    {
        while(auxcel->pso!=NULL)
        {
            if(auxcel->pso->info==number)
                return 0;
            auxcel=auxcel->pso;
        }
        return 1;

    }
    else
    {
        if(auxcel->pso==NULL)   //andar só para pne
        {
            while(auxcel->pne!=NULL)
            {
                if(auxcel->pne->info==number)
                    return 0;
                auxcel=auxcel->pne;
            }
            return 1;
        }
        else
        {
            //fazemos para as duas
            while(auxcel->pso!=NULL)
            {
                if(auxcel->pso->info==number)
                    return 0;
                auxcel=auxcel->pso;
            }
            auxcel=first;
            while(auxcel->pne!=NULL)
            {
                if(auxcel->pne->info==number)
                    return 0;
                auxcel=auxcel->pne;
            }
            return 1;
        }
    }

}
/**
* funcao que percorre a box e testa o numero
 * @param cel celula onde estamos a testar o numero
 * @param n   numero a ser testado
 * @return  retorna 1 caso de sucesso e 0 no caso de erro
 * @param size  tamanho do tabuleiro
 * @return
 */
int checkbox(TAB *tab,CEL *cel,int n,int size)
{
    int aux=(int)sqrt(size);
    int number=n;
    int li,ci; //linha e coluna iniciais da cel da submatriz
    li=(cel->line)-(cel->line%aux);
    ci=(cel->col)-(cel->col%aux);
    CEL *found=chegar_celula(li,ci,tab);
    CEL *auxcel=found;//igual á 1º cel
    CEL *wlines=found;//igual á 1º cel
    for(int i =0;i<aux;i++)
    {
        auxcel=wlines;
        for(int j=0;j<aux;j++)
        {
            if(auxcel->info==number)
                return 0;
            auxcel=auxcel->pe;
        }
        wlines=wlines->ps;
    }
    return 1;
}