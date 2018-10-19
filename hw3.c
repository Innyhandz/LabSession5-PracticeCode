#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h>
#include<sys/stat.h> 
#include<fcntl.h>


int main(){

  char line[500];
  char *argsarray[120]= {"/bin/ls",(char*) 0 };
 char *argsarrayA[120]; 
 char *argsarrayB[120];
  char quit[10];
  strcpy(quit, "exit");
  int quits = 1;
  int j = 9999;
  char semi[10];
  strcpy(semi, ";");
  int semicolon = 0;
//Loop

while(quits == 1){
  j = 9999;
  if(quits == 0){
	break;
   }
  printf("CS361 >");

//parser
  fgets(line, 500, stdin);

char *word = strtok(line, " \n");
int i = 0;

//strcpy to argarray 
while(word){

if(strncmp(word, semi, strlen(semi)) == 0){
        
//       printf("semicolon found at %d word\n", i);
       j= i;
      semicolon = 1;
       i=i+1;            
      word = strtok(NULL, " "); 
      continue;
 }


if(semicolon == 1){
argsarrayA[i] =(char*)malloc(sizeof(word)+1); 
strcpy(argsarrayA[i], word);
}
else{
argsarray[i] =(char*)malloc(sizeof(word)+1);
strcpy(argsarray[i],word);
} 


if(strncmp(word, quit, strlen(quit))== 0){
//   printf("Quitting Program...\n");
   quits=0; 
   break;
   }

word = strtok(NULL, " ");  
 i=i+1;


 }



//do basic arguments
int pid = fork();



//redirection checker 

//semicolon checker



if(pid == 0){
 if(j!= 9999){
 execvp(argsarrayA[0], argsarrayA);

}
 
 
 execvp(argsarray[0],argsarray);
}
else{
 int status;
 wait(&status);
 printf("pid:%d status:%d\n", pid, WEXITSTATUS(status));
}

 }

return 0; 
}
 
