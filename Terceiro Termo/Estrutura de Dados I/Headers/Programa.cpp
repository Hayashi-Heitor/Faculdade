#include <stdio.h>
#include <string.h>
#include <conio2.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

#include "TADpopulacao.h"

char Menu() {
	clrscr();
	printf("\n### M E N U ###\n");
	printf("[A] Cadastrar Cidades\n");
	printf("[B] Consultar Cidades pelo Nome\n");
	printf("[C] Ordenar Cidades pelo Nome\n");
	printf("[D] Ordenar Cidades pela População\n");
	printf("[ESC] Finalizar\n");
	printf("\nOpção Desejada: ");
	return toupper(getch());
}

void Executar() {
	char opcao;
	
	do {
		opcao = Menu();
		switch (opcao) {
			
			case 'A':
				clrscr();
				Cadastrar();
				break;
			
			case'B':
				clrscr();
				Consultar();
				break;
				
			case'C':
				clrscr();
				Ordenar();		
		}
		
	}while(opcao != 27);
}



int main() {
	
	setlocale(LC_ALL, "portuguese");
	Executar();
	
	return 0;
}
