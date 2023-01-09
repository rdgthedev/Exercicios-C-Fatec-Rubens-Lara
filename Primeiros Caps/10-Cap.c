#define ex3
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


#ifdef ex1

/*1 - Escreva um programa para criar e abrir um arquivo texto de nome "arq.txt".
Receba via teclado diversos caracteres (um por vezes) e escreva-os
nesse arquivo. O caracter '0' finaliza a entrada de dados. Abra o arquivo
"arq.txt", leia e imprima na tela todos os caracteres armazenados no
arquivo (um por vezes).*/


int main()
{

    FILE *p;
    char c;
    int cont, x;

    if((p = fopen("arq.txt", "w")) == NULL){
        printf("Erro ao abrir o arquivo!");
        exit(0);
    }

    for(cont=0;; cont++){

        printf("Digite uma letra: ");
        scanf("%c", &c);
        getchar();

        if(c == '0'){
            break;
        }

        putc(c, p);

    }

    fclose(p);

    if((p = fopen("arq.txt", "r")) == NULL){
        printf("Erro ao abrir o arquivo!");
        exit(0);
    }

    for(x=0; x < cont; x++){

        c = getc(p);
        printf("%c\n", c);
    }


    fclose(p);

    return 0;
}
#endif // ex1

#ifdef ex2

/*2 - Escreva um programa para gerenciar uma agenda de contatos. Para cada contato
armazene o nome, o telefone e o aniversario (dia e mes) em uma estrutura de
dados. Utilize um vetor de estrutura de 4 elementos como variavel LOCAL na
funcao main(). Utilize ponteiros para passar o vetor de estrutura para
as funcoes. Sempre que o programa for encerrado, os contatos devem ser
escritos no arquivo e quando o programa iniciar os contatos devem ser lidos
do arquivo.

O programa deve ter as seguintes opcoes:(cada opcao do menu e' um funcao)

1 - inserir contato
2 - altera contato
3 - exclui contato
4 - pesquisar um contato pelo nome
5 - listar todos os contatos
6 - listar os contatos cujo nome inicia com uma letra digitada
7 - imprimir os aniversariantes do mês.
8 - saida*/


struct organize{

    char nome[100];
    char telefone[21];
    int dia;
    int mes;

};

int main(){

    struct organize vet[4];
    struct organize *p;
    int opcao;
    int x;

    FILE *fp;

    p = &vet[0];

    setlocale(LC_ALL,"");

if((fp = fopen("capp10.txt", "r"))==NULL){
   printf("\nO Arquivo deu erro, para corrigir digite dados no arquivo!\n\n");
}

        for(x=0; x < 4; x++){
        fread((p+x), sizeof(*p), 1, fp);
        }

        fclose(fp);


        for(;;){
            printf("\n\t MENU\n\n");
            printf("1 - Inserir contato\n");
            printf("2 - Alterar contato\n");
            printf("3 - Excluir contato\n");
            printf("4 - Pesquisar contato\n");
            printf("5 - Listar todos os contatos\n");
            printf("6 - Listar os contatos cujo nome inicia com uma letra digitada\n");
            printf("7 - Imprimir os aniversariantes do mês\n");
            printf("8 - Sair do programa\n\n");

            printf("Escolha uma opção: \n");
            scanf("%d", &opcao);

            switch(opcao){
            case 1:
                system("cls");
                insertdatas(p);
                break;

            case 2:
                system("cls");
                changecontact(p);
                break;

            case 3:
                system("cls");
                deleteDatas(p);
                break;

            case 4:
                system("cls");
                searchcontact(p);
                break;

            case 5:
                system("cls");
                listcontacts(p);
                break;

            case 6:
                system("cls");
                listinitial(p);
                break;

            case 7:
                system("cls");
                printbirthdays(p);
                break;

            case 8:
                exiit(p);
                break;
            }
        }

    return 0;
}

