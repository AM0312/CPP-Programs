#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> kRotate(vector<int> a, int k,int n)
{
    vector<int> v;
    k = k % n;
 
    for(int i = 0; i < n; i++)
    {
       if(i < k)
       {
           v.push_back(a[n + i - k]);
       }
       else
       {
           v.push_back(a[i - k]);
       }
    }
    for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
	}
}

int main(){
	int k;
	int arr[]={1,2,3,4,5,6,7};
	int n=sizeof(arr)/sizeof(int);
	vector<int> vect(arr,arr+n);
	cout<<"Original Array is :"<<endl;
	for(int i=0;i<n;i++){
		cout<<vect[i]<<" ";
	}
	cout<<endl;
	cout<<"Enter number of times to rotate the array"<<endl;
	cin>>k;
	cout<<endl<<"Rotated array is:";
	kRotate(vect,k,n);
	return 0;
}



