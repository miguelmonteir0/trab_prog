#include <stdio.h>
#include <string.h>
#include "alunos.h"

typedef struct {
    char turma;
    char nome[40];
    int numero;
    float t1;
    float t2;
    float av_cont;
    float media_f;
    struct aluno *next;
} aluno;


void adicionaraluno (){
    aluno *novoaluno =malloc(sizeof(aluno));
    printf("Introduza o nome do aluno:\n");
    scanf("%s", novoaluno->nome);
    printf("Introduza o numero do aluno:\n");
    scanf("%s", novoaluno->numero);
    printf("Introduza a turma do aluno:\n");
    scanf("%s", novoaluno->turma);
    printf("Introduza a nota do primeiro teste:\n");
    scanf("%d", &novoaluno->t1 );
    printf("Introduza a nota do segundo teste:\n");
    scanf("%f", &novoaluno->t2);
    printf("Introduza a nota da avaliacao continua:\n");
    scanf("%f", &novoaluno->av_cont);

    novoaluno->next = head;
    head = novoaluno;
}

void write(){
    FILE *fptr;
    fptr = fopen ("alunos.b","wb");

    if(fptr == NULL){
        printf("Erro ao abrir ficheiro");
        return;
    }

    aluno *ptr = head;

    while (ptr != NULL){
        fwrite(ptr, sizeof(aluno),1,fptr);
        ptr = ptr->next;
    }
    fclose(fptr);

}
void read(){
    FILE *fptr;
    fptr = fopen ("aluno.b","rb");

    if(fptr == NULL){
        printf("Erro ao abrir ficheiro");
        return;
    }

    while (1){
        aluno *novoaluno = malloc(sizeof(aluno));
        if (fread(novoaluno, sizeof(aluno),1,fptr)==0 ){
            fclose(fptr);
            return;
        }
        novoaluno->next = head;
        head = novoaluno;
    }

    fclose(fptr);

}

int main(){
    printAluno();

    int escolha = -1;


    while (escolha != 0){
        printf ("Escolha uma opcao\n");
        printf ("1 - Mostrar alunos\n");
        printf ("2 - Inserir alunos\n");
        printf ("3 - Eliminar alunos\n");
        printf ("0 - Sair\n");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                // Mostrar alunos
                ();
                break;
            case 2:
                //inserir aluno
                ();
                break;
            case 3:
                //inserir nota 1
                ();
                break;
            case 0:
                write();
                exit(0);
                break;
            default:
                printf ("Opção inválida\n");
        }
    }
    return 0;
}