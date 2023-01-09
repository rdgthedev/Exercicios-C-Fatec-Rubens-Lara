#define ex5
#include <stdio.h>
#include <locale.h>
#include<stdlib.h>

#ifdef ex1


/*1 - Escreva um programa que receba via teclado um tempo em segundos e converta
    para horas, minutos e segundos.
    Ex.: recebe 3850 segundos que converte para 1h 4min 10s. */


int main(){

int hora, min, seg, hora2, resto;
    setlocale(LC_ALL, "");


    inicio:
    printf("Digite a quantidade de segundos que deseja converter: \n");
    scanf("%d", &hora2);


    hora = hora2/3600;
    resto = hora2 % 3600;
    min = resto / 60;
    seg = resto % 60;

    printf("A quantidade de segundos convetidos é: %dh %dm %ds\n", hora, min, seg);

    }
return 0;
}
#endif //ex1

#ifdef ex2


/*2 - Escreva um programa que receba dados via teclado para variaveis do tipo short,
    long, int, float, double e um char e imprima-os no video no seguinte
    formato: */



    int main(){

    short int s;
    float f;
    long int l;
    double d;
    int i;
    char a;


    inicio:
    setlocale(LC_ALL,"");
    printf("Short: ");
    scanf("%d", &s);

    printf("float:");
    scanf("%f", &f);

    printf("Long: ");
    scanf("%d", &l);

    printf("Double: ");
    scanf("%lf", &d);

    printf("Int: ");
    scanf("%d", &i);

    printf("Char: ");
    scanf("\n%c", &a);


    printf("\n        10        20        30        40        50        60\n");
    printf("12345678901234567890123456789012345678901234567890123456789012345\n");
    printf("%10hd   %17ld    %16lu\n",s,l,i);
    printf("%20.2f   %17.0f   %17c\n",f,d,a);

    }
    return 0;
    }

  #endif // ex2


  #ifdef ex3

  /*3 - Escreva um programa que determine o menor multiplo de um numero inteiro. Este
    multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
    teclado.
    Ex: menor multiplo de 13 maior que 100. Resultado: 104. */


   int main(){

    int num1=0, num2=0,vtotal=0, cont=0;


    setlocale(LC_ALL,"");

    inicio:
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("\nDigite o limite mínimo: ");
    scanf("%d", &num2);

    for(cont=0; vtotal < num2; cont++){
    vtotal = num1 * cont;
    }

    printf("\nMenor multiplo de %d maior que %d. Resultado: %d\n",num1, num2, vtotal);

    return 0;
    }






  #endif // ex3


  #ifdef ex4

  /*4 - Escreva um programa que permute o conteúdo de duas variáveis sem utilizar uma
    variável auxiliar. */



int main()
{

    int a, b;

    setlocale(LC_ALL,"");
    inicio:
    printf("Digite o primeiro número: ");
    scanf("%d", &a);

    printf("Digite o segundo número: ");
    scanf("%d", &b);


    a = a + b;
    b = a - b;
    a = a - b;


    printf("\nO primeiro número é: %d\n", a);
    printf("O segundo número é: %d\n", b);

    return 0;
}


  #endif // ex4

  #ifdef ex5

  /*5 - Escreva um programa que lê um valor em reais e calcula qual o menor número
    possível de notas de $100, $50, $20, $10, $5, $2 e $1 em que o valor lido pode
    ser decomposto. Escrever o valor lido e a relação de notas necessárias. */

 int main(){

  int v100, v50, v20, v10, v5, v2, v1, valor;
    setlocale(LC_ALL,"");

    inicio:
    printf("Escreva o valor que deseja: ");
    scanf("%d", &valor);

    //ATRIBUIÇÃO DE VALORES ÀS VARIÁVEIS
    v100 = valor / 100;
    valor = valor - v100 * 100;

    v50 = valor / 50;
    valor = valor - v50 * 50;

    v20 = valor / 20;
    valor = valor - v20 * 20;

    v10 = valor / 10;
    valor = valor - v10 * 10;

    v5 = valor / 5;
    valor = valor - v5 * 5;

    v2 = valor / 2;
    valor = valor - v2 * 2;

    v1 = valor;


    printf("\nA quantidade de notas de 100 é: %d\n", v100);
    printf("A quantidade de notas de 50 é: %d\n", v50);
    printf("A quantidade de notas de 20 é: %d\n", v20);
    printf("A quantidade de notas de 10 é: %d\n", v10);
    printf("A quantidade de notas de 5 é: %d\n", v5);
    printf("A quantidade de notas de 2 é: %d\n", v2);
    printf("A quantidade de notas de 1 é: %d\n", v1);

return 0;
 }
  #endif // ex5










