#include "R9.h"
#include "Check.h"

/**
 * funcao que inicializa o tabs  com os ntabs que temos no ficheiro
 * @param size
 * @return
 */
TABS* init_tabs(int size)
{
    TABS *tabs=calloc(size,sizeof(TABS));
    tabs->ntabs=(TAB*)malloc(sizeof(TAB));
    tabs->nt=size;
    return tabs;
}

/**
 * inicializa um tabuleiro ligando todas as suas celulas, alocando espaço para as mesmas
 * @param tab -> tabuleiro
 */
void inicializar_tabuleiro(TAB *tab) {
    CEL *current = calloc(sizeof(CEL), 1), *linhaant, *colant;
    tab->pfirst = current;
    linhaant = tab->pfirst;
    colant = tab->pfirst;
    int tam = tab->size;
    for (int linhas = 0; linhas < tam; linhas++) {
        for (int colunas = 0; colunas < tam; colunas++) {
            if (linhas == 0 && colunas == 0) { //se estiver na primeira posiçao
                current->line = linhas;
                current->col = colunas;
                current->pe = calloc(sizeof(CEL), 1);
                current->ps = calloc(sizeof(CEL), 1);
            } else if (linhas == 0 && colunas != 0 &&
                       colunas != tam - 1) {   //se estiver na primeira linha mas nao na primeira posiçao nem na ultima
                current->line = linhas;
                current->col = colunas;
                current->pe = calloc(sizeof(CEL), 1);
                current->po = colant;
                current->ps = calloc(sizeof(CEL), 1);
            } else if (linhas == 0 && colunas == tam - 1) {//se estiver  na ultima posiçao da primeira linha
                current->line = linhas;
                current->col = colunas;
                current->ps = calloc(sizeof(CEL), 1);
                current->po = colant;

            } else if (linhas != 0 && colunas == 0 && linhas != tam -
                                                                1) {       //se estiver na primeira coluna e nao estiver nem na primeira nem na ultima linha
                current->line = linhas;
                current->col = colunas;
                current->pn = linhaant;
                current->ps = calloc(sizeof(CEL), 1);
                current->pe = linhaant->pe->ps;
            } else if (linhas != 0 && colunas != 0 && colunas != tam - 1 &&
                       linhas != tam - 1) { //se nao estiver em nenhuuma e xtremidade
                current->line = linhas;
                current->col = colunas;
                current->pn = colant->pn->pe;
                current->pe = colant->pn->pe->pe->ps;
                current->po = colant;
                current->ps = calloc(sizeof(CEL), 1);
            } else if (linhas != 0 && colunas == tam - 1 &&
                       linhas != tam - 1) {//se estiver na ultima colunas mas em nenhuma das extremidades
                current->line = linhas;
                current->col = colunas;
                current->po = colant;
                current->ps = calloc(sizeof(CEL), 1);
                current->pn = colant->pn->pe;
            } else if (linhas == tam - 1 && colunas != 0 &&
                       colunas != tam - 1) { //se estiver na ultima linha mas em nenhuma das extremidades
                current->line = linhas;
                current->col = colunas;
                current->pn = colant->pn->pe;
                current->po = colant;
                current->pe = colant->pn->pe->pe->ps;;
            } else if (linhas == tam - 1 && colunas == 0) {        //primeira coluna ultima linha
                current->line = linhas;
                current->col = colunas;
                current->pn = linhaant;
                current->pe = linhaant->pe->ps;
            } else if (linhas == tam - 1 && colunas == tam - 1) { //ultima coluna ultima linha
                current->line = linhas;
                current->col = colunas;
                current->po = colant;
                current->pn = colant->pn->pe;

            }

            colant = current;
            current = current->pe;
        }
        if (linhas >= 1) {
            linhaant = linhaant->ps;
        }
        current = linhaant->ps;
    }

    //ligar diagonar principal

    current = tab->pfirst;
    for (int i = 0; i < tam - 1; i++) {
        current->pse = current->ps->pe;
        current = current->pse;
    }
    for (int j = 0; j < tam - 1; ++j) {
        current->pno = current->pn->po;
        current = current->pno;

    }

    //diagonal secundaria
    for (int k = 0; k < tam - 1; ++k) {
        current = current->pe;
    }

    for (int l = 0; l < tam - 1; ++l) {
        current->pso = current->ps->po;
        current = current->pso;
    }
    for (int m = 0; m < tam - 1; ++m) {
        current->pne = current->pn->pe;
        current = current->pne;
    }


}

/**
 * imprime o tabuleiro
 * @param tab
 */
void imprimir_tabuleiro(TAB tab) {
    CEL *aux = tab.pfirst;
    CEL *andarcolunas = tab.pfirst;
    for (int i = 0; i < tab.size; ++i) {
        aux = andarcolunas;
        printf("\n");
        for (int j = 0; j < tab.size; ++j) {
            printf("%d ", aux->info);
            aux = aux->pe;
        }
        andarcolunas = andarcolunas->ps;

    }
}
/**
 * funcao para chegar a uma celula anda para pe e para ps
 * @param line  linha da celula
 * @param col   coluna da celula
 * @param tab   tabuleiro
 * @return
 */
