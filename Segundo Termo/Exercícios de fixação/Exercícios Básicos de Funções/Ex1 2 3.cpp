#include<stdio.h>
#include<conio2.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int lenumero(void){
	int decimal;
	printf("\nConverte o numero: ");
	scanf("%d",&decimal);
	return decimal;
}

void exibenumero(int valor){
    printf("\nResultado: %d", valor);
    getch();
}

int convertebinario(int decimal){
	
    int soma = 0, resto, mult = 1;
    while(decimal>0){
        resto=decimal%2;
        soma+=resto*mult;
        mult*=10;
        decimal/=2;	//decimal /= 2: Abreviação comum e eficiente.
					//decimal = decimal / 2: Forma completa, mais explícita.
					//decimal = decimal * 0.5: Alternativa para floats, menos adequada para inteiros.
    }
    return soma;
}

int convertedecimal(int binario){
	int soma=0, resto, multi=0; 
    
    while(binario>=10){
        resto = binario%10;
        binario = binario/10;
        soma = soma + resto * pow(2,multi);
        multi++;
    }
    soma = soma + pow(2,multi);
    return soma;
}

void Perfeito(int Numero)
{
	int divisor, SomaDiv=0;
	for(divisor=1; divisor<=Numero/2; divisor++)
		if (Numero%divisor == 0)
			SomaDiv += divisor;   //SomaDiv=SomaDiv+divisor;
	
	if (SomaDiv == Numero)
		printf("\nNumero eh PERFEITO!\n");
	else
		printf("\nNumero NAO eh PERFEITO!\n");	
		
	getch();
}

int main(void)
{
	printf("\n### Conversao de Decimal para Binario ###\n");
	exibenumero(convertebinario(lenumero()));
	
	printf("\n\n### Conversao de Binario para Decimal ###\n");
	exibenumero(convertedecimal(lenumero()));
	
	printf("\n\n### Numero Perfeito ###\n");
	Perfeito(lenumero());
	return 0;
}


