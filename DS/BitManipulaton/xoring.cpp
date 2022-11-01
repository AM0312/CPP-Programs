#include<bits/stdc++.h>
using namespace std;

int xoring(int arr[],int n){
	int res=arr[0];
	for(int i=1;i<n;i++){
		res=res^arr[i];
	}
	return res;
}

int main(){
	int arr[]={1,4,7,2,3,1,4,7,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<xoring(arr,n);
	return 0;
}
