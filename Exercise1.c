#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char code[50];
  char courseName[50];
  char weekday[50];
  char AMPM[50];
  int period[2];
  char week[50];
  char room[50];
}COURSE;

void readFile(char* filename);

int main(int argc, char *argv[]){
  COURSE course[10]; // malloc cho cac phan tu
  if (argc>1)
  {
    char* filename =  argv[1];
    readFile(filename);
    
  }else printf("No source file found!");
  
  return 0;
}

void readFile(char* filename){ 
  // char *list = (char*)malloc(sizeof(char)*200);
  COURSE course[10];
  char list[10][1000];
  FILE *fp;
  int c;
  int courseNum = 0;
  fp = fopen(filename,"r");
  if(fp == NULL){
    printf("Error while opening file.");
  }
  while( (c=fgetc(fp)) != EOF ){   
    if(c != ';'){
      char buff= (char) c;
      strcat(list[courseNum],(char[]){buff, '\0'});      
    }else{
      courseNum++;
      printf("");
    }    
  }
  fclose(fp); 
  for(int i=0;i<courseNum;i++)
  printf("\n\n%s",list[i]);
  // return course[0];
}