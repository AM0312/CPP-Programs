#include<bits/stdc++.h>
using namespace std;

int firstocc(int arr[],int n,int key){
	if(arr[0]==key){
		return 0;
	}
	if(n==0){
		return -1;
	}
	int subindex=firstocc(arr+1,n-1,key);
	if(subindex!=-1){
		return subindex+1;
	}
	return -1;
}

int main(){
	int key;
	int arr[]={0,5,1,5,7,1,6,7};
	cin>>key;
	int n=sizeof(arr)/sizeof(n);
	cout<<firstocc(arr,n,key)<<endl;
	return 0;
}