void insertdatas(struct organize* p){

    int cont;

    for(cont=0; cont < 4; cont++){

        printf("%d° Nome: ", cont+1);
        scanf("%s", &(p+cont)->nome);

        printf("%d° Telefone: ", cont+1);
        scanf("%s", &(p+cont)->telefone);
        printf("%d° Aniversário\n", cont+1);
        printf("Dia: ");
        scanf("%d", &(p+cont)->dia);

        printf("Mês: ");
        scanf("%d", &(p+cont)->mes);

        printf("\n");
    }
}

void changecontact(struct organize* p){

    char alterar[100];
    int cont, cont1, ALTaux=0;

    printf("Digite o nome do contato: ");
    scanf("%s", &alterar);

    for(cont=0; cont < 4; cont++){
        for(cont1=0; alterar[cont1] != '\0'; cont1++){
            if(alterar[cont1] != (p+cont)->nome[cont1]){
                ALTaux++;
                break;
            }
        }
        if(alterar[cont1] == '\0' && (p+cont)->nome[cont1] == '\0'){
            printf("Insira um novo contato\n\n");

            printf("Nome: ");
            scanf("%s", (p+cont)->nome);

            printf("Telefone: ");
            scanf("%s", (p+cont)->telefone);

            printf("Aniversário\n");
            printf("Dia: ");
            scanf("%d", &(p+cont)->dia);
            printf("Mês: ");
            scanf("%d", &(p+cont)->mes);
            break;
        }

    }
    if(ALTaux == 4){
        printf("Esse contato não existe!\n");
    }
}

void deleteDatas(struct organize* p){

    char excluir[100];
    int cont, cont1, EXCaux=0;

    printf("Digite o nome do contato: ");
    scanf("%s", &excluir);

    for(cont=0; cont < 4; cont++){
        for(cont1=0; excluir[cont1] != '\0'; cont1++){
            if(excluir[cont1] != (p+cont)->nome[cont1]){
                EXCaux++;
                break;
            }
        }

            if(excluir[cont1] == '\0' && (p+cont)->nome[cont1] == '\0'){

                (p+cont)->nome[0] = '*';
                printf("Contato excluído com sucesso!");
            }


    }

    if(EXCaux == 4){
        printf("Esse contato não existe!\n");
    }
}

void searchcontact(struct organize* p){

    char pesquisar[100];
    int cont, cont1, PESQaux=0;

    printf("Digite o nome do contato\n");
    scanf("%s", &pesquisar);

    for(cont=0; cont < 4; cont++){
        for(cont1=0; pesquisar[cont1] != '\0'; cont1++){
            if(pesquisar[cont1] != (p+cont)->nome[cont1]){
                PESQaux=0;
                break;
            }
        }
            if(pesquisar[cont1] == '\0' && (p+cont)->nome[cont1] == '\0'){

                printf("\nNome: %s\n", (p+cont)->nome);
                printf("Telefone: %s\n", (p+cont)->telefone);
                printf("Aniversário: %.2d/%.2d\n", (p+cont)->dia, (p+cont)->mes);
                break;
            }

    }
    if(PESQaux == 4){
        printf("Esse contato não existe!");
    }

}

void listcontacts(struct organize* p){

    int cont=0;

    for(cont=0; cont < 4; cont++){


        if((p+cont)->nome[0] != '*'){
            printf("\n%d° Nome: %s\n", cont+1, (p+cont)->nome);
            printf("%d° Telefone: %s\n", cont+1, (p+cont)->telefone);
            printf("%d° Aniversário: %.2d/%.2d\n", cont+1, (p+cont)->dia, (p+cont)->mes);
            printf("\n");
        }
    }
}
void listinitial(struct organize* p){

    char inicial;
    int cont, cont1, INITIALaux=0;

    printf("Digite a inicial do nome: ");
    scanf("\n%c", &inicial);

    for(cont=0; cont < 4; cont++){
        for(cont1=0; (p+cont)->nome[cont1] != inicial; cont1++){
            if((p+cont)->nome[cont1] != inicial)
            {
                INITIALaux++;
                break;
            }
        }
        if((p+cont)->nome[cont1]  == inicial){

            printf("\nNome: %s\n", (p+cont)->nome);
            printf("Telefone: %s\n", (p+cont)->telefone);
            printf("Aniversário: %.2d/%.2d\n", (p+cont)->dia, (p+cont)->mes);
            printf("\n");

        }
    }


}

