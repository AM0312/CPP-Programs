#include<iostream>
using namespace std;

void optimisedsort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		bool s=false;
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				s=true;
			}
		}
		if (s==false){
			break;
		}
	}
}

int main(){
	int arr[]={1,4,12,2,-5,7};
	int n=sizeof(arr)/sizeof(int);
	cout<<"Original array is:"<<endl;
	for(int k=0;k<n;k++){
		cout<<arr[k]<<" ";
	}
	optimisedsort(arr,n);
	cout<<endl<<"Sorted array is:"<<endl;
	for(int l=0;l<n;l++){
		cout<<arr[l]<<" ";
	}
	return 0;
}
