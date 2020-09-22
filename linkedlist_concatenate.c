#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node *next;
};

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

void insert1( node *head1, int num1 ){
        while( head1->next!=NULL){
                head1=head1->next;
        }
        head1->next=( node*)malloc( sizeof(node));
        head1=head1->next;
        head1->value=num1;
        head1->next=NULL;
}	
void print( node *head ){
	while( head->next!=NULL ){
		printf( "%d->", head->value );
		head=head->next;
	}
	printf( "%d\n", head->value );
}
	
void print1( node *head1 ){
        while( head1->next!=NULL ){
                printf( "%d->", head1->value );
                head1=head1->next;
        }
        printf( "%d\n", head1->value );
}

void print2( node *head, node*head1 ){
	while( head!=NULL ){
		printf( "%d->", head->value );
		head=head->next;
	}
	while( head1->next!=NULL ){
		printf( "%d->", head1->value );
		head1=head1->next;
	}
	printf( "%d\n", head1->value );
}
int main(){
	
	node *head,*head1;
	int n,i,num,n1,num1;
	scanf( "%d", &n );
	head=( node* )malloc( sizeof(node) );
	scanf( "%d", &head->value );
	head->next=NULL;
	for( i=1;i<n;i++){
		scanf( "%d",&num );
		insert( head,num );
	}
	print( head );	
	scanf( "%d", &n1 );
	head1=( node* )malloc( sizeof( node) );
	scanf( "%d", &head1->value );
	head1->next=NULL;
	for( i=0;i<n;i++){
		scanf( "%d", &num1 );
		insert1( head1,num1 );
	}
	print1( head1 );
	print2( head, head1 );
	return 0;
}