CEL *chegar_celula(int line, int col, TAB *tab) {
    CEL *aux = tab->pfirst;
    if (line != 0) {
        for (int i = 0; i < line; ++i) {
            aux = aux->ps;
        }
    }
    if (col != 0) {
        for (int i = 0; i < col; ++i) {
            aux = aux->pe;
        }
    }
    return aux;
}


/**
 * inicia um tabuleiro random
 * @param n  numero de numeros com que queremos inicializar
 * @param tab  tabuleiro
 */
void init_tab_rand(int n, TAB *tab) {
    int nr = 0, lr = 0, cr = 0, i = 0;

    int size = tab->size;
    time_t t;
    srand((unsigned) time(&t));
    while (i != n) {
        lr = rand() % size;
        cr = rand() % size;
        nr = (1 + rand() % size);
        CEL *aux = chegar_celula(lr, cr, tab);

        if (aux->info == 0) {
            if (checkConsist(*tab, *aux, nr) == 1) {
                aux->info = nr;
                i++;

            }
        }
    }
}
/**
 * funcao que faz a mascara de solucoes para o tabuleiro
 * @param tab -> tabuleiro
 */
void get_mascara(TAB *tab){
    CEL *aux=tab->pfirst;
    CEL *perclinhas=aux;
    for (int i = 0; i < tab->size; ++i) {
        aux=perclinhas;
        for (int j = 0; j < tab->size; ++j) {
            verifica_possibilidades(tab,aux);
            aux=aux->pe;
        }
        perclinhas=perclinhas->ps;
    }
}
/**
 * funcao que verfica todas as solucoes posiveis para uma determinada celula
 * @param tab  tabuleiro
 * @param aux  celula
 */
void verifica_possibilidades(TAB *tab,CEL *aux){
    if(aux->info==0){
        for (int num = 1; num <=tab->size; ++num) {
            if(checkConsist(*tab,*aux,num)){
                if(aux->nsol==0) {
                    aux->psol = (int*)malloc(sizeof(int));
                    *(aux->psol)=num;
                    aux->nsol++;
                }
                else{
                    aux->psol=realloc(aux->psol, sizeof(int)*(aux->nsol+1));
                    *(aux->psol+aux->nsol)=num;
                    aux->nsol++;
                }
            }

        }
    }
}
/**
 * funcao que vai atualizar a mascara de solucoes para uma determinada celula dependendo da sua posicao
 * @param tab -> tabuleiro
 * @param cel ->celula
 */
void atualizar_mascara(TAB *tab, CEL *cel) //atualiza a mascara para linha, coluna, box, e diagonais
{
    int size=tab->size;
    int line=cel->line;
    int col=cel->col;
    if(line==col && line+col ==size-1)//caso seja celula do centro
    {

            atualizar_linha(tab,cel,cel->info);
            atualizar_coluna(tab,cel,cel->info);
            atualizar_principal(tab,cel,cel->info);
            atualizar_secundaria(tab,cel,cel->info);
            atualizar_box(tab,cel,cel->info);

    }
    else
        {
        if(line==col)//caso seja celula da diagonal principal
        {
            atualizar_linha(tab,cel,cel->info);
            atualizar_coluna(tab,cel,cel->info);
            atualizar_principal(tab,cel,cel->info);
            atualizar_box(tab,cel,cel->info);}
        else
        {
            if(line+col==size-1)//caso seja celula da diagonal secundaria
            {
                atualizar_linha(tab,cel,cel->info);
                atualizar_coluna(tab,cel,cel->info);
                atualizar_secundaria(tab,cel,cel->info);
                atualizar_box(tab,cel,cel->info);
            }
            else
            {
                atualizar_linha(tab,cel,cel->info);
                atualizar_coluna(tab,cel,cel->info);
                atualizar_box(tab,cel,cel->info);
            }
        }

    }
}
/**
 * atualiza a mascara para a linha
 * @param tab ->tabuleiro
 * @param cel ->celula
 * @param num ->numero a eliminar
 */
void atualizar_linha(TAB *tab,CEL *cel,int num)
{
    int size=tab->size;
    CEL *linha=chegar_celula(cel->line,0,tab); //primeira celula da linha

    for(int i=0;i<size;i++)
    {
        atualizar_psol(linha,num);
        linha=linha->pe;
    }
}
/**
 * atualiza a mascara para a coluna
 * @param tab ->tabuleiro
 * @param cel ->celula
 * @param num ->numero a eliminar
 */
