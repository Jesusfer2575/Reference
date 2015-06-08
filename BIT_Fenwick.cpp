#include<stdio.h>
 
int numeritos[1000006];
int BIT[1000006],n;
int query(int);
int update(int,int);
int a,b;
int main(){
 
 scanf("%d",&n);
 for(int i=1;i<=n;i++){
    scanf("%d",&numeritos[i]);
    update(i,numeritos[i]);
 }
 for(int i=1;i<=n;i++)
    printf("%d\n",BIT[i]);
 scanf("%d %d",&a,&b);
 printf("%d\n",query(a)+query(b-1));
 return 0;
}
 
int query(int idx){
 int sum = 0;
 while(idx>0){
    sum += BIT[idx];
    idx -= (idx&(-idx));
 }
 return sum;
}
 
int update(int idx,int a){
 while(idx<=n){
    BIT[idx] += a;
    idx += (idx&-idx);
 }
}
