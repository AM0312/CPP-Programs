#include<bits/stdc++.h>
using namespace std;

bool compare(int a,int b){
	return a>b;
}

void bubblesort(int a[],int n){
	if(n==1){
		return;
	}
	
	for(int j=0;j<n-1;j++){
		if(a[j]>a[j+1]){
			swap(a[j],a[j+1]);
		}
	}
	bubblesort(a,n-1);
}

void bubblesort2(int a[],int n,int j){
	if(n==1 or n==0){
		return;
	}
	if(j==n-1){
		bubblesort2(a,n-1,0);
	}
	
	if(a[j]>a[j+1]){
		swap(a[j],a[j+1]);
	}
	bubblesort2(a,n,j+1);
}

int main(){
	int arr[]={5,4,3,2,1};
	int n=sizeof(arr)/sizeof(int);
	bubblesort2(arr,n,0);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
