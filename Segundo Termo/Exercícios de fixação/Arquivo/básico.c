#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct TPaluno{
	char ra[14], nome[30];
	int ano_nasc; 
};

int busca_aluno_ra(FILE *PTRaluno, char chave_ra[14]){ //exaustiva em arquivo
	TPaluno r;
	
	rewind(PTRaluno);
	//fseek(PTRaluno, 0, 0);
	
	fread(&r, sizeof(TPaluno), 1, PTRaluno);
	while(!feof(PTRaluno) && strcmp(chave_ra, r.ra) != 0)
		fread(&r, sizeof(TPaluno), 1, PTRaluno);
	
	if(strcmp(chave_ra, r.ra) == 0)
		return ftell(PTRaluno) - sizeof(TPaluno);
	else
		return -1;
	
}

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

void consultar_aluno(void){
	TPaluno RAluno;
	int pos;
	
	FILE *PTRaluno = fopen("Alunos.dat", "rb");
	clrscr();
	printf("\n## Consultar por R.A ##\n");
	
	if(PTRaluno == NULL)
		printf("\nErro de Abertura");
		
	else{
		printf("\nR.A a Consultar: ");
		fflush(stdin);
		gets(RAluno.ra);
		
		while(strcmp(RAluno.ra, "\0") != 0){
			pos = busca_aluno_ra(PTRaluno, RAluno.ra);
			
			if(pos == -1)
				printf("\nR.A nao cadastrado!\n");
				
			else{
				fseek(PTRaluno, pos, 0);
				fread(&RAluno, sizeof(TPaluno), 1, PTRaluno);
				printf("\n*** Dados Encontrados ***\n");
				printf("R.A: %s\n", RAluno.ra);
				printf("Nome: %s\n", RAluno.nome);
				printf("Ano nasc: %d\n", RAluno.ano_nasc);
			}
			
			printf("\nR.A a Consultar: ");
			fflush(stdin);
			gets(RAluno.ra);
		}
		
		fclose(PTRaluno);
	}
	getche();
}

void alterar_aluno(void){
	TPaluno RAluno;
	int pos;
	
	FILE *PTRaluno = fopen("Alunos.dat", "rb+");
	clrscr();
	printf("\n## Consultar por R.A ##\n");
	
	if(PTRaluno == NULL)
		printf("\nErro de Abertura");
		
	else{
		printf("\nR.A a Alterar: ");
		fflush(stdin);
		gets(RAluno.ra);
		
		while(strcmp(RAluno.ra, "\0") != 0){
			pos = busca_aluno_ra(PTRaluno, RAluno.ra);
			
			if(pos == -1)
				printf("\nR.A nao cadastrado!\n");
				
			else{
				fseek(PTRaluno, pos, 0);
				fread(&RAluno, sizeof(TPaluno), 1, PTRaluno);
				printf("\n*** Dados Encontrados ***\n");
				printf("R.A: %s\n", RAluno.ra);
				printf("Nome: %s\n", RAluno.nome);
				printf("Ano nasc: %d\n", RAluno.ano_nasc);
				
				printf("\nDeseja Alterar (S/N)?");
				if(toupper(getche()) == 'S'){
					printf("\nNovo nome: ");
					fflush(stdin);
					gets(RAluno.nome);
					printf("\nNovo Ano nasc: ");
					scanf("%d", &RAluno.ano_nasc);
					fseek(PTRaluno, pos, 0);
					fwrite(&RAluno, sizeof(TPaluno), 1, PTRaluno);
					printf("\nRegistro Atualizado com sucesso");
				}
			}
			printf("\nR.A a Alterar: ");
			fflush(stdin);
			gets(RAluno.ra);
		}
		fclose(PTRaluno);
	}
	getche();
}

void OrdenarAluno(void) { 
	TPaluno RegA, RegB;
	int QtdeReg;
	FILE *PTRalu = fopen("Alunos.dat", "rb+");
	
	if(PTRalu == NULL)
		printf("\nErro de Abretura!\n");
		
	else {
		fseek(PTRalu, 0, 2);
		QtdeReg = ftell(PTRalu) / sizeof(TPaluno);
		
		for(int i = 0; i < QtdeReg-1; i++)
			for(int j = i+1; j < QtdeReg; j++) {
				
				fseek(PTRalu, i*sizeof(TPaluno), 0);
				fread(&RegA, sizeof(TPaluno), 1, PTRalu);
				
				fseek(PTRalu, j*sizeof(TPaluno), 0);
				fread(&RegB, sizeof(TPaluno), 1, PTRalu);
				
				if(stricmp(RegA.nome, RegB.nome) > 0) { 
					fseek(PTRalu, i*sizeof(TPaluno), 0);
					fwrite(&RegB, sizeof(TPaluno), 1, PTRalu);
					
					fseek(PTRalu, j*sizeof(TPaluno), 0);
					fwrite(&RegA, sizeof(TPaluno), 1, PTRalu);
					
				}
			}
		fclose(PTRalu);
		printf("Ordenacao concluida com sucesso!\nPressione qualquer tecla para continuar... ");
	}
	getche();
	
}

int main (void){
	
	OrdenarAluno();
	exibir_aluno();
	
	return 0;
}
