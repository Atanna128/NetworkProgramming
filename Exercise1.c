#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char code[20];
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
  if(fp == NULL)
  {
    printf("Error while opening file.");
  }
  while( (c=fgetc(fp)) != EOF )
  {   
    if(c != ';'){
      char buff= (char) c;
      strcat(list[courseNum],(char[]){buff, '\0'});      
    }else{
      course[courseNum] = Analyse(list[courseNum]);
      courseNum++;
    }    
  }
  fclose(fp); 
  for(int i=0;i<courseNum;i++)
  // printf("\n\n%s",list[i]);

  return course;
}

COURSE Analyse(char* list){
  COURSE course;
  char code[20] = "";
  char courseName[50] = "";
  char weekday[50] = "";
  char AMPM[50] = "";
  int period[2] = {0,0};
  char week[50] = "";
  char room[50] = "";
  int i = 0;
  int length = strlen(list);
  for(i;i<length;i++)
  { // get code
    if(list[i] != ' ')
    {
      strcat(code,(char[]){list[i],'\0'});
    }
    else break;
  }
  for(i;i<length;i++)
  {
    if(list[i] == '1' && list[i+1] == ',' ){
      break;
    }
    else strcat(courseName,(char[]){list[i],'\0'});
  }

  strcpy(course.code,code);
  strcpy(course.courseName,courseName);
  printf("%s\t %s\n",course.code,course.courseName);
  return course;
}