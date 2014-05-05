#include<stdio.h>
#define lli long long int 

lli binarypow(lli n, lli k){
      if(k==1) return n; 
      else{
         if(k%2==0)
            return binarypow(n, k/2) * binarypow(n,k/2); 

         else
            return n * binarypow(n, k-1);

      }   
}
int main(){
   lli n,base;
   scanf("%lld %lld",&base,&n);
   lli k =  binarypow(base,n);
   printf("%lld\n",k);
   return 0;
}
