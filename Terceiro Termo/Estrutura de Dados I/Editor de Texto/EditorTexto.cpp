#include <conio2.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <windows.h>

#define TF 70

void VerificaArquivo(char NomeArquivo[TF]) {
	FILE *PtrArq = fopen(NomeArquivo, "r");
	
	if(PtrArq == NULL) {
		
		printf("\n--Arquivo não existe--\nDeseja cria-lo? (S) (N)");
		if(toupper(getche()) == 'S') {
			
			PtrArq = fopen(NomeArquivo, "w");
			fclose(PtrArq);
			printf("\n--Arquivo texto criado com sucesso--");
			
		}
		
	}
	
	else {
		printf("\n--Arquivo existente--\n");
		fclose(PtrArq);
	}
		
}

void LerNome(char ArqNome[TF]) {
	
	printf("\nDigite o nome ou caminho do arquivo: ");
	fflush(stdin);
	gets(ArqNome);
	
}

void LeTextoChr(char NomeArquivo[TF]) {
	FILE *PtrTxt = fopen(NomeArquivo, "a");
	char Caracter;
	
	clrscr();
	printf("Nome do Arquivo: %s\n", NomeArquivo);
	printf("Digite um texto e pressione [ESC] para finalizar\n");
	Caracter = getche();
	
	while(Caracter != 27) {
		
		if(Caracter == 13) {
			fputc('\n', PtrTxt);
			printf("\n");
		}
			
		else
			fputc(Caracter, PtrTxt);
			
		Caracter = getche();
	}
	
	fclose(PtrTxt);
	
}

void ExibeTextoChr(char NomeArquivo[TF]) {
	FILE *PtrTxt = fopen(NomeArquivo, "r");
	char Caracter;
	
	clrscr();
	printf("Nome do Arquivo: %s\n", NomeArquivo);
	Caracter = fgetc(PtrTxt);
	
	while(!feof(PtrTxt)) {

		printf("%c", Caracter);	
		Caracter = fgetc(PtrTxt);
		
	}
	getche();
	
	fclose(PtrTxt);
	
}

void LeTextoStr(char NomeArquivo[TF]) {
	FILE *PtrTxt = fopen(NomeArquivo, "a");
	char Linha[TF];
	
	clrscr();
	printf("Nome do Arquivo: %s\n", NomeArquivo);
	printf("Digite um texto e pressione [ENTER] em uma linha vazia para finalizar\n");
	fflush(stdin);
	gets(Linha);
	
	while(strcmp(Linha,"\0") != 0) {
		
		fputs(Linha, PtrTxt);
		fputs("\n", PtrTxt);
		
		fflush(stdin);
		gets(Linha);
		
	}
	
	fclose(PtrTxt);
	
}

void ExibeTextoStr(char NomeArquivo[TF]) {
	FILE *PtrTxt = fopen(NomeArquivo, "r");
	char Caracter;
	
	clrscr();
	printf("Nome do Arquivo: %s\n", NomeArquivo);
	Caracter = fgetc(PtrTxt);
	
	while(!feof(PtrTxt)) {

		printf("%c", Caracter);	
		Caracter = fgetc(PtrTxt);
		
	}
	getche();
	
	fclose(PtrTxt);
	
}

int main (void) {
	char Arquivo[TF];
	
	setlocale(LC_ALL, "portuguese");
	LerNome(Arquivo);
	VerificaArquivo(Arquivo);
	LeTextoStr(Arquivo);
	ExibeTextoStr(Arquivo);
	
	return 0;
	
}
