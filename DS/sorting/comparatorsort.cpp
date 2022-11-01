#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b){
	return not(a>b);
}

int main(){
	int arr[]={6,3,7,-3,10,2,8};
	int n=sizeof(arr)/sizeof(int);
	
	cout<<"Original array is"<<endl;
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	sort(arr,arr+n,compare);
	
	cout<<endl<<"Sorted array is"<<endl;
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
} 
