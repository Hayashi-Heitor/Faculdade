#include<stdio.h>

#define TF 10

void ordenacao_por_bolha(int TL, int vetor[TF]){
	int aux;
	
	while(TL > 1){
		for(int a = 0; a < TL-1; a++)
			if(vetor[a] > vetor[a+1]){
				aux = vetor[a];
				vetor[a] = vetor[a+1];
				vetor[a+1] = aux;
			}
		TL--;
	}
}

void ordenacao_direta(int TL, int vetor[TF]){
	int maior, maiorpos, aux, a;
	
	while(TL > 1){
		maior = vetor[0];
		posmaior = 0;
		for(a = 0; a < TL; a++)
			if(vetor[a] > maior){
				maior = metor[a];
				posmaior = a;
			}
	}
		
}

int main (void){
	int vetor[TF], TL=0;
	
	for(int i = 0; i < TF; i++){
		vetor[i] = TF - i;
		TL++;
	}
	//ordenacao_por_bolha(TL, vetor);
	ordenacao_direta(TL, vetor);
	
	for(int i = 0; i < TF; i++)
		printf("%d\n", vetor[i]);
	
	return 0;
}
