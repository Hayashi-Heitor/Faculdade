#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio2.h>
#include<locale.h>
#include<ctype.h>

#define TFL 30
#define TFA 15
#define TF 50

struct TPbiblioteca{
	char livro[TFL], autor[TFA];
	int ano;
	float preco;
};

char menu(){
	setlocale(LC_ALL, "portuguese");
	clrscr();
	textcolor(10);
	printf("\n### MENU ###\n");
	printf("\n[A] - Cadastro de livro");
	printf("\n[B] - Exibir livros");
	printf("\n[C] - Consultar livro por título");
	printf("\n[ESC] - Encerrar");
	printf("\nOpção desejada: ");
	
	return toupper(getch());
}

void cadastra(int &TL, TPbiblioteca bib[TF]){
	char aux[TFL];
	
	clrscr();
	printf("\n### CADASTRO ###\n");
	if(TL == TF)
		printf("\nCadastro cheio!!!");
	else{
		textcolor(5);
		printf("\nPressione apenas ENTER para encerrar a inserção");
		fflush(stdin);
		printf("\nInforme o Livro[%d]: ", TL+1);
		gets(aux);
		
		while(TL < TF && strcmp(aux, "\0") != 0){
			strcpy(bib[TL].livro, aux);
			printf("\nInforme o autor: ");
			fflush(stdin);
			gets(bib[TL].autor);
			printf("\nInforme o ano: ");
			scanf("%d", &bib[TL].ano);
			printf("\nInforme o preço: ");
			scanf("%f", &bib[TL++].preco);
			printf("\nInforme o Livro[%d]: ", TL+1);
			fflush(stdin);
			gets(aux);
		}
	}
	getch();
}

void exibe(int &TL, TPbiblioteca lib[TF]){
	clrscr();
	textcolor(11);
	setlocale(LC_ALL, "portuguese");
	printf("\n### EXIBIÇÃO ###\n");
	if(TL == 0)
		printf("\nSem dados!!!");
	else
		for(int i = 0; i < TL; i++){
			printf("\n-------------------------------------\n");
			printf("\nLivro[%d]: %s \t Autor: %s",i+1, lib[i].livro, lib[i].autor);
			printf("\nAno: %d \t Preço: %.2fR$", lib[i].ano, lib[i].preco);	
		}
	getch();
}

void busca(int TL, TPbiblioteca lib[TF]){
	char aux[TFL];
	int pos;
	
	clrscr();
	textcolor(13);
	setlocale(LC_ALL, "portuguese");
	printf("\n### BUSCA POR LIVRO ###\n");
	if(TL == 0)
		printf("Sem livros cadastrados\n");
	else{
		printf("Informe o nome do livro: ");
		fflush(stdin);
		gets(aux);
		pos = 0;
		while(pos < TL && stricmp(aux, lib[pos].livro) != 0)
			pos++;
		if(pos == TL)
			printf("Livro não encontrado!");
		else{
			printf("\nLivro[%d]: %s \t Autor: %s",pos+1, lib[pos].livro, lib[pos].autor);
			printf("\nAno: %d \t Preço: %.2fR$", lib[pos].ano, lib[pos].preco);	
		}
	}
	getch();
}

void executar(){
	TPbiblioteca lib[TF];
	int TL=0;
	char op;
	
	do{
		op = menu();
		switch (op){
			case 'A': cadastra(TL, lib);
			break;
			case 'B': exibe(TL, lib);
			break;
			case 'C': busca(TL, lib);
		}
		
	}while(menu() != 27);
	
}

int main (void){
	
	executar();
	
	return 0;
}
