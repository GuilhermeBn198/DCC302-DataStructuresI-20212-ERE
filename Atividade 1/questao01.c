#include <stdio.h>
int main()
{
  char str[1000], rev[1000];
  int i, j, count = 0;
  scanf("%s", str);
  printf("\nString Before Reverse: %s", str);
  //encontrando o tamanho das strings
  while (str[count] != '\0')
  {
    count++;
  }
  j = count - 1;

  //fazendo swap 
  for (i = 0; i < count; i++)
  {
    rev[i] = str[j];
    j--;
  }

  printf("\nString After Reverse: %s\n", rev);
}