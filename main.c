#include <stdio.h>
#include <string.h>

void copy_content(FILE *file1, FILE *file2){
  char Line[50], Buffer[6] = {' ', ' ', ' ', ' ', ' ', '\0'};
  int i=0;
  printf("escrevendo...\n");
  while (fgets(Line, 50, file1) != NULL){
    //1. aceitar apenas palavras com mais de 4 letras
    if (strlen(Line)>5){
      //2. verificar se primeira letra lida é igual a da palavra anterior
      if (Line[0] == Buffer[0]){
        //3. verificar se segunda letra lida é igual
        if (Line[1] == Buffer[1]) {
          //4. verificar se a terceira letra lida é igual
          if (Line[2] == Buffer[2]){
            //5. verificar se a quarta letra lida é igual
            if (Line[3] == Buffer[3]){
              if (Line[4] != Buffer[4]){
                //6. se a quinta lida for diferente, escreve a palavra e muda a última letra do buffer
                fputs(Line, file2);
                Buffer[4] = Line[4];
              } //6. senão, ignora a palavra
            } //5. senão, escreve a palavra e muda as 2 últimas letras do buffer
            else{
              fputs(Line, file2);
              Buffer[3] = Line[3];
              Buffer[4] = Line[4];
            }
          } //4. senão, escreve a palavra e muda as 3 últimas letras do buffer
          else{
              fputs(Line, file2);
              Buffer[2] = Line[2];
              Buffer[3] = Line[3];
              Buffer[4] = Line[4];
            }
        } //3. senão, escreve a palavra e muda as 4 últimas letras do buffer
        else {
          fputs(Line, file2);
          Buffer[1] = Line[1];
          Buffer[2] = Line[2];
          Buffer[3] = Line[3];
          Buffer[4] = Line[4];
        }
      } //2. senão, escreve a palavra e muda o buffer
      else {
        fputs(Line, file2);
        Buffer[0] = Line[0];
        Buffer[1] = Line[1];
        Buffer[2] = Line[2];
        Buffer[3] = Line[3];
        Buffer[4] = Line[4];
      }
    } //1. senão, ignora a palavra
  }
  printf("finalizado!");
}
 
int main() {
  FILE *dict_unix, *dict_br;

  dict_unix = fopen("unix-br.txt", "r");
  if (dict_unix == NULL){
    printf("Problema na leitura do dicionario unix \n");
    return 0;
  }
  
  dict_br = fopen("dictionary.txt", "w");

  copy_content(dict_unix, dict_br);

  fclose(dict_unix);
  fclose(dict_br);

  return 0;
}