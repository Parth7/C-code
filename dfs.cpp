#include<stdio.h>
#include<stdlib.h>
#define initial 1
#define visited 2
int a[100],adj[100][100],pre[100],state[100];
int n;
int top=-1;
void push(int num){
	a[++top]=num;
}

int pop(){
	if(top==-1)
	  return;
	return a[top--];
}
void DFS(int v){    //iterative function
	int i;
	push(v);
	while(top!=-1){
		v=pop();
		state[v]=visited;
		for(i=n-1;i>=0;i--){
			if(adj[v][i]==1 && state[i]==initial){
				push(i);
				pre[i]=v;
			}
		}
	}
	
}   

void DFS(int v){   //recursive function
	int i;
	push(v);
	state[v]=visited;
	for(i=0;i<n;i++){
		if(adj[v][i]==1 && state[v]==initial)
		   DFS(v);
	}
}


void DFStraversal(){
	int i;
	for(i=0;i<n;i++){
	   state[i]=initial;
	   pre[i]=-1;
    }
    printf("enter starting vertex: ");
    scanf("%d",&i);
    DFS(i);
    for(i=1;i<n;i++){
    	if(state[i]==initial)
    	   DFS(i);
    }
    for(i=0;i<n;i++){
         printf("\nvertex: %d   predeccesor: %d \n",i,pre[i]);
    }
}
void creategraph(){
  printf("enter the number of vertices: ");
  scanf("%d",&n);
  int maxedges=n*(n-1);
  int origin,destin,i;
  for(i=1;i<=maxedges;i++){
  	printf("enter %d edge: ",i);
  	scanf("%d%d",&origin,&destin);
  	if(origin==-1 && destin==-1)
  	   break;
  	adj[origin][destin]=1;
  }	
}
int main(){
	creategraph();
	DFStraversal();
}
