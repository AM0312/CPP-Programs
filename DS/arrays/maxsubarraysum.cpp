#include <iostream>
using namespace std;

int max_subarr_sum(int arr[],int n){
	int cs=0,ms=0;
	for(int i=0;i<n;i++){
		cs+=arr[i];
		if(cs<0){
			cs=0;
		}
		ms=max(ms,cs);
	}
	return ms;
}

int main(){
	int arr[]={1,3,-4,7,-12,8,-34,67};
	int n=sizeof(arr)/sizeof(int);
	cout<<"Max subarray sum is"<<max_subarr_sum(arr,n)<<endl;
	return 0;
}
