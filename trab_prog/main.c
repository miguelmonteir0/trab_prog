#include <stdio.h>
#include <string.h>


typedef struct {
    char turma;
    char nome[40];
    int num;
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

void mostraralunos(int n1, int n2, int n_av){
    aluno *ptr=head;

    printf ("Nome \tNumero \tTurma  \tTeste 1 \tTeste 2 \tAv. Continua \n");

    while (ptr != NULL) {
        ptr->media_f = (ptr->t1 * n1) + (ptr->t2 * n2) + (ptr->av_cont * n_av);

        printf("%s \t%d \t%c \t%.2f \t%.2f \t%.2f \t %.2f \n", ptr->nome, ptr->num, ptr->turma, ptr->t1, ptr->t2, ptr->av_cont, ptr->media_f);

        ptr = ptr->next;
    }
}

int main(){

    int escolha = -1;
    float n1, n2, n_av;

    printf("*********************************************REGISTO ESCOLAR************************************************\n");
    printf("Defina o modelo de avaliacao: \n");
    printf("Introduza a percentagem do primeiro teste [0-100]: \n");
    scanf("%d", &n1);
    printf("Introduza a percentagem do segundo teste [0-100]: \n");
    scanf("%d", &n2);
    printf("Introduza a percentagem da avaliacao continua [0-100]: \n");
    scanf("%d", &n_av);
    n1 = n1*0.01;
    n2 = n2*0.01;
    n_av = n_av*0.01

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

int ModeloAv (){


}