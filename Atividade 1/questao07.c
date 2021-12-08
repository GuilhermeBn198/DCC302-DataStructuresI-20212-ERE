#include <stdio.h>
#include <stdlib.h>

char game[3][3];
char player1[50], player2[50];

void initializeMatrix()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            game[i][j] = ' ';
        }
    }
}

int isValid(char word)
{
    if (word == 'x' || word == '0')
        return 1;
    else
        return 0;
}

int coordenateIsValid(int x, int y)
{
    if (x >= 0 && x < 3)
    {
        if (y >= 0 && y < 3)
            return 1;
    }
    return 0;
}

int nullPosition(int x, int y)
{
    if (game[x][y] != 'x' && game[x][y] != '0')
        return 1;
    return 0;
}

int winLines()
{
    int i, j, same = 1;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (isValid(game[i][j]) && game[i][j] == game[i][j + 1])
                same++;
        }
        if (same == 3)
            return 1;
        same = 1;
    }
    return 0;
}

int winColumns()
{
    int i, j, same = 1;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (isValid(game[j][i]) && game[j][i] == game[j + 1][i])
                same++;
        }
        if (same == 3)
            return 1;
        same = 1;
    }
    return 0;
}

int ganhoudiagPrincipal()
{
    int i, same = 1;
    for (i = 0; i < 2; i++)
    {
        if (isValid(game[i][i]) && game[i][i] == game[i + 1][i + 1])
            same++;
    }
    if (same == 3)
        return 1;
    else
        return 0;
}

int ganhoudiagSecundaria()
{
    int i, same = 1;
    for (i = 0; i < 2; i++)
    {
        if (isValid(game[i][3 - i - 1]) && game[i][3 - i - 1] == game[i + 1][3 - i - 2])
            same++;
    }
    if (same == 3)
        return 1;
    else
        return 0;
}

void print()
{
    int lin, col;

    printf("\n\t    0  1  2\n");
    for (lin = 0; lin < 3; lin++)
    {
        printf("\t%d ", lin);
        for (col = 0; col < 3; col++)
        {
            if (col < 2)
                printf(" %c |", game[lin][col]);
            else
                printf(" %c ", game[lin][col]);
        }
        if (lin < 2)
            printf("\n\t   ---------\n");
    }
}

void play()
{
    int x, y, valida, jogadas = 0, winner = 0, ordem = 1;

    do
    {
        do
        {
            print();
            printf("\nDigite a coordenada que deseja jogar: ");
            scanf("%d%d", &x, &y);
            valida = coordenateIsValid(x, y);
            if (valida == 1)
                valida += nullPosition(x, y);
        } while (valida != 2);
        if (ordem == 1)
            game[x][y] = 'x';
        else
            game[x][y] = '0';
        jogadas++;
        ordem++;
        if (ordem == 3)
            ordem = 1;
        winner += winLines();
        winner += winColumns();
        winner += ganhoudiagPrincipal();
        winner += ganhoudiagSecundaria();
    } while (winner == 0 && jogadas < 9);

    if (winner != 0)
    {
        print();
        if (ordem - 1 == 1)
            printf("\nParabens. Voce venceu %s\n", player1);
        else
            printf("\nParabens. Voce venceu %s\n", player2);
    }
    else
        printf("\nDeu Velha!\n\n");
}

int main()
{

    int op;

    printf("Player 1 digite seu nome: ");
    fgets(player1, 50, stdin);
    printf("Player 2 digite seu nome: ");
    fgets(player2, 50, stdin);

    do
    {
        initializeMatrix();
        play();
        printf("Deseja jogar novamente?\n1 - Sim\n2 - Nao\n");
        scanf("%d", &op);
    } while (op == 1);

    return 0;
}