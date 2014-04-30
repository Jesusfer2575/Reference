#include<stdio.h>
#include<iostream>
#define lli long long int
using namespace std;
lli numeritos[1000006];
lli BIT[1000006],n;
lli query(lli);
lli update(lli,lli);
lli a,b,q,act2,act3;
char act1;
 
struct action{
 char a1;
 lli a2,a3;
}A;
 
int main(){
 
 scanf("%lld %lld",&n,&q);
 
 for(int i=1;i<=n;i++){
    scanf("%lld",&numeritos[i]);
    update(i,numeritos[i]);
 }
 
 /*while(q--){
    cin>>A.a1>>A.a2>>A.a3;
    
    
    if(A.a1=='S')
       printf("%lld\n",query(A.a3+1)-query(A.a2));
    
    else if(A.a1=='G')
       update(A.a2+1,numeritos[A.a2+1]+A.a3 - numeritos[A.a2+1]);
    
    else if(A.a1=='T')
       update(A.a2+1,numeritos[A.a2+1]-A.a3 - numeritos[A.a2+1]);//El a nuevo - a viejo   
    
 }*/
 return 0;
}
 
lli query(lli a){
 if(a==0)
    return 0;
 return BIT[a] + query(a-(a&-a));
}
 
lli update(lli i,lli a){
 if(i>n)
    return 0;
 BIT[i] += a;
 return update(i+(i&-i),a);
}
