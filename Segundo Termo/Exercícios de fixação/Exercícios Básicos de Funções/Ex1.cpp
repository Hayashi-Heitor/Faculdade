#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int lenumero(void){
    int Decimal;
    printf("\nvalor decimal:");
    scanf("%d",&Decimal);
    return Decimal;
}
void ExibeNumero(int Valor){
    printf("\nResultado:%d\n",Valor);
    getch();
}
int ConverteBinario(int Decimal){
    int Binario=0, resultado,i=1,resto;
    while(Decimal>0){
        resultado=Decimal/2;
        resto=Decimal%2;
        resto=resto*i;
        i=i*10;
        Binario=Binario+resto;
        Decimal=resultado;
    }
    return Binario;
}
int main(void) {
    int ValorDec,ValorBin;
    ValorDec=lenumero();
    ValorBin=ConverteBinario(ValorDec);
    ExibeNumero(ValorBin);
    return 0;
}
