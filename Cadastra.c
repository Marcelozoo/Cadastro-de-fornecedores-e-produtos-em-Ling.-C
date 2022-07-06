#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


#define fornetam 70
#define produtam 100



// ESTRUTURAS //
typedef struct fornecedor{

    int cod,dd,nrua;
    char nome[100],rua[100],complemento[100],bairro[100],cidade[100],estado[100],cpf[19],telefone[10];

}Forne;

typedef struct produtos{

    int codp,estoquea,em,codforne;
    char nomep[100],descricao[100];
    float pu;

}Prod;

// FUNCOES //
void arquivoprodu(Prod cp[],int *tam,Forne lp[],int *tam2);
void CadastrarFornecedor (Forne lp[],int *tam2);
void alterarfornecedor(Forne lp[],int *tam);
void CadastrarProduto(Prod cp[],int *tam);
void Alterarproduto(Prod cp[], int *tam);
void Entradadeestoque(Prod cp[],int *tam);
void Venda(Prod cp[],int *tam);
void Relatoriodeestoqueminimo(Prod cp[],int *tam, Forne lp[],int *tam2);
void Gravardados(Prod cp[],int *tam,Forne lp[],int *tam2);

//FUNCAO PRINCIPAL//

void main (){



    Forne fornecedores [fornetam];
    Prod produtos [produtam];
    int resp, i, numprodutos = 0, numfornecedores = 0;

    arquivoprodu (produtos, &numprodutos,fornecedores,&numfornecedores);

    do{
        system("cls");
        printf("-----------------------------------\n");
        printf("------------- MENU ----------------\n");
        printf("-----------------------------------\n");
        printf("\n");
        printf("1 - Cadastrar fornecedor\n");
        printf("2 - Alterar Fornecedor\n");
        printf("3 - Cadastrar Produtos\n");
        printf("4 - Alterar Produtos\n");
        printf("5 - Entrada de Estoque\n");
        printf("6 - Realizar Venda\n");
        printf("7 - Relatorio de Estoque Minimo\n");
        printf("8 - Gravar Dados\n");
        printf("9 - Sair\n");
        printf("\nEscolha uma das opcoes: \n");
        scanf("%d", &resp);

        switch(resp){

            case 1 :

                CadastrarFornecedor (fornecedores,&numfornecedores);
                break;

            case 2:

                alterarfornecedor (fornecedores,&numfornecedores);
                break;

            case 3:

                CadastrarProduto (produtos,&numprodutos);
                break;

            case 4:

                Alterarproduto (produtos, &numprodutos);
                break;

            case 5:

                Entradadeestoque (produtos,&numprodutos);
                break;

            case 6:

                Venda (produtos,&numprodutos);
                break;

            case 7:

                Relatoriodeestoqueminimo (produtos,&numprodutos,fornecedores,&numfornecedores);
                break;

            case 8:

                Gravardados (produtos,&numprodutos,fornecedores,&numfornecedores);
                break;

            case 9:

                break;

            default:

                printf("OPCAO INVALIDA!\n");
                break;
        }
    }while(resp != 9);

    system("cls");
    printf("\n");
    printf("OBRIGADO POR UTILIZAR NOSSO SERVICOS!");
    printf("\n");
}

//FUNÇÔES//

void arquivoprodu(Prod cp[],int *tam,Forne lp[],int *tam2){

    FILE *arq;
    FILE *arq2;
    int i;
    char asteriscos[5];

    arq = fopen("prod.txt", "r");

    if (arq == NULL){
        printf("O ARQUIVO NAO PODE SER ABERTO!\n");
    }
    else{
        fscanf(arq, "%d", tam);
        fscanf(arq, "%s", asteriscos);
        for(i=0;i<(*tam);i++){
            fscanf(arq, "%d", &cp[i].codp);
            fscanf(arq, "%s", cp[i].nomep);
            fscanf(arq, "%s", cp[i].descricao);
            fscanf(arq, "%d", &cp[i].codforne);
            fscanf(arq, "%f", &cp[i].pu);
            fscanf(arq, "%d", &cp[i].estoquea);
            fscanf(arq, "%d", &cp[i].em);
            fscanf(arq, "%s", asteriscos);
        }
        fclose(arq);
    }
    arq2 = fopen("forn.txt", "r");

    if (arq2 == NULL){
        printf("O ARQUIVO NAO PODE SER ABERTO\n");
    }
    else{
        fscanf(arq2, "%d", tam2);
        fscanf(arq2, "%s", asteriscos);
        for(i=0;i<(*tam2);i++){
            fscanf(arq2, "%d", &lp[i].cod);
            fscanf(arq2, "%s", lp[i].nome);
            fscanf(arq2, "%s", lp[i].cpf);
            fscanf(arq2, "%s", lp[i].rua);
            fscanf(arq2, "%d", &lp[i].nrua);
            fscanf(arq2, "%s", lp[i].complemento);
            fscanf(arq2, "%s", lp[i].bairro);
            fscanf(arq2, "%s", lp[i].cidade);
            fscanf(arq2, "%s", lp[i].estado);
            fscanf(arq2, "%d", &lp[i].dd);
            fscanf(arq2, "%s", lp[i].telefone);
            fscanf(arq2, "%s", asteriscos);
        }
        fclose(arq2);
    }
}

