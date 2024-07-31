#include <stdio.h>
#include <stdlib.h>

typedef union documento{
    char cpf[15];
    char rg[15];
    char sus[15];
    char pass[15];
} Documento;

typedef enum genero{
    MASCULINO = 1,
    FEMININO,
    NEUTRO,
    OUTRO
} Genero;

typedef struct pessoa{
    char nome[50];
    Documento documento;
    int idade;
    Genero genero;
    int tipoDoc;
} Pessoa;

void preenche(Pessoa *pessoa){
    printf("Informe o nome: \n");
    scanf(" %[^\n]", pessoa->nome);
    printf("Informe o tipo do documento: (1-CPF, 2-RG, 3-SUS, 4-PASS)\n");
    scanf("%d", &pessoa->tipoDoc);
    switch(pessoa->tipoDoc){
        case 1:
            printf("Informe o CPF: \n");
            scanf("%s", pessoa->documento.cpf);
            break;
        case 2:
            printf("Informe o RG: \n");
            scanf("%s", pessoa->documento.rg);
            break;
        case 3:
            printf("Informe o SUS: \n");
            scanf("%s", pessoa->documento.sus);
            break;
        case 4:
            printf("Informe o PASS: \n");
            scanf("%s", pessoa->documento.pass);
            break;
        default:
            printf("Opção de documento inválida!\n");
            break;
    }
    printf("Informe sua idade: \n");
    scanf("%d", &pessoa->idade);
    printf("Informe seu gênero: (1-Masculino, 2-Feminino, 3-Neutro, 4-Outro)\n");
    scanf("%d", (int *)&pessoa->genero);
}

void imprime(Pessoa *pessoa){
    printf("Nome: %s\n", pessoa->nome);
    switch(pessoa->tipoDoc){
        case 1:
            printf("CPF: %s \n", pessoa->documento.cpf);
            break;
        case 2:
            printf("RG: %s \n", pessoa->documento.rg);
            break;
        case 3:
            printf("SUS: %s \n", pessoa->documento.sus);
            break;
        case 4:
            printf("PASS: %s\n", pessoa->documento.pass);
            break;
        default:
            printf("Opção de documento inválida!\n");
            break;
    }
    printf("Idade: %d\n", pessoa->idade);
    printf("Gênero: %s\n", pessoa->genero == MASCULINO ? "MASCULINO" :
                          pessoa->genero == FEMININO ? "FEMININO" :
                          pessoa->genero == NEUTRO ? "NEUTRO" : "OUTRO");
}

int main(void){
    Pessoa pessoa;

    preenche(&pessoa);
    imprime(&pessoa);

    return 0;
}
