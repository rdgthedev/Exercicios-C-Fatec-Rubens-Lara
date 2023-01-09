#define ex1
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*1 - Escreva um programa que receba um vetor de tamanho 10 e o decomponha em dois
    outros vetores. Um contera' as componentes de ordem impar e o outro contera'
    as componentes de ordem par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7}, o programa
    deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3}.*/


#ifdef ex1
    int vet[10], vetpar[10], vetimpar[10];

    int main(){

        int cont, imp, num11;

        setlocale(LC_ALL,"");



        for(cont=0; cont < 10; cont++){

        do{
        printf("Digite o %d° número: ", cont+1);
        scanf("%d", &vet[cont]);
        }while(vet[cont] < 0);


        }
        printf("\n");
        for(cont=0; cont < 10; cont++){

            printf("%d", vet[cont]);

        }
        printf("\n\n");
        imppar();

    return 0;
    }

    void imppar(){

        int cont, contpar=0, contimpar=0, contauxparr=0, contauximp=0;

        for(cont=0; cont < 10; cont++){

            if(vet[cont]%2 == 0){

               vetpar[contpar] = vet[cont];
               contpar++;
               contauxparr++;
        }

        else{

        vetimpar[contimpar] = vet[cont];
        contimpar++;
        contauximp++;
        }
        }

        if(contauxparr == 0){

            printf("Não há números pares!");
        }
        else{
            printf("Os números pares digitados foram: \n");
            for(cont=0; cont < contpar; cont++){
            printf("%d, ",vetpar[cont]);
            }
        }
        printf("\n");

        if(contauximp == 0){

            printf("Não há números ímpares!");
        }
        else{
            printf("\n\nOs números ímpares digitados foram: \n");

            for(cont=0; cont < contimpar; cont++){
            printf("%d, ", vetimpar[cont]);
            }
        }
    }




#endif // ex1

#ifdef ex2

/*2 - Receba via teclado valores do tipo int para uma vetor 5 x 5. Receba via
    teclado um valor x. O programa dever fazer a busca desse valor x no vetor
    e, ao final escrever a localizacao (linha e coluna) ou uma mensagem de
    ”nao encontrado”.*/


    int vetor[5][5];



    int main(){


    int num=0, linha, coluna, contaux=0;
    char r;


    setlocale(LC_ALL,"");


    for(linha=0;linha<5;linha++){
        for(coluna=0;coluna<5;coluna++){
        printf("Digite o número que irá conter na posição [%d],[%d]:", linha+1, coluna+1);
        scanf("%d", &vetor[linha][coluna]);
        }
    }

    inicio:
    printf("\nDigite o número que deseja pesquisar: ");
    scanf("%d", &num);

    contaux=0;

    for(linha=0; linha<5; linha++){
        for(coluna=0; coluna<5; coluna++){



           if(vetor[linha][coluna] == num){

            printf("O número foi encontrado na linha %d e coluna %d\n", linha+1, coluna+1);
            contaux++;
           }

        }

    }

        if(contaux<=0){
            printf("\nO número não foi encontrado!\n");
        }

        printf("\nDeseje continuar pesquisando o número nas matrizes?\n");
        printf("Digite 1 para continuar. Caso não queira continuar, aperte qualquer tecla: ");
        scanf("%c", &r);
        r = getchar();

        if(r == '1'){
            goto inicio;
        }
    return 0;
    }
#endif //ex2

#ifdef ex3
    /*3 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
    que recebe os dados via teclado para esses 2 vetores. Usando o operador
    adicao "+", some os elementos de mesmo indice dos 2 vetores e guarde o
    resultado em um 3. vetor. Imprima na tela o indice, os valores e o resultado
    dos 6 elementos dos vetores.*/


    int vetor1[2][3], vetor2[2][3];

    int main(){

    int linha1,coluna1, linha2, coluna2;

    for(linha1=0;linha1)
    printf("Digite ");

    return 0;
    }
#endif //ex3

#ifdef ex4
/*4 - Escreva um programa para receber via teclado em vetores 3 int, 3 long,
    3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:*/


    int vetint[3], cont;
    long int vetlong[3];
    unsigned int vetunsigned[3];
    float vetfloat[3];
    double vetdouble[3];


    int main(){

    setlocale(LC_ALL,"");
    for(cont=0; cont < 3; cont++){
    printf("Variável INT: ");
    scanf("%d", &vetint[cont]);
    }

        for(cont=0; cont < 3; cont++){
    printf("Variável LONG: ");
    scanf("%d", &vetlong[cont]);
    }

        for(cont=0; cont < 3; cont++){
    printf("Variável UNSIGNED: ");
    scanf("%d", &vetunsigned[cont]);
    }

            for(cont=0; cont < 3; cont++){
    printf("Variável FLOAT: ");
    scanf("%f", &vetfloat[cont]);
    }

            for(cont=0; cont < 3; cont++){
    printf("Variável DOUBLE: ");
    scanf("%lf", &vetdouble[cont]);
    }

    printf("\n      10        20        30        40        50\n");
    printf("12345678901234567890123456789012345678901234567890\n");
    printf("%3hd %19ld %26hd\n", vetint[0], vetlong[0], vetunsigned[0]);
    printf("%17.2f %19.2f\n", vetfloat[0],vetdouble[0]);
    printf("%3hd %19ld %26hd\n", vetint[1], vetlong[1], vetunsigned[1]);
    printf("%17.2f %19.2f\n", vetfloat[1],vetdouble[1]);
    printf("%3hd %19ld %26hd\n", vetint[2], vetlong[2], vetunsigned[2]);
    printf("%17.2f %19.2f\n", vetfloat[2],vetdouble[2]);


    return 0;
    }
    #endif //ex4

    #ifdef ex5
    /*5 - Receba via teclado 10 valores inteiros e ordene por ordem crescente assim
    que sao digitados. Guarde-os em um vetor. Mostre ao final os valores ordenados*/

    int num[10], menor;

    int main(){

    setlocale(LC_ALL,"");
    int cont, cont2;

    for(cont=0; cont < 10; cont++){

        printf("Digite o %d° número: ", cont+1);
        scanf("%d", &num[cont]);
    }

    for(cont=0;cont<10;cont++){
        for(cont2= cont+1; cont2<10;cont2++){
            if(num[cont] > num[cont2]){

                menor = num[cont];
                num[cont] = num[cont2];
                num[cont2] = menor;
            }
        }
    }

    printf("\nOs números em ordem são:\n\n");

    for(cont=0;cont<10;cont++){
        printf("%d", num[cont]);

        if(cont < cont2 -1){
            printf(", ");
        }
        else{
            printf(".");
    }
    }
    return 0;
    }
    #endif //ex5


















































































