%----------------------------------------------------------%
% Funcao responsavel por gerar instancias com as seguintes % 
% caracteristicas:                                         %
%----------------------------------------------------------%
%----------------------------------------------------------%
% GENERAL DESCRIPTION OF INSTANCE FILE.                    %
%----------------------------------------------------------%
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
%----------------------------------------------------------%
%                                                          %
%----------------------------------------------------------%
function geraMaster

  % Vetores com os parametros a serem empregados na geracao
  % de instancias tal como descrito acima.
  vnr = [4 8 10];
  vnc = [4:10:170];
  vnp = [5:5:30];
  vdt = [1:3];
  total = length(vnr)*length(vnc)*length(vnp)*length(vdt);
  
  % La�os para a gera��o de instancias.
  vclock = clock;
  sdir = sprintf('Instances%s-%02d%02d%02.0f',date,vclock(4),vclock(5),vclock(6));
  % Criando diretorio.
  mkdir(sdir);
  
  % Variavel para contar o numero de arquivos criados 
  % e atualizar a barra de espera.
  cont = 0;
  
  % Barra de espera.
  h = waitbar(0,'Please wait...','Name','Creating Stowage Files');
  
  % Construindo as instancias com varios lacos.
  % Laco do numero de linhas.
  for i=1:length(vnr)
    % La�o do numero de colunas.  
    for j=1:length(vnc)
      % La�o do numero de portos  
      for k=1:length(vnp)
        % La�o do numero de tipos de matriz.  
        for t=1:length(vdt)  
            
          % Contando o n�mero de arquivos gerados.
          cont = cont + 1;
          
          % Gerar "Mixed Matrix".
          if (1 == vdt(t))
            [D]=geraD1(vnr(i),vnc(j),vnp(k));  
          end    
          % Gerar "Long Distance Matrix".    
          if (2 == vdt(t))
            [D]=geraD2(vnr(i),vnc(j),vnp(k));  
          end    
          % Gerar "Short Distance Matrix".    
          if (3 == vdt(t))   
            [D]=geraD3(vnr(i),vnc(j),vnp(k));  
          end
          
          %-----------------------------------------------------%
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
          % Chamando funcao de gravacao de dados.
          %gravarD(nr,nc,np,1,D);
          gravarD(vnr(i),vnc(j),vnp(k),vdt(t),D,sdir);

          % Atualizando a barra de espera.
          waitbar(cont/total,h)
        end
      end
    end
  end  
  
  % Fechar a barra de espera apos encerrar o processo de geracao
  % aleatorio de arquivos de dados.
  close(h);
