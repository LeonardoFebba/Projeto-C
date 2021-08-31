#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#define SIZE 200

char nome[SIZE][50];
char sobrenome[SIZE][50];
char pet[SIZE][50];
char raca[SIZE][50];
char prod[SIZE][50];
char rua[SIZE][50];
char bairro[SIZE][50];
int numero[SIZE];
int preco[SIZE];
int qtd[SIZE];
int lote[SIZE];
int cpf[SIZE];
int tel[SIZE];
int dia[SIZE];
int mes[SIZE];
int ano[SIZE];
int op;
void cadastro();
void pesquisa();
void lista();
void vet();
void ban();
void venda();
void produtos();
void cadprod();
void reg_Venda();
void adm();
void del();
void cad_Cli();
void gerar_Rel();

int main(void)
{
    setlocale(LC_ALL, "portuguese");

    do
    {
        system("cls");
        printf("\t\t\tPETCONFORT SOFTWARE MANAGER");
        printf("\n\t\t\t---------------------------\n");
        printf("\n\t**OBSERVACAO: O sistema nao aceita espaco ou caracteres especiais como: (,#,-,@,!...\n");
        printf("\n\tUtilize apenas letras ou numeros para efetuar os registros\n");
        printf("\n\t| 1-Clinica Veterinaria \n\t| 2-Banho & tosa \n\t| 3-Loja \n\t| 4-ADM \n\t| 5-Sair\n");
        printf("\n\tEscolha uma das opcoes que voce deseja acessar: ");
        // printf("\n1- Cadastrar cliente\n2- Pesquisar cadastro e tosa\n3- Listar todos\n4- Sair\n\n");
        //printf("Escolha uma das a��es acima para utilizar o sistema: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            vet();
            break;

        case 2:
            system("cls");
            ban();
            break;

        case 3:
            system("cls");
            venda();
            break;

        case 4:
            system("cls");
            adm();
            break;
        case 5:
            system("cls");
            printf("\n\tO sistema sera finalizado, obrigado por utilizar o software!");
            break;
        /*
        case 3:
            lista();
            break;
        case 4:
            system("exit");
            break;
            */
        default:
            printf("\nOpcao invalida");
            getchar();
            getchar();
            break;
        }
    } while (op != 5);
    getch();
    return 0;
}
/**** FINAL  FUN��O MAIN ******/

/**** INICIO FUN��O CADASTRO ******/
void cadastro()
{
    static int linha;
    do
    {
        printf("\n\tInforme o nome do cliente: ");
        scanf("%s", &nome[linha]);
        printf("\n\tInforme o sobrenome: ");
        scanf("%s", &sobrenome[linha]);
        printf("\n\tDigite o CPF do responsavel: ");
        scanf("%d", &cpf[linha]);
        printf("\n\tInforme o dia do seu nascimento (dd): ");
        scanf("%d", &dia[linha]);
        printf("\n\tInforme o mes do seu nascimento (mm): ");
        scanf("%d", &mes[linha]);
        printf("\n\tInforme o ano do seu nascimento (aaaa): ");
        scanf("%d", &ano[linha]);
        printf("\n\tInforme o nome da sua rua: ");
        scanf("%s", &rua[linha]);
        printf("\n\tInforme o numero da residencia: ");
        scanf("%d", &numero[linha]);
        printf("\n\tInforme seu bairro: ");
        scanf("%s", &bairro[linha]);
        printf("\n\tDigite o Telefone: ");
        scanf("%d", &tel[linha]);
        printf("\n\tInforme o nome do Pet: ");
        scanf("%s", &pet[linha]);
        printf("\n\tInforme a ra�a: ");
        scanf("%s", &raca[linha]);
        printf("\n\tDeseja cadastrar outro cliente? 1-Sim | 2-Nao: ");
        scanf("%i", &op);
        linha++;
    } while (op == 1);
}
/**** FINAL FUN��O CADASTRO ******/

