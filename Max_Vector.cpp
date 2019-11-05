/*
 Kadane’s Algorithm
*/
#include<stdio.h>
#include<limits.h>
#include<algorithm>
#define MAX 1000005
using namespace std;
 
int mx,sum,N;
int ar[MAX];
 
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&ar[i]);
	sum = 0;
	mx = INT_MIN;
	for(int i=0;i<N;i++){
		if((sum+ar[i])>=0)
			sum += ar[i];
		else sum = 0;
		mx = max(sum,mx);
	}
	printf("%d\n",mx);
	return 0;
}
