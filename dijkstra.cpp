#include<stdio.h>
#include<stdlib.h>
#define temp 1
#define perm 2
#define infinity 9999
#define NIL -1
int adj[100][100]={0},path[100],pre[100],status[100];
int n;
void creategraph(){
	int origin,destin,i;
	printf("enter the number of verticces: ");
	scanf("%d",&n);
	int maxedges=n*(n-1);
	for(i=1;i<=maxedges;i++){
		printf("enter %d edge: ",i);
		scanf("%d%d",&origin,&destin);
		if(origin==-1 && destin==-1)
		  break;
		printf("enter weight f vertex: ");
		scanf("%d",&adj[origin][destin]);
	}
}

int mintemp(){
	int i;
	int k=NIL,min=infinity;
	for(i=0;i<n;i++){
		if(status[i]==temp && path[i]<min){
			min=path[i];
			k=i;
		}
	}
	return k;
}

void findpath(int s,int v){
	int u,i;
   int way[100],dist=0;
   int count=0;
   while(v!=s){
   	  path[count]=v;
   	  u=pre[v];
   	  dist+=adj[u][v];
   	  v=u;
   	  count++;
   }
   
   path[count]=s;
   printf("shortest path: ");
   for(i=count;i>=0;i--)
      printf("%d ",path[i]);
    
   printf("\nshortest distance: %d\n",dist);	
}

void dijkstra(int s){
    int i,current;
	for(i=0;i<n;i++){
		status[i]=temp;
		pre[i]=NIL;
		path[i]=infinity;
	}
	path[s]=0;
	while(1){
		current=mintemp();
		if(current==NIL)
		   return;
		status[current]=perm;
		for(i=0;i<n;i++){
			if(adj[current][i]!=0 && status[i]==temp){
				if(path[current]+adj[current][i]<path[i]){
					pre[i]=current;
					path[i]=path[current]+adj[current][i];
				}
			}
		}
	}	
}

int main(){
	int s,v;
	creategraph();
	printf("enter source vertex: ");
	scanf("%d",&s);
	dijkstra(s);
	while(1){
		printf("enter destination vertex: ");
		scanf("%d",&v);
		if(v==-1)
		   break;
		else
		   findpath(s,v);
	}
}
