#define ex1
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


#ifdef ex1

/*1 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada e o vetor usando ponteiros e faca a pesquisa
    usando ponteiros.(utilize o comando return).
    O vetor deve ser declarado como variavel LOCAL na funcao main().

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y*/

int pesq(char *pointer, char *p);

int main()
{

    static char charvet[13] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};
    char letter;
    char *p;
    char *pointer;
    int resp=0, retorno=0;


    pointer = &letter;
    p = &charvet[0];

    setlocale(LC_ALL,"");
    inicio:
    printf("Digite uma letra: ");
    scanf("%c", pointer);



    printf("\nA letra digitada foi: %c\n", *pointer);

    retorno = pesq(pointer, p);

    if(retorno == 1){
        printf("\nA letra digitada está no vetor\n\n");
    }
    else{
        printf("\nA letra digitada não está no vetor\n\n");
    }

    printf("\n\nVocê deseja continuar no programa?\n\n");
    printf("1 - SIM\n");
    printf("2 - NÃO");
    printf("\n\nEscolha uma opção: ");
    scanf("%d", &resp);

    if(resp == 1){
        system("cls");

        getchar();
        goto inicio;
    }
    else{
        system("cls");
        printf("\nEspero que você tenha tido uma ótima experiência\n");
        printf("Te espero mais vezes!\n\n");
    }


}

    int pesq (char *pointer, char *p){

    int cont, contaux=0, retorno=0;

    for(cont=0; cont < 13; cont++){
        if(*(p+cont) == *pointer){
            contaux++;
        }
    }

    if(contaux > 0){
        retorno = 1;
    }
    else{
        retorno = 0;

    }

    return retorno;
}
#endif // ex1

#ifdef ex2

/*2 - Escreva um programa que receba em uma funcao 2 strings de ate' 10 caracteres
    passando como parametro um ponteiro.
    Os vetores devem ser declarados como variaveis LOCAIS na função main().
    Escreva uma funcao para comparar as 2 strings. Passe como parametros para
    a funcao as 2 strings usando ponteiros e retorne como resultado se IGUAIS 1
    ou se DIFERENTES 0. Mostre o resultado no video na funcao main().*/

    void receber(char* p, char* ptr);
    int compara(char* p, char* ptr);


    int main(){

    static char vet1[11], vet2[11];
    char *p;
    char *ptr;
    int retorno=0, resp=0;

    p = &vet1;
    ptr = &vet2;

    setlocale(LC_ALL,"");
    inicio:


    receber(p, ptr);
    retorno = compara(p, ptr);

    if(retorno == 1){
        printf("As strings são iguais, portanto o retorno é: %d", retorno);
    }
    else{
        printf("As strings são diferentes, portanto o retorno é: %d", retorno);
    }


    printf("\n\n\nVocê deseja continuar no programa?\n\n");
    printf("1 - SIM\n");
    printf("2 - NÃO");
    printf("\n\nEscolha uma opção: ");
    scanf("%d", &resp);

    if(resp == 1){
        system("cls");
        goto inicio;
    }
    else{
        system("cls");
        printf("\nEspero que você tenha tido uma ótima experiência\n");
        printf("Te espero mais vezes!\n\n");
    }

    }

    void receber(char *p, char *ptr){

        printf("Digite a 1° string: ");
        scanf("%s", p);

        printf("Digite a 2° string: ");
        scanf("%s", ptr);

        printf("\n\nA primeira string foi: %s\n", p);
        printf("A segunda string foi: %s\n\n", ptr);

    }

    int compara(char *p, char *ptr){

        int cont=0, retorno=0;


        while(*(ptr+cont) == *(p+cont) && *(ptr+cont) != '\0' && *(p+cont) != '\0'){
            cont++;
        }
        if(*(ptr+cont) == '\0' && *(p+cont) == '\0'){
            retorno = 1;
        }
        else{
            retorno = 0;
        }

        return retorno;
    }

#endif // ex2

#ifdef ex3

/*3 - Escreva um programa que receba n valores via teclado e receba tambem a
    operação a ser executada. Quando for digitado "=" o programa deve mostrar
    o resultado acumulado dos n valores. As operações aritmeticas e a entrada
    de dados devem ser funcoes que recebe os valores usando ponteiros.
    As variaveis sao LOCAIS na funcao main().*/

#include<stdio.h>
#include<locale.h>

float operacoes(float *p1, float *p2, char *opcao);

