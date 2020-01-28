#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct nodo{
	int dato;
	struct nodo *sig;
}*Pila;

void push(Pila &p,int x){
	Pila aux = (Pila)malloc(sizeof(struct nodo));
	aux->dato = x;
	aux->sig = p;
	p = aux;
}

bool isEmpty(Pila p){
	return p==NULL;
}

int pop(Pila &p){
	Pila aux;
		
	aux = p;
	int num = aux->dato;
	p = aux->sig;
	
	delete(aux);
	return num;
} 

int main(){
	int n,number;
	Pila stac = NULL;
	cin>>n;
	while(n--){
		cin>>number;
		push(stac,number);
	}
	while(!isEmpty(stac))
		printf("%d\n",pop(stac));
	
	
	return 0;
}