void CadastrarFornecedor(Forne lp[], int *tam2){

    int i = 0, cod1, l = 0;

    system("cls");
    printf("-------------------------------------------\n");
    printf("--------- CADASTRAR FORNECEDOR ------------\n");
    printf("-------------------------------------------\n");
    printf("\n");

    printf("Digite o codigo do novo fornecedor: \n");
    scanf("%d", &cod1);
    for(i=0;i<*tam2;i++){
        if(lp[i].cod == cod1){
            printf("JA EXISTE UM FORNECEDOR COM ESSE CODIGO!\n");
            getchar();
            getchar();
            l++;
        }
    }
    if(l == 0){
        i = *tam2;
        lp[i].cod = cod1;
        fflush(stdin);
        printf("\nInforme o nome do fornecedor: \n");
        scanf("%[^\n]s", lp[i].nome);
        fflush(stdin);
        printf("\nInforme o CPF ou CNPJ: \n");
        scanf("%s", lp[i].cpf);
        printf("\nInforme a rua: \n");
        scanf("%s", lp[i].rua);
        printf("\nInforme o numero da rua: \n");
        scanf("%d", &lp[i].nrua);
        printf("\nInforme o complemento da rua: \n");
        scanf("%s", lp[i].complemento);
        printf("\nInforme o bairro: \n");
        scanf("%s", lp[i].bairro);
        printf("\nInforme a cidade: \n");
        scanf("%s", lp[i].cidade);
        printf("\nInforme o seu Estado: \n");
        scanf("%s", lp[i].estado);
        printf("\nInforme o dd do seu telefone:\n");
        scanf("%d", &lp[i].dd);
        printf("\nInforme o seu telefone:\n");
        scanf("%s", lp[i].telefone );
        *tam2 = i+1;
    }
}

void alterarfornecedor(Forne lp[],int *tam){

    int cod1, i, k = 0;


    system("cls");
    printf("-------------------------------------------\n");
    printf("--------- ALTERAR FORNECEDOR --------------\n");
    printf("-------------------------------------------\n");
    printf("\n");


    printf("Digite o codigo do  fornecedor que deseja alterar: \n");
    scanf("%d", &cod1);
    for(i=0;i<(*tam);i++){
        if(lp[i].cod == cod1){
            fflush(stdin);
            printf("\nDigite o novo nome para esse fornecedor: \n");
            scanf("%[^\n]s", lp[i].nome);
            fflush(stdin);
            printf("\nInforme o CPF: \n");
            scanf("%s", lp[i].cpf);
            printf("\nInforme a rua: \n");
            scanf("%s", lp[i].rua);
            printf("\nInforme o numero da rua: \n");
            scanf("%d", &lp[i].nrua);
            printf("\nInforme o complemento da rua: \n");
            scanf("%s", lp[i].complemento);
            printf("\nInforme o bairro: \n");
            scanf("%s", lp[i].bairro);
            printf("\nInforme a cidade: \n");
            scanf("%s", lp[i].cidade);
            printf("\nInforme o seu Estado: \n");
            scanf("%s", lp[i].estado);
            printf("\nInforme o dd do seu telefone:\n");
            scanf("%d", &lp[i].dd);
            printf("\nInforme o numero de telefone: \n");
            scanf("%s", &lp[i].telefone);
            k++;
        }
    }
    if(k == 0){
        printf("CODIGO NAO ENCONTRADO!\n");
        getchar();
        getchar();
    }
}

