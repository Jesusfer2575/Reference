//Implementacion de Algoritmo de DFS (Depth First Search) o Búsqueda en profundidad
/*
 Creado por: Adrian de Jesus Fernandez Ramirez
 Implementacion en c++
 12/03/2014
*/
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
 
vector<int>e[10000];
int N,E,nodito1,nodito2;
int etiqueta[10000];
void DFS(int,int);
 
int main(){
 scanf("%d %d",&N,&E);
 for(int i=1;i<=E;i++){
    scanf("%d %d",&nodito1,&nodito2);
    e[nodito1].push_back(nodito2);
    e[nodito2].push_back(nodito1);
 }
 int num_etiqueta = 1;
 for(int i=1;i<=N;i++){
    if(etiqueta[i]==0){
       DFS(i,num_etiqueta);
       num_etiqueta++;
    }
 }
 for(int i=1;i<=N+1;i++)
    printf("%d ",etiqueta[i]);
 puts("");
 /*for(int i=1;i<=N;i++){
    cout<<i<<": ";
    for(int j=0;j<e[i].size();j++)
       cout<<e[i][j]<<" ";
    puts("");
 }*/
 return 0;
}
 
void DFS(int nodito,int nEtiqueta){
      etiqueta[nodito] = nEtiqueta;
   for(int i=0;i<e[nodito].size();i++){
      int nodo = e[nodito][i];
      if(etiqueta[nodo]==0)
         DFS(nodo,nEtiqueta);
   }
}

