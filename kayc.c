#include <stdio.h>

int main() {
    int numNotas;
    float soma = 0.0, media;

    printf("Digite o número de notas: ");
    scanf("%d", &numNotas);

    float notas[numNotas];

    for(int i = 0; i < numNotas; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &notas[i]);
        soma += notas[i];
    }

    media = soma / numNotas;

    printf("A média do aluno é: %.2f\n", media);

    return 0;
}
