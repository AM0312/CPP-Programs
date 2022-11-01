#include<bits/stdc++.h>
#include<vector>
using namespace std;

void printarr(vector<int> &arr,int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<< " ";
	}
	cout<<endl;
}

void fillArray(vector<int> &arr,int i,int n,int val){
	if(i==n){
		printarr(arr,n);
		return;
	}
	arr[i]=val;
	fillArray(arr,i+1,n,val+1);
	arr[i]=-1*arr[i];
}



int main(){
	
	vector<int> arr(100,0);
	int n;
	cin>>n;
	
	fillArray(arr,0,n,1);
	printarr(arr,n);
	
	
	
	
	
	return 0;
}
