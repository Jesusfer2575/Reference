#include<stdio.h>

int MCD(int a,int b){
	while(a!=0 && b!=0)
		(a>b) ? a=a%b: b=b%a;
    return (a!=0) ? a:b;
}

int a,b;

int main(){
	scanf("%d %d",&a,&b);
	printf("%d\n",MCD(a,b));
	
	return 0;
}
