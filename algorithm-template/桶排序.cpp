#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	int num[100000] = { 0 }, N, i, j, x;
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &x);
		num[x]++;
	}
	for (i = 0; i<100000; i++)if (num[i] == 1) cout<<i<<" ";
		else if (num[i]>1)
			for (j = 0; j<num[i]; j++)cout<<i<<" ";
	return 0;
}