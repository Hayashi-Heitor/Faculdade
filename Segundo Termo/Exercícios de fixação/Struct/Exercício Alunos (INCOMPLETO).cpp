#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<ctype.h>
#include<locale.h>

#define TF 50

struct aluno{
	char nome[TF], ra[TF], curso[TF];
};

void menu(){
	system("cls");
	setlocale(LC_ALL, "portuguese");
	textcolor(GREEN);
	printf("\n### MENU ###\n");
	printf("\n[A] - Cadastro de aluno");
	printf("\n[B] - Exibição de aluno");
	printf("\nOpção selecionada: ");
	
	return toupper(getch());
}

void cadastro(&TL, aluno al[TF]){
	char aux[TF];
	
	clrscr();
	setlocale(LC_ALL, "portuguese");
	printf("\n### CADASTRO ###\n");
	if(TL == TF)
		printf("Cadastro cheio!!!");
	else{
		printf("\nInsira 0 para encerrar a inserção!\n");
		printf("\nInforme o nome do[%d] aluno: ", TL+1);
		fflush(stdin);
		gets(aux);
		
		while(TL < TF && strcmp(aux, "\0") != 0){
			strcpy(al[TL].nome, aux);
			printf("\nInforme o ra do aluno: ");
			fflush(stdin); gets(al[TL].ra);
			printf("\nInforme a disciplina do aluno: ";
			fflush(stdin); gets(al[TL].curso);
			printf("\nInforme o nome do[%d] aluno: ", TL+1);
			fflush(stdin); gets(aux);
		}
	}
	getch();
}

void exibe(TL, aluno al[TF]){
	clrscr();
	setlocale(LC_ALL, "portuguese");
	printf("\n### EXIBIÇÃO ###\n");
	
}

int main (void){
	
	return 0;
}
