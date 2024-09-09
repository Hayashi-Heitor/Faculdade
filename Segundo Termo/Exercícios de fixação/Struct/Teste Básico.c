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

int busca_nome(TPagenda ag[TF], int TL, char nome[30]){
	int pos = 0;
	
	while(pos < TL && stricmp(nome, ag[pos].nome) != 0)
		pos++;
	
	if(pos < TL)
		return pos;
	else
		return -1;
}

void cad_agenda (TPagenda tab_ag[TF], int &TL){
	char aux_nome[30];
	
	setlocale(LC_ALL, "portuguese");
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
	setlocale(LC_ALL, "portuguese");
	
	if(TL == 0)
		printf("\nNão há dados");
	else{
		for(i = 0; i < TL-1; i++)
			for(j = 0; j<TL; j++)
				if(stricmp(tab_ag[i].nome, tab_ag[j].nome) > 0){
					reg = tab_ag[i];
					tab_ag[i] = tab_ag[j];
					tab_ag[j] = reg;
				}
		printf("\nAgenda ordenada\n");
	}
	getch();
}

void consulta(TPagenda tab_ag[TF],int TL){
	int pos;
	char aux_nome[30];
	
	setlocale(LC_ALL, "portuguese");
	system("cls");
	printf("\n### CONSULTA POR NOME ###\n");
	printf("\nInforme o nome: ");
	fflush(stdin);
	gets(aux_nome);
	
	while(strcmp(aux_nome, "\0") != 0){
		pos = busca_nome(tab_ag, TL, aux_nome);
		if(pos == -1)
			printf("O nome não foi encontrado!");
		else{
			system("cls");
			printf("\nDados da pessoa:\n");
			printf("\nNome: %s", tab_ag[pos].nome);
			printf("\nEndereço: %s", tab_ag[pos].endereco);
			printf("\nTelefone: %s\n", tab_ag[pos].fone);
			getch();
			system("cls");
			printf("\nNome a consultar: ");
			fflush(stdin);
			gets(aux_nome);
		}
	}
		getch();
}

void excluir(TPagenda ag[30],int &TL){
	char aux_nome[30];
	int pos;
	
	system("cls");
	setlocale(LC_ALL, "portuguese");
	printf("\n### EXCLUSÃO ###\n");
	printf("\nInforme o valor a ser excluido: ");
	fflush(stdin);
	gets(aux_nome);
	
	while(strcmp(aux_nome, "\0") != 0){
		pos = busca_nome(ag, TL, aux_nome);
		if(pos == -1)
			printf("Nome não encontrado!!\n");
		else{
			for(; pos < TL-1; pos++){
				ag[pos] = ag[pos+1];
			}
			TL--;
			printf("Exclusão efetuada com sucesso!");
			printf("\nInforme o valor a ser excluido: ");
			fflush(stdin);
			gets(aux_nome);
		}
		getch();
	}
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
			case 'C': ordenar(ag, TLAG);
				break;
			case 'D': consulta(ag, TLAG);
				break;
			case 'E': excluir(ag, TLAG);
		}
	}while(menu() != 27);
}

int main (void){
	executar();
	return 0;
}
