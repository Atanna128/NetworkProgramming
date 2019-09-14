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
COURSE* ReadFile(char* filename);
COURSE Analyse(char* list);

int main(int argc, char *argv[]){
  COURSE *course1= malloc(sizeof(COURSE)*10);
  if (argc>1)
  {
    char* filename =  argv[1];
    course1 = ReadFile(filename);
    
    // printf("\n\n period = %d",course1[0].period[0]);
        
  }else printf("No source file found!");
  
  return 0;
}

COURSE* ReadFile(char* filename){ 
  COURSE *course = malloc(sizeof(COURSE)*10);
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
      course[courseNum] = Analyse(list[courseNum]);
      courseNum++;
    }    
  }
  course[0].period[0] =1;
  fclose(fp); 
  for(int i=0;i<courseNum;i++)
  // printf("\n\n%s",list[i]);

  return course;
}

COURSE Analyse(char* list){
  // printf("%s\n",list);
}