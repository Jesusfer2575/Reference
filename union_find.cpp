#include<stdio.h>
#include<algorithm>
using namespace std;

//Union-Find
int padre[1000005];

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
	int raizA = raiz(a);
	int raizB = raiz(b);
	padre[raizA]=raizB;
}
bool mismo(int a, int b){
	if(raiz(a)==raiz(b))
	   return true;
	return false;
}
int E,N;
int main(){
	scanf("%d",&N);
	MakeSet(N);
	
	return 0;
}
