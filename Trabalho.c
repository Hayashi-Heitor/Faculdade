#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <string.h>

//#include "meuconio.h"

#define TF 100

struct _Aluno {
	char ra[10];
	char nome[30];
};

struct _Disc {
	int cod;
	char nome[30];
};

struct _Nota {
	char ra[10];
	int cod;
	float nota;
};

//busca, cadastro, exclusão e alteração de alunos

int BuscaAluno(_Aluno aluno[], char auxRa[10], int TL) {
	int pos=0;
	
	while(pos<TL && strcmp(aluno[pos].ra, auxRa)!=0)
		pos++;
		
	if(pos==TL)
		return -1;
	else
		return pos;
}

void CadastroAluno(_Aluno aluno[], int &TL) {
	char auxRa[30];
	
	system("cls");
	textcolor(14);
	printf("\n### CADASTRO DE ALUNOS ###\n");
	printf("\nInsira o RA do aluno: ");
	fflush(stdin);
	gets(auxRa);
	
	while(TL<TF && strcmp(auxRa, "\0")!=0) {
		if (BuscaAluno(aluno, auxRa, TL) < 0) {
			strcpy(aluno[TL].ra, auxRa);
			printf("\nInsira o nome do aluno: ");
			fflush(stdin);
			gets(aluno[TL].nome);
			
			printf("\n Aluno: %s CADASTRADO COM SUCESSO!\n", aluno[TL++].nome);
			getch();
		}
		else {
			printf("\n*** ALUNO JA CADASTRADO ***\n");
			getch();
		}
		
		system("cls");
		printf("\nInsira o RA do aluno: ");
		fflush(stdin);
		gets(auxRa);
	}
	
	printf("\n### CADASTRO FINALIZADO ###\n");
	getch();
}

//busca, cadastro, exclusão e alteração de disciplinas

int BuscaDisciplina(_Disc disc[], int auxCodDisc, int TL) {
	int pos = 0;
	
	while (pos<TL && disc[pos].cod != auxCodDisc)
		pos++;
	
	if (pos == TL)
		return -1;
	else
		return pos;
}

void CadastroDisciplina(_Disc disc[], int &TL) {
	int auxCodDisc;
	
	system("cls");
	textcolor(14);
	printf("\n### CADASTRO DE DISCIPLINAS ###\n");
	printf("\nInsira o codigo da disciplina ou 0 para sair: ");
	scanf("%d", &auxCodDisc);
	
	while (TL<TF && auxCodDisc != 0) {
		if (BuscaDisciplina(disc, auxCodDisc, TL) < 0) {
			disc[TL].cod = auxCodDisc;
			printf("\nInsira o nome da disciplina: ");
			fflush(stdin);
			gets(disc[TL].nome);
			
			printf("\nDisciplina %s cadastrada com sucesso!\n", disc[TL++].nome);
			getch();
		}
		else {
			printf("\n*** DISCIPLINA JA CADASTRADA ***\n");
			getch();
		}
		
		system("cls");
		printf("\nInsira o codigo da disciplina ou 0 para sair: ");
		scanf("%d", &auxCodDisc);
	}
	
	printf("\n### CADASTRO FINALIZADO ###\n");
	getch();
}

//busca, cadastro, exclusão e alteração de notas

int BuscaNota(_Nota nota[], char auxRa[10], int auxCodDisc, int TL) {
	int pos=0;
	
	while (pos<TL && (strcmp(nota[pos].ra, auxRa)!=0 || nota[pos].cod != auxCodDisc))
		pos++;
		
	if(pos == TL)
		return -1;
	else
		return pos;
}

void CadastroNota(_Nota nota[], _Aluno aluno[], _Disc disc[], int TLA, int TLD, int &TL) {
	int auxCodDisc, posAluno, posDisc;
	char auxRa[10];
	
	system("cls");
	textcolor(14);
	printf("\n### CADASTRO DE NOTAS ###\n");
	printf("\nInsira o RA do aluno: ");
	fflush(stdin);
	gets(auxRa);
	
	while (TL<TF && strcmp(auxRa, "\0")!=0) {
		posAluno = BuscaAluno(aluno, auxRa, TLA);
		
		if (posAluno >= 0) {
			printf("\nInsira o codigo da disciplina: ");
			scanf("%d", &auxCodDisc);
			posDisc = BuscaDisciplina(disc, auxCodDisc, TLD);
			
			if(posDisc >= 0) {
				if (BuscaNota(nota, auxRa, auxCodDisc, TL) < 0) {
					strcpy(nota[TL].ra, auxRa);
					nota[TL].cod = auxCodDisc;
					printf("\nInsira a nota do aluno: ");
					scanf("%f", &nota[TL].nota);
					
					printf("\nAluno: %s\t Disciplina: %s\t Nota: %.2f\n", aluno[posAluno].nome, disc[posDisc].nome, nota[TL++].nota);
					getch();
				}
				else {
					printf("\n*** NOTA JA CADASTRADA ***");
					getch();
				}
			}
			else {
				printf("\n*** CODIGO DA DISCIPLINA NAO ECONTRADO ***");
				getch();
			}
		}
		else {
			printf("\n*** RA NAO ENCONTRADO ***\n");
			getch();
		}
		
		system("cls");
		printf("\nInsira o RA do aluno: ");
		fflush(stdin);
		gets(auxRa);
	}
	
	printf("\n### CADASTRO FINALIZADO ###\n");
	getch();
}

