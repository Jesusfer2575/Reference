//Código pendiente!
#include<iostream>
#include<malloc.h>
#include<stdio.h>
using namespace std;

typedef struct node{
	int dato;
	struct node *sig;
}*Lista;

void insert(Lista &l,int x){
	Lista list = (Lista)malloc(sizeof(struct node));
	list->dato = x;
	list->sig = l;
	l = list;
}

void insert_end(Lista &l,int x){
	Lista temp, aux = (Lista)malloc(sizeof(struct node));
	aux->sig = NULL;
	aux->dato = x;
	 
	if(l==NULL)
		l = aux;
	else{
		temp = l;
		while(temp->sig != NULL)
			temp = temp->sig;
		temp->sig = aux;
	}
}

int main(){
	Lista lis = NULL;
	int n,number;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&number);
		insert(lis,number);
	}
	scanf("%d",&n);
	insert_end(lis,n);
	
	Lista t = NULL;
	t = lis;
	while(t != NULL){
		printf("%d\n",t->dato);
		t = t->sig;
	}
	
	return 0;
}
