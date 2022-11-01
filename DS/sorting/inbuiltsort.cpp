#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int arr[]={10,8,3,6,12,7,1,11};
	int n=sizeof(arr)/sizeof(int);
	
	sort(arr,arr+n);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
