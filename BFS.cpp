/*
 2713 - Poisonous Gas COJ
*/
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

vector<int> nodos[100];
queue<int> Q;
int visitados[100];
int n,l,c,s,d,q,conti,T,e;

void bfs(int origen){
	Q.push(origen);
	visitados[origen] = 1;
	while(!(Q.empty())){
		int v = Q.front();
		Q.pop();
		for(int i=0;i<nodos[v].size();i++){
         //printf("%d\n",visitados[nodos[v][i]]);
			if(visitados[nodos[v][i]] == -1){
				visitados[nodos[v][i]] = visitados[v] + 1;
			    Q.push(nodos[v][i]);
			    conti++;
			}  
		}
	}
}

int main(){
	scanf("%d",&T);
	while(T--){
      for(int i=0;i<=n;i++)
         nodos[i].clear();
		scanf("%d %d %d",&n,&l,&c);
      for(int i=0;i<=n;i++)
         visitados[i] = -1;
		for(int i=0;i<l;i++){
			scanf("%d %d",&s,&d);
			nodos[s].push_back(d);
		}

      bfs(1);
		for(int i=0;i<c;i++){
			scanf("%d",&q);
         printf("%d\n",visitados[q]);
		}	
		
	}
	
	return 0;
}
