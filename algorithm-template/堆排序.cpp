#include<cstdio>
#include<iostream>
using namespace std;
void heapdown(int s[],int i,int n){
	int l,r,tmp;
	while(true){
		l=2i;r=2i+1;
		if(r>n){
			if(l>n)return;
			if(s[l]>s[i]){
				tmp=s[l];
				s[l]=s[i];
				s[i]=tmp;
			}
			return;
		}
		if(s[l]>s[i]&&s[l]>s[r]){
			tmp=s[l];
			s[l]=s[i];
			s[i]=tmp;
			i=l;
			continue;
		}
		if(s[r]>s[i]){
			tmp=s[r];
			s[r]=s[i];
			s[i]=tmp;
			r=l;
			continue;
		}
}
void heapsort(int s[],int n){
	for(int i=(n+1)/2+1;i>0;i--)heapdown(s,i,n);
	
}
int main(){
	int n;
	scanf("%d",&n);
	int *s = new int[n];
	for(int i=0;i<n;i++)scanf("%d",s[i]);
	heapsort(s,n-1);
	for(int i=0;i<n;i++)cout<<s[i]<<" ";
	return 0;
}