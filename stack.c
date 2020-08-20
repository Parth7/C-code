#include<stdio.h>
#include<stdlib.h>
int i=0;
struct stack{
	int s[50];
	int top;
}se;

int top_s(){
	if( se.top<=-1 ){
		printf( "STACK UNDERFLOW\n" );
	} else {
		printf( "%d\n", se.s[se.top]);
	}
}

int push(int item){
	if (se.top >= 49){
		printf( "STACK OVERFLOW\n" );
		return 0;
	}else{
		se.top++;
		se.s[se.top] = item;	
	        printf( "%d\n", se.s[se.top] );
	}
}

void  pop(){
	top_s();
	se.top--;	
}

int main(){
	int item,n,p,a,c=0;
	char ans,cq[10];	
	scanf( "%d", &n );
	while( n--){
		++i;
		se.top=-1;
		scanf( "%d", &p );
		for(i=0;i<p;i++)
		{
			scanf( "%s", cq );
			if(cq[2]=='S')
			{
				scanf( "%d", &a );
				push(a);
			}
			else if(cq[0]=='P' && cq[1]=='O')
			{
				pop();
			}	
			else if(cq[0]=='T')
			{
				top_s();
			}
		}
	}
	return 0;
}
