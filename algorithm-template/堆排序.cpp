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
		for(int j=0;j<n;j++)cout<<s[j]<<" ";
		cout<<endl;
	}
}
void heapsort(int s[],int n){
	int tmp;
	for(int i=(n+1)/2+1;i>0;i--)heapdown(s,i,n);
	for(int i=n-1;i>0;i--){
		tmp=s[0];
		s[0]=s[i];
		s[i]=tmp;
		heapdown(s,0,i);
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