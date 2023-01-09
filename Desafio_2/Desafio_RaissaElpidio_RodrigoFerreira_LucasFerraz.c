#include <stdio.h>
#include <locale.h>

struct datas{
    char music[100];
    char author[100];
    float price;
    int quantity;

};

int main(){

    struct datas sound;
    struct datas* p;
    int opcao;

    p = &sound;

    setlocale(LC_ALL,"");

    for(;;){
        printf("\t\t***************\n");
        printf("\t\t***DESAFIO 2***\n");
        printf("\t\t***************\n\n");

        printf("1 - Inserir dados da música\n");
        printf("2 - Listar todas as músicas\n");
        printf("3 - Pesquisar uma música pelo nome completo\n");
        printf("4 - Pesquisar o autor da música pelo nome completo\n");
        printf("5 - Pesquisar por faixa de preço\n");
        printf("6 - Alterar quantidade (entrada e saída) pesquisando pelo nome completo\n");
        printf("7 - Alterar o preço de uma música pesquisando pelo nome completo\n");
        printf("8 - Alterar dados, pesquisando pelo nome completo\n");
        printf("9 - Excluir dados, pesquisando pelo nome completo\n");
        printf("10 - Sair do programa\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao){

        case 1:
            system("cls");
            insert(p);
            break;

        case 2:
            system("cls");
            list(p);
            break;

        case 3:
            system("cls");
            searchMusic(p);
            break;

        case 4:
            system("cls");
            searchAuthor(p);
            break;

        case 5:
            system("cls");
            searchPrice(p);
            break;

        case 6:
            system("cls");
            changeQuantity(p);
            break;

        case 7:
            system("cls");
            changePrice(p);
            break;

        case 8:
            system("cls");
            changeDatas(p);
            break;

        case 9:
            system("cls");
            deleteDatas(p);
            break;

        case 10:
            system("cls");
            exitt();
            break;
        }
    }
}

void insert(struct datas* p){

    FILE* fp;

    if((fp = fopen("Desafio.txt", "a"))==NULL){
        printf("Erro no arquivo!");
        exit(0);
    }

    printf("Música: ");
    getchar();
    gets(p->music);
    printf("Autor: ");
    gets(p->author);
    printf("Preço: ");
    scanf("%f", &p->price);
    printf("Quantidade: ");
    scanf("%d", &p->quantity);
    getchar();
    printf("\n\n");

    fwrite(p, sizeof(*p), 1, fp);
    fclose(fp);
}

void list(struct datas* p)
{

    FILE* fp;
    int y;

    if((fp = fopen("Desafio.txt", "r"))==NULL){
        printf("Erro no arquivo!");
        exit(0);
    }

    for(;;){
        y = fread(p, sizeof(*p), 1, fp);

        if(y == 0){
            break;
        }

        if(p->music[0] != '*'){
            printf("\nMúsica: %s\n", p->music);
            printf("Autor: %s\n", p->author);
            printf("Preço: %.2f\n", p->price);
            printf("Quantidade: %d\n\n", p->quantity);
        }
    }
    fclose(fp);
}

void searchMusic(struct datas* p)
{

    FILE* fp;
    char searchAUX[100];
    int x, y;

    if((fp = fopen("Desafio.txt", "r"))==NULL){
        printf("Erro no arquivo!");
        exit(0);
    }

    printf("Digite o nome completo da música que deseja pesquisar\n\n");
    printf("Nome: ");
    getchar();
    gets(searchAUX);

    for(;;){
        y = fread(p, sizeof(*p), 1, fp);

        if(y == 0){
            printf("\nMúsica não encontrada!\n\n");
            break;
        }

        for(x=0; searchAUX[x] != '\0'; x++){
            if(searchAUX[x] != p->music[x]){
                break;
            }
        }
        if(searchAUX[x] == '\0' && p->music[x] == '\0'){
            printf("\nInformações da música pesquisada\n\n");
            printf("Música: %s\n", p->music);
            printf("Autor: %s\n", p->author);
            printf("Preço: %.2f\n", p->price);
            printf("Quantidade: %d\n\n", p->quantity);
            break;
        }
    }
    fclose(fp);
}

