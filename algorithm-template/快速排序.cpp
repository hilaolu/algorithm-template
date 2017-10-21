#include<iostream>
#include<stdio.h>
using namespace std;
void qsort(int s[], int l, int r) {
	if (l>=r)return;
	int tmp, i=l-1,x=s[r];
	for (int j = l; j < r; j++) {
		if(s[j]>x)continue;
		i++;
		tmp=s[j];
		s[j]=s[i];
		s[i]=tmp;
	}
	s[r]=s[i+1];
	s[i+1]=x;
	qsort(s,l,i);
	qsort(s,i+2,r);
}
int main(){
	int n;
	scanf("%d",&n);
	int * a;
	a = new int[n];
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	qsort(a,0,n-1);
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	cin.get();
	cin.get();
	return 0;
}