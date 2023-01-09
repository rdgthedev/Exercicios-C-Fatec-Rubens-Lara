#define ex5
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


#ifdef ex1

/*1 - As ligacoes telefonicas são cobradas pela sua duracao. O sistema registra os
    instantes em que a ligacao foi iniciada e concluida.
    Escreva um programa que recebe via teclado dois instantes dados em
    horas, minutos e segundo e determina o intervalo de tempo
    (em horas, minutos e segundos) decorrido entre eles. */


int h1, m1, s1, h2, m2, s2, h0, hf, duracao, hd, md, sd;
char r;



int main()
{

    setlocale(LC_ALL, "");
    inicio:
    printf("INICIO DA LIGAÇÃO\n\n");

    printf("Hora: ");
    scanf("%d", &h1);

    printf("\nMinutos: ");
    scanf("%d", &m1);

    printf("\nSegundos: ");
    scanf("%d", &s1);

    printf("\nTERMINO DA LIGAÇÃO\n\n");

    printf("Hora: ");
    scanf("%d", &h2);

    printf("\nMinutos: ");
    scanf("%d", &m2);

    printf("\nSegundos: ");
    scanf("%d", &s2);

    h1 = h1 * 3600;
    h2 = h2 * 3600;

    m1 = m1 * 60;
    m2 = m2 * 60;

    h0 = h1 + m1 + s1;
    hf = h2 + m2 + s2;

    duracao = hf - h0;

    hd = duracao/3600;
    duracao = duracao - hd*3600;

    md = duracao/60;
    duracao = duracao - md*60;

    sd = duracao;

    printf("\nA duração da sua chamada foi de: %d:%.2d:%.2d", hd, md, sd);

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
#endif //ex1

#ifdef ex2

/*2 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
    pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
    comando if-else. */

    int min = 1, max = 99, num, r;
    char c;


        int main(){

        setlocale(LC_ALL,"");
        while(c!='=')
            {
            inicio:
            printf("\O numero é maior, menor ou igual a %d ?" , num=(max+min)/2);
            scanf("\n%c",&c);

            if(c=='>')
            {
            min = num;
            num=(max+min)/2;
            getchar();
            }

            else if(c=='<')
            {
            max = num;
            num=(max+min)/2;
            getchar();
            }
            }


        printf("\nSeu número é igual a: %d\n",num);

        printf("\n\nDeseja continuar o programa?\n");
        printf("Pressione a tecla 1 para continuar no programa, caso contrário aperte qualquer outra tecla: \n");
        scanf("%c", &r);
        r=getchar();
        if(r == '1'){
            min=1;
            max=99;
            system("cls");
            goto inicio;
        }

    return 0;

        }
#endif // ex2

#ifdef ex3

/*3 - Reescreva o programa do exercicio anterior agora utilizando o comando switch.
    Conte o n. de tentativas e imprima o resultado no video.*/


    int min = 1, max = 99, num;
    char c, r;

        int main(){

        setlocale(LC_ALL,"");
        while(c!='=')
            {
            inicio:
            printf("\O numero é maior, menor ou igual a %d ?" , num=(max+min)/2);
            scanf("\n%c",&c);

            switch(c)
            {
            case '>':

            min = num;
            num=(max+min)/2;
            getchar();
            break;

            case '<':

            max = num;
            num=(max+min)/2;
            getchar();
            break;
            }
            }

        printf("\nSeu número é igual a: %d\n",num);

        printf("\n\nDeseja continuar o programa?\n");
        printf("Pressione a tecla 1 para continuar no programa, caso contrário aperte qualquer outra tecla: \n");
        scanf("%c", &r);
        r=getchar();
        if(r == '1'){
            min=1;
            max=99;
            system("cls");
            goto inicio;
        }

        return 0;
        }
#endif // ex3

#ifdef ex4


/* 4 - Escreva um programa que receba via teclado numeros inteiros positivos.
    Quando o numero digitado for negativo o programa deve parar e calcula a
    media dos valores positivos digitados. */


    int main(){

    int num=1,cont=0;
    float calcula=0, media=0;
    char r;

    setlocale(LC_ALL, "");
    inicio:
    for(cont=0;num>0;cont++){
        printf("Digite um número inteiro: ");
        scanf("%d", &num);
        if(num > 0){
        calcula += num;
        }
    }

    media = calcula/(cont-1);

    printf("\nA média dos números é: %.2f", media);

    printf("\n\nDeseja continuar o programa?\n");
    printf("Pressione a tecla 1 para continuar no programa, caso contrário aperte qualquer outra tecla: \n");
    scanf("%c", &r);
    r = getchar();
        if(r == '1'){
            num=1;
            calcula=0;
            media=0;
            system("cls");
            goto inicio;
        }
    return 0;
    }


#endif // ex4

#ifdef ex5

    /*5 - Um posto está vendendo combustíveis com a seguinte tabela de descontos:
     Álcool até 20 litros, desconto de 3% por litro acima de 20 litros, desconto de 5% por litro
     Gasolina até 20 litros, desconto de 4% por litro acima de 20 litros, desconto de 6% por litro
     Escreva um programa que leia o número de litros vendidos e o tipo de combustível (codificado da seguinte forma: A-álcool, G-gasolina).
     Calcule e imprima o valor a ser pago pelo cliente sabendo-se que o preço do litro da gasolina é R$ 5,88 e o preço do litro do álcool é R$ 4,18. */


float litros=0, alcool = 4.18,gasolina = 5.88, precoalc=0, precogas=0, descalc=0, descgas=0, desctotal=0, subtotal=0, total=0, lalc=0, lgas=0;

char c;

int main()
{
    setlocale(LC_ALL,"");

    inicio:

    printf("Digite a quantidade de litros que você deseja: ");
    scanf("%f", &litros);

    while(litros <= 0) {
        printf("\nA quantidade de litros deve ser maior que 0: ");
        scanf("%f", &litros);
    }

    do {
        printf("Digite o tipo de combustível que você deseja: ");
        scanf("%c", &c);
        c = getchar();
    } while(c != 'a' && c!= 'g');

    if(c == 'a') {
        lalc += litros;
    } else if (c == 'g'){
        lgas += litros;
    }

    abastecerdnv:

    printf("\nDeseja abastecer novamente (s/n)? ");
    scanf("%c", &c);
    c=getchar();

    if (c != 's' && c != 'n'){
        goto abastecerdnv;
    } else if (c == 's') {
        printf("\n");
        goto inicio;
    } else {
        if (lalc<=20){
            descalc = 0.03;
        } else {
            descalc = 0.05;
        }
        if (lgas<=20){
            descgas = 0.04;
        } else {
            descgas = 0.06;
        }
        precoalc = alcool*lalc;
        precogas = gasolina*lgas;
        subtotal = precoalc + precogas;
        desctotal = precoalc*descalc + precogas*descgas;
        total = subtotal - desctotal;


        system("cls");
        printf("\n\n    POSTO RODRIGUINHO CARRARA\n\n");
        if (lalc != 0) {
            printf("%.2fL\tAlcool\t\tR$ %.2f\n",lalc,precoalc);
        }
        if (lgas != 0) {
            printf("%.2fL\tGasolina\tR$ %.2f\n",lgas,precogas);
        }
        printf("\n\tSUBTOTAL\tR$ %.2f\n",subtotal);
        printf("\tDESCONTO\tR$ %.2f\n",desctotal);
        printf("\tTOTAL\t\tR$ %.2f\n\n\n",total);

    }
        printf("\n\nDeseja continuar o programa?\n");
        printf("Pressione a tecla 1 para continuar no programa, caso contrário aperte qualquer outra tecla: \n");
        scanf("%c", &c);
        c = getchar();
        if(c == '1'){
            litros=0;
            precoalc=0;
            precogas=0;
            descalc=0;
            descgas=0;
            desctotal=0;
            subtotal=0;
            total=0;
            lalc=0;
            lgas=0;
            system("cls");
            goto inicio;
        }

    return 0;
}s
#endif // ex5

