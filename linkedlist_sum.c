#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node *next;
};
int count=0;
typedef struct node node;

void insert( node *head, int num ){
	while( head->next!=NULL){
		head=head->next;
	}
	head->next=( node*)malloc( sizeof(node));
	head=head->next;
	head->value=num;
	head->next=NULL;
}
	
void print( node *head ){
	while( head->next!=NULL ){
		printf( "%d->", head->value );
		head=head->next;
	}
	printf( "%d\n", head->value );
}

int sum( node *head ){
	while( head!=NULL ){
		count=count+head->value;
		head=head->next;
	}
	return count;
}

	
int main(){
	
	node *head;
	int n,i,num,s;
	scanf( "%d", &n );
	head=( node* )malloc( sizeof(node) );
	scanf( "%d", &head->value );
	head->next=NULL;
	for( i=1;i<n;i++){
		scanf( "%d",&num );
		insert( head,num );
	}
	print( head );	
	s=sum( head );
	printf( "%d\n", s );
	return 0;
}

