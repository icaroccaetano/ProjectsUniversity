#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define GET_MS(ini, fim) ((fim.tv_sec * 1000000 + fim.tv_usec) - (ini.tv_sec * 1000000 + ini.tv_usec))
struct timeval inicio, fim;

//15 elementos -> tamanho = 2 * elementos (primo mais proximo) = 30 -> 31
#define TAM 31

typedef struct Data {
    int dia, mes, ano;
} Data;

typedef struct Endereco {
    char rua[40];
    char pais[30];
    char cidade[30];
    char bairro[30];
    int num, cep;
} Endereco;

typedef struct Contrato {
    int codigo;
    Data dataAss;
    char cargo[30];
    float salario;
} Contrato;

typedef struct Pessoa {
    Endereco endResidencial;
    Data dataNasc;
    Contrato contrato;
    char nome[40];
    int cpf;
} Pessoa;

void inicializaTabela(Pessoa *tabela) {
    int i;
    for(i = 0; i < TAM; i++)  {
        tabela[i].cpf = 0;
        strcpy(tabela[i].nome, "-");
        tabela[i].contrato.codigo = 0;
        strcpy(tabela[i].contrato.cargo, "-");
        tabela[i].contrato.dataAss.dia = 0;
        tabela[i].contrato.dataAss.mes = 0;
        tabela[i].contrato.dataAss.ano = 0;
        tabela[i].contrato.salario = 0;
        tabela[i].dataNasc.dia = 0;
        tabela[i].dataNasc.mes = 0;
        tabela[i].dataNasc.ano = 0;
        strcpy(tabela[i].endResidencial.rua, "-");
        strcpy(tabela[i].endResidencial.bairro, "-");
        tabela[i].endResidencial.cep = 0;
        tabela[i].endResidencial.num = 0;
        strcpy(tabela[i].endResidencial.cidade, "-");
        strcpy(tabela[i].endResidencial.pais, "-");
    }
}

int funcaoHash(int chave) {
    return (chave % TAM);
}

void insere(Pessoa p, Pessoa *tabela) {
    int pos = funcaoHash(p.cpf);
    while(tabela[pos].cpf != 0) {
        pos++;
        if(pos > TAM) pos = 0;
    }
    tabela[pos] = p;
}

int busca(Pessoa *tabela, int chave) {
    int aux;
    int pos = funcaoHash(chave);
    aux = pos;
    while(tabela[pos].cpf != chave) {
        if(tabela[pos].cpf == 0) return -1; //se a chave for 0, quer dizer que o elemento não esta inserido ainda
        pos++;
        if(pos > TAM) pos = 0;
        if(pos == aux) return -1; // isso acontece quando é dada uma volta completa no vetor
    }
    return pos;
}

void imprimeTabela(Pessoa *tabela) {
    int i;
    for(i = 0; i < TAM; i++) {
        printf("POS %d: \n", i);
        imprimePessoa(tabela[i]);
        printf("---------------------------------------------------------------------------------\n\n");
    }
}

void imprimePessoa(Pessoa p) {
    printf("Nome: %s\n", p.nome);
    printf("CPF: %d\n", p.cpf);
    printf("Data de nascimento: ");
    imprimeData(p.dataNasc);
    printf("\n");
    printf("Endereco residencial: \n");
    imprimeEndereco(p.endResidencial);
    printf("\n");
    printf("Dados contratuais: \n");
    imprimeContrato(p.contrato);
    printf("\n");
}

void imprimeEndereco(Endereco e) {
    printf("Rua: %s\n", e.rua);
    printf("CEP: %d\n", e.cep);
    printf("Numero: %d\n", e.num);
    printf("Bairro: %s\n", e.bairro);
    printf("Cidade: %s\n", e.cidade);
    printf("Pais: %s\n", e.pais);
}

void imprimeContrato(Contrato c) {
    printf("Contrato: %d\n", c.codigo);
    printf("Cargo: %s\n", c.cargo);
    printf("Salario: %.2f\n", c.salario);
    printf("Data da assinatura: ");
    imprimeData(c.dataAss);
}

void imprimeData(Data d) {
    printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}

Data lerData() {
    Data d;
    printf("Dia: ");
    scanf("%d", &d.dia);
    printf("Mes: ");
    scanf("%d", &d.mes);
    printf("Ano: ");
    scanf("%d%*c", &d.ano);

    return d;
}

Endereco lerEndereco() {
    Endereco e;
    printf("Rua: ");
    scanf("%[^\n]%*c", e.rua);
    printf("CEP: ");
    scanf("%d", &e.cep);
    printf("Numero: ");
    scanf("%d%*c", &e.num);
    printf("Bairro: ");
    scanf("%[^\n]%*c", e.bairro);
    printf("Cidade: ");
    scanf("%[^\n]%*c", e.cidade);
    printf("Pais: ");
    scanf("%[^\n]%*c", e.pais);

    return e;
}

Contrato lerContrato() {
    Contrato c;
    printf("Codigo do contrato: ");
    scanf("%d%*c", &c.codigo);
    printf("Cargo: ");
    scanf("%[^\n]%*c", c.cargo);
    printf("Salario: ");
    scanf("%f%*c", &c.salario);
    printf("Data da assinatura: \n");
    c.dataAss = lerData();

    return c;
}

Pessoa lerPessoa() {
    Pessoa p;
    printf("Nome: ");
    scanf("%*c%[^\n]", p.nome);
    printf("CPF: ");
    scanf("%d%*c", &p.cpf);
    printf("Data de nascimento: \n");
    p.dataNasc = lerData();
    p.contrato = lerContrato();
    printf("Endereço residencial:\n");
    p.endResidencial = lerEndereco();

    return p;
}

int main() {
    Pessoa tabela[TAM], pessoa;
    int opcao, pos, num;
    inicializaTabela(tabela);

    do {
        printf("0 - SAIR\n1 - INSERIR\n2 - BUSCAR\n3 - IMPRIMIR\n");
        scanf("%d", &opcao);
        switch (opcao) {
        case 0:
            break;
        case 1:
            pessoa = lerPessoa();
            insere(pessoa, tabela);
            break;
        case 2:
            printf("Digite o CPF: ");
            scanf("%d", &num);
            printf("\n");
            gettimeofday(&inicio, NULL);
            pos = busca(tabela, num);
            if(pos == -1) printf("O CPF %d nao foi encontrado.\n\n");
            else {
                printf("O CPF %d esta na posicao %d\n\n", num, pos);
                imprimePessoa(tabela[pos]);
            }
            gettimeofday(&fim, NULL);
            printf("\nTempo de execucao: %ld ms\n\n", GET_MS(inicio, fim));
            break;
        case 3:
            printf("\n");
            imprimeTabela(tabela);
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    }while(opcao != 0);

    return 0;
}