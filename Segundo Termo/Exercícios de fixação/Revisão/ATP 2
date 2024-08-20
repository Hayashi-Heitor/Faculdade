#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define TFP 10
#define TFC 30
#define TFV 50

int main(void)
{
	char op, Produto[TFP][30], Cliente[TFC][30], AuxProd[30], AuxCli[30];
	int i, j, pos, TLV=0, TLC=0, TLP=0, MatVendas[TFV][3], Estoque[TFP];
	float Preco[TFP];
	
	
	do
	{
		system("cls");     //clrscr();
		printf("\n### M E N U  VENDAS ###\n");
		printf("[A] Cadastrar Produtos\n");
		printf("[B] Exibir Produtos\n");
		printf("[C] Consultar Produtos\n");
		printf("[D] Excluir Produtos\n");
		printf("[E] Alterar Estoque de Produtos\n");
		printf("[F] Ordenar Produtos pela Qtde em Estoque (Decrescente)\n");
		printf("[G] Cadastrar Clientes\n");
		printf("[H] Exibir Clientes\n");
		printf("[I] Ordenar Clientes (Crescente)\n");
		printf("[J] Excluir Clientes\n");
		printf("[K] Realizar Vendas\n");
		printf("[L] Exibir Vendas\n");
		printf("[ESC] Finalizar\n");
		printf("\n\nOpcao desejada: ");
		
		op = toupper(getch()); //getche();
		switch(op)
		{
			case 'A':  system("cls");
					   printf("\nCadastrar Produtos:\n");
					   if (TLP==TFP)
					   {
					   	  printf("\nVetor de Produtos Cheio!\n");
					   	  getch();
					   }
					   else
					   		{
					   		   printf("Descricao do Produto [%d]: ",TLP);
							   fflush(stdin);
							   gets(AuxProd);
							   //while (TLP<TFP && AuxProd[0]!='\0')
							   //while (TLP<TFP && strlen(AuxProd)>0)
							   //while (TLP<TFP && strcmp(AuxProd,"")!=0)
							   while (TLP<TFP && strcmp(AuxProd,"\0")!=0)
							   {
								  //Busca para validar a existência do Produto
								  pos=0;
								  while (pos<TLP && stricmp(AuxProd,Produto[pos])!=0)
								  			pos++;
								  
								  if(pos==TLP) //Não achou...
								  {
									  strcpy(Produto[TLP],AuxProd);
									  printf("Preco [%d]: ",TLP);
									  scanf("%f",&Preco[TLP]);
									  printf("Qtde Estoque [%d]: ",TLP);
									  scanf("%d",&Estoque[TLP]);
									  TLP++;
								  }
								  else
								  	{
								  		printf("\nProduto ja Cadastrado!\n");
								  		getch();
								  	}
								  
								  
								  if (TLP<TFP)
								  {
								  	printf("\nDescricao do Produto [%d]: ",TLP);
							        fflush(stdin);
							        gets(AuxProd);
								  }
								  else
								  	  {
								  	  	printf("\nVetor de Produtos Cheio!\n");
								  	  	getch();
								  	  }
							   }
					   		}
					   
					   break;
					   
			case 'B':
			system("cls");
			printf("\n### RELATORIO DE PRODUTOS\n");
				if (TLP==0)
					printf("\nNao ha Produtos!\n");
				else
				   	for(i=0; i<TLP; i++){
				   	printf("\nProduto[%d]:\n",i);
					printf("Descricao: %s\n",Produto[i]);
				   	printf("Preco: R$ %.2f\n",Preco[i]);
				   	printf("Estoque: %d\n",Estoque[i]);
				   	}
					   
					   getch();
					   break;
					   
			case 'C':
			system("cls");
			printf("\nConsultar Produtos:\n");
					   if (TLP==0)
					   {
					   	  printf("\nNao ha Produtos!\n");
					   	  getch();
					   }
					   else	
					   	  {
					   	  	 printf("\nProduto a Consultar: ");
					   	  	 fflush(stdin);
					   	  	 gets(AuxProd);
					   	  	 while (strcmp(AuxProd,"\0")!=0)
					   	  	 {
					   	  	 	pos=0;
					   	  	 	while(pos<TLP && stricmp(AuxProd,Produto[pos])!=0)
					   	  	 			pos++;
					   	  	 	
					   	  	 	if(pos<TLP)  //Achou
					   	  	 	{
					   	  	 		printf("\n### Detalhes do Produto ###\n");
					   	  	 		printf("Produto: %s",Produto[pos]);
					   	  	 		printf("\nPreco: R$ %.2f",Preco[pos]);
					   	  	 		printf("\nEstoque: %d\n",Estoque[pos]);
					   	  	 	}
					   	  	 	else
					   	  	 		printf("\nProduto nao Cadastrado!\n");
					   	  	 	
								getch();
								printf("\nProduto a Consultar: ");
					   	  	 	fflush(stdin);
					   	  	 	gets(AuxProd);
					   	  	 }
					   	  }
					   
					   break;
					   
			case 'D': 
			system("cls");
			printf("\n### EXCLUIR PRODUTOS ###\n");
					   if (TLP==0)
					   {
					   	  printf("\nNao ha Produtos!\n");
					   	  getch();
					   }
					   else	
					   	  {
					   	  	 printf("\nProduto a Excluir: ");
					   	  	 fflush(stdin);
					   	  	 gets(AuxProd);
					   	  	 while (TLP>0 && strcmp(AuxProd,"\0")!=0)
					   	  	 {
					   	  	 	pos=0;
					   	  	 	while(pos<TLP && stricmp(AuxProd,Produto[pos])!=0)
					   	  	 			pos++;
					   	  	 	
					   	  	 	if(pos<TLP)  //Achou
					   	  	 	{
					   	  	 		printf("\n### Detalhes do Produto ###\n");
					   	  	 		printf("Produto: %s",Produto[pos]);
					   	  	 		printf("\nPreco: R$ %.2f",Preco[pos]);
					   	  	 		printf("\nEstoque: %d\n",Estoque[pos]);
					   	  	 		printf("\nConfirma Exclusao (S/N)? ");
					   	  	 		if (toupper(getche())=='S')
					   	  	 		{
					   	  	 			for(; pos<TLP-1; pos++)
					   	  	 			{
					   	  	 				strcpy(Produto[pos],Produto[pos+1]);
					   	  	 				Estoque[pos] = Estoque[pos+1];
					   	  	 				Preco[pos] = Preco[pos+1];	
					   	  	 			}
					   	  	 			TLP--;
					   	  	 			printf("\nProduto [%s] Excluido!\n", AuxProd);
					   	  	 		}
					   	  	 	}
					   	  	 	else
					   	  	 		printf("\nProduto nao Cadastrado!\n");
					   	  	 	
								getch();
								printf("\nProduto a Excluir: ");
					   	  	 	fflush(stdin);
					   	  	 	gets(AuxProd);
					   	  	 }
					   	  }
					   
					   break;
					   
			case 'E':
				system("cls");
				printf("\nAlterar Estoque de Produtos:\n");
					   if (TLP==0)
					   {
					   	  printf("\nNao ha Produtos!\n");
					   	  getch();
					   }
					   else	
					   	  {
					   	  	 printf("\nAlterar Estoque do Produto: ");
					   	  	 fflush(stdin);
					   	  	 gets(AuxProd);
					   	  	 while (strcmp(AuxProd,"\0")!=0)
					   	  	 {
					   	  	 	pos=0;
					   	  	 	while(pos<TLP && stricmp(AuxProd,Produto[pos])!=0)
					   	  	 			pos++;
					   	  	 	
					   	  	 	if(pos<TLP)  //Achou
					   	  	 	{
					   	  	 		printf("\n### Detalhes do Produto ###\n");
					   	  	 		printf("Produto: %s",Produto[pos]);
					   	  	 		printf("\nPreco: R$ %.2f",Preco[pos]);
					   	  	 		printf("\nEstoque: %d\n",Estoque[pos]);
					   	  	 		printf("\nAlterar Estoque (S/N)? ");
					   	  	 		if (toupper(getche())=='S')
					   	  	 		{
					   	  	 			do
					   	  	 			{
					   	  	 				printf("\nNova qtde em Estoque: ");
					   	  	 				scanf("%d",&Estoque[pos]);
					   	  	 				if (Estoque[pos]<0)
					   	  	 				  printf("\nDigite um valor MAIOR ou IGUAL a ZERO!\n");
										}while(Estoque[pos] < 0);
										
					   	  	 			
					   	  	 			printf("\nQtde do Produto [%s] Alterado!\n", AuxProd);
					   	  	 		}
					   	  	 	}
					   	  	 	else
					   	  	 		printf("\nProduto nao Cadastrado!\n");
					   	  	 	
								getch();
								printf("\nAlterar Estoque do Produto: ");
					   	  	 	fflush(stdin);
					   	  	 	gets(AuxProd);
					   	  	 }
					   	  }
			case 'F':
				system("cls");
				printf("\n### ORDENACAO DE PRODUTOS EM ESTOQUE ###\n");
				if(TLP == 0){
					printf("Nao ha produtos cadastrados!!!\n");
					getch();
				}
				else{
					
				}
					   break;
					   
			case 'G':
					   system("cls");
					   printf("\n### CADASTRAR CLIENTES ###\n");
					   if(TLC == TFC){
							printf("Limite de clientes cadastrados atingidos!!!\n");
							getch();
					   }
					   else{
					   		printf("\nInsira o nome do [%d] cliente: ", TLC);
					   		fflush(stdin);
					   		gets(AuxCli);
					   		while(TLC < TFC && strcmp(AuxCli, "") != 0){
					   			
					   			pos=0;
					   			while(pos<TLC && strcmp(AuxCli, Cliente[pos]) != 0)
					   				pos ++;
					   				
					   			if(pos == TLC){
					   				strcpy(Cliente[pos], AuxCli);
					   				TLC++;
					   				printf("\nCadastro efetuado com sucesso!\n");
					   				printf("Insira o proximo cliente: ");
					   				fflush(stdin);
					   				gets(AuxCli);
					   				}
					   				
								else{
									printf("\nCliente ja cadastrado!\n");
									printf("Insira outro cliente: ");
									fflush(stdin);
									gets(AuxCli);
								}	
					   		}
					   }
					   break;
					   
			case 'H':
			system("cls");
			printf("\n### RELATORIO DE CLIENTES ###\n");
			if(TLC == 0)
				printf("Nao ha clientes cadastrados!!!\n");
			else{
				for(i=0; i<TLC; i++){
					printf("\n--------------------------\n");
					printf("\nCliente [%d] = %s\n", i, Cliente[i]);
				}
			}
			getch();	
			break;
					   
			case 'I':	for(i=0; i<TLC-1; i++)
							for(j=i+1; j<TLC; j++)
								if(strcmp(Cliente[i],Cliente[j])>0)
								{
									strcpy(AuxCli,Cliente[i]);
									strcpy(Cliente[i],Cliente[j]);
									strcpy(Cliente[j],AuxCli);
								}
						printf("\nClientes Ordenados com SUUUUCESSO!!\n");
						getch();
						break;
			
			case 'J':  printf("\nRealizar Vendas:\n");
					   getch();
					   break;
			
			case 'K':  printf("\nExibir Vendas:\n");
					   getch();
					   break;
		}
		
	}while (op != 27);  //ESC
	
	return 0;
}
