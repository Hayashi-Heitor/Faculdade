#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

//#include "meuconio.h"
#include <conio2.h>

#define TF 100

struct _Aluno {
	char nome[30], RA[30];
};

struct _Disciplina {
	int codDisc;
	char nomeDisc[30];
};

struct _Nota {
	int nota;
	char RA[30];
	int codDisc;
};

//buscas
int BuscaRA(_Aluno aluno[TF], char auxRA[30], int TL) {
	int pos=0;
	
	while(pos < TL && strcmp(aluno[pos].RA, auxRA)!=0)
		pos++;
	
	if(pos == TL)
		return -1;
	else
		return pos;
}

int BuscaCodDisc(_Disciplina disc[TF], int auxCodDisc, int TL) {
	int pos=0;
	
	while(pos < TL && auxCodDisc != disc[pos].codDisc)
		pos++;
		
	if (pos == TL)
		return -1;
	else 
		return pos;
}

int BuscaNota(_Nota nota[TF], char auxRA[30], int auxCodDisc, int TL) {
	int pos=0;
	
	while (pos < TL && strcmp(nota[pos].RA, auxRA)!=0 || nota[pos].codDisc != auxCodDisc)
		pos++;
		
	if (pos == TL)
		return -1;
	else
		return pos;
}


//Base da moldura do menu principal
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
	moldura(30, 3, 80, 25, 15, 0);
	textcolor(15);
	gotoxy(32, 4);
	printf("################ MENU PRINCIPAL ###############");
	gotoxy(39, 8);
	textcolor(14);
	printf("[ ]Cadastro de alunos");
	gotoxy(39, 10);
	textcolor(11);
	printf("[ ]Cadastro de disciplina");
	textcolor(10);
	gotoxy(39, 12);
	printf("[ ]Cadastro de notas");
	gotoxy(39, 14);
	textcolor(12);
	printf("[ ]Encerrar o programa");
}

void LeAluno (_Aluno aluno[TF], int &TL) {
	char auxRA[30];
	system("cls");
	textcolor(14);
	printf("\n##CADASTRO DE ALUNOS##\n");
	printf("\nInsira o RA do aluno: ");
	fflush(stdin);
	gets(auxRA);
	
	while(TL<TF && strcmp(auxRA, "\0")!=0) {
		if (BuscaRA(aluno, auxRA, TL) < 0) {
			strcpy(aluno[TL].RA, auxRA);
			printf("\nInsira o nome do aluno: ");
			fflush(stdin);
			gets(aluno[TL++].nome);
			
			printf("\n## Aluno [%d], %s - cadastrado com sucesso!! ##\n", TL, aluno[TL-1].nome);
		}
		else 
			printf("\nRA ja cadastrado!!\n");
			
		
		if(TL == TF)
			printf("\nCadastro de alunos cheio!!");
		else {
			printf("\nInsira o RA do aluno: ");
			fflush(stdin);
			gets(auxRA);
		}
	}
	printf("\n**CADASTRO FINALIZADO**\n");
	getch();
}

void LeDisciplina (_Disciplina disc[TF], int &TL) {
	int auxCod;
	system("cls");
	textcolor(11);
	printf("\n##CADASTRO DE DISCIPLINAS##\n");
	printf("\nInsira o codigo da disciplina: ");
	scanf("%d",&auxCod);
	while(TL<TF && auxCod > 0) {
		if(BuscaCodDisc(disc, auxCod, TL) < 0) {
			disc[TL].codDisc = auxCod;
			printf("\nInsira o nome da disciplina: ");
			fflush(stdin);
			gets(disc[TL++].nomeDisc);
		}
		else
			printf("\nDisciplina ja cadastrada!!\n");
		
		
		if (TL == TF)
			printf("\nCadastro de disciplinas cheio!!");
		else {
			printf("\nInsira o codigo da disciplina (ou 0 para sair): ");
			scanf("%d",&auxCod);
		}
	}
	printf("\n**CADASTRO FINALIZADO**\n");
	getch();
}

void LeNota(_Nota nota[TF], int &TL) {
	char auxRA[30];
	int auxCodDisc;
	
	system("cls");
	textcolor(10);
	printf("\n##CADASTRO DE NOTAS##\n");
	printf("\nInsira o RA do aluno: ");
	fflush(stdin);
	gets(auxRA);
	while(TL < TF && strcmp(auxRA, "\0")!=0) {
		printf("\nInsira o Codigo da disciplina: ");
		scanf("%d", &auxCodDisc);
		if (BuscaNota(nota, auxRA, auxCodDisc, TL) < 0) {
			strcpy(nota[TL].RA, auxRA);
			nota[TL++].codDisc = auxCodDisc;
		}
		else
			printf("\nJa existe!");
		
		if (TL == TF) 
			printf("\nCadastro de notas cheio!!");
		else {
			printf("\nInsira o RA do aluno: ");
			fflush(stdin);
			gets(auxRA);	
		}
	}
	printf("\n**CADASTRO FINALIZADO**\n");
	getch();
}

//sistema de navegação no menu
int nav (void){
	char op;
	int pos = 14;
	
	do{
		textcolor(0);
		op = toupper(getche());
			if(op == 'W' && pos != 8)
				pos -= 2;
			else if(op == 'S' && pos != 14)
				pos += 2;
			gotoxy(40, pos);

	}while (op != 13);
	
	return pos; //volta o valor de Y
}

void operacao (void){
	_Nota nota[TF];
	_Aluno aluno[TF];
	_Disciplina disc[TF];
	int TLA = 0, TLD = 0, TLN = 0, pos;
	
	do{
		painel_principal();
		pos = nav();
		switch(pos){
			case 8: LeAluno(aluno, TLA); break;
			case 10: LeDisciplina(disc, TLD); break;
			case 12: LeNota(nota, TLN);
		}
	}while(pos != 14);
}

int main (int argc, char** argv){
	
	operacao();
	
	return 0;
}
