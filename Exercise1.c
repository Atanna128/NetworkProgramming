#include <stdio.h>

typedef struct {
  char code[50];
  char courseName[50];
  char weekday[50];
  char AMPM[50];
  int period[2];
  char week[50];
  char room[50];
}COURSE;

int main(int argc, char *argv[]){
  COURSE course; // malloc cho cac phan tu
  readFile(argv[1]);
  



  return 0;
}

int readFile(char* filename){
  char *list[2];
  FILE *fp;
  int c;
  int courseNum = 0;
  fp = fopen(filename,"r");
  if(fp == NULL){
    printf("Error while opening file.");
    return 1;
  }
  while( (c=fgetc(fp)) != EOF ){    
    printf("%c", c);
    
  }
  fclose(fp); 
}