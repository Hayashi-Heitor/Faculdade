#include<stdio.h>

#define TF 20

void InsercaoDireta(int TL, int vet[TF]){
	int aux;
	TL--;
	while(TL > 0 && vet[TL] < vet[TL-1]){
		aux = vet[TL];
		vet[TL] = vet[TL-1];
		vet[TL-1] = aux;
		TL--;
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
