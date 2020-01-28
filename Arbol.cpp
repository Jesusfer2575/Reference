#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;

typedef struct nodo{
	int dato;
	struct nodo *izq,*der;
}*Arbol;

Arbol crea(int elem){
	Arbol a = (Arbol)malloc(sizeof(struct nodo));
	a->dato = elem;
	a->der = NULL;
	a->izq = NULL;
	return a;
}

void inserta(Arbol &a,int x){
	if(a==NULL)
		a = crea(x);
		
	else if(x < a->dato)
		inserta(a->izq,x);
		
	else if(x > a->dato)
		inserta(a->der,x);
}

void preorden(Arbol a){
	if(a!=NULL){
		cout<<a->dato<<"\n";
		preorden(a->izq);
		preorden(a->der);
	}
}

void inorden(Arbol a){
	if(a!=NULL){
		inorden(a->izq);
		cout<<a->dato<<"\n";
		inorden(a->der);
	}
}
void postorden(Arbol a){
	if(a!=NULL){
		inorden(a->izq);
		inorden(a->der);
		cout<<a->dato<<"\n";
	}	
}
int main(){
	int n,number;
	Arbol ar = NULL;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&number);
		inserta(ar,number);
	}
	//preorden(ar);
	inorden(ar);
	//postorden(ar);
	return 0;
}
