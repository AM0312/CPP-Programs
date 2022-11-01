#include<bits/stdc++.h>
using namespace std;

bool issorted(int arr[],int n){
	if(n==1 or n==0){
		return true;
	}
	
	if(arr[0]<arr[1] and issorted(arr+1,n-1)){
		return true;
	}
	return false;
}

int main(){
	int arr[]={1,2,3,4,5,6,3};
	int n=sizeof(arr)/sizeof(int);
	if(issorted(arr,n)){
		cout<<"1";
		return 0;
	}
	cout<<"0"<<endl;
	return 0;
}
