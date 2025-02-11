//Estruturas de dados
struct TpCidade {
	char Nome[50];
	int Populacao;
};

//Protótipos das Operações
void Cadastrar(void);
void InserirRegistro(FILE *PtrArq, TpCidade Reg);
int BuscarNome(FILE *PtrArq, char NomeCidade[50]);
void Relatorio(void);
void Ordenar(void);
void Consultar(void);

//Operações Associadas
void Cadastrar(void) {
	FILE *PtrCidade = fopen("Cidades.dat", "ab+");
	TpCidade RCidade;
	
	printf("\n*** Cadastrar Cidades ***\n");
	printf("\nCidade: ");
	fflush(stdin);
	gets(RCidade.Nome);
	
	while(strcmp(RCidade.Nome, "\0") != 0) {
		printf("Populaçao: ");
		scanf("%d", &RCidade.Populacao);
		
		
		printf("\nCidade: ");
		fflush(stdin);
		gets(RCidade.Nome);
	}
	
	InserirRegistro(PtrCidade, RCidade);
	fclose(PtrCidade);
}

void InserirRegistro(FILE *PtrArq, TpCidade Reg) {
	fwrite(&Reg, sizeof(TpCidade), 1, PtrArq);
}

int BuscarNome(FILE *PtrArq, char NomeCidade[50]) {
	
}

void Relatorio(void) {
	
}

void Ordenar(void) {
	
}

void Consultar(void) {
	
}