void printbirthdays(struct organize* p){

    int monthBirthdays=0;
    int cont, quantidade=0;

    printf("Digite o mês: ");
    scanf("%d", &monthBirthdays);

    for(cont=0; cont < 4; cont++){
        if(monthBirthdays == (p+cont)->mes){
            if((p+cont)->nome[0] != '*'){
            printf("\nNome: %s\n", (p+cont)->nome);
            printf("Telefone: %s\n", (p+cont)->telefone);
            printf("Aniversário: %.2d/%.2d\n", (p+cont)->dia, (p+cont)->mes);
            printf("\n");
            quantidade++;
            }
        }
    }
    if(quantidade == 0){
        printf("\nNão há aniversariantes neste mês!\n");
    }
}

void exiit(struct organize* p){

        FILE *fp;
        int x;

fp = fopen("capp10.txt", "w");

        for(x=0; x < 4; x++){
        fwrite((p+x), sizeof(*p), 1, fp);
        }

        fclose(fp);

        exit(0);
}
#endif //ex2

#ifdef ex3

/*3 - Escreva um programa para controle de um cadastro de clientes. Para cada
    registro sera' armazenado nome, end, cidade, estado, cep numa estrutura
    de dados. A unica estrutura de dados e' uma variavel LOCAL na funcao main().
    Escreva os registros direto no arquivo. (utilize a funcao fseek quando
    necessario). NAO pode usar vetor de estruturas. Utilize ponteiros para
    passar parametros para as funcoes.
    O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
    1 - inclui registros
    2 - listar todos os registros
    3 - pesquisar registro pelo nome
    4 - altera registro
    5 - exclui registro
    6 - saida*/


struct dados{
    char nome[100];
    char endereco[50];
    char cidade[50];
    char estado[3];
    char cep[11];
};