int main(){

    int cont;
    float number1=0, number2=0;
    float resultado=0;
    int resp;
    float *p1;
    float *p2;
    char op;
    char *opcao;


    setlocale(LC_ALL,"");

    p1 = &number1;
    p2 = &number2;
    opcao = &op;

    inicio:

    recebe1(p1);

    for(;;){
        recebeOperador(opcao);

        if(*opcao == '='){
            break;
        }

        recebe3(p2);
        operacoes(p1, p2, opcao);
    }

        resultado = operacoes(p1, p2, opcao);

        printf("\n\nResultado: %.2f\n\n", resultado);

        printf("\nVocê deseja continuar no programa?\n\n");
        printf("1 - SIM\n");
        printf("2 - NÃO\n");
        scanf("%d", &resp);

        if(resp == 1){
            system("cls");
            goto inicio;
        }
}

void recebe1(float* p1){

    printf("Digite 1° número: ");
    scanf("%f", p1);
    printf("\n");
}

void recebeOperador(char* opcao){

    printf("Operação: ");
    getchar();
    scanf("%c", opcao);
}

void recebe3(float* p2){

    printf("\nDigite outro número: ");
    scanf("%f", p2);
}

float operacoes(float *p1, float *p2, char *opcao){

    float soma=0, multiplicacao=0, subtracao=0, n1=0, n2=0;
    float resultado=0;
    float divisao=0;

    switch(*opcao){
    case '+':
        soma = *p1+*p2;
        resultado = soma;
        printf("\n%.2f + %.2f = %.2f\n\n",*p1,*p2, soma);
        *p1 = resultado;
        break;

    case '-':
        subtracao= *p1-*p2;
        resultado=subtracao;
        printf("\n%.2f - %.2f = %.2f\n\n",*p1,*p2, subtracao);
        *p1 = resultado;
        break;

    case '/':
        divisao = (float)*p1 /(float)*p2;
        resultado = divisao;
        printf("\n%.2f / %.2f = %.2f\n\n",*p1,*p2, divisao);
        *p1 = resultado;
        break;

    case '*':
        n1 = *p1;
        n2 = *p2;
        multiplicacao = n1*n2;
        resultado = multiplicacao;
        printf("\n%.2f * %.2f = %.2f\n\n",*p1,*p2, multiplicacao);
        *p1 = resultado;
        break;
    }
    resultado = *p1;

    return resultado;
}
#endif // ex3

