%------------------------------------------------%
% Funcao responsavel por gerar aleatoriamente as %
% matrizes de Demanda.                           %
%------------------------------------------------%
% GERAR MATRIZES EMPREGANDO O CRITERIO PARA GERAR%
% MATRIZES DE CURTA DISTANCIA.                   %
%------------------------------------------------%
%--------------------------------%
% Parametros de entrada:         %
%--------------------------------%
% nr - numero de linhas.
% nc - numero de colunas.
% np - numero de portos. 
%--------------------------------%
%--------------------------------%
% Parametros de saida:           %
%--------------------------------%
% D - matriz de demandas. 
%--------------------------------%
function [D]=geraDSn(nr,nc,np)

  % Matriz D inicial, supoem que nenhum elemento ainda 
  % foi gerado, indicando para isto que todos os elementos
  % recebem o valor -1.
  D=-ones(np,np);
  
  % Numero de elementos percorridos para a matriz D.
  nelem = 0;
  ntotal = nr*nc;
  
  % Controle do la�o para percorrer os elementos de D.
  control = 1;
  
  k=1;
  % La�o que percorre do elemento mais a esquerda 
  % e mais acima ate o ultimo elemento da matriz D.
  % Este tipo de percurso ao longo da matriz D beneficia
  % a gera��o de elementos proximos a diagonal e, 
  % portanto, problemas nos quais a carga percorre 
  % pequenas distancias.
  while ((k<=(np-1))&&(control)) 
    i=1;  
    while ((i<=(np-k))&&(control))
      % Calculando o indice j a partir de i.
      j = i + k;
      % Preenchendo aleatoriamente o elemento D(indi,indj),
      % mas respeitando as restricoes de factibilidade.
      % Respeitar capacidade maxima do navio no porto i.
      [carga] = verifCargaT(i,j,D,np);
      % Calculando espaco vazio do navio no porto i.
      if (carga <= 0)
        carga = ntotal;
      else
        carga = max(ntotal-carga,0);
      end
      kmin = carga; 
      % Se nao existir mais cargas a serem alocadas,
      % entao, terminar a varredura que completa D. 
      if (kmin == 0)
        control = 0;
      end       
      % Gerar numero aleatorio dentro do intervalo !
      D(i,j) = round(rand*kmin);
      i=i+1;
    end    
    k=k+1;
  end            
  
  % Modificar os elementos que n�o foram alterados de -1 para 0.
  for i=1:np
    for j=1:np
      if (D(i,j) == -1)
        D(i,j) = 0;
      end
    end
  end 
  
  % Chamando funcao para realizar a gravacao de matriz D
  % gerada em um arquivo. Caracteristicas importantes a 
  % serem gravadas:
  %-----------------------------------------------------%
  % GENERAL DESCRIPTION OF INSTANCE FILE.               %
  %-----------------------------------------------------%
  % // Number of Rows
  % [NR] 
  % 6, 8, 10  
  % // Number of Columns
  % [NC]
  % 50 to 170
  % // Number of Ports
  % [NP]
  % 10, 15, 20, 25, 30
  % // Demand Matriz Type
  % [DT]
  % 1 - Mixed, 2 - Long Distance, 3 - Short Distance 
  % // Demand Matriz Information
  % [DI]
  % 0 10 15 ... 30
  % 0  0 20 ... 13
  % |  |  \  -   |  
  % 0  0  0 ... 25
  %
  % // The name of the file is generated by a combination
  % // of the information for each instance. For example:
  % // stowage06050101 mean:
  %            |  | ||
  %            |  | ||
  %            |  | |v
  %            |  | vMixed Matrix
  %            |  v 10 ports
  %            v  50 columns 
  %            6 rows
  %-----------------------------------------------------%
  %                                                     %
  %-----------------------------------------------------%
  %gravarD(nr,nc,np,3,D);