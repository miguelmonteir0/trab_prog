#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char nome[35];
    char turma;
    int num;
    float t1;
    float t2;
    float av_cont;
    float media_f;
    struct aluno *next;
}aluno;

aluno *head = NULL;

void mostraralunos(){
    aluno *ptr=head;

    printf ("Nome\t\t\tNumero \tTurma \tTeste1 \tTeste2 \tAv. Continua \tMedia\n");

    while (ptr != NULL) {

        printf("%s\t\t\t%d \t%c \t%.2f \t%.2f \t%.2f \t\t%.2f\n", ptr->nome, ptr->num, ptr->turma, ptr->t1, ptr->t2, ptr->av_cont, ptr->media_f);

        ptr = ptr->next;
    }
}


void eliminar(){
    int i=1, pos;

    printf("Introduza a posição do elemento que quer eliminar: \n");
    scanf("%d", &pos);

    aluno *aux, *temp;

    aux=temp=head;

    for(i=1; i<pos-1;i++){
        aux=aux->next;
    }
    temp = aux->next;
    aux->next = temp->next;

}
/*
void eliminar()
{
   int pos, i;

   printf("Introduza a posição do elemento que quer eliminar: \n");
   scanf("%d", &pos);


   if (head == NULL)
      return;

   // guardar cabeça da lista
    aluno *aux = head;

    // se for para eliminar a cabeça da lista
    if (pos == 0)
    {
        head = aux->next;   // mudar head
        free(aux);               // free old head
        return;
    }

    // Find previous node of the node to be deleted
    for ( i=0; aux!=NULL && i<pos-1; i++)
         aux = aux->next;

    // If position is more than number of ndoes
    if (aux == NULL || aux->next == NULL)
         return;

    // Node aux->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    aluno *next = aux->next->next;

    // Unlink the node from linked list
    free(aux->next);  // Free memory

    aux->next = next;  // Unlink the deleted node from list
}*/

void adicionaraluno(float n1, float n2, float n_av){
    aluno *novoaluno = malloc(sizeof(aluno));
    printf("Introduza o nome do aluno:\n");
    scanf("%s", novoaluno->nome);
    printf("Introduza a turma do aluno:\n");
    scanf("%s", &novoaluno->turma);
    printf("Introduza o numero do aluno:\n");
    scanf("%d", &novoaluno->num);

    do{
        printf("Introduza a nota do primeiro teste:\n");
        scanf("%f", &novoaluno->t1);
    }while(novoaluno->t1 < 0 || novoaluno->t1 > 20 );

    do{
        printf("Introduza a nota do segundo teste:\n");
        scanf("%f", &novoaluno->t2);
    }while(novoaluno->t2 < 0 || novoaluno->t2 > 20 );

    do{
        printf("Introduza a nota da avaliacao continua:\n");
        scanf("%f", &novoaluno->av_cont);
    }while(novoaluno->av_cont < 0 || novoaluno->av_cont > 20 );

    novoaluno->media_f = (novoaluno->t1 * n1) + (novoaluno->t2 * n2) + (novoaluno->av_cont * n_av);

    novoaluno->next = head;
    head = novoaluno;
}

void OrdenarTurmas(){

    int aux = 1;


    while (aux == 1) {

        aux = 0;

        aluno *ptr = head;
        aluno *prev = NULL;

        while (ptr != NULL) {
            aluno *proxaluno = ptr->next;
            if (proxaluno == NULL){
                break;
            }
            if (ptr->turma > proxaluno->turma) {
                aux = 1;
                ptr->next = proxaluno->next;
                if (prev != NULL){
                    prev->next = proxaluno;
                }else{
                    head = proxaluno;
                    proxaluno->next = ptr;
                }
            }
            prev = ptr;


            ptr = ptr->next;
        }
    }

    mostraralunos();
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
    int n, escolha = -1;
    float n1, n2, n_av;


    printf("*********************************************REGISTO ESCOLAR************************************************\n");
    printf("Defina o modelo de avaliacao: \n");
    do{
        printf("Introduza a percentagem do primeiro teste [0-100]: \n");
        scanf("%f", &n1);
        printf("Introduza a percentagem do segundo teste [0-100]: \n");
        scanf("%f", &n2);
        printf("Introduza a percentagem da avaliacao continua [0-100]: \n");
        scanf("%f", &n_av);
    }while(n1 + n2 + n_av != 100);

    n1 = n1*0.01;
    n2 = n2*0.01;
    n_av = n_av*0.01;



    while (escolha != 0){
        printf ("Escolha uma opcao\n");
        printf ("1 - Mostrar alunos\n");
        printf ("2 - Inserir alunos\n");
        printf ("3 - Eliminar alunos\n");
        printf ("0 - Sair\n");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                OrdenarTurmas();
                break;
            case 2:
                adicionaraluno(n1, n2, n_av);
                break;
            case 3:
                eliminar();
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
