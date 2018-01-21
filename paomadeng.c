#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
/*利用指针，实现跑马灯的效果*/
int main(){
 char a[] = "hello,world";
 char *p = NULL;

    p = a;
   while(1){

    while(*p != '\0'){
      system("clear");
      printf("%s\n",p);
      p++;
      sleep(1);
     }
    p = a;
 }

}
