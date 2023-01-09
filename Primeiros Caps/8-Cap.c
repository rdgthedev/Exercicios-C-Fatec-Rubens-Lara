#define ex4
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


#ifdef ex1
/*1 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
funcao para compara-las usando ponteiros e retorne como resultado se
sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main().
Imprima o resultado na funcao main(). (Declare os vetores como variavel global)*/

char string1[11], string2[11];

//int compara();

int main()
{

    int retorno;


    setlocale(LC_ALL,"");
    printf("Digite a 1° string: ");
    scanf("%s", &string1);

    printf("Digite a 2° string: ");
    scanf("%s", &string2);

    printf("\n\nA primeira string foi: %s\n", string1);
    printf("A segunda string foi: %s\n\n", string2);

    retorno = compara();

    printf("\nO valor do retorno foi: %d\n\n", retorno);

    return 0;
}

int compara()
{

    char *p;
    int retorno, cont=0;

    p = &string1;

    while(p[cont] ==  string2[cont] && p[cont] != '\0' && string2[cont] != '\0')
    {
        cont++;
    }
    if(p[cont] == '\0' && string2[cont] == '\0')
    {
        retorno=1;
    }
    else
    {
        retorno=0;
    }


    return retorno;
}
#endif //ex1

#ifdef ex2

/*2 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
uma funcao que pesquise esta letra existe no vetor abaixo usando ponteiros.
Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
para a funcao a letra digitada usando ponteiros.(utilize o comando return).
O vetor deve ser declarado como variavel global.

vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y*/


char charvet[]= {'b','d','f','h','j','k','m','o','q','s','u','w','y'};
void pesq(char p);

int main()
{

    char letter;
    char *p;
    int resp=0;

    p = &letter;

    setlocale(LC_ALL,"");

    inicio:
    printf("Digite uma letra: ");
    scanf("\n%c", &p);


    pesq(p);

    printf("\n\nVocê deseja continuar no programa?\n\n");
    printf("1 - SIM\n");
    printf("2 - NÃO");
    printf("\n\nEscolha uma opção: ");
    scanf("%d", &resp);

    if(resp == 1)
    {
        system("cls");
        goto inicio;
    }
    else
    {
        system("cls");
        printf("\nEspero que você tenha tido uma ótima experiência\n");
        printf("Te espero mais vezes!\n\n");
    }

    return *p;
}

void pesq(char p)
{

    int cont, contaux=0, digito=0;

    for(cont=0; cont < 13; cont++)
    {

        if(p == charvet[cont])
        {
            contaux++;
        }
    }

    if (contaux > 0)
    {
        digito = printf("\n\nA letra digitada está no vetor\n\n");
    }
    else
    {
        digito = printf("\n\nA letra digitada não está no vetor\n\n");
    }

    return digito;
}
#endif //ex2

#ifdef ex3

/*3 - Escreva um programa que receba via teclado usando ponteiros um char,
int, long, unsigned, float, double, unsigned long e unsigned char,
e imprima-os no video utilizando ponteiros no seguinte formato:

        10        20        30        40        50        60
123456789012345678901234567890123456789012345678901234567890
    int                 long                unsigned
              float               double              char
         unsigned long       unsigned char*/

struct types
{

    char a;
    int b;
    long int c;
    unsigned int d;
    float e;
    double f;
    unsigned long int g;
    unsigned char h;
};

struct types vet[8];


int main()
{

    struct types *pa;
    struct types *pb;
    struct types *pc;
    struct types *pd;
    struct types *pe;
    struct types *pf;
    struct types *pg;
    struct types *ph;

    int resp=0;

    pa = &vet[0];
    pb = &vet[0];
    pc = &vet[0];
    pd = &vet[0];
    pe = &vet[0];
    pf = &vet[0];
    pg = &vet[0];
    ph = &vet[0];

    setlocale(LC_ALL,"");
inicio:
    printf("Char: ");
    getchar();
    scanf("%c", &(pa+0)->a);

    printf("\nInt: ");
    scanf("%d", &(pb+1)->b);

    printf("\nLong: ");
    scanf("%d", &(pc+2)->c);

    printf("\nUnsigned: ");
    scanf("%u", &(pd+3)->d);

    printf("\nFloat: ");
    scanf("%f", &(pe+4)->e);

    printf("\nDouble: ");
    scanf("%lf", &(pf+5)->f);

    printf("\nUnsigned Long: ");
    scanf("%lu", &(pg+6)->g);

    printf("\nUnsigned Char: ");
    getchar();
    scanf("%c", &(ph+7)->h);

    printf("\n\n            10        20        30        40        50        60\n");
    printf("    123456789012345678901234567890123456789012345678901234567890\n\n");
    printf("%9d %19d %19u\n",(pa+1)->b, (pc+2)->c, (pd+3)->d);
    printf("%22.2f %19.2f %16c\n", (pe+4)->e, (pf+5)->f, (pa+0)->a);
    printf("%14lu %19c\n\n", (pg+6)->g, (ph+7)->h);



    printf("\n\nVocê deseja continuar no programa?\n\n");
    printf("1 - SIM\n");
    printf("2 - NÃO");
    printf("\n\nEscolha uma opção: ");
    scanf("%d", &resp);


    if(resp == 1)
    {
        system("cls");
        goto inicio;
    }
    else
    {
        system("cls");
        printf("\nEspero que você tenha tido uma ótima experiência\n");
        printf("Te espero mais vezes!\n\n");
    }

    return 0;
}
#endif // ex3

#ifdef ex4

