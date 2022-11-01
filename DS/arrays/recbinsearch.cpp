#include<bits/stdc++.h>
#include<vector>
using namespace std;

int binarySearch(int arr[],int x,int s,int e){
	if(s>=e){
		return -1;
	}
	
	int mid=(s+e)/2;
	if(arr[mid]==x){
		return  mid;
	}
	if(x<arr[mid]){
		return binarySearch(arr,x,s,mid-1);
	}
	
	if(x>arr[mid]){
		return binarySearch(arr,x,mid+1,e);
	}
}

int main(){
	int arr[]={1,4,6,9,13,25,24};
	int s=0;
	int n=sizeof(arr)/sizeof(int);
	int e=n-1;
	int x;
	cin>>x;
	cout<<binarySearch(arr,x,s,e);
	return 0;
}