void searchAuthor(struct datas* p){

    FILE* fp;
    char authorAUX[100];
    int x, y;

    printf("Digite o nome completo do autor que deseja pesquisar\n\n");
    printf("Nome: ");
    getchar();
    gets(authorAUX);

    if((fp = fopen("Desafio.txt", "r"))==NULL){
        printf("Erro no arquivo!");
        exit(0);
    }

    for(;;){
        y = fread(p, sizeof(*p), 1, fp);

        if(y == 0){
            printf("\nAutor não encontrado!\n\n");
            break;
        }

        for(x=0; authorAUX[x] != '\0'; x++){
            if(authorAUX[x] != p->author[x]){
                break;
            }
        }
        if(authorAUX[x] == '\0' && p->author[x] == '\0'){
            printf("\nInformações do autor pesquisado\n\n");
            printf("Música: %s\n", p->music);
            printf("Autor: %s\n", p->author);
            printf("Preço: %.2f\n", p->price);
            printf("Quantidade: %d\n\n", p->quantity);
            break;
        }
    }
    fclose(fp);
}

void searchPrice(struct datas* p){

    FILE* fp;
    float priceAUX1, priceAUX2;
    int y;
    int cont=0;

    printf("Digite a faixa de preço: ");
    scanf("%f", &priceAUX1);

    printf("Digite a faixa de preço: ");
    scanf("%f", &priceAUX2);




    if((fp = fopen("Desafio.txt", "r"))==NULL){
        printf("Erro no arquivo!");
        exit(0);
    }

    for(;;){

        y = fread(p, sizeof(*p), 1, fp);

        if(y == 0){
            if(cont == 0){
            printf("\nNão há músicas com nessa faixa de preço!\n\n");
            }
            break;
        }

        if(priceAUX1 <= p->price && priceAUX2 >= p->price){

            if(p->music[0] != '*'){
                printf("\nMúsicas com esta faixa de preço\n\n");
                printf("Música: %s\n", p->music);
                printf("Autor: %s\n", p->author);
                printf("Preço: %.2f\n", p->price);
                printf("Quantidade: %d\n\n", p->quantity);
                cont++;
            }
        }

    }
    fclose(fp);
}

void changeQuantity(struct datas* p){

    FILE* fp;
    char quantityAUX[100], op;
    int x, y, nRegisters=0, quantityValueAUX=0;
    long k;

    printf("Digite o nome completo da música que deseja alterar a quantidade\n\n");
    printf("Nome: ");
    getchar();
    gets(quantityAUX);


    if((fp = fopen("Desafio.txt", "r+"))==NULL){
        printf("Erro no arquivo!");
        exit(0);
    }

    for(;;){
        y = fread(p, sizeof(*p), 1, fp);

        if(y == 0){
            printf("\nMúsica não encontrada!\n\n");
            break;
        }

        for(x=0; quantityAUX[x] != '\0'; x++){
            if(quantityAUX[x] != p->music[x]){
                break;
            }
        }

        if(quantityAUX[x] == '\0' && p->music[x] == '\0'){
            printf("\nInformações da música que deseja alterar o preço\n\n");
            printf("Música: %s\n", p->music);
            printf("Autor: %s\n", p->author);
            printf("Preço: %.2f\n", p->price);
            printf("Quantidade: %d\n\n", p->quantity);


            do{
            printf("Digite o operador (+ ou -): ");
            scanf("%c", &op);
            }while(op != '+' && op != '-');

            do{
                printf("\nDigite a quantidade que você deseja: \n");
                scanf("%d", &quantityValueAUX);
            }
            while(quantityValueAUX < 0);



            switch(op){

            case '+':
                system("cls");
                printf("\nInformações da música\n\n");
                printf("Música: %s\n", p->music);
                printf("Quantidade anterior: %d\n", p->quantity);
                p->quantity = p->quantity + quantityValueAUX;
                printf("Nova quantidade: %d\n\n", p->quantity);

                k = nRegisters * sizeof(*p);
                fseek(fp, k, 0);
                fwrite(p, sizeof(*p), 1, fp);
                break;

            case '-':
                system("cls");

                printf("\nInformações da música\n\n");
                printf("Música: %s\n", p->music);
                printf("\nQuantidade anterior: %d\n\n", p->quantity);
                p->quantity = p->quantity - quantityValueAUX;
                printf("Nova quantidade: %d\n\n", p->quantity);


                k = nRegisters * sizeof(*p);
                fseek(fp, k, 0);
                fwrite(p, sizeof(*p), 1, fp);
                break;
            }
            break;

        }
        nRegisters++;
    }
    fclose(fp);
}

