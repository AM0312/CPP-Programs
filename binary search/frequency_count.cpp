#include<bits/stdc++.h>
using namespace std;

int lb(vector<int> arr,int key){
    int s=0;
    int e=arr.size()-1;
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;

        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int ub(vector<int> arr,int key){
    int s=0;
    int e=arr.size()-1;
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;

        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr{0,1,1,2,3,3,3,3,4,5,5,5,10};
    int n=arr.size();

    cout<<ub(arr,3)-lb(arr,3)+1<<endl;
    return 0;
}