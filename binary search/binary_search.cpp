#include<bits/stdc++.h>
using namespace std;

int binsearch(int arr[],int n,int key){
    int s=0;
    int e=n-1;
    int mid;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}

int main()
{
    int arr[]={5,7,9,11,3,6,4,1,0,13};
    int n=sizeof(arr)/sizeof(int);
    sort(arr,arr+n);
    for(int x:arr){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<binsearch(arr,n,6);
    return 0;
}