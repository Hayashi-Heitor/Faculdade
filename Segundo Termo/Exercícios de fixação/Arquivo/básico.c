#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct TpAluno
{
	char RA[14], Nome[40];
	int AnoNasc, Status;
};

int BuscaAlunoRA(FILE *PtrAluno, char ChaveRA[14])
{
	TpAluno R;
	//fseek(PtrAluno,0,0);
	rewind(PtrAluno);
	fread(&R,sizeof(TpAluno),1,PtrAluno);
	//while (!feof(PtrAluno) && (strcmp(ChaveRA,R.RA)!=0 || R.Status!=1))	
	//while (!feof(PtrAluno) && !(strcmp(ChaveRA,R.RA)==0 && R.Status==1))
	int achou=0;
	
	while (!feof(PtrAluno) && !achou)
	{
		if (strcmp(ChaveRA,R.RA)==0 && R.Status==1)
			achou=1;
		else
			fread(&R,sizeof(TpAluno),1,PtrAluno);
	}
	
	if (strcmp(ChaveRA,R.RA)==0 && R.Status)
		return ftell(PtrAluno)-sizeof(TpAluno);
	else
		return -1;
}

void GravarAluno(void)
{
	TpAluno Reg;
	FILE *PtrAlu = fopen("AlunosLOG.dat","ab+");
	printf("\n## Cadastro de Alunos ##\n");
	printf("R.A.: ");
	fflush(stdin);
	gets(Reg.RA);
	while (strcmp(Reg.RA,"\0")!=0)
	{
		if (BuscaAlunoRA(PtrAlu,Reg.RA) == -1) //Não achou
		{
			printf("Nome do Aluno: ");
			fflush(stdin);
			gets(Reg.Nome);
			printf("Ano de Nasc.:" );
			scanf("%d",&Reg.AnoNasc);
			Reg.Status = 1;
			fwrite(&Reg,sizeof(TpAluno),1,PtrAlu);
			printf("\nDados Cadastrados!\n");
		}
		else
			printf("\nR.A. ja Cadastrado!\n");
			
		getch();
		printf("\nR.A.: ");
		fflush(stdin);
		gets(Reg.RA);
	}
	fclose(PtrAlu);
}

void ExibirAluno(void)
{
	TpAluno R;
	FILE *PtrAlu = fopen("AlunosLOG.dat","rb");
	clrscr();
	printf("\n### Conteudo do Arquivo AlunosLOG.dat###\n");
	if (PtrAlu == NULL)
		printf("\nErro de Abertura!\n");
	else
		{
			fread(&R,sizeof(TpAluno),1,PtrAlu);
			while (!feof(PtrAlu))
			{
				if (R.Status)  //Registro ativo
				{
					printf("\nRA: %s",R.RA);
					printf("\nNome: %s",R.Nome);
					printf("\nAno Nasc.: %d\n",R.AnoNasc);
				}
				fread(&R,sizeof(TpAluno),1,PtrAlu);
			}
			fclose(PtrAlu);
			printf("\n----Fim do Arquivo----\n");
		}	
	getch();
}

void ConsultarAluno(void)
{
	TpAluno RAluno;
	int pos;
	FILE *PtrAlu = fopen("AlunosLOG.dat","rb");
	clrscr();
	printf("\n## Consultar por R.A. ##\n");
	if (PtrAlu == NULL)
		printf("\nErro de Abertura!\n");
	else
		{
			printf("\nR.A. a Consultar: ");
			fflush(stdin);
			gets(RAluno.RA);
			while(strcmp(RAluno.RA,"\0")!=0)
			{
				pos = BuscaAlunoRA(PtrAlu,RAluno.RA);
				if (pos == -1)
					printf("\nR.A. Nao Cadastrado!\n");
				else
					{
						printf("\n*** Dados Encontrados ***\n");
						fseek(PtrAlu,pos,0);
						fread(&RAluno,sizeof(TpAluno),1,PtrAlu);
						printf("R.A.: %s\n",RAluno.RA);
						printf("Nome: %s\n",RAluno.Nome);
						printf("Ano Nasc.: %d\n",RAluno.AnoNasc);
					}
					
				getch();
				printf("\nR.A. a Consultar: ");
				fflush(stdin);
				gets(RAluno.RA);
			}	
			fclose(PtrAlu);
		}
	
	getch();
}