/**** INICIO FUN��O PESQUISA ******/
void pesquisa()
{
    int cpfPesquisa;
    int i;
    char nomePesquisa;
    system("cls");
    printf("\n\tEfetue a pesquisa por CPF ou volte a tela inicial: 1-CPF | 2-Voltar: ");
    scanf("%d", &op);
    do
    {
        switch (op)
        {
        case 1:
            printf("\tDigite o CPF para efetuar a pesquisa: ");
            scanf("%d", &cpfPesquisa);
            for (i = 0; i < SIZE; ++i)
            {
                if (cpf[i] == cpfPesquisa)
                {
                    printf("\n\tNome: %s | Sobrenome: %s | CPF: %d | Nascimento: %d/%d/%d", nome[i], sobrenome[i], cpf[i], dia[i], mes[i], ano[i]);
                    printf("\n\tRua: %s, Numero: %d - Bairro: %s | Telefone: %d | Pet: %s \n", rua[i], numero[i], bairro[i], tel[i], pet[i]);
                    printf("\n\t_____________________________________________________________\n");
                }
                else
                {
                    printf("\t");
                    system("pause");
                    break;
                }
            }
            break;

        case 2:
            return adm();
            break;

        default:
            printf("\n\tOpcao invalida");
            break;
        }
        printf("\n\tDeseja continuar pesquisando? 1-Sim | 2-Nao: ");
        scanf("%d", &op);
    } while (op == 1);
}
/**** FINAL FUN��O PESQUISA ******/

/**** INICIO FUN��O LISTA ******/
void lista()
{
    system("cls");
    int i;
    printf("\n\t\tLista de clientes cadastrados\n ");
    for (i = 0; i < SIZE; ++i)
    {
        if (cpf[i] > 0)
        {
            printf("\n\tNome: %s | Sobrenome: %s | CPF: %d | Nascimento: %d/%d/%d", nome[i], sobrenome[i], cpf[i], dia[i], mes[i], ano[i]);
            printf("\n\tRua: %s, N�mero: %d - Bairro: %s | Telefone: %d | Pet: %s \n", rua[i], numero[i], bairro[i], tel[i], pet[i]);
            printf("\n\t_____________________________________________________________\n");
        }
        else
        {
            break;
        }
    }

    return adm();
}
/**** FINAL FUN��O LISTA ******/

/**** INICIO AGENDAMENTO VETERIN�RIO ******/
void vet()
{
    int cad;
    printf("\n\tJa possui cadastro? 1-Sim | 2-Nao: ");
    scanf("%i", &cad);
    if (cad == 2)
    {
        cadastro();
    }

    int data;
    do
    {
        printf("\n\tOs dias que temos disponiveis para nossa clinica sao: ");
        printf("\t16/06/2021 as 14:30 | 18/06/2021 as 10:00 |\n\t01/07/2021 as 15:00\n");
        printf("\n\tDeseja agendar em algum dos dias disponaveis? 1-Sim | 2-Nao: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\n\tInforme (somente) a data (dd) desejada: ");
            scanf("%d", &data);
            printf("\n\tAgendamento efetuado!\n");
            printf("\n\tDeseja efetuar outro agendamento?: 1-Sim | 2-Nao");
            scanf("%d", &op);
            if (op == 1)
            {
                return vet();
            }
            else
            {
                printf("\t");
                system("pause");
            }
            getchar();
            getchar();
            break;
        case 2:
            printf("\n\tInformaremos quando houver outras datas e horarios!\n");
            getchar();
            getchar();
            printf("\t");
            system("pause");
            break;
        default:
            printf("\n\tOpcao invalida");
            break;
        }
    } while (op == 1);
}
/**** FINAL AGENDAMENTO VETERIN�RIO ******/