void moldura(int ci, int li, int cf, int lf,int cor_tex,int cor_fun){
	textcolor(cor_tex);
	textbackground(cor_fun);
	gotoxy(ci, li); printf("%c", 201);
	gotoxy(cf, li); printf("%c", 187);
	gotoxy(ci, lf); printf("%c", 200);
	gotoxy(cf, lf); printf("%c", 188);
	
	for(int i = ci+1; i < cf; i++){
		gotoxy(i,li); printf("%c", 205);
		gotoxy(i,lf); printf("%c", 205);
	}
	for(int i = li+1; i < lf; i++){
		gotoxy(ci,i); printf("%c", 186);
		gotoxy(cf,i); printf("%c", 186);
	}
	textcolor(7);
	textbackground(0);
}

//painel montado do menu principal
void painel_principal(void){
	clrscr();
	moldura(30, 3, 80, 25, 0, 15);
	moldura(31, 4, 79, 6, 15, 0);
	moldura(47, 9, 61, 11, 14, 0);
	moldura(47, 18, 61, 20, 12, 0);
	textcolor(15);
	gotoxy(49, 5); printf("MENU PRINCIPAL");
	gotoxy(48, 10); textcolor(14); printf("[ ]CADASTROS");
	gotoxy(48, 13); textcolor(11); printf("[ ]teste");
	gotoxy(48, 16); textcolor(10); printf("[ ]teste");
	gotoxy(48, 19); textcolor(12); printf("[ ]ENCERRAR");
}

void painel_cadastro(void){
	system("cls");
	moldura(30, 3, 80, 25, 0, 14);
	moldura(31, 4, 79, 6, 14, 0);
	moldura(47, 9, 61, 11, 14, 0);
	moldura(47, 12, 61, 14, 14, 0);
	moldura(47, 15, 61, 17, 14, 0);
	moldura(47, 18, 61, 20, 15, 0);
	textcolor(14);
	gotoxy(49, 5); printf("MENU CADASTRO");
	gotoxy(48, 10); textcolor(14); printf("[ ]ALUNO");
	gotoxy(48, 13); printf("[ ]DISCIPLINA");
	gotoxy(48, 16); printf("[ ]NOTA");
	gotoxy(48, 19); textcolor(15); printf("[ ]VOLTAR");
}

int nav (void){
	char op;
	int pos = 19;
	
	do{
		textcolor(0);
		op = toupper(getche());
			if(op == 'W' && pos != 10)
				pos -= 3;
			else if(op == 'S' && pos != 19)
				pos += 3;
			gotoxy(49, pos);

	}while (op != 13);
	
	return pos; //volta o valor de Y
}

int nav_cad (void){
	char op;
	int pos = 19;
	
	do{
		textcolor(0);
		op = toupper(getche());
			if(op == 'W' && pos != 10)
				pos -= 3;
			else if(op == 'S' && pos != 19)
				pos += 3;
			gotoxy(49, pos);

	}while (op != 13);
	
	return pos; //volta o valor de Y
}

void operacao (void){
	_Aluno aluno[TF];
	_Disc disc[TF];
	_Nota nota[TF];
	int TLA=0, TLD=0, TLN=0, pos, pos_cad;
	
	do{
		painel_principal();
		pos = nav();
		switch(pos){
			case 10: 
				do{
					painel_cadastro();
					pos_cad = nav_cad();
					switch (pos_cad){
						case 10: CadastroAluno(aluno, TLA);
							break;
						case 13: CadastroDisciplina(disc, TLD);
							break;
						case 16: CadastroNota(nota, aluno, disc, TLA, TLD, TLN);
				}
				}while(pos_cad != 19);
			break;
			case 13: CadastroDisciplina(disc, TLD); break;
			case 16: CadastroNota(nota, aluno, disc, TLA, TLD, TLN);
		}
	}while(pos != 19);
	system("cls");
	textcolor(15);
}



int main(int argc, char** argv) {
	
	operacao();
	
	return 0;
}