void changePrice(struct datas* p)
{

    FILE* fp;
    char changeValue[100];
    int x, y, nRegisters=0;
    long k;
    int cont=0;

    printf("Digite o nome completo da música que deseja alterar o preço\n\n");
    printf("Nome: ");
    getchar();
    gets(changeValue);

    if((fp = fopen("Desafio.txt", "r+"))==NULL){
        printf("Erro no arquivo!");
        exit(0);
    }

    for(;;){
        y = fread(p, sizeof(*p), 1, fp);

        if(y == 0){
                if(cont == 0){
                    printf("\nNenhuma música encontrada!\n\n");
                }
            break;
        }

        for(x=0; changeValue[x] != '\0'; x++){
            if(changeValue[x] != p->music[x]){
                break;
            }
        }
        if(changeValue[x] == '\0' && p->music[x] == '\0'){
            printf("\nInformações da música que deseja alterar o preço\n\n");
            printf("Música: %s\n", p->music);
            printf("Autor: %s\n", p->author);
            printf("Preço: %.2f\n", p->price);
            printf("Quantidade: %d\n\n", p->quantity);

            printf("Digite o novo preço: ");
            scanf("%f", &p->price);

            printf("\n Preço alterado com sucesso!\n");

            k = nRegisters * sizeof(*p);
            fseek(fp, k, 0);
            fwrite(p, sizeof(*p), 1, fp);

            cont++;
            break;
        }
        nRegisters++;
    }
    fclose(fp);
}

void changeDatas(struct datas* p){
    FILE* fp;
    char datasAUX[100];
    int x, y, nRegisters=0;
    long k;
    int cont=0;

    printf("Digite o nome completo da música que deseja alterar o preço\n\n");
    printf("Nome: ");
    getchar();
    gets(datasAUX);

    if((fp = fopen("Desafio.txt", "r+"))==NULL){
        printf("Erro no arquivo!");
        exit(0);
    }

    for(;;){
        y = fread(p, sizeof(*p), 1, fp);

        if(y == 0){
            if(cont == 0){
            printf("\nDados não encontrados!\n\n");
            }
            break;
        }

        for(x=0; datasAUX[x] != '\0'; x++){
            if(datasAUX[x] != p->music[x])
            {
                break;
            }
        }
        if(datasAUX[x] == '\0' && p->music[x] == '\0'){
            printf("\nInformações da música que deseja alterar o preço\n\n");
            printf("Música: %s\n", p->music);
            printf("Autor: %s\n", p->author);
            printf("Preço: %.2f\n", p->price);
            printf("Quantidade: %d\n\n", p->quantity);

            printf("Música: ");
            gets(p->music);
            printf("Autor: ");
            gets(p->author);
            printf("Preço: ");
            scanf("%f", &p->price);
            printf("Quantidade: ");
            scanf("%d", &p->quantity);

            k = nRegisters * sizeof(*p);
            fseek(fp, k, 0);
            fwrite(p, sizeof(*p), 1, fp);
            cont++;
            break;
        }
        nRegisters++;
    }
    fclose(fp);
}

void deleteDatas(struct datas* p){

    FILE* fp;
    char deleted[100];
    int x, y, nRegisters=0;
    long k;
    int cont=0;

    printf("Digite o nome completo da música que deseja alterar o preço\n\n");
    printf("Nome: ");
    getchar();
    gets(deleted);


    if((fp = fopen("Desafio.txt", "r+"))==NULL){
        printf("\nErro no arquivo!\n\n");
        exit(0);
    }


    for(;;){
        y = fread(p, sizeof(*p), 1, fp);

        if(y == 0){
                if(cont==0){
            printf("\nMúsica não encontrada!\n\n");
            }

            break;
        }

        for(x=0; deleted[x] != '\0'; x++){
            if(deleted[x] != p->music[x]){
                break;
            }
        }
        if(deleted[x] == '\0' && p->music[x] == '\0'){
            printf("\nInformações da música que deseja alterar o preço\n\n");
            printf("Música: %s\n", p->music);
            printf("Autor: %s\n", p->author);
            printf("Preço: %.2f\n", p->price);
            printf("Quantidade: %d\n\n", p->quantity);

            p->music[0] = '*';
            printf("Música deletada com sucesso!\n\n");

            k = nRegisters * sizeof(*p);
            fseek(fp, k, 0);
            fwrite(p, sizeof(*p), 1, fp);
            cont++;
            break;
        }
        nRegisters++;
    }
    fclose(fp);
}

void exitt(){
    printf("\nFoi um prazer ter você aqui!\n\n");
    exit(0);
}
























