#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i=0;
struct student {
	char roll_no[50][50];
	char first_name[50][50];
	char last_name[50][50];
	int top;
}s1;

int top_s(){
	if( s1.top<=-1 ){
		printf( "STACK UNDERFLOW\n" );
	} else {
		printf( "%s ", s1.roll_no[s1.top] );
		printf( "%s ", s1.first_name[s1.top] );
		printf( "%s\n", s1.last_name[s1.top] );
	}
}

void push( char item[], char fn[], char ln[]){ 
	if (s1.top >= 49){
		printf( "STACK OVERFLOW\n" );
		return ;
	}else{
		s1.top++;    
		strcpy (s1.roll_no[s1.top],item);
		strcpy (s1.first_name[s1.top],fn);
		strcpy (s1.last_name[s1.top],ln);
		printf( "%s ", s1.roll_no[s1.top] );
		printf( "%s ", s1.first_name[s1.top] );
		printf( "%s\n", s1.last_name[s1.top] );
	}
}   

void  pop(){
	//      char item[50];
	//      char fn[50],ln[50];
	//      strcpy (s1.roll_no[s1.top],item);
	top_s();
	s1.top--;
}

int main(){
	int n,p,c=0;
	char ans,cq[10],item[50],fn[50],ln[50];
	scanf( "%d", &n );
	while( n--){
		s1.top=-1;
		scanf( "%d", &p );
		for(i=0;i<p;i++){
			scanf( "%s", cq );
			if(cq[2]=='S'){
				scanf( "%s", item );
				scanf( "%s", fn );
				scanf( "%s", ln );
				push(item,fn,ln);
			}else if(cq[0]=='P' && cq[1]=='O'){
				pop();
			}
			else if(cq[0]=='T'){
				top_s();
			}
		}
	}
	return 0;
}

