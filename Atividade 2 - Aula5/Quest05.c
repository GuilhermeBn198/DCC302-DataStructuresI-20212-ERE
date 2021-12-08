#include <stdio.h>
#include <stdlib.h>

#define TAM 3

typedef struct
{
  int dia;
  int ano;
  char mes[30];
} Data;

typedef struct
{
  char nome[31];
  int idade;
  char sexo;
  char cpf[12];
  char cargo[31];
  float salario;
  Data nascimento;
  int cod_setor;
} Funcionario;

int main(int argc, char *argv[])
{
  Funcionario funcionarios[TAM];

  // Pega as informacoes para preencher o vetor
  for (int i = 0; i < TAM; i++){
    printf("Entrada de dados do funcionario %d \n", i + 1);
    printf("\t Nome: ");
    scanf(" %c", &funcionarios[i].nome);
    printf("\t Idade: ");
    scanf(" %d", &funcionarios[i].idade);
    printf("\t Sexo: ");
    scanf(" %c", &funcionarios[i].sexo);
    printf("\t CPF: ");
    scanf(" %c", &funcionarios[i].cpf);
    printf("\t Cargo: ");
    scanf(" %c", &funcionarios[i].cargo);
    printf("\t Salario: ");
    scanf(" %f", &funcionarios[i].salario);
    printf("\t Data de nascimento: ");
    scanf(" %d %c %d", &funcionarios[i].nascimento.dia, &funcionarios[i].nascimento.mes, &funcionarios[i].nascimento.ano);
    printf("\t Codigo do setor: ");
    scanf(" %d", &funcionarios[i].cod_setor);
  }

  // Imprime informações
  printf("\n \n Imprimindo vetor: \n \n");
  for (int i = 0; i < TAM; i++)
  {
    printf("Funcionario %d : \n", i + 1);
    printf("\t Nome: %s \n ", funcionarios[i].nome);
    printf("\t Idade : %d \n", funcionarios[i].idade);
    printf("\t Sexo: %c \n ", funcionarios[i].sexo);
    printf("\t CPF: %s \n", funcionarios[i].cpf);
    printf("\t Cargo: %s \n", funcionarios[i].cargo);
    printf("\t Salario: %.2f  \n", funcionarios[i].salario);
    printf("\t Data de nascimento: %d de %s de %d \n", funcionarios[i].nascimento.dia, funcionarios[i].nascimento.mes, funcionarios[i].nascimento.ano);
    printf("\t Codigo do setor: %d \n \n", funcionarios[i].cod_setor);
  }

  return 0;
}