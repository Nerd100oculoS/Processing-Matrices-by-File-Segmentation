<h1 align = "center">Processing Matrices by File Segmentation</h1>

* [Introdução](#introduction)

<div id="introduction">
  
  <h2>Introdução</h2>
  
  <p align="justify">
  O intuito deste trabalho é implementar um sistema de multiplicação de matrizes baseando-se em uma estratégia de segmentação em arquivo. Um arquivo M grande - <i>original_matriz.txt</i> - é fornecido no formato NxN com valores inteiros como entrada. Este, é processado a partir de várias coordenadas introduzidas por um segundo arquivo, <i>coordinates.txt</i>. Neste arquivo é descrito por linha, uma dupla de 'i' e 'j' correspondendo a posição inicial e final a serem lidas. Por exemplo, as posições 2,4,6,10 indica que a leitura em M deve iniciar na linha 2 coluna 4 e seguir até a linha 6 coluna 10 - Gerando assim um quadrante.<br> 
  Feito a leitura da composição no arquivo M para um tipo matriz de inteiros C, a segunda etapa, consistiu em produzir a transposta de M = Mt. Feito isso, será feita a multiplicação de "C" com "M" e o resultado, armzenado como valor das duplas de i's e j's em uma Tabela Hash, sendo as duplas do quandrante, a chave. Assim, para cada novo cálculo, antes o programa consulta a Tabela Hash para identificar se a multiplicação já foi realizada. Em caso afirmativo, é retornado que a chave já se encontra armazenada, caso contrário, é feito o processamento do quandrante desejado.
      </p>
  
</div>

