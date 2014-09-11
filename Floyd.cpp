/*
Algoritmo de Floyd Warshal para caminos minimos O(N^3)
*/
#include<stdio.h>
#define MAX 100005
int graph[MAX][MAX];
 
int x,y,pe;
int V,E;
 
int main(){
	scanf("%d%d",&V,&E);
	while(E--){
		scanf("%d%d%d",&x,&y,&pe);
		graph[x][y] = pe;
		graph[y][x] = pe;// Para grafos no dirigidos
	}
	
	for(int p=1;p<=V;p++)
		for(int i=1;i<=V;i++)
			for(int j=1;j<=V;j++)
				if(graph[i][p] + graph[p][j] < graph[i][j])
					 graph[i][j] = graph[i][p] + graph[p][j];
	for(int i=1;i<=V;i++){
		for(int j=1;j<=V;j++)
			printf("%d ");
		puts("");
	}
		
	return 0;
}