/*4 - Escreva um programa que contenha uma estrutura representando uma data
valida. Essa estrutura deve conter os campos dia, mes e ano. Em seguida,
leia duas datas e armazene nessa estrutura usando ponteiros. Calcule e exiba
o numero de dias que decorreram entre as duas datas usando ponteiros.
Utilize um vetor de estruturas.*/

struct data
{

    int dia;
    int mes;
    int ano;
};
struct data date[2];
struct data *p;
struct data *pexibe;

int main()
{

    int cont, calculadia=0, calculames=0, calculaano=0, resp=0;

    p = &date[0];

    setlocale(LC_ALL,"");
    inicio:
    printf("Insira a 1° data\n\n");
    printf("Dia: ");
    scanf("%d", &(p+0)->dia);
    printf("Mês: ");
    scanf("%d", &(p+0)->mes);
    printf("Ano: ");
    scanf("%d", &(p+0)->ano);

    printf("\n\nInsira a 2° data\n\n");
    printf("Dia: ");
    scanf("%d", &(p+1)->dia);
    printf("Mês: ");
    scanf("%d", &(p+1)->mes);
    printf("Ano: ");
    scanf("%d", &(p+1)->ano);

    calculadia = (p+0)->dia - (p+1)->dia;
    calculames = (p+0)->mes - (p+1)->mes;
    calculaano = (p+0)->ano - (p+1)->ano;



    if(calculadia < 0)
    {
        calculames -=1;
        calculadia +=30;
    }
    if(calculames < 0){
        calculaano -=1;
        calculames +=30;
    }
    if(calculaano < 0 ){
        printf("\n\nVocê digitou uma data inválida!");
    }

    pexibe = calculadia*1 + calculames*30 + calculaano*365;

    printf("\nAs datas digitas foram: \n\n");
    printf("%d/%d/%d\n",(p+0)->dia, (p+0)->mes, (p+0)->ano);
    printf("%d/%d/%d",(p+1)->dia, (p+1)->mes, (p+1)->ano);

    printf("\n\nA diferença de dias entre as duas datas é: %d dias\n\n",pexibe);

    printf("Você deseja continuar no programa?\n\n");
    printf("1 - SIM\n");
    printf("2 - NÃO\n\n");
    printf("Escolha uma opção: ");
    scanf("%d", &resp);

    if(resp == 1){
        system("cls");
        goto inicio;
    }

    return 0;
}
#endif // ex4

#ifdef ex5

/*5 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
recebidos no video numa usando ponteiros. Utilize um comando de loop.
O vetor de estruturas de ser declarado como variavel global
   estrutura: nome, end, cidade, estado, cep*/

struct dados
{

    char nome[100];
    char end[100];
    char cidade[50];
    char estado[3];
    char cep[10];
};

struct dados vet[4];
struct dados *pointer;

int main()
{

    int cont, resp=0;



    pointer = &vet[0];

    setlocale(LC_ALL,"");
inicio:
    printf("Insira seus dados\n\n");
    for(cont=0; cont < 4; cont++)
    {
        printf("Nome: ");
        scanf("\n%99[^\n]s", &(pointer+cont) -> nome);
        printf("Endereço: ");
        scanf("\n%99[^\n]s", &(pointer+cont)->end);
        printf("Cidade: ");
        scanf("\n%49[^\n]s", &(pointer+cont)->cidade);
        printf("Estado: ");
        scanf("\n%2[^\n]s", &(pointer+cont)->estado);
        printf("Cep: ");
        scanf("\n%9[^\n]s", &(pointer+cont)->cep);
        printf("\n");
    }

    system("cls");

    printf("Aqui estão todos os dados");
    for(cont=0; cont < 4; cont++)
    {
        printf("\n\nO nome da %d° pessoa é: %s", cont+1, (pointer+cont)->nome);
        printf("\nO endereço da %d° pessoa é: %s", cont+1, (pointer+cont)->end);
        printf("\nA cidade da %d° pessoa é: %s", cont+1, (pointer+cont)->cidade);
        printf("\nO estado da %d° pessoa é: %s", cont+1, (pointer+cont)->estado);
        printf("\nO cep da %d° pessoa é: %s", cont+1, (pointer+cont)->cep);
    }
    printf("\n\n");

    printf("Você deseja continuar no programa?\n\n");
    printf("1 - SIM\n");
    printf("2 - NÃO\n\n");
    printf("Escolha uma opção: ");
    scanf("%d", &resp);

    if(resp == 1)
    {
        system("cls");
        goto inicio;
    }

    return 0;
}
#endif // ex5

#ifdef ex6

/*6 - Escreva um programa que receba via teclado numeros inteiros positivos usando
ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
feitos usando ponteiro.*/

struct numbers
{

    int num[100];

};
struct numbers n;
struct numbers *pnumber;


int main()
{

    int cont=0, contaux=0, positivos=0, resp=0;
    float media=0;

    pnumber = &n;

    setlocale(LC_ALL,"");

inicio:
    contaux=0;
    positivos=0;
    for(cont=0; pnumber->num[cont-1] >= 0; cont++)
    {

        printf("Digite o %d° número: ", cont+1);
        scanf("%d", &pnumber->num[cont]);

        if(pnumber->num[cont] >= 0)
        {
            contaux++;
            positivos+=pnumber->num[cont];
        }
    }
    if(contaux == 0)
    {
        contaux=1;
    }
    media = (float)positivos / (float)contaux;

    printf("\n\nA média dos números é: %.2f\n\n", media);

    printf("Você deseja continuar no programa?\n\n");
    printf("1 - SIM\n");
    printf("2 - NÃO\n\n");
    printf("Escolha uma opção: ");
    scanf("%d", &resp);

    if(resp == 1)
    {
        system("cls");
        goto inicio;
    }


    return 0;
}
    #endif //ex6















































