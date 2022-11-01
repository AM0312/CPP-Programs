#include<bits/stdc++.h>
using namespace std;

void printarr(int *arr,int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<< " ";
	}
}

void fillArray(int *arr,int i,int n,int val){
	if(i==n){
		printarr(arr,n);
		return;
	}
	arr[i]=val;
	fillArray(arr,i+1,n,val+1);
	arr[i]=-1*arr[i];
}



int main(){
	
	int arr[100]={0};
	int n;
	cin>>n;
	
	fillArray(arr,0,n,1);
	printarr(arr,n);
	
	
	
	
	
	return 0;
}
