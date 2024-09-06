#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<ctype.h>
#include<string.h>

#define TF 20

struct TPagenda{
	char nome[30], endereco[30], fone[30];
};

char menu (void){
	
	setlocale(LC_ALL, "portuguese");
	system("cls");
	printf("\n### AGENDA ###\n");
	printf("\n[A] - Cadastrar");
	printf("\n[B] - Exibir");
	printf("\n[C] - Ordenar");
	printf("\n[D] - Consultar");
	printf("\n[E] - Excluir");
	printf("\n[F] - Alterar");
	printf("\n[ESC] - Sair\n");
	printf("\nOpção desejada: ");
	
	return toupper(getch());
}



void cad_agenda (TPagenda tab_ag[TF], int &TL){
	char aux_nome[30];
	
	system("cls"); 
	printf("\n### CADASTRO DE PESSOAS ###\n");
	printf("\nNome: ");
	fflush(stdin);
	gets(aux_nome);
	
	while(TL < TF && strcmp(aux_nome, "\0") != 0){
		strcpy(tab_ag[TL].nome, aux_nome);
		printf("\nEndereço: ");
		fflush(stdin);
		gets(tab_ag[TL].endereco);
		printf("\nTelefone: ");
		fflush(stdin);
		gets(tab_ag[TL++].fone);
		printf("\n\nNome: ");
		fflush(stdin);
		gets(aux_nome);
	}
}

void rel_agenda (TPagenda tab_ag[TF], int qtd){
	int i;
	system("cls");
	printf("\n### RELATÓRIO AGENDA ###\n");
	if(qtd == 0)
		printf("Agenda vazia");
	else{
		printf("\n-----------------------------------------------------\n");
		printf("|Nome |\t\t| Endereço |\t\t| Telefone|\n");
		printf("-----------------------------------------------------\n");
		for( i = 0; i < qtd; i++)
			printf("%s \t\t  %s \t\t  %s\n", tab_ag[i].nome, tab_ag[i].endereco, tab_ag[i].fone);
	}
	getch();
}

void ordenar (TPagenda tab_ag[TF], int TL){
	TPagenda reg;
	int i, j;
	if(TL == 0)
		printf("\nNão há dados)
	else{
		for(i = 0; i < TL-1; i++)
			for(j = 0; j<TL; j++)
				if(stricmp(tab_ag[i].nome, tab_ag[j].nome) > 0){
					reg = tab_ag[i];
					tab_ag[i] = tab_ag[j];
					tab[j] = reg;
				}
		printf("\nAgenda ordenada\n");
	}
	getch();
}

void executar(void){
	TPagenda ag[TF];
	char op;
	int TLAG = 0;
	do{
		op = menu();
		switch(op){
			case 'A': cad_agenda(ag, TLAG);
				break;
			case 'B': rel_agenda(ag, TLAG);
				break;
			case 'C': 
		}
	}while(menu() != 27);
}

int main (void){
	executar();
	return 0;
}
