#include <stdio.h>
//Suas férias estão finalmente prestes a começar! Para aproveitar o máximo seu merecido descanso, você decidiu viajar de Curytyba para Riacho de Fevereiro, uma grande cidade turística do país. Existem N cidades no país, numeradas de 1 a N. Curytyba é a cidade C, enquanto Riacho de Fevereiro é a cidade R. Além disso, exitem também M rotas disponíveis. Cada rota liga duas cidades A e B, pode ser utilizada para ir de A para B ou vice-versa, e leva exatamente uma hora para ser realizada.

//Tudo estaria bem para sua viagem se não fosse por um detalhe: o prefeito da cidade de Estadunido (cidade E), o sr. Donaldo Trumpe, em um decreto polêmico, proibiu todo cidadão de Curytyba de entrar em sua cidade! Por isso, você deve ir para Riacho de Fevereiro sem passar por Estadunido. Sua tarefa é determinar o menor número de horas necessárias para ir de Curytyba para Riacho de Fevereiro, sem passar por Estadunido.

//Entrada
//A entrada contém vários casos de teste. A primeira linha de cada caso contém dois inteiros N e M (3 ≤ N ≤ 1000, 1 ≤ M ≤ N(N-1)/2), o número de cidades e de rotas no país, respectivamente. As próximas M linhas descrevem uma rota cada. Cada linha contém dois inteiros A e B (1 ≤ A, B ≤ N, A≠B), indicando uma rota entre as cidades A e B. A última linha contém três inteiros C, R e E (1 ≤ C,R,E ≤ N, C≠R≠E), indicando qual cidade é Curytyba, Riacho de Fevereiro e Estatunido, respectivamente.

//Nenhuma rota aparece mais de uma vez na entrada. É garantido que é possível ir da cidade C para a cidade R sem passar pela cidade E, utilizando as rotas dadas na entrada.

//A entrada termina com fim-de-arquivo (EOF).

//Saída
//Para cada caso de teste, imprima uma linha contendo o número mínimo de horas necessárias para ir da cidade C para a cidade R, sem passar pela cidade E.

int main(void) {
  int N, M, A, B;
  scanf("&d" "&d", N, M);
  while(3 <= N && N <= 1000){
    if(1 <= M && M <= (N*(N-1)/2)){
      printf("%d e %d\n", N, M);
      if(1 <= A && B <= N && A!=B){}
        
    }
    else break;
  }
    
}
