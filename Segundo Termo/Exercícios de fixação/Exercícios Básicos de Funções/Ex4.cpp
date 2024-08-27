#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <locale.h>

int recebe (void){
	int h1, h2, m1, m2, s1, s2, resul;
	setlocale(LC_ALL, "portuguese");
	printf("\n ### Insira o horário inicial ### \n");
	scanf("%d %d %d", &h1, &m1, &s1);
	printf("\n ### Insira o horário final ### \n");
	scanf("%d %d %d", &h2, &m2, &s2);
	
	resul = h2 - h1;
	m2 += resul * 24;
	resul = m2 - m1;
	s2 = resul * 60;
	resul = s2 - s1;
	
	return resul;
}

void exibe (int resul){
	system("cls");
	setlocale(LC_ALL, "portuguese");
	printf("A diferença em segundos é: %d", resul);
}

int main (void){
	exibe(recebe());
	
	return 0;
}
