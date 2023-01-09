#define ex2
#include <stdio.h>
#include <locale.h>



/*1 - Faça um programa que receba dois numeros inteiros e execute as seguintes
    funçoes:

    - Verificar se o numero digitado e' positivo ou negativo. Sendo que o valor de
      retorno sera' 1 se positivo, 0 se negativo ou -1 se for igual a 0.

    - Se os 2 numeros sao positivos, retorne a soma dos N numeros existentes entre
      eles.

    - Se os 2 numeros sao negativos, retorne a multiplicacao dos N numeros existente
      entre eles.

    - Se 1. numero for positivo e o 2. negativo faca a divisao entre eles.*/


#ifdef ex1

 int cont;

float divposinegativo(int num1, int num2);

int main()
{
    int num1=0, num2=0,retorno1=0, retorno2=0,intervalo=0, maior=0, menor=0, soma=0, produto=0, retornovet=0;;
    float divisao=0;


    setlocale(LC_ALL, "");


    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o primeiro número: ");
    scanf("%d", &num2);



    retorno1 = posinegativo(num1);
    retorno2 = posinegativo(num2);
    if(retorno1 == 1 && retorno2 == 1){
       printf("O retorno é: %d", positivos(num1, num2));
    }



        if(retorno1 == 0 && retorno2 == 0){
       printf("O retorno é: %d", negativos(num1, num2));

    }

    if(retorno1 == 1 && retorno2 == 0){
        printf("O retorno é: %f",divposinegativo(num1, num2));
    }



    return 0;
}


int posinegativo(int num1)
{
    int retorno1;

    if(num1 > 0)
    {
        retorno1 = 1;
    }

    else if(num1 < 0)
    {
        retorno1 = 0;
    }

    else
    {
        retorno1 = -1;
    }

    return retorno1;
}



int positivos(int num1, int num2)
{
    int maior, menor, intervalo, soma=0;

    if(num1 > 0 && num2 > 0)
    {


        if(num1 > num2)
        {
            maior = num1;
            menor = num2;
            intervalo = num1 - num2 - 1;
        }
        else if(num2 > num1)
        {
            maior = num2;
            menor = num1;
            intervalo = num2 - num1 - 1;
        }

        for(cont=0; cont < intervalo; cont++)
        {

            soma += menor + 1 + cont;
        }
    }

    return soma;
}


int negativos(int num1, int num2)
{

    int maior, menor, intervalo, cont, produto;

    if(num1 < 0 && num2 < 0)
    {

        if(num1 > num2)
        {
            maior = num1;
            menor = num2;
            intervalo = num1 - num2 - 1;
        }

        else if(num2 > num1)
        {
            maior = num2;
            menor = num1;
            intervalo = num2 - num1 - 1;
        }

        for(cont=0; cont < intervalo; cont++)
        {
            produto *= menor + 1 + cont;

        }
    }

    return produto;
}


float divposinegativo(int num1, int num2)
{

    float divisao;


        divisao = (float)num1/(float)num2;
    return divisao;
}


#endif //ex1


#ifdef ex2
/*2 - Escreva um programa que receba um numero N via teclado. Escreva uma funcao
    que retorne a soma dos algarismos do resultado de N!. O resultado deve ser
    mostrado na funcao main().

    Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos e´ 2 + 4 = 6.*/



int algarismos[];

int main(){
    int num=0, r;


    setlocale(LC_ALL,"");
    inicio:
    do{
        printf("Digite um número: ");
        scanf("%d", &num);
    }
    while(num < 0);

    somaalg(num);



    printf("\n\nDeseja continuar o programa?\n");
    printf("Pressione a tecla 1 para continuar no programa, caso contrário aperte qualquer outra tecla: ");
    scanf("%d", &r);


    if(r == 1){
        system("cls");
        goto inicio;
    }

return num;
}


