#include<bits/stdc++.h>
using namespace std;

void printarray(int arr[100][100],int n,int m){
	cout<<"Elements of array are"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int arr[100][100];
	int n,m;
	cout<<"Enter number of rows and columns"<<endl;
	cin>>n>>m;
	cout<<"Enter elements"<<endl<<endl;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	printarray(arr,n,m);
} 
