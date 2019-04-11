#include "user.h"

//user.tct의 파일에 있는 사용자 id,password 읽어오기
int load_file(LOGIN* list[], char* filename){
 #ifdef DEBUG_MODE
  printf("DEBUG: load_file()");
 
 #endif
  
int count=0;
  int choice;
 FILE *datafile = fopen(filename, "r");

if(datafile == NULL){
   printf("Error!!\n");
   printf("%s file not exist! makew anyway?(yes1, no 2) >> \n",filename);
   scanf("%d",&choice);

   if(choice ==1){
      printf("Welcome\n");
      datafile = fopen(filename,"w");
 	fclose(datafile);
    }	return 0;
  }

   datafile = fopen(filename,"r");
  while(!feof(datafile)){
    list[count]=(LOGIN*)malloc(sizeof(LOGIN));
    fscanf(datafile,"%s %s",list[count]->id,list[count]->password);
    count++;
  }
  printf("%d records read!\n",count);\
  fclose(datafile);
  count--;
  return count;
}

//회원가입
void join(LOGIN* list[], int count){
  char id[20], pass[20];
  while(1){
    printf("Enter new user id >> ");
    scanf("%s", id); 
    int dup=0;//현재 아이디 없는 경우 0
    for(int i=0;i<count;i++){//현재 있는 id 인지 check
      if(strcmp(id, list[i]->id)==0) {
        dup=1; break; //있으면 dup = 1
      }
    }
    if(dup==1){
      printf("Already exist!!\n");
    }
    else{ //없으면
      printf("Enter password >> ");
      scanf("%s", pass);
      list[count] = (LOGIN*)malloc(sizeof(LOGIN));
      strcpy(list[count]->id, id); //비밀번호 입력 후 , 아이디와 비번을 포인터에 저장한다.
      strcpy(list[count]->password, pass);
      printf("New user added!\n");
      break;
    }
  }
}
//
int login(LOGIN* list[], int count){
  char id[20], pass[20];
  printf("Enter user id >> ");
  scanf("%s", id);
  int dup=0, found; //아이디가 기존에 있는 아이디인지 찾기
  for(int i=0;i<count;i++){
    if(strcmp(id, list[i]->id)==0) {
      dup=1; //기존 회원이면 dup =1
      found = i;
      break;
    }
  }
  if(dup!=1){ 
    printf("No such user!!\n");
    return -1;
  }
  else{
    printf("Enter password >> ");
    scanf("%s", pass);
    if(strcmp(list[found]->password, pass)==0){
      printf("Welcome %s!!\n", id);
      return 1;
    }
    else{
      printf("Password incorrect!!\n");
      return 0;
    }
  }
}
void logout(int* is_login){
#ifdef DEBUG_MODE

printf("DEBUG: logout()");
  #endif  
*is_login = 0;
  printf("Logout!!\n");
}

void save_file(LOGIN* list[], int count, char* filename){
 #ifdef DEBUG_MODE
     printf("DEBUG: save_file()");
#endif
  FILE *datafile = fopen(filename, "w");
  for(int i=0; i<count; i++){
    fprintf(datafile, "%s %s\n", list[i]->id, list[i]->password);
  }
  printf("%s Saved!\n", filename);
  fclose(datafile);
}
void list(LOGIN* list[], int count){
#ifdef DEBUG_MODE
printf("DEBUG: list()"); 
#endif
 
for(int i=0; i<count; i++){
     printf("[%d]%s / %s\n",i+1,list[i]->id, list[i]->password); 
 }
}