//FUNÇÃO PARA FAZER FATORIAL + SOMA ALGARISMOS
void somaalg(int num){

    int cont=0, fat=1, rascfat=0, soma=0, contaux=0, contaux2=0;

    for(cont=0; cont < num; cont++){
        fat *= (num-cont);
    }

    rascfat = fat; //SALVA O NÚMERO DO FATORIAL ANTES DE FAZER AS SINAS DOS ALGARISMOS;
    while(fat != 0){

        soma+= fat%10; //ACRESCENTANDO O ÚLTIMO ALGARISMO DE FAT À VARIÁVEL SOMA

        algarismos[contaux] = fat%10; //SALVA O ÚLTIMO NÚMERO QUE FOI SEPARADO NA POSIÇÃO DO VETOR.


        fat = fat/10; //DIVIDE O ÚLTIMO NÚMERO POR 10, PEGANDO A PARTE INTEIRA DA DIVISÃO.
        contaux++;
        printf("\n\ncontaux: %d\n\n", contaux);
    }

    contaux2 = contaux;

    printf("\nSe N = %d, N! = %d. Logo, a soma de seus algarismos é ", num, rascfat);

    while(contaux-1 >= 0){
        if(contaux == contaux2){
            printf(" %d", algarismos[contaux-1]);
        }

        else{
            printf(" + %d", algarismos[contaux-1]);
        }
        contaux--;
    }
    printf(" = %d", soma);
}
#endif //ex2

#ifdef ex3

/*3 - Escreva um programa que receba uma letra via teclado. Escreva uma funcao que
    pesquise esta letra dentro do vetor abaixo. Imprima o resultado da pesquisa
    no video na funcao main(). Passe como informacao para a funcao a letra
    digitada.(utilize o comando return). O vetor deve ser uma variavel global.

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y*/

    char charvet[]={'b','d','f','h','j','k','m','o','q','s','u','w','y'};
    char letra(char a);

        int main(){

        char a;

        int r;

        setlocale(LC_ALL, "");

        do{
        printf("Digite uma letra: ");
        scanf("%c", &a);


        letra(a);

        printf("\n\nDeseja continuar o programa?\n");
        printf("Pressione a tecla 1 para continuar no programa, caso contrário aperte qualquer outra tecla: \n");
        scanf("%d", &r);
        getchar();
        system("cls");
        }while(r==1);

        return a;
    }

    char letra(char a){

    int cont,contaux=0, digito;

    for(cont=0;cont<13;cont++){

        if(charvet[cont]==a){
        contaux++;
    }
    }

    if(contaux>0){
        digito = printf("\nA letra digitada está no vetor");
    }
    else{
        digito = printf("\nA letra digitada não está no vetor");
    }

    return digito;
    }
#endif // ex3

#ifdef ex4

/*    4 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
    uma funcao para cada operacoes aritmeticas e passe como parametro os 2
    valores recebidos na funcao main(). Retorne os resultados usando o comando
    return e imprima os 4 resultados no video na funcao main().*/

    //CHAMANDO AS FUNÇÕES ANTES DO MAIN
    int somar(int num1, int num2);
    int subtrair(int num1, int num2);
    int multiplicar(int num1, int num2);
    float divisao(int num1, int num2);

    int main(){

    int num1=0, num2=0, soma=0, sub=0, mult=0;
    char r;

    float divi=0;

    setlocale(LC_ALL,"");
    inicio:
    printf("Digite o 1° número: ");
    scanf("%d", &num1);

    printf("Digite o 2° número: ");
    scanf("%d", &num2);

    //CHAMANDO AS FUNÇÕES DENTRO DO MAIN
    soma = somar(num1, num2);
    sub = subtrair(num1, num2);
    mult = multiplicar(num1, num2);
    divi = divisao(num1, num2);


    printf("\n%d + %d = %d",num1, num2, soma);
    printf("\n%d - %d = %d", num1, num2, sub);
    printf("\n%d * %d = %d", num1, num2, mult);
    printf("\n%d / %d = %.2f", num1, num2, divi);

        printf("\n\nDeseja continuar o programa?\n");
        printf("Pressione a tecla 1 para continuar no programa, caso contrário aperte qualquer outra tecla: \n");
        scanf("%c", &r);
        r = getchar();
        if(r == '1'){
            system("cls");
            goto inicio;
        }

    return 0;
    }

    //FUNÇÃO PARA SOMAR
    int somar(int num1, int num2){

    int soma;

    soma = num1+num2;

    return soma;
    }

    //FUNÇÃO PARA SUBTRAIR
    int subtrair(int num1, int num2){

    int sub;

    sub = num1-num2;

    return sub;
    }

    //FUNÇÃO PARA MULTIPLICAR
    int multiplicar(int num1, int num2){

    int mult;

    mult = num1*num2;

    return mult;
    }

    //FUNÇÃO PARA DIVIDIR
    float divisao(int num1,int num2){

    float divi=0;


    divi = (float) num1/ (float) num2;

    return  divi;
    }


