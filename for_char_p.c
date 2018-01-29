#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*循环打印字符*/
int main(){
	char arr1[6] = {'n','i','h','a','o'};
	char arr2[6] = {'0'};
	int i,j = 0;
	//printf("Input a number to move\n");
	//scanf("%d",&i);
	while(1){
		i++;
		if (i%5 == 0)
			i = 0;
		for(j = 0; j < 5; j++){
			arr2[(j + i)%5] = arr1[j];
		}
		arr2[5] = '\0';
		printf("%s\n",arr2);
		sleep(1);
		system("clear");
	}
}
