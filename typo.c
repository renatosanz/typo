#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include<unistd.h>
#include <inttypes.h>

#define RAND_POS_MAX 22223 
#define NUM_WORDS 7
#define WORD_SIZE 10

typedef struct NODE{
  char string[WORD_SIZE];
  struct NODE *next;
}NODE;

int getRandNumber();
int clearSnt(NODE *sntc);
int64_t thisTime();
void getRandomWord(char* strin);
void printSnt(NODE *head);
void printSntERROR(NODE *head);
NODE* sntCreator(NODE* head,int n_word);
NODE* checkSntce(char *sntcUsr, NODE* sntc);

int main(int argc, char const *argv[]){
  int maxCharacters = NUM_WORDS*WORD_SIZE;
  int64_t start_t, end_t;
  double total_t;
  char cad[maxCharacters],op='s';
  struct NODE *sntrpl = NULL;
  
  while(op=='s'){
    start_t=thisTime();
    fflush(stdin);
    fflush(stdin);
    fflush(stdin);
    printf("\033[H\033[J");
    printf("\n                                                            ");
    printf("\n                                                            ");
    printf("\n                                                            ");
    printf("\n                                                            ");
    printf("\n                                                            ");
    printf("\n                                                            ");
  
    clearSnt(sntrpl);
    sntrpl=NULL;
    sntrpl = sntCreator(sntrpl,NUM_WORDS); // cadena a replicar
    printf("\rREPLICA: ");
    printSnt(sntrpl);
    
    printf("\r\r\r\rREPLICA: ");


    fflush(stdin);
    fgets(cad,maxCharacters,stdin);
    getchar();

    fflush(stdin);

    end_t=thisTime();
    
    printf(" ---ERRORES---\n");
    printSntERROR(checkSntce(cad,sntrpl));
    total_t = (float)(end_t-start_t)/1000;
    printf("\nMedia de tiempo por palabra: %.3f\n",total_t/NUM_WORDS);
    printf("\nVolver a intentar: Si(s) No(n): ");
    scanf("%c",&op);
    getchar();
  }
  return 0;
}

NODE* checkSntce(char *sntcUsr, NODE* sntc){
  NODE *aux = sntc, *errors = NULL;
  int i,j=0,report;
  while(aux!=NULL){
    report=0;
    fflush(stdin);
    for (i = 0; i < WORD_SIZE; ++i) {
      if (aux->string[i]!=' ' && aux->string[i]!=0) {
        if (aux->string[i]!=sntcUsr[j]){
          report=1;
        }
        j++;
      }
    }
    if (report == 1) {
      NODE* newError = (NODE *)malloc(sizeof(NODE));
      strcpy(newError->string,aux->string);
      newError->next = NULL;
      if (errors==NULL) {
        errors=newError;
      }else{
        NODE* list = errors;
        while(list->next!=NULL){
          list = list->next;
        }
        list->next = newError;
      }
    }
    aux=aux->next;
    j++;
  }
  return errors;
}

NODE* sntCreator(NODE* head,int n_word){
  if (n_word==0) {return head;}
  NODE* aux = (NODE *)malloc(sizeof(NODE));
  getRandomWord(aux->string);
  aux->next = NULL;
  if (head==NULL){
    head = aux;
    return sntCreator(head,n_word-1);
  }
  NODE* list = head;
  while(list->next!=NULL){
    list = list->next;
  }
  list->next = aux;
  return sntCreator(head,n_word-1);
}

void getRandomWord(char* strin){
  FILE *data = fopen("data.txt","r");
  if (data!=NULL) {
    srand(getRandNumber());
    int randpos = rand() % RAND_POS_MAX; 
    fseek(data,randpos,SEEK_SET);
    char p = fgetc(data);

    strcpy(strin,"          ");
    while(ftell(data)<RAND_POS_MAX){
      fseek(data,1,SEEK_CUR);
 //     sleep(1);
      p = fgetc(data);
      if (p==' ') {
        break;
      }
    }
    fscanf(data,"%s",strin);
    fclose(data);
  }
}

int getRandNumber(){
  unsigned int randValue;
  FILE *f;

  f = fopen("/dev/random","r");
  fread(&randValue,sizeof(randValue),1,f); 
  fclose(f);
  return randValue;
}

void printSnt(NODE *head){
  NODE* list = head; 
  while(list!=NULL){
    printf("%s ", list->string);
    list=list->next;
  }
}

void printSntERROR(NODE *head){
  NODE* list = head; 
  while(list!=NULL){
    printf("%s \n", list->string);
    list=list->next;
  }
}

int clearSnt(NODE *sntc){
  NODE* aux = sntc, *auxFree = NULL;
  if (sntc==NULL) { return 0;}
  while(aux!=NULL){
    auxFree=aux;
    aux=aux->next;
    free(auxFree);
  }
}

int64_t thisTime(){
    struct timespec now;
    timespec_get(&now, TIME_UTC);
    return ((int64_t) now.tv_sec) * 1000 + ((int64_t) now.tv_nsec) / 1000000;
}

