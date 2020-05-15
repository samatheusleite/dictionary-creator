#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void copy_content(FILE *file1, FILE *file2){
  char Line[50], Buffer[5] = {' ', ' ', ' ', ' ', '\0'};
  int i=0;
  printf("escrevendo...\n");
  while (fgets(Line, 50, file1) != NULL){
    int j=0;
    while (Line[j]!='\n'){
      Line[j] = tolower(Line[j]);
      j++;
    }
    fputs(Line, file2);
  }
  printf("finalizado!");
  return;
}

void error_reading_file(FILE *file){
  if (file == NULL){
      printf("Problema na leitura do dicionario\n");
      exit(0);
    }
}

int main(){
  FILE *dict_unix, *dict_br;
  
  dict_unix = fopen("unix-br.txt", "r");
  error_reading_file(dict_unix);

  dict_br = fopen("dictionary.txt", "w");

  copy_content(dict_unix, dict_br);

  fclose(dict_unix);
  fclose(dict_br);

  return 0;
}