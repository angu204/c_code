#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<memory.h>
typedef struct spot{
	int x;
	int y;
	char pic;
} spot;
print_snake(char arr[20][20],spot s[]);
init(spot s[]);
move_all(spot s[],char  b,char  a);
move(spot *s,char  direction);
int main(){
	int i = 0;
	char b,a;
	b = 'R';
	a = 'R';
	spot snake[4];
	init(snake);
	char arry[20][20] ={'-'};
	memset(arry,' ',sizeof(arry));
	print_snake(arry,snake);
	while( i++ < 20 ){
	printf("i====%d\n",i);
		if (i==5){
			b = a;
			a = 'D';	 
		}else if (i == 10){
			b = a;
			a = 'L';	 
		}else if (i == 15){
			b = a;
			a = 'U';	 
		}
		memset(arry,' ',sizeof(arry));
		move_all(snake,b,a);
		print_snake(arry,snake);
		sleep(1);
	}
}
print_snake(char arr[20][20],spot s[]){
	int i,j,m;
	i = 0;
	j = 0;
	m = 0;
	for ( m = 0; m < 4; m++){
		arr[s[m].x][s[m].y] = s[m].pic;	
	}
	for ( ; i < 20; i++){
		for( j = 0; j < 20; j++){
			printf("%c",arr[i][j]); 
		}
		printf("\n");

	}
}
init(spot s[]){
	int i;
	spot s1 = {10,10,'@'};
	spot s2 = {10,9,'*'};
	spot s3 = {10,8,'*'};
	spot s4 = {10,7,'*'};
	s[0] = s1;
	s[1] = s2;
	s[2] = s3;
	s[3] = s4;
}
move_all(spot s[],char  b,char  a){
	int i ;
	for (i = 0; i< 4; i++){
		if ( i == 0)
			move(&s[i],a);
		else
		{
			if ((a == 'R'|| a == 'L') && s[i].x == s[0].x ){
				move(&s[i],a);
			}else if(( a =='D' || a == 'U') && s[i].y == s[0].y) {
				move(&s[i],a);
			}else{
				move(&s[i],b);
			}
		}
	}
}
move(spot *s,char  direction){
	switch (direction){
		case 'R':
			s->y++;
			break;
		case 'D':
			s->x++;
			break;
		case 'L':
			s->y--;
			break;
		case 'U':
			s->x--;
			break;
	}
}
