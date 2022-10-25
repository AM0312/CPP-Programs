#include<bits/stdc++.h>
using namespace std;

bool divideAmongK(int arr[],int n,int k,int min){
    int frnd=0;
    int cur=0;

    for(int i=0;i<n;i++){
        if(cur+arr[i]>=min){
            frnd+=1;
            cur=0;
        }
        else{
            cur+=arr[i];
        }
    }
    return frnd>=k;
}

int k_partition(int *arr,int n,int k){
    int s=0;
    int e=0;
    for(int i=0;i<n;i++){
        e+=arr[i];
    }
    int ans;

    while(s<=e){
        int mid=(s+e)/2;
        bool isPossible=divideAmongK(arr,n,k,mid);

        if(isPossible){
            s=mid+1;
            ans=mid;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}

int main()
{
    int a[]={10,20,40,30};
    int n=sizeof(a)/sizeof(int);
    int k=3;

    cout<<k_partition(a,n,k);

    return 0;
}