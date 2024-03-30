#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[32];
    int mat;
    char curso[32];
    int idade;
}   Aluno;


int main (void)
{
    Aluno aluno[2];
    printf("Dados do aluno 1:\n<nome>\n<matricula>\n<curso>\n<idade>\n");
    scanf ("%[^\n]%*c", &aluno[0].nome); 
    scanf("%d%*c", &aluno[0].mat);
    scanf ("%[^\n]%*c", &aluno[0].curso);
    scanf("%d%*c", &aluno[0].idade);

    printf("Dados do aluno 2:\n<nome>\n<matricula>\n<curso>\n<idade>\n");
    scanf ("%[^\n]%*c", &aluno[1].nome);
    scanf("%d%*c", &aluno[1].mat);
    scanf ("%[^\n]%*c", &aluno[1].curso);
    scanf("%d%*c", &aluno[1].idade);

    printf("Dados do aluno 1:\n");
    printf("Nome: %s\n", aluno[0].nome);
    printf("Matrícula: %d\n", aluno[0].mat);
    printf("Curso: %s\n", aluno[0].curso);
    printf("Idade: %d\n", aluno[0].idade);

    printf("Dados do aluno 2:\n");
    printf("Nome: %s\n", aluno[1].nome);
    printf("Matrícula: %d\n", aluno[1].mat);
    printf("Curso: %s\n", aluno[1].curso);
    printf("Idade: %d\n", aluno[1].idade);

    return 0;
}