/****** INICIO AGENDAMENTO BANHO ******/
void ban()
{
    int cad;
    printf("\n\tJa possui cadastro? 1-Sim | 2-N�o: ");
    scanf("%i", &cad);
    if (cad == 2)
    {
        cadastro();
    }

    int data;
    do
    {
        printf("\n\tPossuimos as seguintes datas e horarios para banho e tosa: ");
        printf("\n\t19/08/2021 �s 15:40 | 22/08/2021 as 11:20|\n\t13/09/2021 as 09:30\n");
        printf("\n\tDeseja agendar em algum dos dias disponiveis? 1-Sim | 2-Nao: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\n\tInforme (somente) a data (dd) desejada: ");
            scanf("%d", &data);
            printf("\n\tAgendamento efetuado!\n", data);
            printf("\n\tDeseja efetuar outro agendamento?: 1-Sim | 2-N�o");
            scanf("%d", &op);
            if (op == 1)
            {
                return ban();
            }
            else
            {
                printf("\t");
                system("pause");
            }
            getchar();
            getchar();
            break;
        case 2:
            printf("\n\tInformaremos quando houver outras datas e horarios!\n");
            printf("\t");
            system("pause");
            getchar();
            getchar();
            break;
        default:
            printf("\n\tOpcao invalida");
            break;
        }
    } while (op == 1);
}
/****** FINAL AGENDAMENTO BANHO ******/

/****** INICIO VENDA ******/
void venda()
{
    printf("\n\t\t\tBem vindo ao registro de vendas!\n");
    int i;
    do
    {
        printf("\n\t| 1-Cadastrar cliente\n\t| 2-Ver lista de produtos\n\t| 3-Registrar venda\n");
        printf("\n\tInforme a acao que deseja tomar: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            system("cls");
            cadastro();
            break;
        case 2:
            system("cls");
            produtos();
            break;
        case 3:
            system("cls");
            reg_Venda();
            break;
        default:
            printf("\n\tOpcao invalida");
            break;
        }

    } while (op == 1);
    getchar();
    getchar();
}
/****** FINAL VENDA ******/

/****** INICIO PESQUISA DE PRODUTOS ******/
void produtos()
{
    int i;
    printf("\n\tPRODUTO\t\t|\tPRECO\t|\tQTD\t|\tLOTE\t|\n");
    printf("\n\tTap_Higenico\t|\t4000\t|\t10\t|\t1234\t|\n ");
    printf("\n\tCol_Antipulga\t|\t2500\t|\t15\t|\t2254\t|\n");
    printf("\n\tDeseja adicionar outro produto? 1-Sim | 2-Nao: ");
    scanf("%d", &op);
    do
    {
        switch (op)
        {
        case 1:
            system("cls");
            cadprod();
            break;
        case 2:
            break;
        default:
            printf("\n\tOpcao invalida");
            break;
        }
    } while (op == 1);
    printf("\n\tDeseja atualizar a lista? 1-Sim | 2-N�o: ");
    scanf("%i", &op);
    if (op == 1)
    {
        printf("\n\tPRODUTO\t\t|\tPRECO\t|\tQTD\t|\tLOTE\t|\n");
        printf("\n\tTap_Higenico\t|\t4000\t|\t10\t|\t1234\t|\n ");
        printf("\n\tCol_Antipulga\t|\t2500\t|\t15\t|\t2254\t|\n");
        for (i = 0; i < SIZE; ++i)
        {
            if (lote[i] > 0)
            {
                printf("\n\t%s\t|\t%d\t|\t%d\t|\t%d\t| \n", prod[i], preco[i], qtd[i], lote[i]);
                printf("\n");
            }
        }
    }
}
/****** FINAL PESQUISA DE PRODUTOS ******/

/****** INICIO CADASTRO DE PRODUTOS ******/
void cadprod()
{
    do
    {
        static int line;
        printf("\n\tInforme o nome do produto: ");
        scanf("%s", &prod[line]);
        printf("\n\tInforme o pre�o: ");
        scanf("%d", &preco[line]);
        printf("\n\tInforme a quantidade: ");
        scanf("%d", &qtd[line]);
        printf("\n\tInforme o lote: ");
        scanf("%d", &lote[line]);
        printf("\n\tProduto cadastrado!\n");
        printf("\n\tDeseja cadastrar novo produto? 1-Sim | 2-Nao: ");
        scanf("%i", &op);
        line++;
    } while (op == 1);
}
/****** FINAL CADSTRO DE PRODUTOS******/

