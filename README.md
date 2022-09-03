<h1 align = "center">Processing Matrices by File Segmentation</h1>

<h2>Súmario</h2>

* [Introdução](#introduction)
* [Desenvolvimento](#Desenvolvimento)
  * [Exemplo de Impressão](#example)
* [Compilar e Executar](#compile)

<div id="introduction">
  
  <h2>Introdução</h2>
  
  <p align="justify">
  O intuito deste trabalho é implementar um sistema de multiplicação de matrizes baseando-se em uma estratégia de segmentação em arquivo. Um arquivo M grande - <i>original_matriz.txt</i> - é fornecido no formato NxN (1000linhas x 1000colunas) com valores inteiros como entrada. Este, é processado a partir de várias coordenadas introduzidas por um segundo arquivo, <i>coordinates.txt</i>. Neste arquivo é descrito por linha, uma dupla de 'i' e 'j' correspondendo a posição inicial e final a serem lidas. Por exemplo, as posições 2,4,6,10 indica que a leitura em M deve iniciar na linha 2 coluna 4 e seguir até a linha 6 coluna 10 - Gerando assim um quadrante.<br> 
  Feito a leitura da composição no arquivo M para um tipo matriz de inteiros C, a segunda etapa, consistiu em produzir a transposta de M = Mt. Feito isso, será feita a multiplicação de "C" com "M" e o resultado, armzenado como valor das duplas de i's e j's em uma Tabela Hash, sendo as duplas do quandrante, a chave. Assim, para cada novo cálculo, antes o programa consulta a Tabela Hash para identificar se a multiplicação já foi realizada. Em caso afirmativo, é retornado que a chave já se encontra armazenada, caso contrário, é feito o processamento do quandrante desejado.
      </p>
</div>

<div id="Desenvolvimento">
  
   <h2>Desenvolvimento</h2>
     
<p align="justify"> 
     A implementação para resolver este problema se baaseia em 4 etapas. A primeira consiste em ler o arquivo de coordendas, tokeniza-lo e armazenar cada dupla de i's e j's correspondente a um quadrante em um array onde cada posição correposde a um quadrante. Como definido na imagem 1 abaixo.
</p>
  
  ![Captura de Tela 2022-09-02 às 19 18 09](https://user-images.githubusercontent.com/103065659/188248532-74c34458-c04c-4d72-81cf-cb1bf05b66cd.png)<br>
  Imagem 1 - Coordinates.txt.<br><br>
  
<p align="justify">
 
 Para testes, basta que o usuário entre no arquivo de coordenadas e acrescente as coordenadas desejadas conforme a formatação por vírgula e não deixe linhas vazias ao salvar. Além disso, ainda na etapa 1 dentro de cada posição do array, é salvo a chave em formato string "x1,j1 x2,j2".<br>
  A segunda etapa, pega o array de coordendas de quadrantes e verifica se as chaves já estão presentes na Tabela Hash. Se a chave não estiver no mapa, é feito então a tokenização do quadrante, a conversão para números inteiro e assim o armazenamento em uma matriz temporária do tipo inteiro.<br>
  A terceira etapa, pega a matriz temporária que etá com o quadrante já no formato de inteiro e faz as operações para encontrar a matriz transposta e então salva a transposta desta matriz em uma matriz auxiliar. Depois faz-se a multipliação da matriz temporária com a sua transposta e armazena o resultado em uma outra matriz auxiliar chamada de <i>"result_final"</i>.<br>
  Por fim, a quarta etapa, armazena <i>"result_final"</i> em uma Tabela Hash com a sua respectiva chave correspondente ao quadrante que deu origem ao resultado final.
 
 </p>
  
  <div id="example">
  
  <h3> Exemplo de Impressão </h4>
</p align="justify">
A baixo a um exemplo de compilação, execução e impressão dos resultados obtidos a partir das coordenadas de quadrante inseridas e após as 4 etapas.
</p><br>

https://user-images.githubusercontent.com/103065659/188249595-f883688c-174d-48bc-bafc-c81e30393f4e.mov
<p align="center">
Vídeo 1 - Exemplo de funcionamento.
</p>

  </div>
</div>

<h2 id="compile"> Compilar e Executar</h2>

Utilize os comandos conforme suas funcões para compilar e executar

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

Em caso de primeira compilação e execução, use o código abaixo:

````
make clean && make && make run
````

