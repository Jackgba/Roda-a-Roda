// Esse c�digo gera um n�mero aleatorio dos n�meros do arquivo PREMIOS.DAT
// Est� funcionando perfeitamente de maneira isolada, mas quando tento colocar no c�digo principal sempre d� erro

#include <stdio.h>

int main(void)
{
 char url[]="PREMIOS.dat";
 float premio[12], valor;
 int i;
 FILE *arq;
 
 arq = fopen(url, "r"); // define arq como o arquivo premio.dat para somente ler
 if(arq == NULL) // teste de erro
   printf("Erro, nao foi possivel abrir o arquivo\n");
 else
 for(i=0;i<12;i++){ //cria um loop para armazenar cada valor de premio no vetor premio
if ((fscanf(arq, "%f\n", &premio[i])) == 1 ) // leia a explicacao no final do c�digo
    srand(time(NULL));
	valor = premio[rand()%12];
}
 fclose(arq);

	printf("%.2f\n", valor);

 return 0;
}

// tentativa de colocar dentro de uma fun��o:

/*

float premios()
{
 char url[]="PREMIOS.dat",
      nome[20];
 float premio[12], valor;
 int i;
 FILE *arq;
 
 arq = fopen(url, "r");
 if(arq == NULL)
   printf("Erro, nao foi possivel abrir o arquivo\n");
 else
 for(i=0;i<12;i++){
if ((fscanf(arq, "%f\n", &premio[i])) == 1 )
    srand(time(NULL));
	valor = premio[rand()%12];
}
 fclose(arq);
 
 return valor;
}

*/

/*
A fun��o fscanf serve para transformar uma linha de um arquivo em uma vari�vel podendo ter varios formatos.
Foi a unica fun��o que eu consegui fazer funcionar para ler esse arquivo como float

arq � o arquivo. %f � o tipo de dado da primeira linha e coluna do arquivo (se o arquivo fosse, por exemplo:
200 abc
dava pra ler usando fscanf(arq,%f %s\n) e daria para criar um loop para ler v�rias linhas). premio[i] �
o valor dos premios que ser�o armazenados. == 1 � para caso d� tudo certo na leitura (como se fosse um teste de erro).

depois disso acho que d� para entender.
*/
