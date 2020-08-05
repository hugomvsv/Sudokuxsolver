# Sudokuxsolver
Sudoku X Solver with diferent strategies

Definições do problema:

Pretende-se desenvolver um programa, organizado em funções, que implemente uma variante do
jogo/passatempo tradicional Sudoku. Os tabuleiros iniciais são fornecidos por via de leitura de
ficheiros ou gerada de diversas formas (e.g., aleatoriamente, recorrendo a heurísticas ou de acordo com
algoritmos específicos). Dado um tabuleiro pretende-se encontrar uma solução do jogo Sudoku.

O Sudoku é um jogo de quebra-cabeças cujo objetivo é preencher uma grelha de 9x9 com números de
modo que em cada linha, coluna e secção 3x3 contenha todos os dígitos entre 1 e 9.
Os tabuleiros iniciais fornecidos contêm já alguns quadrados preenchidos. O objetivo é usar lógica e
aritmética para preencher os dígitos que faltam de modo a completar o tabuleiro.

Regras:

● Não pode existir repetições de números nas linhas.

● Não pode existir repetições de números nas colunas.

● Não pode existir repetições de números nos sub-Tabuleiros.

Pretende-se desenvolver um programa que determine soluções para uma variante do jogo tradicional
Sudoku, o SudokuX. Às regras tradicionais acrescem as duas seguintes:

● Não pode existir repetições de números na diagonal principal.

● Não pode existir repetições de números na diagonal secundária

![alt text](https://i.imgur.com/JNvPJHL.png)

Requesitos:

Devem ser utilizados apontadores e estruturas ligadas para organizar os
dados referentes aos tabuleiros do SudokuX. A figura seguinte exemplifica um tabuleiro 4x4
em que cada quadrado representa uma célula da matriz de estruturas. Cada célula deve conter
os apontadores necessários para a resolução do problema.

![alt text](https://i.imgur.com/H5Dvn96.png)

● Permitir a construção e inicialização de um ou mais tabuleiros.
i) Leitura dos tabuleiros a partir de um ficheiro de texto;

● Permitir guardar os tabuleiros previamente carregados;

i) Deve usar uma estrutura de dados do tipo “fila”.

● Permitir resolver tabuleiros 9x9 (Sudoku X); 16x16 (Sudoku X), 25x25 (Sudoku),
36x36 (Sudoku).

● Permitir resolver o problema com abordagens brute-force, encontrando as
soluções possíveis para os tabuleiros;

● Melhorar o algoritmo desenvolvido, utilizando estruturas ligadas implementando estratégias que melhorem a eficiência na pesquisa de uma solução
possível :

i) Hidden Singles

ii) Naked Pairs/Triples

iii) Pointing Pairs

iv) Box/Line Reduction

● Permitir gerar um ficheiro de texto com os tabuleiros de números;

● Permitir gerar um ficheiro binário com todos os tabuleiros de números resolvidos;
