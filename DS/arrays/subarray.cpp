#include <iostream>
using namespace std;

void printSubArr(int arr[],int n){
	int sum1=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=i;k<=j;k++){
				cout<<arr[k]<<",";
				sum1+=arr[k];
			}
			cout<<endl;
			cout<<"Sum of subarray is"<<sum1<<endl;
			sum1=0;
		}
		cout<<endl;
	}
}

int main(){
	int arr[]={10,20,30,40,50,60};
	int n=sizeof(arr)/sizeof(int);
	
	printSubArr(arr,n);
	
	return 0;
}
