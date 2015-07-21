#include<stdio.h>
#define lli long long int 

lli binarypow(lli a,lli b) {
    lli res = 1;
    while(b){
        if(b % 2)
            res = res*a;
        a = a*a;
        b /= 2;
    }
    return res;
}
int main(){
   lli n,base;
   scanf("%lld %lld",&base,&n);
   lli k =  binarypow(base,n);
   printf("%lld\n",k);
   return 0;
}
