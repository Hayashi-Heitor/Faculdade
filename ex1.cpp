#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int le_numero(void){
	int decimal;
	printf("\nValor Decimal: ");
	scanf("%d", &decimal);
	
	return decimal;
}

void exibe_numero(int valor){
	printf("\nResultado: %d\n", valor);
	getch();
}

int converte_binario(int decimal){
	int multi = 1, resul = 0, valor_binario;
	
	while(decimal > 1){
		resul += decimal % 2 * multi;
		decimal = decimal/2;
		multi = multi * 10;
	}
	
	resul += decimal * multi;
	
	return resul;
}

int main (void){
	int valor_dec, valor_binario, decimal;
	
	decimal = le_numero();
	valor_binario = converte_binario(decimal);
	exibe_numero(valor_binario);
	
	return 0;
}
