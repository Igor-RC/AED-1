#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// EXEMPLO:
// 2
// CBA
// DDD
//----------------------------------------------------------------------------

main(){
  int   l, i, M, N, soma;
  int P[100][50];
  char **C;
  'a'=0,  'b'=1, 'c'=2, 'd'=3, 'e'= , 'f'= , 'g'= , 'h'= , 'i'= , 'j'= , 'k'= , 'l'= , 'm'= , 'n'= , 'o'= , 'p'= , 'q'= , 'r'= , 's'= , 't'= , 'u'= , 'v'= , 'w'= , 'x'= , 'y'= , 'z'= ;
  
  
  scanf("%d", &M);
  C = malloc(sizeof(char*)*M);

  for(i=0; i<M; i++){
    C[i]=malloc(sizeof(char)*50);

    printf("%u", (unsigned)strlen(C[i]));
  }
  
  P[M][N];
  soma = 0;

  for(l=0; l<M; i++){
    for(i=0; i<N; i++){
      P[l][i] = P[l][i] + l + i;   // 'C' no elemento M posição N
       soma = soma + P[l][i];
    }


    
  }
  
  printf("%d\n", &soma);

}