void atualizar_coluna(TAB *tab,CEL *cel,int num)
{

    int size=tab->size;
    CEL*coluna=chegar_celula(0,cel->col,tab);//primeira coluna
    for(int i=0;i<size;i++)
    {
        atualizar_psol(coluna,num);
        coluna=coluna->ps;
    }
}
/**
 * atualiza a mascara para a diagonal principal
 * @param tab ->tabuleiro
 * @param cel ->celula
 * @param num ->numero a eliminar
 */
void atualizar_principal(TAB *tab, CEL *cel,int num)
{
    CEL* dp=tab->pfirst;
    int size=tab->size;

    for(int i=0;i<size;i++)
    {
        atualizar_psol(dp,num);
        dp=dp->pse;
    }
}
/**
 * atualiza a mascara para a diagonal secundaria
 * @param tab ->tabuleiro
 * @param cel ->celula
 * @param num ->numero a eliminar
 */
void atualizar_secundaria(TAB *tab, CEL *cel,int num)
{
    CEL* ds=chegar_celula(0,(tab->size)-1,tab);
    int size=tab->size;

    for(int i=0;i<size;i++)
    {
        atualizar_psol(ds,num);
        ds=ds->pso;
    }
}
/**
 * atualiza a mascara para a box da celula
 * @param tab ->tabuleiro
 * @param cel ->celula
 * @param num ->numero a eliminar
 */
void atualizar_box(TAB *tab,CEL *cel,int num)
{
    int aux=(int)sqrt(tab->size);
    int li,ci; //linha e coluna iniciais da cel da submatriz
    li=(cel->line)-(cel->line%aux);
    ci=(cel->col)-(cel->col%aux);
    CEL *lines=chegar_celula(li,ci,tab); //primeira celula da box
    CEL *auxcel=NULL;

    for(int i =0;i<aux;i++)
    {
        auxcel=lines;
        for(int j=0;j<aux;j++)
        {
                atualizar_psol(auxcel,num);
                auxcel=auxcel->pe;
        }
        lines=lines->ps;
    }
}
/**
 * atualiza o psol da celula eliminando o numero enviado
 * @param cel celula a ser atualizada
 * @param num  numero que vai ter de eliminar
 */
void atualizar_psol(CEL *cel,int num)
{
    int aux;
    int *psol=cel->psol;
    for(int i=0;i<cel->nsol;i++) //vai percorrer o psol
    {
            if (*(psol + i) == num) //se a posicao de psol for igual ao info da celula
            {
                for (int k = i; k < cel->nsol; k++) {
                    //elimina essa posiçao
                    if (k + 1 == cel->nsol)//se k+1 = numero de solucoes da celula podemos dar free já
                    {
                        free(psol + k);
                        cel->nsol--;
                    } else {
                        aux = *(psol + (k + 1));
                        *(psol + (k + 1)) = *(psol + k);
                        *(psol + k) = aux;
                    }
                }
            }
    }
}
/**
 * funcao auxiliar usada para teste que imprime o tabuleiro
 * @param tab
 */
void print_mascara(TAB *tab){
  int size=tab->size;
  int count=0;
  int aux=0;
  CEL *linha=tab->pfirst;
  CEL *current=linha;

  for(int i=0;i<size;i++) //percorre as linhas
  {
      current=linha;
      for(int j=0;j<size;j++) //percorre colunas
      {
              for (int k = 0; k < current->nsol; k++) //percorre as solucçoes
              {
                  printf("%d", *(current->psol + k));
              }

              aux = size - current->nsol;

              while (aux != 0) {
                  printf(" ");
                  aux = aux - 1;
              }
              printf("|");
              current=current->pe;

      }
      printf("\n");
      linha=linha->ps;
      count++;
  }
}

//tabuleiros do txt
/**
 * funcao que retira os tabuleiros dos txt e passa para os tabuleiros!alocando espaço para os mesmos
 * @return
 */

TABS* get_tabuleiros_from_txt()
{
    int ntabs=0;
    int size=0;
    char c;
    FILE *fp=fopen("C:\\Users\\Ruben Jorge\\Desktop\\hugopj\\lpprog2fi\\tabuleiros","r");
    if(fp==NULL)
    {
        printf("\nErro ao abrir txt!");
        return NULL;
    }
    fscanf(fp,"%*[^:]:%d",&ntabs);
    TABS *tabs=init_tabs(ntabs);
    TAB *tab=tabs->ntabs;

    for(int i=0;i<ntabs;i++)
    {
        fscanf(fp,"%*[^:]:%*[^:]:%d",&size);
        (tab+i)->size=size;
        inicializar_tabuleiro(tab+i);
        CEL *linha=(tab+i)->pfirst;
        CEL *current=linha;
        for(int j=0;j<size;j++)
        {
            current=linha;
            for(int k=0;k<size;k++)
            {
                fscanf(fp,"%d",&current->info);
                current=current->pe;
            }
            linha=linha->ps;
        }
    }
    fclose(fp);
    return tabs;
}