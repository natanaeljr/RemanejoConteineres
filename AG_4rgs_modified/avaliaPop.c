void avaliaPop(int np, int tp, int pop[][np], int row, int col, int D[][np-1], int loop_gerac){
     
/*------------------------------------------------------------------------------
     int i, j;
     
     if(non==0){
          for(i=0; i<tp; i++){
               pop[i][np-1] = (rand()%900)+100;
          }
     }else{
          for(i=0; i<tp; i++){
               if(((non==1)&&(i==0)) || ((non==2)&&((i==0)||(i==1)))){
               }else{
                   pop[i][np-1] = (rand()%900)+100;
               }
          }
     }
------------------------------------------------------------------------------*/

     int i, j, k, loop_np, loop_tp, soma, lastP, vet_sd[row*col];
     int tamD, total, value, nmov;
     tamD = np-1;//tamanho da matriz de transporte
     lastP = 0;
     total = 0;
     soma = 0;
     value = 0;
     nmov = 0;
     int M[row][col];
     
     //determina a matriz de transporte
     /*srand(300);
     k = 0;
     for(i=0; i<tamD; i++){
          for(j=tamD; j>=0; j--){
               if(j >= k){
                    D[i][j] = rand()%6;
               }else{
                    D[i][j] = 0;
               }
          }
          k++;
     }
     if(loop_gerac == 1){
     printf("\n\nMATRIZ DE TRANSPORTE");
     printMat(np-1, np-1, D);
     }
     //getch();  
     printf("\n");
     
     srand(time(NULL));*/
     
     /*D[0][0] = 2;
     D[0][1] = 5;
     D[0][2] = 0;
     D[0][3] = 0;
     D[1][0] = 0;
     D[1][1] = 2;
     D[1][2] = 3;
     D[1][3] = 1;
     D[2][0] = 0;
     D[2][1] = 0;
     D[2][2] = 2;
     D[2][3] = 2;
     D[3][0] = 0;
     D[3][1] = 0;
     D[3][2] = 0;
     D[3][3] = 1;*/
     
     
     
     //laco
     for(loop_tp = 0; loop_tp<tp; loop_tp++){
                 
          total = 0;
          //zera a matriz de ocupacao
          for(i=0; i<row; i++){
               for(j=0; j<col; j++){
                    M[i][j] = 0;
               }         
          }
          /*printf("\n\nMATRIZ DE OCUPACAO");
          printMat(row, col-40, M);*/
          
          for(loop_np = 0; loop_np<np-1; loop_np++){
               soma = 0;
               value = 0;
               nmov = 0;
               //zera vet_sd
               for(i=0; i<row*col; i++){
            	    vet_sd[i] = 0;
               }
               //---
               //system("PAUSE");
               switch(pop[loop_tp][loop_np]){
                                             
                    case 1://Combinação de regra ONE------------------------------------------------------------------------//
                         //printf("\nCASE 1 -------");
                         //printf("\npop[%i][%i] = %i",loop_tp, loop_np, pop[loop_tp][loop_np]);
                         if(loop_np>0){
                         //funcao de saida 1
                         	  //printf("\nREGRA SAIDA 1");
                              nmov = frs1(np, tamD, col, row, pop, D, M, loop_np, nmov, vet_sd);
                              value = value + nmov;
                              //printf("\nvalue saida = %i", value);
                              //------------
                              //printf("\n\nMATRIZ DE OCUPACAO");
                              //printMat(col, row, M);
                         }
                         //funcao de entrada 1
                         //printf("\nREGRA ENTRADA 1");
                         fre1(np, tamD, col, row, pop, D, M, loop_np, vet_sd);
                         for(i=0; i<tamD; i++){
                              soma = soma + D[loop_np][i];
                         }
                         value = value + soma;
                         //printf("\nvalue total = %i", value);
                         //------------
                         //printf("\n\nMATRIZ DE OCUPACAO");
                         //printMat(col, row, M);
                         //printf("\nFECHA 1 -------");
                         break;
                    
                    //------------------------------------------------------------------------------------------------------      
                    case 2://Combinação de regra TWO------------------------------------------------------------------------//
                         //printf("\nCASE 2 -------");
                         //printf("\npop[%i][%i] = %i",loop_tp, loop_np, pop[loop_tp][loop_np]);
                         //printf("\n\nMATRIZ DE OCUPACAO");
                         //printMat(col, row, M);
                         if(loop_np>0){
                         //funcao de saida 2
                              //printf("\nREGRA SAIDA 1");
                              nmov = frs1(np, tamD, col, row, pop, D, M, loop_np, nmov, vet_sd);
                              value = value + nmov;
                              //printf("\nvalue saida = %i", value);
                              //----------
                              //printf("\n\nMATRIZ DE OCUPACAO");
                              //printMat(col, row, M);
                         }
                         //funcao de entrada 1
                         //printf("\nREGRA ENTRADA 1");
                         fre1(np, tamD, col, row, pop, D, M, loop_np, vet_sd);
                         for(i=0; i<tamD; i++){
                              soma = soma + D[loop_np][i];
                         }
                         value = value + soma;
                         //printf("\nvalue total = %i", value);
                         //----------
                         //printf("\n\nMATRIZ DE OCUPACAO");
                         //printMat(col, row, M);
                         //printf("\nFECHA 2 -------");
                         break;
                    
                    //------------------------------------------------------------------------------------------------------    
                    case 3://Combinação de regra THREE----------------------------------------------------------------------//
                         //printf("\nCASE 3 -------");
                         //printf("\npop[%i][%i] = %i",loop_tp, loop_np, pop[loop_tp][loop_np]);
                         if(loop_np>0){
                         //funcao de saida 1
                              //printf("\nREGRA SAIDA 1");
                              nmov = frs1(np, tamD, col, row, pop, D, M, loop_np, nmov, vet_sd);
                              value = value + nmov;
                              //printf("\nvalue saida = %i", value);
                              //------------
                              //printf("\n\nMATRIZ DE OCUPACAO");
                              //printMat(col, row, M);
                         }
                         //funcao de entrada 2
                         //printf("\nREGRA ENTRADA 2");
                         fre2(np, tamD, col, row, pop, D, M, loop_np, vet_sd);
                         for(i=0; i<tamD; i++){
                              soma = soma + D[loop_np][i];
                         }
                         value = value + soma;
                        // printf("\nvalue total = %i", value);
                         //------------
                         //printf("\n\nMATRIZ DE OCUPACAO");
                         //printMat(col, row, M);
                         //printf("\nFECHA 3 -------");
                         break;
                    
                    //------------------------------------------------------------------------------------------------------ 
                    case 4://Combinação de regra FOUR-----------------------------------------------------------------------//
                         //printf("\nCASE 4 -------");
                         //printf("\npop[%i][%i] = %i",loop_tp, loop_np, pop[loop_tp][loop_np]);
                         //printf("\n\nMATRIZ DE OCUPACAO");
                         //printMat(col, row, M);
                         if(loop_np>0){
                         //funcao de saida 2
                              //printf("\nREGRA SAIDA 1");
                              nmov = frs1(np, tamD, col, row, pop, D, M, loop_np, nmov, vet_sd);
                              value = value + nmov;
                              //printf("\nvalue saida = %i", value);
                              //----------
                              //printf("\n\nMATRIZ DE OCUPACAO");
                              //printMat(col, row, M);
                         }
                         //funcao de entrada 2
                         //printf("\nREGRA ENTRADA 2");
                         fre2(np, tamD, col, row, pop, D, M, loop_np, vet_sd);
                         for(i=0; i<tamD; i++){
                              soma = soma + D[loop_np][i];
                         }
                         value = value + soma;
                         //printf("\nvalue total = %i", value);
                         //----------
                         //printf("\n\nMATRIZ DE OCUPACAO");
                         //printMat(col, row, M);
                         //printf("\nFECHA 2 -------");
                         break;
               }
               total = total + value;
          }
          //contabiliza o ultimo porto
          for(i=0; i<tamD; i++){
               lastP = lastP + D[i][tamD-1];
          }
          total = total + lastP;
          pop[loop_tp][np-1] = total;
          //printf("\ntotal linha %i = %i\n", loop_tp, pop[loop_tp][np-1]);
          lastP = 0;
          
          
     }
     
     
     
}
