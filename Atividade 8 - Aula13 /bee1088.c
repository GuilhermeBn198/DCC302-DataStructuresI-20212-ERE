#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
} string;

void sort(string *, int tam);


void sort(string *alunos, int tam) {
  	short i = 1, j;
  	string key;

  	while (i < tam) {
    	j = i - 1;
    	key = alunos[i];

    	while (j >= 0 && strcmp(alunos[j].nome, key.nome) > 0) {
      		alunos[j + 1] = alunos[j];
      		j--;
    	}

    	alunos[j + 1] = key;
    	i++;
  	}
}



void main() {
  	int i;
  	int numalunos, premioAluno;

  	scanf("%d %d", &numalunos, &premioAluno);
  	string alunos[numalunos];

 	for (i = 0; i < numalunos; i++) scanf("%s", alunos[i].nome);

  	sort(alunos, numalunos);

  	printf("%s\n", alunos[premioAluno - 1].nome);
}
