/*
	Autor: Guilherme Bernardo 2019004044
	
	--------------------BEECROWD 2381---------------------
	Tia Joana é uma respeitada professora e tem vários alunos. Em sua última aula, ela prometeu que iria sortear um Aluno para ganhar um bônus especial na nota final: ela colocou N pedaços de papel numerados de 1 a N em um saquinho e sorteou um determinado número K; o Aluno premiado foi o K-ésimo Aluno na lista de chamada.
	O problema é que a Tia Joana esqueceu o diário de classe, então ela não tem como saber qual número corresponde a qual Aluno. Ela sabe os nomes de todos os alunos, e que os números deles, de 1 até N, são atribuídos de acordo com a ordem alfabética, mas os alunos dela estão muito ansiosos e querem logo saber quem foi o vencedor.
	Dado os nomes dos alunos da Tia Joana e o número sorteado, determine o nome do Aluno que deve receber o bônus.
	
	Entrada
	A primeira linha contém dois inteiros N e K separados por um espaço em branco (1 ≤ K ≤ N ≤ 100). Cada uma das Nlinhas seguintes contém uma cadeia de caracteres de tamanho mínimo 1 e máximo 20 representando os nomes dos alunos. Os nomes são compostos apenas por letras minúsculas de 'a' a 'z'.
	
	Saída
	Seu programa deve imprimir uma única linha, contendo o nome do Aluno que deve receber o bônus.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define TAM 21
// ------------------ definição da estrutura!------------------
typedef struct Aluno{
	char nome[TAM];
}Aluno;

int comp(const void *p1,const void *p2){
	Aluno *i=(Aluno *)p1,*j=(Aluno *)p2;
	return strcmp(i->nome,j->nome); //comparador dos elementos de Aluno
}

int main(int argc,char *argv[]){

	int x,n,k;
	scanf("%d %d",&n,&k);
	Aluno Aluno[n];

	for (x=0;x<=n;x++){
	scanf(" %s",Aluno[x].nome);
	}

	qsort(Aluno,n,sizeof(Aluno[0]),comp); 
	// puts("-------------------");
	// puts("o vencedor é:\n");
	printf("%s\n",Aluno[k-1].nome);
	return 0;
}