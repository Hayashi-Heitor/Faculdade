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
	
	FILE *PTRaluno = fopen("Alunos.dat", "ab"); //'wb' cria toda vez, 'ab' abbend
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

void exibir_aluno(void){
	TPaluno r;
	
	FILE *PTRaluno = fopen("Alunos.dat","rb"); // 'rb' ou 'rb+' tem que existir!
	clrscr();
	printf("\n### Contudo do Arquivo Alunos.dat ###\n");
	
	if(PTRaluno == NULL) // confere se o ponteiro está apontando para nada
		printf("\nErro de abertura\n");
		
	else{
		fread(&r, sizeof(TPaluno), 1, PTRaluno);
		while(!feof(PTRaluno)){
			printf("\n-------------------\nRA: %s\n\nNome: %s\n\nAno nasc: %d\n-------------------\n", r.ra, r.nome, r.ano_nasc);
			fread(&r, sizeof(TPaluno), 1, PTRaluno);
		}
		
		fclose(PTRaluno);
		printf("\n--- Fim do Arquivo ---\n");
		
	}
	getche();
}

int main (void){
	
	gravar_aluno();
	exibir_aluno();
	return 0;
}
