#include<bits/stdc++.h>
#include<vector>
using namespace std;

void merge(vector<int> &array,int s,int e){
	int i=s;
	int m=(s+e)/2;
	int j=m+1;
	
	vector<int> temp;
	while(i<=m and j<=e){
		if(array[i]<array[j]){
			temp.push_back(array[i]);
			i++;
		}
		else{
			temp.push_back(array[j]);
			j++;
		}
	}
	while(i<=m){
		temp.push_back(array[i++]);
	}
	while(j<=e){
		temp.push_back(array[j++]);
	}
	int k=0;
	for(int idx=s;idx<=e;idx++){
		array[idx]=temp[k++];
	}
	return;
}

void mergesort(vector<int> &array,int s,int e){
	if(s>=e){
		return;
	}
	int mid=(s+e)/2;
	mergesort(array,s,mid);
	mergesort(array,mid+1,e);
	return merge(array,s,e);
}

int main(){
	int array[]={10,4,7,2,9,3,6,0,5};
	int n=sizeof(array)/sizeof(int);
	vector<int> arr(array,array+n); 
	
	int s=0;
	int e=arr.size()-1;
	mergesort(arr,s,e);
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
