#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<limits.h>
using namespace std;
int query(int,int); 
void update(int,int);
void ini(int,int);
int n,k,auxi,numbers[10000],mayores[1000],menores[10000],a,b,rangos;
int rango;
int main(){
     scanf("%d %d",&n,&k);
     for(int i=1;i<=n;i++)
          scanf("%d",&numbers[i]);
    int r=sqrt(n);
     rango=sqrt(n)-1;
     if(n%(rango+1) == 0)
         rangos=n/(rango+1);
     else
         rangos=(n/(rango+1))+1;
     for(int x=1;x<=n;){
         if(x+rango<=n){
            ini(x,x+rango);
            x=x+rango+1;
         }
         else{
            ini(x,n);   
            x+=n;       
         }
     }
     for(int i=1;i<=rangos;i++)
       printf("rango %d menor %d  mayor %d\n",i,menores[i],mayores[i]);

     while(k--){
        scanf("%d",&auxi);
        scanf("%d %d",&a,&b);
         if(auxi==1)
             query(a,b);
         else if(auxi==0)
            update(a,b);
     }

     return 0;
}

void ini(int ini,int fin){
int aux=INT_MAX,aux2=INT_MIN;
   int range;
   if(ini%(rango+1)==0)
         range=ini/(rango+1);
   else
         range=(ini/(rango+1))+1;
    for(int i=ini;i<=fin;i++){
        menores[range] =aux= min(aux,numbers[i]);
        mayores[range] =aux2= max(aux2,numbers[i]);
    }
 }
void update(int pos,int num){
    int range; 
    int aux=INT_MAX,aux2=INT_MIN;   
    numbers[pos]=num; 
    if(pos%(rango+1)==0)
         range=pos/(rango+1);
   else
         range=(pos/(rango+1))+1;
    for(int i=pos;i<=(range*(rango+1));i++){
        menores[range] =aux= min(aux,numbers[i]);
        mayores[range] =aux2= max(aux2,numbers[i]);
    }
}

int query(int ini,int fin){
int aux=INT_MAX,aux2=INT_MIN;
   int rangein,rangefin;
   if(ini%(rango+1)==0)
         rangein=ini/(rango+1);
   else
         rangein=(ini/(rango+1))+1;
   if(fin%(rango+1)==0)
         rangefin=fin/(rango+1);
   else
         rangefin=(fin/(rango+1))+1;
    for(int i=rangein;i<=rangefin;i++){
        aux= min(aux,menores[i]);
        aux2= max(aux2,mayores[i]);
    }
    printf("menor %d  mayor %d\n",aux,aux2);
 }
