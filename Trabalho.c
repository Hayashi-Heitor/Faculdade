#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "meuconio.h"

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

void painel_principal(void){
	clrscr();
	moldura(30, 3, 80, 25, 15, 0);
	textcolor(15);
	gotoxy(49, 4);
	printf("### MENU ###");
	gotoxy(25, 10);
	printf("[A] - TEste");
}

int main (void){
	
	painel_principal();
	
	getch();
	return 0;
}
