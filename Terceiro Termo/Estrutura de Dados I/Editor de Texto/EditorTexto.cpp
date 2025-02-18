#include <conio2.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <windows.h>

#define TF 70

//Tamanhos Físicos relacionados a interface
#define LARGURA_TELA_TEXTO 70
#define ALTURA_TELA_TEXTO 25

#define LARGURA_TELA_OPCOES 70
#define ALTURA_TELA_OPCOES 3

struct TpReg {
	
	int Codigo;
	char Nome[TF];
	float Valor;
	
};

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

void LeTextoFORM(char NomeArquivo[TF]) {
	FILE *PtrTxt = fopen(NomeArquivo, "a");
	TpReg R;
	 
	clrscr();
	printf("Nome do Arquivo: %s\n", NomeArquivo);
	printf("Digite o CODIGO e pressione ZERO NO CODIGO para finalizar\n");
	scanf("%d", &R.Codigo);
	
	while(R.Codigo > 0) {
		
		printf("Nome: ");
		fflush(stdin);
		gets(R.Nome);
		printf("Valor: R$ ");
		scanf("%f", &R.Valor);
		fprintf(PtrTxt, "%d \t %s \t %.2f\n", R.Codigo, R.Nome, R.Valor);
		
		printf("Digite o CODIGO e pressione ZERO NO CODIGO para finalizar\n");
		scanf("%d", &R.Codigo);
		
	}
	
	fclose(PtrTxt);
	
}

void ExibeTextoFORM(char NomeArquivo[TF]) {
	FILE *PtrTxt = fopen(NomeArquivo, "r");
	TpReg Reg;
	float Total;
	
	clrscr();
	printf("Nome do Arquivo: %s\n", NomeArquivo);
	fscanf(PtrTxt, "%d %s %f", &Reg.Codigo, &Reg.Nome, &Reg.Valor);
	
	while(!feof(PtrTxt)) {
		
		Total += Reg.Valor;
		printf("%d \t %s \t %.2f\n", Reg.Codigo, Reg.Nome, Reg.Valor);	
		fscanf(PtrTxt, "%d %s %f", &Reg.Codigo, &Reg.Nome, &Reg.Valor);
		
	}	
	printf("\n\nTOTAL: %.2f R$", Total);
	getche();
	
	fclose(PtrTxt);
	
}

//Interface

void Moldura(int ColunaInicial, int LinhaInicial, int ColunaFinal, int LinhaFinal,int CorLinha,int CorFundo){
	
	textcolor(CorLinha);
	textbackground(CorFundo);
	gotoxy(ColunaInicial, LinhaInicial); printf("%c", 201);
	gotoxy(ColunaFinal, LinhaInicial); printf("%c", 187);
	gotoxy(ColunaInicial, LinhaFinal); printf("%c", 200);
	gotoxy(ColunaFinal, LinhaFinal); printf("%c", 188);
	
	for(int i = ColunaInicial+1; i < ColunaFinal; i++){
		gotoxy(i,LinhaInicial); printf("%c", 205);
		gotoxy(i,LinhaFinal); printf("%c", 205);
	}
	for(int i = LinhaInicial+1; i < LinhaFinal; i++){
		gotoxy(ColunaInicial,i); printf("%c", 186);
		gotoxy(ColunaFinal,i); printf("%c", 186);
	}
	textcolor(7);
	textbackground(0);
	
}

void DesenhaInterface(void) {
	
	system("cls");
	Moldura(5, 1, LARGURA_TELA_OPCOES, ALTURA_TELA_OPCOES, WHITE, 0);
	gotoxy(8, 2); printf("SALVAR ARQUIVO");
	gotoxy(30, 2); printf("RETORNAR AO MENU");
	gotoxy(LARGURA_TELA_TEXTO/2 - 9, 6);
	printf("---EDITOR DE TEXTO---");
	Moldura(5, 7, LARGURA_TELA_TEXTO, ALTURA_TELA_TEXTO, WHITE, 0);
	
}

void NavegaMenu(void) {
	int OpcaoSelecionada;
	
	if(OpcaoSelecionada == 1) {
		
	}
	
	if(OpcaoSelecionada == 2) {
		
	}
	
}

int main (void) {
	char Arquivo[TF];
	
	setlocale(LC_ALL, "portuguese");
	LerNome(Arquivo);
	VerificaArquivo(Arquivo);
	/*LeTextoStr(Arquivo);
	ExibeTextoStr(Arquivo);
	DesenhaInterface();
	LeTextoFORM(Arquivo);*/
	ExibeTextoFORM(Arquivo);

	return 0;
	
}