#ifdef ex4

    /*4 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    A estrutura e' uma variavel LOCAL na funcao main().Receba via teclado o
    conteudo de cada um dos membros numa funcao e imprima-os no video no
    seguinte formato(também numa função).

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
    };

    void main(){

    struct numbers n;
    struct numbers *p;
    int resp=0;

    p = &n;

    setlocale(LC_ALL,"");
    inicio:
    recebe(p);
    imprimir(p);

    printf("\n\nVocê deseja continuar?\n\n");
    printf("1 - SIM\n");
    printf("2 - NÃO\n\n");
    printf("Escolha uma opção: ");
    scanf("%d", &resp);

    if(resp == 1){
        system("cls");
        goto inicio;
    }
}

void recebe(struct numbers* p){

    printf("Char: ");
    scanf("\n%c", &p->a);

    printf("\nInt: ");
    scanf("%d", &p->b);

    printf("\nLong: ");
    scanf("%d", &p->c);

    printf("\nFloat: ");
    scanf("%f", &p->d);

    printf("\nDouble: ");
    scanf("%lf", &p->e);

    printf("\nUnsigned Char: ");
    getchar();
    scanf("%c", &p->f);

    printf("\nUnsigned Int: ");
    scanf("%u", &p->g);

    printf("\nUnsigned Long: ");
    scanf("%lu", &p->h);

}

void imprimir(struct numbers* p){

    printf("\n            10        20        30        40        50        60        70\n");
    printf("    1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("%9c %9d %9d %19.0f %19.0lf\n", p->a, p->b, p->c, p->d, p->e);
    printf("%15c %19u %19lu", p->f, p->g, p->h);

}
#endif //ex4

#ifdef ex5

    /*5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos como variavel LOCAL na funcao main(). Receba os 4 registros
    sequencialmente pelo teclado numa função e imprima todos os registros no
    video em outra funcao. Faça um menu. Utilize ponteiros nas funcoes.
    Coloque no menu a opção de sair tambem. Utilize o comando switch.
    (vetor de estruturas)
     estutura: nome, end, cidade, estado, cep*/

     struct dados{

        char nome[100];
        char end[50];
        char cidade[50];
        char estado[3];
        char cep[10];

     };

     int main(){

        struct dados vet[4];
        struct dados *p;
        int opcao;
        p = &vet[0];

        setlocale(LC_ALL,"");
        for(;;){
        printf("\n\t MENU\n\n");
        printf("1 - Inserir dados\n");
        printf("2 - Listar dados\n");
        printf("3 - Sair do programa\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        system("cls");
        option(opcao, p);
        }


     return opcao;
     }

     void option(int opcao, struct dados* p){

        int cont;

        switch(opcao){

    case 1:
        printf("\n\nVocê escolheu a opção 1\n");
        printf("Insira seus dados\n\n");

        for(cont=0; cont < 4; cont++){
        printf("Nome: ");
        scanf("%s", (p+cont)->nome);

        printf("Endereço: ");
        scanf("%s", (p+cont)->end);

        printf("Cidade: ");
        scanf("%s", (p+cont)->cidade);

        printf("Estado: ");
        scanf("%s", (p+cont)->estado);

        printf("CEP: ");
        scanf("%s", (p+cont)->cep);
        printf("\n");
        }
        break;

    case 2:
        for(cont=0; cont < 4; cont++){

        printf("%d° Nome: %s\n", cont+1, (p+cont)->nome);
        printf("%d° Endereço: %s\n", cont+1, (p+cont)->end);
        printf("%d° Cidade: %s\n", cont+1, (p+cont)->cidade);
        printf("%d° Estado: %s\n", cont+1, (p+cont)->estado);
        printf("%d° CEP: %s\n", cont+1, (p+cont)->cep);
        printf("\n");
        }
        break;

    case 3:
        exit(0);
        }
     }
#endif //ex5

#ifdef ex6

        struct dados{

        char nome[100];
        char end[50];
        char cidade[50];
        char estado[3];
        char cep[10];

     };

     int main(){

        struct dados vet[4];
        struct dados *p;
        int opcao;
        p = &vet[0];

        setlocale(LC_ALL,"");
        for(;;){
        printf("\n\t MENU\n\n");
        printf("1 - Inserir dados\n");
        printf("2 - Listar dados\n");
        printf("3 - Procurar dados\n");
        printf("4 - Alterar dados\n");
        printf("5 - Excluir dados\n");
        printf("6 - Sair do programa\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        system("cls");
        option(opcao, p);
        }


     return opcao;
     }

     void option(int opcao, struct dados* p){

        int cont, aux=0;
        char pesquisa[100];

        switch(opcao){

    case 1:
        printf("\n\nVocê escolheu a opção 1\n");
        printf("Insira seus dados\n\n");

        for(cont=0; cont < 4; cont++){
        printf("Nome: ");
        scanf("%s", (p+cont)->nome);

        printf("Endereço: ");
        scanf("%s", (p+cont)->end);

        printf("Cidade: ");
        scanf("%s", (p+cont)->cidade);

        printf("Estado: ");
        scanf("%s", (p+cont)->estado);

        printf("CEP: ");
        scanf("%s", (p+cont)->cep);
        printf("\n");
        }
        break;

    case 2:

        for(cont=0; cont < 4; cont++){

        printf("%d° Nome: %s\n", cont+1, (p+cont)->nome);
        printf("%d° Endereço: %s\n", cont+1, (p+cont)->end);
        printf("%d° Cidade: %s\n", cont+1, (p+cont)->cidade);
        printf("%d° Estado: %s\n", cont+1, (p+cont)->estado);
        printf("%d° CEP: %s\n", cont+1, (p+cont)->cep);
        printf("\n");
        }
        break;

    case 3:

        printf("Você escolheu a opção 3\n");
        printf("Pesquise dados usando o nome\n\n");
        printf("Digite um nome: ");
        scanf("%s", &pesquisa);

        for(cont=0; cont < 4; cont++){
        for(cont=0; pesquisa[cont] != '\0'; cont++){
            if(pesquisa[cont] != (p+cont)->nome[cont]){
               aux++;
               break;
            }
            if(pesquisa[cont] == '\0' && (p+cont)->nome[cont] == '\0'){

                printf("%d° Nome: %s\n", cont+1, (p+cont)->nome);
                printf("%d° Endereço: %s\n", cont+1, (p+cont)->end);
                printf("%d° Cidade: %s\n", cont+1, (p+cont)->cidade);
                printf("%d° Estado: %s\n", cont+1, (p+cont)->estado);
                printf("%d° CEP: %s\n", cont+1, (p+cont)->cep);
            }

        }
        }
        break;

    case 6:
        exit(0);
        }
     }
#endif //ex6














