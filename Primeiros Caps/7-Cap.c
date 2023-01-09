#define ex1
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#ifdef ex1

/*1 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estruturas de 4 elementos. Receba os dados pelo teclado e imprima-os no
    video. Faça um menu. (vetor de estruturas)
		estrutura: nome, end, cidade, estado, cep */

struct dados{

    char nome[100];
    char end [100];
    char cidade[10];
    char estado[3];
    char cep[10];

};
struct dados user[4];

int aux=0;

int main(){

int opcao=0, menuu;
for(;;){
setlocale(LC_ALL,"");
printf("\n\tMENU\n\n");
printf("1 - Inserir dados\n");
printf("2 - Listar dados\n");
printf("3 - Sair do programa\n\n");
printf("Escolha uma opção: ");
scanf("%d", &opcao);
getchar();
system("cls");

menuu = menu(opcao);
}
return opcao;
}

int menu(int opcao){

    int cont;

switch(opcao){
case 1:

    printf("\n\nVocê escolheu a opção 1\n");
    printf("Insira seus dados\n\n");


    if(aux < 4){
    printf("Nome: \n");
    scanf("%s", &user[aux].nome);
    printf("Endereço: \n");
    scanf("%s", &user[aux].end);
    printf("Cidade: \n");
    scanf("%s", &user[aux].cidade);
    printf("Estado: \n");
    scanf("%s", &user[aux].estado);
    printf("Cep: \n");
    scanf("%s", &user[aux].cep);
    aux++;
    }
    break;

case 2:

    printf("\n\nVocê escolheu a opção 2\n");
    printf("Seus dados foram imprimidos na tela\n\n");

    for(cont=0; cont < aux; cont++){
    printf("\n\nNome: %s\n", user[cont].nome);
    printf("Endereço: %s\n", user[cont].end);
    printf("Cidade: %s\n", user[cont].cidade);
    printf("Estado: %s\n", user[cont].estado);
    printf("Cep: %s\n", user[cont].cep);
}
    break;

case 3:
    exit(0);
}
}
#endif // ex1

#ifdef ex2

/*2 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    Receba dados via teclado em uma funcao e imprima estes conteudos no video,
    em outra funcao, no seguinte formato.
     estrutura: char, int, long, float, double, unsigned char, unsigned int,
                unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long*/

struct numbers{

    char a;
    int b;
    long int c;
    float d;
    double e;
    unsigned char f;
    unsigned int g;
    unsigned long int h;
    int resp;
};

struct numbers org;

int main(){

    setlocale(LC_ALL,"");
    inicio:
    printf("Char: ");
    scanf("\n%c", &org.a);

    printf("\nInt: ");
    scanf("%d", &org.b);

    printf("\nLong: ");
    scanf("%d", &org.c);

    printf("\nFloat: ");
    scanf("%f", &org.d);

    printf("\nDobule: ");
    scanf("%lf", &org.e);

    printf("\nUnsigned Char: ");
    getchar();
    scanf("%c", &org.f);


    printf("\nUnsigned Int: ");
    scanf("%u", &org.g);

    printf("\nUnsigned Long: ");
    scanf("%lu", &org.h);

    printf("\n");


    printf("            10        20        30        40        50        60        70\n");
    printf("    1234567890123456789012345678901234567890123456789012345678901234567890");
    printf("\n%9c %9lu %9ld %29.0f %9.0lf\n", org.a, org.b, org.c, org.d, org.e);
    printf("%15c %19u %19lu", org.f, org.g, org.h);


    printf("\n\nVocê deseja continuar no programa?\n\n");
    printf("1 - SIM\n");
    printf("2 - NÃO");

    printf("\n\nEscolha uma opção: ");
    scanf("%d", &org.resp);

    if(org.resp == 1){
      system("cls");
      goto inicio;
    }
    else{
        system("cls");
        printf("\n\nVocê encerrou o programa!\n\n");
    }

return 0;
}
#endif //ex2

#ifdef ex3

/*3 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estrutura de 4 elementos. Receba dados via teclado e imprima-os no video.
    Faça um menu com as seguintes opcoes:
    1 - receber todos os dados
    2 - imprime todos os dados
    3 - calcula o IMC de todas as pessoas.
    4 - sair
        Calculo do IMC = peso/(altura*altura).
        estrutura: nome, peso, altura*/

