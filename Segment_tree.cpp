/*Segment Tree Implementation
 The nodes are numbered from 1 to N
*/
#include<bits/stdc++.h>
#include<stdio.h>
#include<limits.h>
#define MAX 1000000
#define INF INT_MIN
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
 
int ar[MAX];
 
typedef struct Node{
 int dato,a,b;
 struct Node *right,*left;
}*Tree;
 
Tree insert(Tree n,int A,int B){
 Tree t = new(struct Node);
 t->right = NULL;
 t->left = NULL;
 t->a = A;
 t->b = B;
 
 return t;
}
 
void inorder(Tree A){
 if(A!=NULL){
    inorder(A->left);
    printf("%d\n",A->dato);
    inorder(A->right);
 }
}
 
Tree build(int a,int b){
 Tree n = new(struct Node);
 n = insert(n,a,b);
 if(a==b)
    n->dato = ar[a];
 
 else{
    int middle = (a+b)/2;
	 n->left = build(a,middle);
	 n->right = build(middle+1,b);
	 n->dato = max(n->left->dato,n->right->dato);
 }
 return n;
}
 
int query(Tree n,int a,int b){
 if(b<(n->a) || (n->b)<a)
    return INF;
 if(a<=(n->a) && (n->b)<=b)
    return n->dato;
 int L = query(n->left,a,b);
 int R = query(n->right,a,b);
 return max(L,R);
}
 
int update(Tree n,int x,int a,int b){
 
 if(n->a==n->b && (n->a==a && n->b==b))
    return n->dato = x;
 
 if(b<(n->a) || (n->b)<a)
    return n->dato;
 if(a<=(n->a) && (n->b)<=b)
    return n->dato = x;
 int L = update(n->left,x,a,b);
 int R = update(n->right,x,a,b);
 return n->dato = max(L,R);
 //printf("cambio de %d a %d\n",n->a,n->b);
 	
}
 
int N,M,x,y,cambio,U;
int main(){
  optimizar_io
 Tree arbolito = NULL;
 scanf("%d",&N);
 for(int i=1;i<=N;i++)
    scanf("%d",&ar[i]);
 arbolito = build(1,N);
 
 /*puts("Impresion 1 inorden");
 inorder(arbolito);*/
 
 scanf("%d",&U);//Updates
 while(U--){
    scanf("%d %d",&cambio,&x);//Cambio es el nodo donde debo ponerlo y x el numero que quiero actualizar
    update(arbolito,x,cambio,cambio);
 }
 /*puts("Impresion 2 inorden");
 inorder(arbolito);*/
 
 scanf("%d",&M);// Querys
 while(M--){
    scanf("%d %d",&x,&y);
    printf("%d\n",query(arbolito,x,y));
 }
 return 0;
}
