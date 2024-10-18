#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>

struct TPaluno{
	char ra[14], nome[30];
	int ano_nasc; 
};

void gravar_aluno(void){
	TPaluno reg;
	
	FILE *PTRaluno = fopen("Alunos.dat", "wb"); //wb cria toda vez
	printf("\n## Cadastro de Alunos ##\n");
	printf("\nR.A: ");
	fflush(stdin);
	gets(reg.ra);
	
	while(strcmp(reg.ra,"\0") != 0){
		
		printf("\nNome do aluno: ");
		fflush(stdin);
		gets(reg.nome);
		printf("\nAno de Nasc: ");
		scanf("%d", &reg.ano_nasc);
		
		fwrite(&reg, sizeof(TPaluno), 1, PTRaluno); //sizeof, tem a função de pegar os bytes: reg ou TPaluno, geralmente tipo pois geralmente não é modificado
		
		printf("\nR.A: ");
		fflush(stdin);
		gets(reg.ra);
	}
	
	fclose(PTRaluno);
}

int main (void){
	
	gravar_aluno();
	return 0;
}