void CadastrarProduto(Prod cp[],int *tam){

    int cod2, i, codf, l = 0;



    system("cls");
    printf("-------------------------------------------\n");
    printf("--------- CADASTRAR PRODUTO ---------------\n");
    printf("-------------------------------------------\n");
    printf("\n");


    printf("Digite o codigo do novo produto: \n");
    scanf("%d", &cod2);
    for(i=0;i<(*tam);i++){
        if(cp[i].codp == cod2){
            printf("JA EXISTE UM PRODUTO COM ESSE CODIGO!\n");
            l++;
            getchar();
            getchar();
        }
    }
    if(l == 0){
        printf("Digite o codigo do fornecedor: \n");
        scanf("%d", &codf);
        i = *tam;
        cp[i].codp = cod2;
        cp[i].codforne = codf;
        fflush(stdin);
        printf("\nInforme o nome do produto: \n");
        scanf("%[^\n]s", cp[i].nomep);
        fflush(stdin);
        printf("\nInforme  a descricao do produto: \n");
        scanf("%s", cp[i].descricao);
        printf("\nInforme o preco unitario do produto: \n");
        scanf("%f", &cp[i].pu);
        printf("\nInforme o estoque atual do produto: \n");
        scanf("%d", &cp[i].estoquea);
        printf("\nInforme o estoque minimo do produto: \n");
        scanf("%d", &cp[i].em);
        *tam = i+1;
    }
}



void Alterarproduto(Prod cp[], int *tam){



    int codproduto, i, k = 0;

    system("cls");
    printf("-------------------------------------------\n");
    printf("-------- ALTERAR PRODUTO ------------------\n");
    printf("-------------------------------------------\n");
    printf("\n\n");

    printf("Digite o codigo do produto que deseja alterar: \n");
    scanf("%d", &codproduto);
    for(i=0;i<(*tam);i++){
        if(cp[i].codp == codproduto){
                fflush(stdin);
                printf("\nInforme o novo nome do produto: \n");
                scanf("%[^\n]s", cp[i].nomep);
                fflush(stdin);
                printf("\nInforme a  descricao: \n");
                scanf("%s", cp[i].descricao);
                printf("\nInforme o novo preço unitario: \n");
                scanf("%f", &cp[i].pu);
                printf("\nInforme o novo estoque minimo: \n");
                scanf("%d", &cp[i].em);
                k++;
        }
    }
    if(k == 0){
        printf("\nCODIGO NAO ENCONTRADO!\n");
        getchar();
        getchar();
    }
}

void Entradadeestoque(Prod cp[],int *tam){


    int codproduto, quantidade, l = 0 , i;


    system("cls");
    printf("-------------------------------------------\n");
    printf("-------- ENTRADA DE ESTOQUE ---------------\n");
    printf("-------------------------------------------\n");
    printf("\n\n");


    printf("\nInforme o codigo do produto: \n");
    scanf("%d", &codproduto);
    for(i=0;i<(*tam);i++){
        if(codproduto == cp[i].codp){
            printf("\nQual a quantidade de produto que entrara no estoque? \n");
            scanf("%d", &quantidade);
            cp[i].estoquea += quantidade;
            l++;
        }
    }
    if(l == 0){
        printf("\nENTRADA NO ESTOQUE NAO FOI REALIZADA POIS O CODIGO DESSE PRODUTO NAO FOI ENCONTRADO!\n");
        getchar();
        getchar();
    }
}


void Venda(Prod cp[],int *tam){

    int codproduto, quantidade, i, cont = 0 , resp, k = 0;
    float valortotal = 0;

    system("cls");
    printf("-------------------------------------------\n");
    printf("----------------- VENDA -------------------\n");
    printf("-------------------------------------------\n");
    printf("\n\n");


    do{
        printf("\nInforme o codigo do produto que deseja comprar: \n");
        scanf("%d", &codproduto);
        for(i=0;i<(*tam);i++){
            if(cp[i].codp == codproduto){

                cont++;
                printf("\nInforme qual a quantidade que deseja adquirir: \n");
                scanf("%d", &quantidade);


                if(cp[i].estoquea < quantidade){
                    printf("\nEstoque insuficiente!\n");
                    k++;
                }
                if(k == 0){
                    cp[i].estoquea = cp[i].estoquea - quantidade;
                    valortotal += cp[i].pu * quantidade;
                }
                k *= 0;
                printf("\n");
                printf("Deseja  comprar mais algum produto?\n1-SIM\t2-NAO\n");
                scanf("%d",&resp);
            }
        }
        if(cont == 0){
            printf("\nPRODUTO NAO CADASTRADO!\n");
            printf("\nDeseja  comprar mais algum produto?\n1-SIM\t2-NAO\n");
            scanf("%d",&resp);
        }
    }while(resp == 1);

    if(cont != 0){
        printf("\nVALOR TOTAL A PAGAR : R$ %.2f\n", valortotal);
        getchar();
        getchar();
    }
}

