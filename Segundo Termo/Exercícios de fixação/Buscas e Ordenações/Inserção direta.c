#include<stdio.h>

#define TF 20

int BuscaBinaria(int TL, int vet[TF], int chave){
	int inicio = 0, fim = TL-1, meio = TL/2;
	
	while(inicio < fim && chave != vet[meio]){
		if(chave > vet[meio])
			inicio = meio+1;
		else
			fim = meio-1;
			
		meio = (inicio+fim) / 2;
	}
	if(chave == vet[meio])
		return meio;
	else
		return -1;
}

void InsercaoDireta(int TL, int vet[TF]){
	int aux;
	
	if(BuscaBinaria(TL, vet, vet[TL-1]) > 0 && TL > 2)
		printf("Valor ja presente no vetor\n");
		
	else{
		while(TL-1 > 0 && vet[TL-1] < vet[TL-2]){
			aux = vet[TL-1];
			vet[TL-1] = vet[TL-2];
			vet[TL-2] = aux;
			TL--;
		}
	}
}

int main (void){
	int vet[TF], TL=0;
	
	for(int i = 0; i < TF; i++){
		vet[i] = TF-i; TL++;
		InsercaoDireta(TL, vet);
	}
	
	
	for(int i = 0; i < TF; i++)
		printf("%d\n", vet[i]);
	
	return 0;
}