struct pessoa{
    char nome[100];
    float peso;
    float altura;
};
struct pessoa dados[4];



int main(){

    int opcao=0, menuu;
    setlocale(LC_ALL,"");
    for(;;){
    printf("\n\tMENU\n\n");
    printf("1 - Receber todos os dados\n");
    printf("2 - Mostrar todos os dados\n");
    printf("3 - Calcular o IMC de todas as pessoas\n");
    printf("4 - Sair do programa\n\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    while(opcao < 1 || opcao > 4){
        printf("\n\nOpção inválida!\n");
        printf("Por favor digite um número de 1 a 4: ");
        scanf("%d", &opcao);
    }
    system("cls");
    menuu= menu(opcao);
    }
return opcao;
}

int menu(int opcao){

    int cont;
    float imc;

    switch(opcao){
case 1:

    printf("Você escolheu a opção 1\n");
    printf("Insira seus dados\n\n");

    for(cont=0; cont < 4; cont++){
    printf("%d° Nome: ", cont+1);
    scanf("%s", &dados[cont].nome);


    printf("%d° Peso: ", cont+1);
    scanf("%f", &dados[cont].peso);
    getchar();

    printf("%d° Altura: ", cont+1);
    scanf("%f", &dados[cont].altura);

    printf("\n");
    }
    break;

case 2:
    printf("Você escolheu a opção 2\n");
    printf("Aqui estão os dados de todas as pessoas\n\n");
    for(cont=0; cont < 4; cont++){
    printf("%d° Nome: %s", cont+1, dados[cont].nome);
    printf("\n%d° Peso: %.2f", cont+1, dados[cont].peso);
    printf("\n%d° Altura: %.2f", cont+1, dados[cont].altura);

    printf("\n\n");
    }
    break;

    case 3:
    printf("Você escolheu a opção 3\n");
    printf("Aqui estão os IMC's de todas as pessoas\n\n");
    for(cont=0; cont < 4; cont++){
        imc = dados[cont].peso/(dados[cont].altura*dados[cont].altura);
        printf("O imc da %d° pessoa é: %.2f", cont+1,imc);
        printf("\n\n");
    }
    break;

    case 4:
        printf("\n\nEspero que tenha gostado da experiência\n");
        printf("Te esperamos mais vezes!\n\n");
        exit(0);
    }
}
#endif // ex3

#ifdef ex4

/*4 - Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via
    teclado e calculo, o numero de dias entre elas e mostre o resultado no
    video. (vetor de estruturas)
                dia, mes, ano*/

     struct data{
       int dia;
       int mes;
       int ano;
     };
     struct data date[2];

    int main(){

    int cont, calculadia=0, calculames=0, calculaano=0, resp=0, diferencadias=0;

    setlocale(LC_ALL,"");
    inicio:
    for(cont=0; cont < 2; cont++){
    if(cont==0){
        printf("\n\nInsira uma data\n\n");
    }
    else{
        printf("\n\nInsira outra data\n\n");
    }
    printf("Dia: ");
    scanf("%d", &date[cont].dia);
    printf("Mes: ");
    scanf("%d", &date[cont].mes);
    printf("Ano: ");
    scanf("%d", &date[cont].ano);
    }

    calculadia = date[0].dia - date[1].dia;
    calculames = date[0].mes - date[1].mes;
    calculaano = date[0].ano - date[1].ano;

    if(calculadia < 0){
        calculames -=1;
        calculadia +=30;
    }
    if(calculames < 0){
        calculaano -=1;
        calculames +=12;
    }

        if(calculaano < 0){
       printf("\n\nVocê digitou datas inválidas!(ERRO: A primeira ata maior que a segunda data)");
       goto restart;
    }
    diferencadias = calculaano*365 + calculames*30 + calculadia*1;


    printf("\nA diferença em dias entre as duas data é de: %d dias", diferencadias);

    restart:
    printf("\n\nDeseja continuar no programa?\n\n");
    printf("1 - SIM\n");
    printf("2 - NÃO\n\n");
    printf("Escolha uma opção: ");
    scanf("%d", &resp);
    if(resp == 1){
        system("cls");
        goto inicio;
    }
    else{
        system("cls");
        printf("\n\nVocê encerrou o programa!\n");
        printf("Espero que tenha gostado da experiência.\n\n");
    }
    return 0;
    }
#endif // ex4


















































































