void Relatoriodeestoqueminimo(Prod cp[],int *tam, Forne lp[],int *tam2){


    int i, j, cont = 0, l = 1;

    system("cls");
    printf("------------------------------------------------\n");
    printf("-------- RELATORIO DE ESTOQUE MINIMO -----------\n");
    printf("------------------------------------------------\n");
    printf("\n\n");


    printf("LISTA DOS PRODUTOS ABAIXO DO ESTOQUE MINIMO:\n");
    for(i=0;i<(*tam);i++){
        if(cp[i].estoquea < cp[i].em){
            for(j=0;j<(*tam2);j++){
                if(cp[i].codforne == lp[j].cod){
                    printf("\nO nome do produto: %s\tCodigo: %d\tEstoque Atual: %d\tEstoque Minimo: %d\tNome do Fornecedor: %s\tTelefone: (%d) %s\n", cp[i].nomep,cp[i].codp,cp[i].estoquea,cp[i].em,lp[j].nome,lp[j].dd,lp[j].telefone);
                    cont++;
                }
            }
        }
    }
    getchar();
    getchar();
    if(cont == 0){
        printf("\nNAO EXISTE NENHUM PRODUTO COM ESTOQUE MINIMO ABAIXO DO ESTOQUE ATUAL!\n");
        getchar();
        getchar();
    }
}
void Gravardados(Prod cp[],int *tam,Forne lp[],int *tam2){

    FILE *arq;
    FILE *arq2;
    char asteriscos[4] = "***";
    int i;

    arq = fopen("prod.txt", "w");

    if(arq == NULL){
        printf ( "O ARQUIVO NAO PODE SER ABERTO!\n" );
        exit(1);
    }
    else{
        fprintf(arq,"%d\n",*tam);
        for(i=0;i<(*tam);i++){
            fprintf(arq, "%s\n", asteriscos);
            fprintf(arq, "%d\n", cp[i].codp);
            fprintf(arq, "%s\n", cp[i].nomep);
            fprintf(arq, "%s\n", cp[i].descricao);
            fprintf(arq, "%d\n", cp[i].codforne);
            fprintf(arq, "%.3f\n", cp[i].pu);
            fprintf(arq, "%d\n", cp[i].estoquea);
            fprintf(arq, "%d\n", cp[i].em);
        }
        system("cls");
        printf("DADOS GRAVADOS COM SUCESSO!\n");
        getchar();
    }
    fclose(arq);

    arq2 = fopen("forn.txt", "w");

    if(arq2 == NULL){
        printf ( "O ARQUIVO NAO PODE SER ABERTO\n" );
        exit(1);
    }
    else{
        fprintf(arq2,"%d\n", *tam2);
        for(i=0;i<(*tam2);i++){
            fprintf(arq2, "%s\n", asteriscos);
            fprintf(arq2, "%d\n", lp[i].cod);
            fprintf(arq2, "%s\n", lp[i].nome);
            fprintf(arq2, "%s\n", lp[i].cpf);
            fprintf(arq2, "%s\n", lp[i].rua);
            fprintf(arq2, "%d\n", lp[i].nrua);
            fprintf(arq2, "%s\n", lp[i].complemento);
            fprintf(arq2, "%s\n", lp[i].bairro);
            fprintf(arq2, "%s\n", lp[i].cidade);
            fprintf(arq2, "%s\n", lp[i].estado);
            fprintf(arq2, "%d\n", lp[i].dd);
            fprintf(arq2, "%s\n", lp[i].telefone);
        }
        system("cls");
        printf("DADOS GRAVADOS COM SUCESSO!\n");
        getchar();
    }
    fclose(arq2);
}