#endif // ex4

#ifdef ex5

/*5 - Aproveitando o programa anterior, inclua a selecao das operacoes aritmeticas
    para transforma esse programa em uma calculadora. (utilize o comando switch).
    As operacoes aritmeticas devem ser funcoes. O resultado deve ser mostrado na
    funcao main()*/

    //CHAMANDO AS FUNÇÕES ANTES DO MAIN
    int somar(int num1, int num2);
    int subtrair(int num1, int num2);
    int multiplicar(int num1, int num2);
    float divisao(int num1, int num2);

    int main(){

    int num1=0, num2=0, soma=0, sub=0, mult=0, resultado=0;;
    char a, r;

    float divi=0;



    setlocale(LC_ALL,"");
    inicio:

    printf("Digite o 1° número: ");
    scanf("%d", &num1);

    do {
    printf("\nDigite o tipo de operação que você deseja ");
    scanf("\n%c", &a);

    if(a == '=') {

            break;

    }
    printf("\nDigite o 2° número: ");
    scanf("%d", &num2);



    switch(a){

    case '+':
        resultado = somar(num1, num2);
        printf("\n%d + %d = %d\n\n", num1, num2,somar(num1, num2));
        break;

    case '-':
        resultado = subtrair(num1, num2);
        printf("\n%d - %d = %d\n\n", num1, num2,subtrair(num1, num2));
        break;

    case '*':
        resultado = multiplicar(num1, num2);
        printf("\n%d * %d = %d\n\n", num1, num2, multiplicar(num1, num2));
        break;

    case '/':
        resultado = divisao(num1, num2);
        printf("\n%d / %d = %.2f\n\n", num1, num2, divisao((float)num1, (float)num2));
        break;
    }
    num1=resultado;

    }while(1==1);

    printf("\nResultado: %d", resultado);

        printf("\n\nDeseja continuar o programa?\n");
        printf("Pressione a tecla 1 para continuar no programa, caso contrário aperte qualquer outra tecla: \n");
        scanf("%c", &r);
        r = getchar();
        if(r == '1'){
            system("cls");
            goto inicio;
        }


    return 0;
    }

    //FUNÇÃO PARA SOMAR
    int somar(int num1, int num2){

    int soma;

    soma = num1+num2;

    return soma;
    }

    //FUNÇÃO PARA SUBTRAIR
    int subtrair(int num1, int num2){

    int sub;

    sub = num1-num2;

    return sub;
    }

    //FUNÇÃO PARA MULTIPLICAR
    int multiplicar(int num1, int num2){

    int mult;

    mult = num1*num2;

    return mult;
    }

    //FUNÇÃO PARA DIVIDIR
    float divisao(int num1,int num2){

    float divi=0;


    divi = (float)num1/(float)num2;

    return  divi;
    }
#endif // ex5
































