#define ex5
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#ifdef ex1
/*1 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
    funcao para compara-las e retorne como resultado se são IGUAIS 1 ou se
    DIFERENTES 0 para a funcao main(). Imprima o resultado na funcao main().
    (Declare os vetores como variavel global)*/


    char string1[11], string2[11];

    int compara();

    int main(){

        setlocale(LC_ALL,"");

        int resposta;

        inicio:
        printf("Digite a 1ª string até 10 caracteres: ");
        scanf("%s", &string1);

        printf("Digite a 2ª string até 10 caracteres: ");
        scanf("%s", &string2);

        printf("\n\nA primeira string foi: %s\n", string1);
        printf("A segunda string foi: %s\n\n", string2);
        compara();

        printf("Deseja continuar?\n\n");
        printf("1 - SIM\n");
        printf("2 - NÃO\n");
        scanf("%d", &resposta);

        if(resposta == 1){
            system("cls");
            goto inicio;
       }

    return 0;
    }

    int compara(){

        int retorno, cont=0;

        while(string1[cont] == string2[cont] && string1[cont] != '\0' && string2[cont] != '\0'){
            cont++;
        }

        if(string1[cont] == '\0' && string2[cont] == '\0'){
            retorno=1;
        }
        else{
            retorno=0;
        }
        printf("\nO valor do retorno foi: %d\n\n", retorno);

    return retorno;
    }
#endif //ex1

#ifdef ex2


/*2 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
    e imprima-os no video no seguinte formato:(Declare os 5 vetores como variaveis
    globais)

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome1                                   nome5
                nome2               nome4
                          nome3*/


        int nome1[8], nome2[8],nome3[8], nome4[8], nome5[8];

        int main(){

            int resposta;

        setlocale(LC_ALL,"");
        inicio:
        printf("Digite o primeiro nome: ");
        gets(nome1);


        printf("Digite o segundo nome: ");
        gets(nome2);

        printf("Digite o terceiro nome: ");
        gets(nome3);

        printf("Digite o quarto nome: ");
        gets(nome4);

        printf("Digite o quinto nome: ");
        gets(nome5);

        printf("\n            10        20        30        40        50\n");
        printf("    12345678901234567890123456789012345678901234567890\n");
        printf("%13s  %38s\n", nome1, nome5);
        printf("%23s %19s\n", nome2, nome4);
        printf("%33s\n\n", nome3);

        printf("Deseja continuar?\n\n");
        printf("1 - SIM\n");
        printf("2 - NÃO\n");
        scanf("%d", &resposta);

        if(resposta == 1){
            getchar();ss
            system("cls");
            goto inicio;
       }

        return 0;
        }
 #endif //ex2

 #ifdef ex3

    /*3 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras maiusculas.*/

    char string[11];
    int resposta;

    int main(){

    int cont;

    setlocale(LC_ALL,"");
    inicio:
    printf("Digite 10 caracteres: ");
    scanf("%s", &string);

    for(cont=0; string[cont]!= '\0'; cont++){

    if(string[cont] >= 97 && string[cont] <=122){
    string[cont] = string[cont]-32;
    }
    }
    printf("%s", string);

        printf("\n\nDeseja continuar?\n\n");
        printf("1 - SIM\n");
        printf("2 - NÃO\n");
        scanf("%d", &resposta);

        if(resposta == 1){
            system("cls");
            goto inicio;
       }

    return 0;
    }
#endif // ex3

#ifdef ex4

/*4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras minusculas.*/



    int main(){

    static char string[11];
    int cont, resposta;

    setlocale(LC_ALL,"");
    inicio:
    printf("Digite 10 caracteres: ");
    scanf("%s", &string);

    for(cont=0; string[cont]!= '\0'; cont++){

    if(string[cont] >= 65 && string[cont] <=90){
    string[cont] = string[cont]+32;
    }
    }
    printf("%s", string);

        printf("\n\nDeseja continuar?\n\n");
        printf("1 - SIM\n");
        printf("2 - NÃO\n");
        scanf("%d", &resposta);

        if(resposta == 1){
            system("cls");
            goto inicio;
       }

    return 0;
    }
#endif // ex4

#ifdef ex5

/*5 - Faca um programa que receba uma sring de no maximo 20 caracteres na funcao main().
    Faca uma funcao que some 2 no valor ASCII de cada um dos caractere recebidos.
    Mostre a string resultante na funcao main().
   (Declare o vetor como variavel global)
*/

char string[20];
int cont, resposta;

int main(){
    setlocale(LC_ALL,"");
    inicio:
    printf("Digite 10 caracteres: ");
    scanf("%s", &string);

    for(cont=0; string[cont]!= '\0'; cont++){

    string[cont] = string[cont]+2;
    }
    printf("\n%s", string);

        printf("\n\nDeseja continuar?\n\n");
        printf("1 - SIM\n");
        printf("2 - NÃO\n");
        scanf("%d", &resposta);

        if(resposta == 1){
            system("cls");
            goto inicio;
       }

    return 0;

    }



#endif // ex5