/****** INICIO REGISTRO DE VENDAS ******/
void reg_Venda()
{
    do
    {
        static int line;
        printf("\n\tInforme o nome do produto: ");
        scanf("%s", &prod[line]);
        printf("\n\tInforme o preco: ");
        scanf("%d", &preco[line]);
        printf("\n\tInforme a quantidade: ");
        scanf("%d", &qtd[line]);
        printf("\n\tInforme o lote: ");
        scanf("%d", &lote[line]);
        printf("\n\tVenda registrada!\n");
        printf("\n\tDeseja registrar nova venda? 1-Sim | 2-N�o: ");
        scanf("%i", &op);
        line++;
    } while (op == 1);
}
/****** FINAL REGISTRO DE VENDAS******/

/****** INICIO ABA ADM ******/
void adm()
{
    printf("\n\t\t\tBem vindo a area administrativa\n");
    printf("\n\t| 1-Cadastrar/deletar clientes \n\t| 2-Listar clientes \n\t| 3-Pesquisar cliente \n\t| 4-Gerar relatorio \n\t| 5-Sair\n");
    printf("\n\tEscolha uma das opcoes para continuar: ");
    scanf("%d", &op);
    int cpfPesquisa;
    int i;

    do
    {
        switch (op)
        {
        case 1:
            cad_Cli();
            break;

        case 2:
            lista();
            getchar();
            getchar();
            break;
        case 3:
            pesquisa();
            break;
        case 4:
            gerar_Rel();
            break;
        default:
            printf("\n\tOpcaoo invalida\n");
            break;
        }
    } while (op != 4);
}
/****** FINAL ABA ADM ******/

/****** INICIO FUNCAO DELETE ******/
void del()
{
    int i, cpfDelete;
    printf("\n\tInforme o cpf para deletar: ");
    scanf("%d", &cpfDelete);
    do
    {
        for (i = 0; i < SIZE; i--)
        {
            if (cpf[i] == cpfDelete)
            {
                printf("\n\tCliente deletado!\n");
            }
            else
            {
                break;
                system("cls");
            }
        }
    } while (op == 1);
}
/****** FINAL FUN��O DELETE ******/

/****** INICIO CADASTRO CLIENTE ******/
void cad_Cli()
{
    printf("\n\t1-Cadastrar | 2-Deletar: ");
    scanf("%d", &op);
    if (op == 1)
    {
        cadastro();
        printf("\t");
        system("pause");
        system("cls");
    }
    else
    {
        del();
    }

    return adm();
}
/****** FINAL CADASTRO CLIENTE ******/

/****** INICIO FUN��O GERAR RELAT�RIO ******/
void gerar_Rel()
{
    FILE *arquivo;
    char dados[200];
    arquivo = fopen("relatoriogeral.txt", "w");
    fprintf(arquivo, "\n\t\tCONTROLE DE GASTOS MENSAL\n\n");
    fprintf(arquivo, "\tDESCRICAO\t|\tDATA\t\t|\tTOTAL\n\n");
    fprintf(arquivo, "\tAGUA\t\t|\t05/05/21\t|\tR$350,00\n");
    fprintf(arquivo, "\tLUZ\t\t|\t05/05/21\t|\tR$430,85\n");
    fprintf(arquivo, "\tTELEFONE\t|\t23/05/21\t|\tR$255,30\n");
    fprintf(arquivo, "\tALUGUEL\t\t|\t28/05/21\t|\tR$2.000,00\n");
    fprintf(arquivo, "\tMATERIAIS\t|\t26/06/21\t|\tR$900,00\n");
    fprintf(arquivo, "\tMANUTENCAOO\t|\t30/05/21\t|\tR$588,65\n");
    fprintf(arquivo, "\tFORNECEDORES\t|\t30/05/21\t|\tR$1348,60\n");
    fclose(arquivo);
    printf("\n\tArquivo criado com sucesso!\n");
    printf("\t");
    system("pause");
    system("cls");
    return adm();
}

/****** FINAL GERAR RELAT�RIO ******/
