#include<cstdio>
#include<iostream>
using namespace std;
void heapdown(int s[],int i,int n){
	int l,r,tmp;
	while(true){
		l=2*i+1;r=2*i+2;
		if(r>n){
			if(l>n)break;
			if(s[l]>s[i]){
				tmp=s[l];
				s[l]=s[i];
				s[i]=tmp;
			}
			break;
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
			i=r;
			continue;
		}
		break;
	}
}
void heapsort(int s[],int n){
	int tmp,k=n;
	for(int i=(n+1)/2;i>=0;i--)heapdown(s,i,n);
	while(k>0){
		tmp=s[0];
		s[0]=s[k];
		s[k]=tmp;
		k--;
		heapdown(s,0,k);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int *s = new int[n];
	for(int i=0;i<n;i++)scanf("%d",&s[i]);
	heapsort(s,n-1);
	for(int i=0;i<n;i++)cout<<s[i]<<" ";
	return 0;
}