void AlterarAluno(void)
{
	TpAluno RAluno;
	int pos;
	FILE *PtrAlu = fopen("AlunosLOG.dat","rb+");
	clrscr();
	printf("\n## Alterar por R.A. ##\n");
	if (PtrAlu == NULL)
		printf("\nErro de Abertura!\n");
	else
		{
			printf("\nR.A. a Alterar: ");
			fflush(stdin);
			gets(RAluno.RA);
			while(strcmp(RAluno.RA,"\0")!=0)
			{
				pos = BuscaAlunoRA(PtrAlu,RAluno.RA);
				if (pos == -1)
					printf("\nR.A. Nao Cadastrado!\n");
				else
					{
						printf("\n*** Dados Encontrados ***\n");
						fseek(PtrAlu,pos,0);
						fread(&RAluno,sizeof(TpAluno),1,PtrAlu);
						printf("R.A.: %s\n",RAluno.RA);
						printf("Nome: %s\n",RAluno.Nome);
						printf("Ano Nasc.: %d\n",RAluno.AnoNasc);
						
						printf("\nDeseja Alterar (S/N)?");
						if (toupper(getche())=='S')
						{
							printf("Novo Nome: ");
							fflush(stdin);
							gets(RAluno.Nome);
							printf("Novo Ano Nasc.: ");
							scanf("%d",&RAluno.AnoNasc);
							fseek(PtrAlu,pos,0);
							fwrite(&RAluno,sizeof(TpAluno),1,PtrAlu);	
							printf("\nRegistro Atualizado!\n");
						}
					}
					
				getch();
				printf("\nR.A. a Consultar: ");
				fflush(stdin);
				gets(RAluno.RA);
			}	
			fclose(PtrAlu);
		}
	
	getch();
}

void OrdenarAluno(void)
{
	TpAluno RegA, RegB;
	int QtdeReg, a, b;
	FILE *PtrAlu = fopen("AlunosLOG.dat","rb+");
	if (PtrAlu==NULL)
		printf("\nErro de Abertura!\n");
	else
		{
			fseek(PtrAlu,0,2);
			QtdeReg = ftell(PtrAlu)/sizeof(TpAluno);
			for(a=0; a<QtdeReg-1; a++)
				for(b=a+1; b<QtdeReg; b++)
				{
					fseek(PtrAlu,a*sizeof(TpAluno),0);
					fread(&RegA,sizeof(TpAluno),1,PtrAlu);
					
					fseek(PtrAlu,b*sizeof(TpAluno),0);
					fread(&RegB,sizeof(TpAluno),1,PtrAlu);
					if (stricmp(RegA.Nome,RegB.Nome)>0)
					{
						fseek(PtrAlu,a*sizeof(TpAluno),0);
						fwrite(&RegB,sizeof(TpAluno),1,PtrAlu);
						
						fseek(PtrAlu,b*sizeof(TpAluno),0);
						fwrite(&RegA,sizeof(TpAluno),1,PtrAlu);
					}
					
				}
				
			fclose(PtrAlu);
			printf("\nArquivo Aluno Ordenado!\n");
		}
	getch();
}

void ExclusaoFisica(void)
{
	TpAluno RegAlu;
	char AuxRA[14];
	int pos;
	FILE *PtrAlu = fopen("AlunosLOG.dat","rb");
	if (PtrAlu==NULL)
		printf("\nErro de Abertura!\n");
	else
		{
			printf("\nR.A. a Excluir: ");
			fflush(stdin);
			gets(AuxRA);
			pos = BuscaAlunoRA(PtrAlu,AuxRA);
			if (pos==-1)
			{
				printf("\nAluno nao cadastrado!\n");
				fclose(PtrAlu);
			}
			else
				{
					printf("\nDados do Aluno:\n");
					fseek(PtrAlu,pos,0);
					fread(&RegAlu,sizeof(TpAluno),1,PtrAlu);
					printf("R.A.: %s\n",RegAlu.RA);
					printf("Nome: %s\n",RegAlu.Nome);
					printf("Ano de Nasc.: %d\n",RegAlu.AnoNasc);
					printf("\nConfirma Exclusao (S/N)? ");
					if (toupper(getche())=='S')
					{
						FILE *PtrTemp = fopen("Temp.dat","wb");
						rewind(PtrAlu);
						fread(&RegAlu,sizeof(TpAluno),1,PtrAlu);
						while (!feof(PtrAlu))
						{
							if (strcmp(AuxRA,RegAlu.RA)!=0)
								fwrite(&RegAlu,sizeof(TpAluno),1,PtrTemp);
						
							fread(&RegAlu,sizeof(TpAluno),1,PtrAlu);
						}
						fclose(PtrAlu);
						fclose(PtrTemp);
						remove("AlunosLOG.dat");
						rename("Temp.dat","AlunosLOG.dat");
						printf("\nAluno excluido!\n");
					}
					else
						fclose(PtrAlu);
				}
			getch();
		}
}

