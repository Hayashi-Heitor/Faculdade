#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

int recebe (void){
	int fatorial;
	setlocale(LC_ALL, "portuguese");
	printf("Informe o número para o cálculo fatorial: ");
	scanf("%d", &fatorial);
	
	return fatorial;
}

int calcula (int fatorial){
	int total=fatorial;
		
	if(fatorial == 0)
		total += 1;
			
	else{
		for(int x=fatorial-1; x>= 1; x--)
			total *= x;
	}
	
	return total;
	
}

void exibe (int resultado){
	setlocale(LC_ALL, "portuguese");
	printf("\nO resultado do faltorial é: %d", resultado);
	getch();
}

int main (void){
	
	exibe(calcula(recebe()));
	
	return 0;
}
