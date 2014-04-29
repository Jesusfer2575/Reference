//Implementacion de Algoritmo de Kruskal o MST(Minimum Spanning Tree)
/*
 Creado por: Adrián de Jesús Fernández Ramírez
 Implementación en c++
 27/03/2014
*/
#include<stdio.h>
#include<algorithm>
using namespace std;
struct MST{
	int nodo1;
	int nodo2;
	int e;
}Arbol[100005];
bool ordena(const MST &a,const MST &b){
	return a.e<b.e;
}
//Union-Find
int padre[100005];

void MakeSet(int N){
	for(int i=1;i<=N;i++)
	   padre[i]=i;
}

int raiz(int a){
	if(padre[a]==a)
	   return a;
	return padre[a] = raiz(padre[a]);
}
void unir(int a,int b){
	int raizA=raiz(a);
	int raizB = raiz(b);
	padre[raizA]=raizB;
}
bool mismo(int a, int b){
	if(raiz(a)==raiz(b))
	   return true;
	return false;
}
int E,N,j,pesotote,bandera = 0,aristitas[100005];
int main(){
	while(scanf("%d %d",&N,&E)!=EOF){
	    pesotote = 0;
		MakeSet(N);
		for(int i=1;i<=E;i++)
			scanf("%d %d %d",&Arbol[i].nodo1,&Arbol[i].nodo2,&Arbol[i].e);
		
			
		sort(Arbol+1,Arbol+(E+1),ordena);
	    
		//Kruskal
		for(int i=1;i<=E;i++){
			if(!mismo(Arbol[i].nodo1,Arbol[i].nodo2)){//Si no pertenecen a la misma componente se agrega su arista al MST
				unir(Arbol[i].nodo1,Arbol[i].nodo2);//asegurando que no se cree ninguna conexion que haga ciclo
				pesotote += Arbol[i].e;
				aristitas[j] = Arbol[i].e;
				j++; 
			}
			   
		}
		/*for(int i=1;i<=j;i++)
		   printf("%d\n",aristitas[i]);*/
		printf("%d\n",pesotote);
	}
	
	return 0;
}
