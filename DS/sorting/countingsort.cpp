#include<iostream>
#include<vector>
using namespace std;

void counting_sort(int a[],int n){
	int largest=0;
	
	for(int i=0;i<n;i++){
		largest=max(largest,a[i]);
	}
	
	vector<int> freq(largest+1,0);
	
	for(int i=0;i<n;i++){
		freq[a[i]]++;
	}
	
	int j=0;
	
	for(int i=0;i<=largest;i++){
		while(freq[i]>0){
			a[j]=i;
			freq[i]--;
			j++;
		}
	}
} 

int main(){
	int arr[]={45,12,14,23,7,18,90};
	int n=sizeof(arr)/sizeof(int);
	
	cout<<"Original array is"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	counting_sort(arr,n);
	
	cout<<endl<<"Sorted array is"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
