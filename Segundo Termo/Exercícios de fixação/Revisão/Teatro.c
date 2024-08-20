#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define linha 20
#define coluna 15

int main(void){
	
	char op=0;
	int lugar[linha][coluna], l, c, contL, contO;
	
	for(l=0; l<linha; l++)
		for(c=0; c<coluna; c++)
			lugar[l][c] = 0;
	do{
		system("cls");
		printf("\n### M E N U ###\n");
		printf("A - Reservar Poltronas\n");
		printf("B - Exibir Poltronas\n");
		printf("C - Exibir Numero de Poltronas Livres/Ocupadas\n");
		printf("D - Verificar Situacao de Poltrona\n");
		printf("E - Reiniciar Mapa\n");
		printf("ESC - Encerrar Programa\n");
		printf("Opcao Desejada: ");
		
		
		switch(op){
			
			case 'A':
				while (op == 'A'){
					system("cls"); 
					printf("### Reserva de Poltronas ###\n");
					printf("Digite a linha da Poltrona: ");
					scanf("%d", &l);
					printf("\nDigite a Coluna da Poltrona: ");
					scanf("%d", &c);
					lugar[l-1][c-1] = 1;
					printf("\nLocal Reservado com Sucesso\n");
					printf("Pressione [A] para reservar outra poltrona\n");
					printf("ou pressione qualquer outra tecla para voltar ao menu: ");
					op = toupper(getch());
			}
				break;
				
			case 'B':
				system("cls");
				printf("### Exibicao de Poltronas ###\n");
				for(l=0; l<linha; l++){
					printf("\n");
					for(c=0; c<coluna; c++)
						printf(" %d ", lugar[l][c]);
				}
				printf("\nPressione qualquer tecla para voltar ao menu: ");
				getch();
				break;
				
			case 'C':
				contL = 0; contO = 0;
				system("cls");
				printf("### Numero de Poltronas ###\n");
				for(l=0; l<linha; l++)
					for(c=0; c<coluna; c++){
						if (lugar[l][c] == 0)
							contL ++;
						else
							contO ++; 
					}
				printf("Poltronas Livres: %d\n", contL);
				printf("Poltronas Ocupadas: %d\n", contO);
				printf("Pressione qualquer tecla para voltar ao menu: ");
				getch();
				break;
			
			case 'D':
				system("cls");
				printf("### Consulta de Poltrona ###\n");
				printf("Digite a linha da poltrona: ");
				scanf("%d", &l);
				printf("\nDigite a coluna da poltrona: ");
				scanf("%d", &c);
				if (lugar[l-1][c-1] == 1)
					printf("A poltrona da linha %d coluna %d se encontra ocupada\n", l, c);
				else
					printf("A poltrona da linha %d coluna %d se encontra vazia\n", l, c);
				printf("Pressione qualquer tecla para retornar ao menu: ");
				getch();
				break;
				
			case 'E':
				system("cls");
				printf("### Redefinicao de Poltrona ###\n");
				for(l=0; l<linha; l++)
					for(c=0; c<coluna; c++)
						lugar[l][c] = 0;
				printf("Redefinicao concluida com sucesso!\n");
				printf("Pressione qualquer tecla para retornar ao menu\n");
				getch();
		}
	} while (op != 27);
	
	return 0;
}
