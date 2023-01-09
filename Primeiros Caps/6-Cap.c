#define ex5
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



#ifdef ex1

    /*1 - Escreva um programa que receba via teclado 2 numeros inteiros e
    imprima-os no video com o resultado das 4 operacoes aritmeticas.*/

int main(){

    int num1=0, num2=0, adicao=0, sub=0,mult=0, resposta;
    float divi=0;

        setlocale(LC_ALL,"");
        inicio:
        printf("Digite um número: ");
        scanf("%d", &num1);

        printf("Digite um número: ");
        scanf("%d", &num2);


        adicao = num1 + num2;
        sub = num1 - num2;
        divi = (float)num1 / (float)num2;
        mult = num1 * num2;

        printf("\n\nA soma de %d + %d é igual a: %d\n",num1, num2, adicao);
        printf("A subtração de %d - %d é igual a: %d\n",num1, num2, sub);
        printf("A divisão de %d / %d é igual a: %.2f\n",num1, num2, divi);
        printf("A multiplicação de %d * %d é igual a: %d\n\n",num1, num2, mult);

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
#endif //ex1

#ifdef ex2

/*2 - Reescreva o exercicio anterior utilizando operadores de atribuicao
    composta.*/


int main(){

    int num1=0, num2=0, numaux, resposta;
    float num11=0, num22=0;

        setlocale(LC_ALL,"");
        inicio:
        printf("Digite um número: ");
        scanf("%d", &num1);

        printf("Digite um número: ");
        scanf("%d", &num2);

        numaux = num1;
        num1+= num2;
        printf("\n\nA soma de %d + %d é igual a: %d\n",numaux, num2, num1);

        num1 = numaux;
        num1 -= num2;
        printf("A subtração de %d - %d é igual a: %d\n",numaux, num2, num1);

        num1 = numaux;
        num11 = numaux;
        num11 /= (float)num2;
        printf("A divisão de %d / %d é igual a: %.2f\n",numaux, num2, num11);

        num1 = numaux;
        num1 *= num2;
        printf("A multiplicação de %d * %d é igual a: %d\n\n",numaux, num2, num1);

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
#endif // ex2

#ifdef ex3

/*3 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
    dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
    data (dia, mes e ano) atual.*/

    int main(){


    int dia, mes, ano, diatual,mesatual, anoatual, resposta, anoidade, mesidade, diaidade;

    setlocale(LC_ALL,"");

    inicio:
    printf("DATA DE NASCIMENTO\n\n");
    printf("Insira o dia em que você nasceu: ");
    scanf("%d", &dia);
    printf("Insira o mês em que você nasceu: ");
    scanf("%d", &mes);
    printf("Insira o ano em que você nasceu: ");
    scanf("%d", &ano);

    printf("\n\nDATA ATUAL\n\n");
    printf("Insira que dia é hoje: ");
    scanf("%d", &diatual);
    printf("Insira o mês atual: ");
    scanf("%d", &mesatual);
    printf("Insira o ano atual: ");
    scanf("%d", &anoatual);

    diaidade = diatual - dia;
    mesidade = mesatual - mes;
    anoidade = anoatual - ano;



    if(diaidade < 0){
        mesidade -= 1;
        diaidade += 30;

    }

    if(mesidade < 0){

        anoidade -=  1;
        mesidade += 12;
    }

    if(anoidade < 0){
       printf("\n\nVocê digitou datas inválidas!(ERRO: Data de Nascimento maior que Data Atual)");
       goto restart;
    }
    printf("\nVocê tem: %d anos, %d meses e %d dias", anoidade, mesidade, diaidade);

    restart:
    printf("\n\nDeseja continuar no programa?\n\n");
    printf("1 - SIM\n\n");
    printf("2 - NÃO\n\n");
    scanf("%d", &resposta);
    if(resposta == 1){
        system("cls");
        goto inicio;
    }
    return 0;
    }
#endif // ex3

#ifdef ex4

/*4 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
    as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
    video no formato decimal e hexadecimal.*/

    int num[2];

int main() {

    int cont;

    setlocale(LC_ALL,"");
    for(cont=0; cont<2; cont ++){

        printf("Digite %d° número: ", cont+1);
        scanf("%d", &num[cont]);
    }

    printf("\n\nAND\n");
    printf("Decimal: %d\n",num[0] & num[1]);
    printf("Hexadecimal: %x",num[0] & num[1]);

    printf("\n\nOU\n");
    printf("Decimal: %d\n",num[0] | num[1]);
    printf("Hexadecimal: %x",num[0] | num[1]);

    printf("\n\nOU EXCLUSIVO\n\n");
    printf("Decimal: %d\n",num[0] ^ num[1]);
    printf("Hexadecimal: %x",num[0] ^ num[1]);

return 0;
}
#endif // ex4


#ifdef ex5

/*5 - Escreva um programa que tem o menu abaixo na funcao main(). Receba via teclado
    a opcao do menu.
    Em cada opcao do menu receba o valor da temperatura e chama as funcoes de conversao
    e mostra resultado.
       1 - transforma graus Celsius em Fahrenheit e Kelvin
       2 - transforma graus Fahrenheit em Celsius e Kelvin
       3 - transforma graus Kelvin em Celsius e Fahrenheit*/

       int opcao, resposta;
       float celsius, fahrenheit, kelvin, celsius2, fahrenheit2, kelvin2, fahkelvin, cekelvin, kelvinfah;

       void menu();

       int main(){

        inicio:
        menu(); //FUNÇÃO MENU

        //CÁLCULOS / CONDIÇÕES DE EXIBIÇÃO
        celsius2 = celsius;
        cekelvin = celsius2 + 273.15;

        fahrenheit2 = fahrenheit;
        fahkelvin = (fahrenheit2 - 32)*5 /9 + 273.15;

        kelvin2 = kelvin;
        kelvinfah = (kelvin2 - 273.15)*9/5+32;

        celsius = (celsius * 9)/5+32;
        fahrenheit = (fahrenheit - 32)*5/9;
        kelvin = kelvin - 273.15;


        if(opcao == 1){
        printf("\n\nVOCÊ ESCOLHEU A OPÇÃO 1:\n");
        printf("CELSIUS PARA FAHRENHEIT: %.2f°F", celsius);
        printf("\nCELSIUS PARA KELVIN: %.2f K\n\n", cekelvin);
        }
        else if(opcao ==2){
        printf("\n\nVOCÊ ESCOLHEU A OPÇÃO 2:\n");
        printf("\nFAHRENHEIT PARA CELSIUS: %.2f°C", fahrenheit);
        printf("\nFAHRENHEIT PARA CELSIUS: %.2f K\n\n", fahkelvin);
        }else{
        printf("\n\nVOCÊ ESCOLHEU A OPÇÃO 3:\n");
        printf("\nKELVIN PARA CELSIUS: %.2f°C", kelvin);
        printf("\nKELVIN PARA FAHRENHEIT : %.2f K\n\n", kelvinfah);
        }
        printf("Deseja continuar?\n\n");
        printf("1 - SIM\n");
        printf("2 - NÃO\n");
        scanf("%d",&resposta);
        if(resposta == 1){
            system("cls");
            goto inicio;
        }

        return 0;
        }

       void menu(){

       setlocale(LC_ALL,"");
       do{
       printf("ESCOLHA UMA OPÇÃO QUE DESEJA FAZER A CONVERSÃO\n\n");
       printf("OPÇÃO 1 - CELSIUS PARA FAHRENHEIT E KELVIN\n");
       printf("OPÇÃO 2 - FAHRENHEIT PARA CELSIUS E KELVIN\n");
       printf("OPÇÃO 3 - KELVIN PARA CELSIUS E FAHRENHEIT\n\n");
       printf("Digite a opção que você deseja: ");
       scanf("%d", &opcao);
       system("cls");
       }while(opcao > 3 || opcao <1);

       switch(opcao){

           case 1:
               printf("\nDigite o quantidade de graus celsius que deseja converter: ");
               scanf("%f", &celsius);
               break;

            case 2:
               printf("\n\nDigite o quantidade de fahrenheits que deseja converter: ");
               scanf("%f", &fahrenheit);
               break;

            case 3:
               printf("\n\nDigite o quantidade de kelvins que deseja converter: ");
               scanf("%f", &kelvin);
               break;
       }
        return 0;
       }
#endif // ex5

































