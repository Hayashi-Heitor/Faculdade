#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<ctype.h>
#include<string.h>
#include<locale.h>

void tabela_ascii (void){

	clrscr();
	textbackground(WHITE); // 0 até 7
	textcolor(14); //0 - preto, 15 - preto, quanto menor o número mais escuro a cor
	textcolor(RED); //Também se pode escrever por atribuição
	for(int i = 0; i < 256; i++)
		printf("\n%d - %c - %o - %x", i, i, i, i);
}

int main (void){
	
	tabela_ascii();
	
	return 0;
}
