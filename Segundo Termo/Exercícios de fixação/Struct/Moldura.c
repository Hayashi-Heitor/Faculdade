#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<windows.h>

void moldura(int ci, int li, int cf, int lf,int cor_tex,int cor_fun){
	textcolor(cor_tex);
	textbackground(cor_fun);
	gotoxy(ci, li); printf("%c", 201);
	gotoxy(cf, li); printf("%c", 187);
	gotoxy(ci, lf); printf("%c", 200);
	gotoxy(cf, lf); printf("%c", 188);
	
	for(int i = ci+1; i < cf; i++){
		gotoxy(i,li); printf("%c", 205);
		Sleep(5);
		gotoxy(i,lf); printf("%c", 205);
	}
	for(int i = li+1; i < lf; i++){
		gotoxy(ci,i); printf("%c", 186);
		Sleep(5);
		gotoxy(cf,i); printf("%c", 186);
	}
	textcolor(7);
	textbackground(0);
}

void painel_principal(void){
	clrscr();
	moldura(1, 1, 80, 25, 15, 1);
	moldura(2, 2, 79, 4, 14, 2);
	textcolor(15);
	gotoxy(28, 3);
	printf("Titulo do Programa");
}

int main (void){
	
	painel_principal();
	printf("\n");
	return 0;
}
