#include<iostream>
using namespace std;

void  bubble_sort(int arr[],int n){
	for(int i=0;i<=n-1;i++){
		for(int j=0;j<=n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
}

int main(){
	int arr[]={-3,-7,7,12,-9,1,4,4};
	int x;
	int  n=sizeof(arr)/sizeof(int);
	bubble_sort(arr,n);
	for(int k=0;k<n;k++){
		cout<<arr[k]<<" ";
	}
	return 0;
}
