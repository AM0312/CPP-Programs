#include<iostream>
using namespace std;

int lowerbound(int arr[],int val,int n){
	int lb=0;
	for(int i=0;i<n;i++){
		if (arr[i]<val){
			lb=max(lb,arr[i]);
		}
	}
	return lb;
}

int main(){
	int val;
	int arr[]={2,3,6,9,14,16,7,1};
	int n=sizeof(arr)/sizeof(int);
	cout<<"The elements of the array are:"<<endl;
	for(int j=0;j<n;j++){
		cout<<arr[j]<<",";
	}
	
	cout<<endl<<"Enter the element for which the lower bound has to be searched for:"<<endl;
	cin>>val;
	
	cout<<"The lowerbound for "<<val<<"is "<<lowerbound(arr,val,n)<<endl;
	return 0;
}