int main(){

    struct dados user;
    struct dados *p;
    int opcao=0;

    p = &user;

    setlocale(LC_ALL,"");
    for(;;){
        printf("\n\tMENU\n\n");
        printf("1 - Incluir registros\n");
        printf("2 - Listar todos os registros\n");
        printf("3 - Pesquisar registro pelo nome\n");
        printf("4 - Alterar registro\n");
        printf("5 - Excluir registro\n");
        printf("6 - Sair do programa\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);


        switch(opcao){

        case 1:
            system("cls");
            addRegister(p);
            break;

        case 2:
            system("cls");
            listRegisters(p);
            break;

        case 3:
            system("cls");
            searchRegisters(p);
            break;

        case 4:
            system("cls");
            changeRegister(p);
            break;


        case 5:
            system("cls");
            deleteRegister(p);
            break;

        case 6:
            system("cls");
            exitProgram();
            break;
        }
    }
    return 0;
}


void addRegister(struct dados* p){

    FILE* fp;

    if((fp = fopen("ex3.txt", "a"))==NULL){
        printf("Erro no arquivo!");
        exit(0);
    }

    printf("Insira seus dados\n\n");

    printf("Nome: ");
    scanf("%s", &p->nome);

    printf("Endereço: ");
    scanf("%s", &p->endereco);

    printf("Cidade: ");
    scanf("%s", &p->cidade);

    printf("Estado: ");
    scanf("%s", &p->estado);

    printf("CEP: ");
    scanf("%s", &p->cep);

    fwrite(p, sizeof(*p), 1, fp);
    fclose(fp);
}

void listRegisters(struct dados* p){

    FILE* fp;

    if((fp = fopen("ex3.txt", "r"))==NULL){
        printf("Erro no arquivo!");
        exit(0);
    }

    for(;;){
        if((fread(p, sizeof(*p), 1, fp)) == 0){
            break;
        }
        if(p->nome[0] != '*'){
            printf("\n\nNome: %s\n", p->nome);
            printf("Endereço: %s\n", p->endereco);
            printf("Cidade: %s\n", p->cidade);
            printf("Estado: %s\n", p->estado);
            printf("CEP: %s\n", p->cep);
        }
    }
    fclose(fp);
}

void searchRegisters(struct dados* p){

    FILE* fp;
    char search[100];
    int x, cont=0, AUXsearch=0;


    if((fp = fopen("ex3.txt", "r"))==NULL){
        printf("Erro no arquivo!");
        exit(0);
    }

    printf("Digite o nome que deseja procurar\n\n");
    printf("Nome: ");
    scanf("%s", &search);

    for(;;){
        if(fread(p, sizeof(*p),1, fp) == 0){
            printf("\nNenhum registro encontrado!\n\n");
            break;
        }
        for(x=0; search[x] != '\0'; x++){
            if(search[x] != p->nome[x]){
                break;
            }
        }
        if(p->nome[x] == '\0' && search[x] == '\0'){
            printf("\n\nNome: %s\n", p->nome);
            printf("Endereço: %s\n", p->endereco);
            printf("Cidade: %s\n", p->cidade);
            printf("Estado: %s\n", p->estado);
            break;
        }
    }
    fclose(fp);
}

void changeRegister(struct dados* p){

    FILE* fp;
    char change[100];
    int x, changeAUX=0, nRegisters=0;
    long k=0;



    if((fp = fopen("ex3.txt", "r+"))==NULL){
        printf("Erro no arquivo!");
        exit(0);
    }

    printf("Digite o nome do contato que deseja alterar\n\n");
    printf("Nome: ");
    scanf("%s", &change);



    for(;;){

        if(fread(p, sizeof(*p), 1, fp) == 0){
            printf("\n\nNenhum registro encontrado!\n\n");
            break;
        }
        for(x=0; change[x] != '\0'; x++){
            if(change[x] != p->nome[x]){
                break;
            }
        }
        if(p->nome[x] == '\0' && change[x] == '\0'){

            printf("\n\nNovo nome: ");
            scanf("%s", p->nome);
            printf("Novo endereço: ");
            scanf("%s", p->endereco);
            printf("Nova cidade: ");
            scanf("%s", p->cidade);
            printf("Novo estado: ");
            scanf("%s", p->estado);
            printf("Novo CEP: ");
            scanf("%s", p->cep);

            k = nRegisters * sizeof(*p);
            fseek(fp, k, 0);
            fwrite(p, sizeof(*p), 1, fp);
            break;

        }
        nRegisters++;
    }
    fclose(fp);
}




void deleteRegister(struct dados* p){

    FILE* fp;
    char deleted[100];
    int x, deletedAUX=0, nRegisters=0;
    long k=0;

    if((fp = fopen("ex3.txt", "r+"))==NULL){
        printf("Erro no arquivo!");
        exit(0);
    }

    printf("Digite o nome do contato que deseja excluir\n\n");
    printf("Nome: ");
    scanf("%s", &deleted);

    for(;;){
        if(fread(p, sizeof(*p),1, fp) == 0){
            printf("\nNenhum registro encontrado!\n\n");
            break;
        }
        for(x=0; deleted[x] != '\0'; x++){

            if(deleted[x] != p->nome[x]){
                break;
            }
        }
        if(p->nome[x] == '\0' && deleted[x] == '\0'){

            p->nome[0] = '*';
            k = nRegisters *sizeof(*p);
            fseek(fp, k, 0);
            fwrite(p, sizeof(*p), 1, fp);
            printf("\n\nRegistro deletado com sucesso!\n\n");
            break;
        }
        nRegisters++;
    }
    fclose(fp);
}

void exitProgram(){
    exit(0);
}
#endif // ex3

#ifdef ex4
/*
4 - Escreva um programa para o controle de mercadorias em uma despensa
    domestica. Para cada produto sera' armazenado um codigo numerico, nome
    do produto e quantidade atual numa estrutura de dados. A unica estrutura
    de dados deve ser declarada como variavel LOCAL na funcao main(). Escreva
    os itens das mercadorias direto no arquivo. (utilize a funcao fseek quando
    necessario). NAO pode usar vetor de estruturas. Utilize ponteiros.
    O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
    1 - inclui produtos
    2 - altera produtos
    3 - exclui produtos
    4 - pesquisar uma mercadoria pela descrição
    5 - listar todos os produtos
    6 - listar os produtos não disponíveis.
    7 - alterar a quantidade atual
    8 - saida
*/

struct product{
    int code;
    char name[100];
    int quantity;
};

int main(){

    struct product prod;
    struct product* p;
    int opcao=0;

    p = &prod;

    setlocale(LC_ALL,"");
    for(;;){
        printf("\n\n1 - Incluir produtos\n");
        printf("2 - Alterar produtos\n");
        printf("3 - Excluir produtos\n");
        printf("4 - Pesquisar uma mercadoria pela descrição\n");
        printf("5 - Listar todos os produtos\n");
        printf("6 - Listar produtos indisponíveis\n");
        printf("7 - Alterar a quantidade atual\n");
        printf("8 - Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            system("cls");
            insert(p);
            break;

        case 2:
            system("cls");
            change(p);
            break;

        case 3:
            system("cls");
            deleteProduct(p);
            break;

        case 4:
            system("cls");
            searchProduct(p);
            break;

        case 5:
            system("cls");
            listProducts(p);
            break;

        case 6:
            system("cls");
            productsUnavailable(p);
            break;

        case 7:
            system("cls");
            changeQuantity(p);
            break;

        case 8:
            system("cls");
            exitt();
            break;
        }
    }
}

void insert(struct product *p){

    FILE* fp;

    if((fp=fopen("ex4.txt", "a"))==NULL){
        printf("Erro no programa!");
        exit(0);
    }

    printf("Digite as informações do produto\n\n");

    printf("Código: ");
    scanf("%d", &p->code);

    printf("Nome do produto: ");
    scanf("%s", &p->name);

    printf("Quantidade: ");
    scanf("%d", &p->quantity);

    fwrite(p, sizeof(*p), 1, fp);
    fclose(fp);

}

void change(struct product* p){

    FILE* fp;
    char changeProd[100];
    int  x, i, nRegisters=0;
    long k=0;

    if((fp=fopen("ex4.txt", "r+")) == NULL){
        printf("Erro no arquivo!");
        exit(0);
    }

    printf("Digite a descrição do produto que deseja alterar\n\n");
    printf("Descrição : ");
    scanf("%s", &changeProd);

    for(;;){
        x = fread(p, sizeof(*p), 1, fp);

        if(x == 0){

            printf("\nProduto não encontrado!");

            break;
        }
        for(i=0; changeProd[i] != '\0'; i++){
            if(changeProd[i] != p->name[i]){
                break;
            }
        }
        if(changeProd[i] == '\0' && p->name[i] == '\0'){

            printf("\nInformações do produto\n\n");
            printf("\n\nCódigo: %.2d\n", p->code);
            printf("Nome: %s\n",p->name);
            printf("Quantidade: %d\n\n",p->quantity);

            printf("\n\nDigite os novos dados\n\n");
            printf("Novo código: ");
            scanf("%d", &p->code);
            printf("Nova nome: ");
            scanf("%s", &p->name);
            printf("Nova quantidade: ");
            scanf("%d", &p->quantity);

            k = nRegisters * sizeof(*p);
            fseek(fp, k, 0);
            fwrite(p, sizeof(*p), 1, fp);
            break;
        }
        nRegisters++;
    }
    fclose(fp);
}



void deleteProduct(struct product* p){

    FILE* fp;
    char deleted[100];
    int  x, i, nRegisters=0;
    long k=0;

    if((fp=fopen("ex4.txt", "r+")) == NULL){
        printf("Erro no arquivo!");
        exit(0);
    }

    printf("Digite o nome do produto do produto que deseja deletar\n\n");
    printf("Nome: ");
    scanf("%s", &deleted);

    for(;;){
        x = fread(p, sizeof(*p), 1, fp);

        if(x == 0){
            printf("\nProduto não encontrado!");
            break;
        }
        for(i=0; deleted[i] != '\0'; i++){
            if(deleted[i] != p->name[i]){
                break;
            }
        }
        if(deleted[i] == '\0' && p->name[i] == '\0'){
            printf("\nInformações do produto que deseja deletar\n\n");
            printf("Código: %.2d\n", p->code);
            printf("Nome: %s\n",p->name);
            printf("Quantidade: %d\n\n",p->quantity);

            p->name[0] = '*';
            printf("\nProduto deletado com sucesso!\n\n");

            k = nRegisters * sizeof(*p);
            fseek(fp, k, 0);
            fwrite(p, sizeof(*p), 1, fp);
            break;
        }
        nRegisters++;
    }
    fclose(fp);
}

void searchProduct(struct product* p){

    FILE* fp;
    char description[100];
    int x, i, descripAUX=0, nRegisters=0;
    long k;

    if((fp = fopen("ex4.txt", "r")) == NULL){
        printf("Erro no arquivo!");
        exit(0);
    }

    printf("Digite a descrição do produto que deseja pesquisar\n\n");
    printf("Descrição: ");
    scanf("%s", &description);


    for(;;){
        x = fread(p, sizeof(*p), 1, fp);

        if(x == 0){

            printf("\nProduto não encontrado!");
            break;
        }
        for(i=0; description[i] != '\0'; i++){
            if(description[i] != p->name[i]){
                break;
            }
        }

        if(description[i] == '\0' && p->name[i] == '\0'){
            printf("\nInformações do produto\n\n");
            printf("\nCódigo: %.2d\n", p->code);
            printf("Nome: %s\n",p->name);
            printf("Quantidade: %d\n\n",p->quantity);

            break;
        }
    }
    fclose(fp);
}

void listProducts(struct product* p){
    FILE* fp;
    int i;

    if((fp = fopen("ex4.txt", "r")) == NULL){
        printf("Erro no arquivo!");
        exit(0);
    }

    for(;;){
        i = fread(p, sizeof(*p), 1, fp);

        if(i == 0){
            break;
        }
        if(p->name[0] != '*'){
            printf("\n\nCódigo: %d\n", p->code);
            printf("Nome: %s\n",p->name);
            printf("Quantidade: %d\n",p->quantity);
        }
    }
    fclose(fp);
}


void productsUnavailable(struct product* p){

    FILE* fp;
    int i, unAUX=0;;

    if((fp = fopen("ex4.txt", "r")) == NULL){
        printf("Erro no arquivo!");
        exit(0);
    }

    for(;;){
        i = fread(p, sizeof(*p), 1, fp);

        if(i == 0){
            break;
        }
        if(p->quantity == 0){
            printf("\n\nCódigo: %.2d\n", p->code);
            printf("Nome: %s\n",p->name);
            printf("Quantidade: %d\n\n",p->quantity);
            unAUX++;
        }
    }
    if(unAUX == 0){
        printf("\n\nTodos os produtos estão disponíveis!\n\n");
    }
    fclose(fp);
}

void changeQuantity(struct product* p){

    FILE* fp;
    char changeDescrip[100];
    int changeAUX=0, nRegisters=0, i, x;
    long k = 0;

    if((fp = fopen("ex4.txt", "r+")) == NULL){
        printf("Erro no arquivo!");
        exit(0);
    }

    printf("Digite a descrição do produto que deseja alterar: ");
    scanf("%s", &changeDescrip);

    for(;;){
        x = fread(p, sizeof(*p), 1, fp);

        if(x == 0){
            printf("\nProduto não encontrado!");
            break;
        }
        for(i=0; changeDescrip[i] != '\0'; i++){
            if(changeDescrip[i] != p->name[i]){
                changeAUX++;
                break;
            }
        }
        if(changeDescrip[i] == '\0' && p->name[i] == '\0'){
            printf("\nInformações do produto\n");
            printf("\nCódigo: %.2d\n", p->code);
            printf("Nome: %s\n",p->name);
            printf("Quantidade: %d\n\n",p->quantity);

            printf("\nNova quantidade: ");
            scanf("%d", &p->quantity);

            k = nRegisters * sizeof(*p);
            fseek(fp, k, 0);
            fwrite(p, sizeof(*p), 1, fp);
            break;
        }
        nRegisters++;
    }
    fclose(fp);
}

void exitt(){
    printf("\n\nVolte logo!\n\n");
    exit(0);
}
#endif //ex4
