void ExclusaoFisicaTodos(void)
{
	TpAluno RegAlu;
	FILE *PtrAlu = fopen("AlunosLOG.dat","rb");
	if (PtrAlu==NULL)
		printf("\nErro de Abertura!\n");
	else
		{
			FILE *PtrTemp = fopen("Temp.dat","wb");
			fread(&RegAlu,sizeof(TpAluno),1,PtrAlu);
			while (!feof(PtrAlu))
			{
				if (RegAlu.Status)
					fwrite(&RegAlu,sizeof(TpAluno),1,PtrTemp);
			
				fread(&RegAlu,sizeof(TpAluno),1,PtrAlu);
			}
			fclose(PtrAlu);
			fclose(PtrTemp);
			remove("AlunosLOG.dat");
			rename("Temp.dat","AlunosLOG.dat");
			printf("\nAlunos excluidos!\n");
		}		
	getch();
}

void ExclusaoLogica(void)
{
	TpAluno RAluno;
	int pos;
	FILE *PtrAlu = fopen("AlunosLOG.dat","rb+");
	clrscr();
	printf("\n## Excluir (LOGICA) por R.A. ##\n");
	if (PtrAlu == NULL)
		printf("\nErro de Abertura!\n");
	else
		{
			printf("\nR.A. a Excluir: ");
			fflush(stdin);
			gets(RAluno.RA);
			while(strcmp(RAluno.RA,"\0")!=0)
			{
				pos = BuscaAlunoRA(PtrAlu,RAluno.RA);
				if (pos == -1)
					printf("\nR.A. Nao Cadastrado!\n");
				else
					{
						printf("\n*** Dados Encontrados ***\n");
						fseek(PtrAlu,pos,0);
						fread(&RAluno,sizeof(TpAluno),1,PtrAlu);
						printf("R.A.: %s\n",RAluno.RA);
						printf("Nome: %s\n",RAluno.Nome);
						printf("Ano Nasc.: %d\n",RAluno.AnoNasc);
						
						printf("\nDeseja Excluir (S/N)?");
						if (toupper(getche())=='S')
						{
							RAluno.Status = 0;
							
							fseek(PtrAlu,pos,0);
							fwrite(&RAluno,sizeof(TpAluno),1,PtrAlu);	
							printf("\nRegistro Excluido Logicamente!\n");
						}
					}
					
				getch();
				printf("\nR.A. a Excluir: ");
				fflush(stdin);
				gets(RAluno.RA);
			}	
			fclose(PtrAlu);
		}
	
	getch();
}

char Menu(void)
{
	clrscr();
	printf("\n ###  M E N U   A L U N O S ###\n");
	printf("\n[A] Cadastrar");
	printf("\n[B] Exibir");
	printf("\n[C] Consultar por R.A.");
	printf("\n[D] Alterar por R.A.");
	printf("\n[E] Ordenar por R.A.");
	printf("\n[F] Exclusao por R.A. (Fisica)");
	printf("\n[G] Exclusao por R.A. (Logica)");
	printf("\n[H] Exclusao dos Inativos");
	printf("\n[ESC] Finalizar");
	printf("\nOpcao desejada: ");
	return toupper(getche());
}

int main(void)
{
	char opcao;
	do
	{
		opcao = Menu();
		switch(opcao)
		{
			case 'A':	GravarAluno();
						break;
			case 'B':	ExibirAluno();
						break;
			case 'C':	ConsultarAluno();
						break;
			case 'D':	AlterarAluno();
						break;
			case 'E':	OrdenarAluno();
						break;
			case 'F':	ExclusaoFisica();
						break;
			case 'G':	ExclusaoLogica();
						break;
			case 'H':	ExclusaoFisicaTodos();
		}
	}while (opcao!=27);
	
	return 0;
}




