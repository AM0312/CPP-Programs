#include<iostream>
using namespace std;

void insertion_sort(int arr[],int n){
	for(int i=0;i<=n-1;i++){
		int current=arr[i];
		int prev=i-1;
		while(prev>0 and arr[prev]>current){
			arr[prev+1]=arr[prev];
			prev--;			
		}
		arr[prev+1]=current;
	}
}

int main(){
	int arr[]={-5,2,4,-1,56,0,-8,5};
	int n=sizeof(arr)/sizeof(int);
	cout<<"Original array is"<<endl;
	for(int j=0;j<n;j++){
		cout<<arr[j]<<" ";
	}
	insertion_sort(arr,n);
	cout<<endl<<"Sorted array is"<<endl;
	for(int j=0;j<n;j++){
		cout<<arr[j]<<" ";
	}
	return  0;
}
