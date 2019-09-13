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

int main(int argc, char *argv[]){
  COURSE course; // malloc cho cac phan tu
  if (argc>1)
  {
    readFile(argv[1]);
  }
  
  



  return 0;
}

int readFile(char* filename){ // tra ve chuoi~ cai string de xu ly
  // char *list = (char*)malloc(sizeof(char)*200);
  char list[10][1000];
  FILE *fp;
  int c;
  int courseNum = 0;
  fp = fopen(filename,"r");
  if(fp == NULL){
    printf("Error while opening file.");
    return 1;
  }
  while( (c=fgetc(fp)) != EOF ){   
    if(c != ';'){
      char buff= (char) c;
      // printf("%c",buff);      
      strcat(list[courseNum],(char[]){buff, '\0'});    
      
      
    }else{
      courseNum++;
      printf("");
    }
    
  }
  fclose(fp); 
  for(int i=0;i<courseNum;i++)
  printf("\n\n%s",list[i]);
  return 0;
}