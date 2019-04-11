#include "user.h"
#include "menu.h"
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
  LOGIN* userlist[100]; // 사용자목록 포인터 배열 (최대 100)
  int is_login=0; // 로그인 여부 (0 NO, 1 Yes)
  int menu_id;
  int choice;
  int check;
  char* menu=(char*)malloc(sizeof(char)*20); 
 
  FILE *fp; 
  if (argc != 2) {
    printf("Usage : manager <datafile>\n");
    return 0;
  }

  int count = load_file(userlist, argv[1]);
  while(1){
   // if(is_login==0 && count!=0) is_login = login(userlist,count); 
   
    ask_menu(menu,is_login); // 현재 로그인 되었는지의 여부를 파라미터로 알려야 한다.
   if(is_login == 0||is_login == -1){
     if(strcmp(menu,"join") ==0) {join(userlist, count); count++;}
     else if (strcmp(menu,"login")==0) is_login = login(userlist, count);
     else if (strcmp(menu,"list")==0) list(userlist,count);
     else if (strcmp(menu,"exit")==0) break; 
     else printf("No such command!\n");
	
  }
     else{
	if(strcmp(menu,"logout")==0) logout(&is_login);
	else printf("%s\n",menu);	
}
}
  save_file(userlist, count, argv[1]);
  return 0;
}
