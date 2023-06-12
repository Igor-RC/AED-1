#include <stdio.h>
#include <stdlib.h>
;//#define TAM_MAX2 101
     // define tamanho igual a 7.

  struct reg {
	 float item; 
	 struct reg *prox; 
  };
// Variável NO tipo reg.
  typedef struct reg NO;

//------------------------------------------------------------------------------------------------
// INICIALIZA TODAS AS FUNÇÕES:

int funcaohash(float, int);           // argumento:  CHAVE (recebe um real).
int buscalista(float, NO **, int);    // argumentos: CHAVE e TABELA (recebe um real e matx struct).
void inicializa(NO **, int);
void insere(float, NO **, int);       // argumentos: item a ser INSERIDO(FLOAT) e TABELA HASH(NO **).
void imprime(NO **, int); 
void libera(NO **, int); 
void apaga(float, NO **, int);        // argumentos: chave a ser apagada e tabela HASH
void inserelista(float, NO **, int);  // argumentos: item a ser inserido e tabela HASH
void percorrelista(int, NO **);  // argumentos: posição da tabela HASH e tabela HASH

//================================================================================================

  int funcaohash(float chave, int M) {
	 return abs(chave) % M;
  }
//---------------------------------------

  int buscalista(float chave, NO **HASH, int M) {
	 int pos = funcaohash(chave, M);
	 NO *lista = HASH[pos];
	 while (lista != NULL) {
		if (chave == lista->item) return 1; // Se encontrou retorna verdadeiro
		lista = lista->prox;
	 }
	 return 0;
  }
//---------------------------------------

  void inicializa(NO **HASH, int TAM_MAX) {
	 int i;
	 for(i=0; i<TAM_MAX; i++)
	  HASH[i]=NULL;		 
  }
//---------------------------------------

  void insere(float item, NO **HASH, int M) { // argumentos: item a ser inserido e tabela HASH
	 int pos = funcaohash(item, M); // CALCULA POSIÇAO
	 if (HASH[pos]!=NULL) { // se ocorreu colisao
	   if (buscalista(item,HASH)) { // verificando se a chave ja existe
	     printf(" *** ATENCAO O item %.2f ja foi cadastrado ***",item);
		   return;
		 }
	 }
	
	 inserelista(item,HASH);
  }
//---------------------------------------

  void inserelista(float item, NO **HASH, int M) {
    int pos = funcaohash(item, M);
    NO **lista = &HASH[pos];
    if (*lista == NULL) {
		  *lista = (NO *) malloc(sizeof(NO));
  		  if (*lista == NULL) {
			   printf("\nErro alocacao memoria!");
			   exit(1);
  		  }
  		(*lista)->item=item;
  		(*lista)->prox=NULL;
  		printf("-> Inserido HASH[%d]",pos);
 	  }
	  else {                        // Se ocorreu colisao
		  printf("-> Colisao  HASH[%d]",pos);
	    NO *guarda= HASH[pos];      // guardando posicao inicial ponteiro
		  while ((*lista)->prox != NULL) 
		                              // Caminha para fim da lista caso contenha mais de 2 itens
			*lista=(*lista)->prox;
		  (*lista)->prox=(NO *) malloc(sizeof(NO));
		  if ((*lista)->prox == NULL) {
			 printf("\nErro alocacao memoria!");
			 exit(1);
  		} 		
		  *lista=(*lista)->prox;
  		(*lista)->item=item;
  		(*lista)->prox=NULL; 	
  		HASH[pos]=guarda;          // retornando ponteiro para a posiçao inicial
	  }
	
  }
//---------------------------------------

  void imprime(NO **HASH, int TAM_MAX) {      // Imprime tabela HASH
	 int i;
	 puts("");
	 for (i=0; i<TAM_MAX; i++) {
		printf("\n%d ->",i);
		percorrelista(i,HASH);
	 }
  }
//---------------------------------------

  void percorrelista(int pos, NO **HASH) { 
   // Percorre lista imprimindo-a
	 NO *lista = HASH[pos];
	 while (lista != NULL) {
		printf(" %.2f ->",lista->item);
		lista = lista->prox;
	 }
	 printf(" \\");
  } 
//---------------------------------------

  void libera(NO **HASH, int TAM_MAX) {
	 int i;
	 NO *proximo;
	 for(i=0; i<TAM_MAX; i++) {
		NO **lista=&HASH[i]; 
		while(*lista!= NULL) { // liberando lista da memoria
  			proximo = (*lista)->prox;                
  			free(*lista);
  			*lista = proximo; 
  		} 
   }
   free(proximo);  	
  }
//---------------------------------------

  void apaga(float chave, NO **HASH, int M) { 
    int pos = funcaohash(chave, M);
    if (!buscalista(chave,HASH)) { // verificando se item pertence a tabela
 	    puts("\nItem nao encontrado");
	    return;
    }
	
    NO **lista = &HASH[pos];
    NO *anterior = *lista;
    NO *proximo = (*lista)->prox;
    NO *guarda = HASH[pos]; // guardando posicao do ponteiro 

    while (*lista!=NULL) { // laço percorre lista		
	   if ((*lista)->item == chave) { // Se encontrou o item		
		  if (*lista == anterior) { // Se o item esta no inicio
        
			 if ((*lista)->prox==NULL) { // Se a lista possui um unico item
				free(*lista);
				HASH[pos]=NULL;
			 }
			 else { 
				(*lista)->prox=proximo->prox;
				(*lista)->item=proximo->item;
				HASH[pos]=guarda;
			 }
		  }
        
		  else { // Se o item NAO esta no inicio
			 anterior->prox=proximo;
			 free(*lista);
			 HASH[pos]=guarda;
		  }
		  return;
 	   } // fim laço encontrou o item		
	   anterior = *lista;
	   *lista = (*lista)->prox;
	   proximo = (*lista)->prox; 		
    } // fim laço percorre lista
	
    HASH[pos]=guarda; // retonando ponteiro para posicao inicial
    free(anterior);
    free(proximo);
    free(guarda);	
  }

//------------------------------------------------------------------------------------------------
// PRINCIPAL:

main() {
  int   i, M, TAM_MAX;
	float item;
  printf("Tabela HASH com tratamento de colisões Lista - M POSIÇÕES");
	printf("\n*********************************************************");
	printf("\nInserindo M elementos ");
  scanf("%d", &M);
  TAM_MAX = M;
	NO *HASH [TAM_MAX];            // criando tabela hash (vetor de ponteiros para lista)(TAM7)
	inicializa(HASH, TAM_MAX);              // inicializando tabela hash na memoria
  funcaohash(item, M);
  
  for (i=0; i<M; i++){
		printf("\nInserindo elemento %d",i+1);
		printf(" - Forneca valor Real (00,0): "); 
		scanf("%f", &item);
		insere(item,HASH);
	} 
	
	imprime(HASH, TAM_MAX);  
	
	while(1) {
		printf("\n\n>> Forneca o item que deseja apagar (-1 SAI): ");
		scanf("%f",&item);
		if (item == -1) break;
		apaga(item,HASH);	
		imprime(HASH, TAM_MAX);
	}  
	
	libera(HASH, TAM_MAX);
	
	puts("\n");
	system("pause");
}

//------------------------------------------------------------------------------------------------
