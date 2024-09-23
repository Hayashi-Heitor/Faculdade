#include <conio2.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>
//#include "meuconio.h"

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
	gotoxy(40, 8);
	textcolor(14);
	printf(" Teste");
	gotoxy(40, 10);
	textcolor(11);
	printf(" Teste");
	textcolor(10);
	gotoxy(40, 12);
	printf(" Teste");
	gotoxy(40, 14);
	textcolor(12);
	printf(" Encerrar o programa");
}

//sistema de navegação no menu
int nav (void){
	char op;
	int pos = 14;
	
	do{
		textcolor(0);
		op = toupper(getche());
		if(pos <= 14 && pos >= 8){
			if(op == 'W')
				pos -= 2;
			else if(op == 'S')
				pos += 2;
			gotoxy(40, pos);
			if(op == 13)
				return pos;
		}
		else{
			if(pos >= 14)
				gotoxy(40, --pos);
			if(pos <= 8)
				gotoxy(40, ++pos);
		}
	}while (op != 27);
}


int main (void){
	
	painel_principal();
	nav();
	
	return 0;
}
