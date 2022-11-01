#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	int arr[]={10,11,2,3,4,5,6};
	int n=sizeof(arr)/sizeof(int);
	vector<int> vect(arr,arr+n);
	
	int key=11;
	
	vector<int>::iterator it=find(arr.begin(),arr.end(),key);
	if(it!=arr.end()){
		cout<<it-arr.begin();
}}
