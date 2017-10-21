#include<iostream>
#include<stdio.h>
using namespace std;
void dosort(int s[],int t[],int l,int r){
	if (r - l<2) {
		if (s[r]<s[l])swap(s[r], s[l]);
		return;
	}
	int mid=(l+r)/2;
	dosort(s,t,l,mid);dosort(s,t,mid+1,r);
	int j=l,i=mid+1,p=l;
	while(true){
		if(j>mid){
			while(p<=r){
				t[p]=s[i];
				i++;p++;
			}	
			break;
		}
		if(i>r)
		{
			while (p <= r) {
				t[p] = s[j];
				j++; p++;
			}
			break;
		}
		if(s[j]<=s[i]){
			t[p]=s[j];
			j++;p++;
		}else{
			  t[p]=s[i];
			  i++;p++;
		    }
	}
	for(i=l;i<=r;i++){
		s[i]=t[i];
	}
}
/*void msort(int s[],int l,int r){
	int n=sizeof(s);
	int *t=new int[n];
	dosort(s,t,l,r);
	delete []t;
}*/
int main(){
	int n;
	scanf("%d",&n);
	int *s=new int[n];
	for(int i=0;i<n;i++)scanf("%d",&s[i]);
	int *t=new int[n];
	dosort(s,t,0,n-1);
	delete []t;
	//msort(s,0,n-1);
	for(int i=0;i<n;i++)cout<<s[i]<<" ";
	cin.get();
	cin.get();
	return 0;
}