#include "menu.h"
#include <stdlib.h>
void ask_menu(char* menu ,int is_login){
// 파라미터 : 로그인여부 (0 No, 1Yes)
// 리턴값 : 선택한 메뉴번호
// 메뉴번호 : 1. Sign up 2. Log in 3. Log out 0. Exit

  if(is_login==0||is_login==-1) // 로그인 안 함. 
    printf(">");
  else if(is_login==1) //로그인 한 경우
    printf("#");
   scanf("%s",menu);
   //scanf("%c",&c);
}
  

