#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define TFP 10
#define TFC 30
#define TFV 50

int main (void){
	
	int TLP=0, TLC=0, TLV=0, estoque[TFP], venda[TFV][2], i, auxqtd;
	char op, auxprod[50], produto[TFP][50], cliente[TFC][50], auxcliente[50];
	float preco[TFP];
	
	do{	
		system("cls");
		printf("### M E N U ###\n");
		printf("[A] - Cadastrar Produtos\n");
		printf("[B] - Exibir Produtos Cadastrados\n");
		printf("[C] - Cadastrar Clientes\n");
		printf("[D] - Exibir Clientes Cadastrados\n");
		printf("[E] - Realizar Vendas\n");
		printf("[F] - Exibir Vendas Realizadas\n");
		printf("[ESC] - Encerrar Programa\n");
		printf("Opcao Desejada: ");
		
		op = toupper(getch());
		
		switch(op){
			case 'A':
				system("cls");
				printf("### CADASTRO DE PRODUTOS ###\n");
				if (TFP == TLP){
					printf("Cadastro de Produtos Cheio!!!\n");
					printf("Pressione Qualquer Tecla Para Voltar ao Menu: ");
					getch();
				}
				else{
					
					printf("Pressione Apenas [ENTER] na Descricao do Produto Para Encerrar os Cadastros\n");
					printf("\nInsira a Descricao do [%d] Produto: ", TLP+1);
					fflush(stdin);
					gets(auxprod);

					while(TLP<TFP && strcmp(auxprod,"") != 0){
						
						strcpy(produto[TLP], auxprod);
						printf("\nInforme o Preco do [%d] Produto: ", TLP+1);
						scanf("%f", &preco[TLP]);
						printf("\nInforme o Estoque do [%d] Produto: ", TLP+1);
						scanf("%d", &estoque[TLP]);
						
						TLP++;
						
						if(TLP == TFP){
							printf("Cadastro de Produtos Cheio!!!\n");
							printf("Pressione Qualquer Tecla para Retornar ao Menu: ");
							getch();
						}
						else{
							system("cls");
							printf("Pressione apenas [ENTER] na Descricao do Produto Para Encerrar os Cadastros\n");
							printf("\nInsira a Descricao do [%d] Produto: ", TLP+1);
							fflush(stdin);
							gets(auxprod);
						}
					}
				}
			break;
			
			case 'B':
				system("cls");
				printf("### EXIBICAO DE PRODUTOS ###\n");
				
				if(TLP == 0){
					printf("Nao ha Produtos Cadastrados!!!\n");

				}
				else{
					for(i=0; i<TLP; i++){
						printf("\n--------------------\n");
						printf("\nPRODUTO [%d]\n", i+1);
						printf("Descricao: %s\n", produto[i]);
						printf("Preco: %.2fR$\n", preco[i]);
						printf("Estoque: %d\n", estoque[i]);
					}
				}
				printf("\nPressione Qualquer Tecla para Retornar ao Menu: ");
				getch();
			
			break;
			
			case 'C':
				system("cls");
				printf("### CADASTRO DE CLIENTES ###\n");
				if(TLC == TFC){
					printf("Limite de Clientes Cadastrados Atingido!!!\n");
					printf("Pressione Qualquer Tecla para Retornar ao Menu: ");
					getch();
				}
				else{
					printf("Pressione Apenas [ENTER] para Encerrar os Cadastros\n");
					printf("Insira o Nome do [%d] Cliente: ", TLC+1);
					fflush(stdin);
					gets(auxcliente);
					
					while(TLC < TFC && strcmp(auxcliente, "") != 0){
						strcpy(cliente[TLC], auxcliente);
						TLC++;
						if(TLC == TFC){
							printf("Limite de Clientes Cadastrados Atigido!!!\n");
							printf("Pressione Qualquer Tecla para Retornar ao Menu: ");
							getch();
						}
						else{
							system("cls");
							printf("Pressione Apenas [ENTER] para Encerrar os Cadastros\n");
							printf("Insira o Nome do [%d] Cliente: ", TLC+1);
							fflush(stdin);
							gets(auxcliente);
						}
					}
				}
			break;
			
			case 'D':
				system("cls");
				printf("### EXIBICAO DE CLIENTES ###\n");
				if(TLC == 0){
					printf("Nao ha Clientes Cadastrados!!!\n");
					printf("Pressione Qualquer Tecla para Continuar: ");
					getch();
				}
				else{
					for(i=0; i<TLC; i++){
						printf("\n--------------------\n");
						printf("\nCLIENTE [%d]\n", i+1);
						printf("Nome: %s\n", cliente[i]);
					}
					printf("\nPressione Qualquer Tecla para Retornar ao Menu: ");
					getch();	
				}
			break;
			
			case 'E':
				while(op != 77){
				system("cls");
				printf("### REALIZACAO DE VENDAS ###\n");
				if(TLP==0){
					printf("Sem Produtos Cadastrados!!!\n");
					printf("Pressione Qualquer Tecla para Retornar ao Menu: ");
					getch();
					op = 77;
				}
				else if(TLC==0){
					printf("Sem Clientes Cadastrados!!!\n");
					printf("Pressione Qualquer Tecla para Retornar ao Menu: ");
					getch();
					op = 77;
				}
				else{
					printf("Informe o Nome do Cliente: ");
					fflush(stdin);
					gets(auxcliente);
					
					i=0;
					while(i<TLC && strcmp(auxcliente, cliente[i]) != 0)
						i++;
						
					if(i==TLC){
						printf("Cliente Nao Encontrado!!!\n");
						printf("Pressione Qualquer Tecla para Retornar ao Menu: ");
						getch();
						op = 77;
					}
					else{
						venda[TLV][0] = i;
						printf("\nInsira o Produto Desejado pelo Cliente [%d]: ", i+1);
						fflush(stdin);
						gets(auxcliente);
						
						i=0;
						while(i < TLP && strcmp(auxcliente, produto[i]) != 0)
							i++;
							
						while(i == TLP){
							printf("\nProduto nao existente!!!\n");
							printf("Insira um Produto Cadastrado: ");
							fflush(stdin);
							gets(auxcliente);
							
							i=0;
							while(i < TLP && strcmp(auxcliente, produto[i]) != 0)
								i++;
							}
							
						printf("\nInsira a Quantidade do Produto [%d]: ", i+1);
						scanf("%d", &auxqtd);
						
						while(auxqtd > estoque[i]){
							printf("\nQuantidade Desejada Maior que a no Estoque!!!");
							printf("\nInsira um Valor Menor: ");
							scanf("%d", &auxqtd);
							}
							
						venda[TLV][2] = auxqtd;
						estoque[i] = estoque[i] - auxqtd;
						
						printf("\nVenda Efetuada com Sucesso!!!\n");
						TLV ++;
						printf("Pressione [M] para retornar ao Menu\n");
						printf("Ou pressione qualquer outra tecla para realizar outra venda: ");
						op = toupper(getch());	
					}
				}
			}
			break;
			
			case 'F':
				system("cls");
				printf("### EXIBICAO DE VENDAS ###\n");
				printf("\n-----------------------------------\n");
				printf("Cliente )
		}
	}while(op != 27);
	
	return 0;	
}

