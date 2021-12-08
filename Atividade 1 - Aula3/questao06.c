#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#define limpar_input() __fpurge(stdin)
#define limpar_tela() system("clear")

char word[20];
char strength[20];
char errors[27];

void limpabuffer(char *buff, int size)
{
  int i = 0;
  for (i = 0; i < size; i++)
  {
    buff[i] = 0;
  }
}

void trimEnd(char *str)
{
  int p;
  for (p = strlen(str);  (str[p]); p--)
  {
    str[p] = 0;
  }
}

int ehLetra(char c)
{
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char uppercase(char c)
{
  return (c >= 'a' && c <= 'z') ? (c - 32) : c;
}

void start(void)
{
  limpabuffer(word, 20);
  limpabuffer(strength, 20);
  limpabuffer(errors, 27);

  printf("\nDigite a palavra secreta: ");
  fgets(word, 20, stdin);
  limpar_input();

  trimEnd(word);

  int i;
  for (i = 0; word[i] != 0; i++)
  {
    char c = word[i];
    strength[i] = ehLetra(c) ? '_' : c;
  }
}

int jogo(void)
{
  char tries;
  int chances = 5;

  int letras = 0;
  int i;
  for (i = 0; word[i] != 0; i++)
  {
    if (ehLetra(word[i]))
      letras++;
  }

  while (chances > 0)
  {
    limpar_tela();
    printf("\nChances: %d - palavras tem %d letras\n\n", chances, letras);

    printf("%s", strength);
    if (strlen(errors) > 0)
    {
      printf("\nErros: %s", errors);
    }

    printf("\n\nDigite uma letra: ");
    scanf("%c", &tries);
    limpar_input();

    // Se o usuário digitou algo que não é letra, o jogo continua sem queimar uma chance.
    if (!ehLetra(tries))
      continue;

    // Se o usuário digitou algo que ele já tentou antes (seja errando ou acertando), o jogo continua sem queimar uma chance.
    int jaTentou = 0;
    for (i = 0; errors[i] != 0; i++)
    {
      if (errors[i] == uppercase(tries))
      {
        jaTentou = 1;
        break;
      }
    }
    if (jaTentou)
      continue;
    for (i = 0; strength[i] != 0; i++)
    {
      if (uppercase(strength[i]) == uppercase(tries))
      {
        jaTentou = 1;
        break;
      }
    }
    if (jaTentou)
      continue;

    int win = 1;
    int found = 0;
    for (i = 0; word[i] != 0; i++)
    {
      if (!ehLetra(word[i]))
        continue;
      if (strength[i] == '_')
      {
        if (uppercase(word[i]) == uppercase(tries))
        {
          strength[i] = word[i];
          found = 1;
        }
        else
        {
          win = 0;
        }
      }
    }

    if (win)
    {
      return 1;
    }

    if (!found)
    {
      chances--;
      errors[strlen(errors)] = uppercase(tries);
    }
  }
  return 0;
}

void showresult(int result)
{
  limpar_input();
  if (result == 0)
  {
    printf("\nVoce perdeu. \nA palavra era %s", word);
  }
  else
  {
    printf("\nParabens, voce acertou a palavra %s ", word);
  }
}

int main()
{
  start();
  int result = jogo();
  showresult(result);
  return 0;
}