#include<bits/stdc++.h>
using namespace std;

int countSubsets(vector<int> arr,int n,int i,int sum){
    if(i==n){
        if(sum==0){
            return 1;
        }
        else{
            return 0;
        }
    }

    int inc=countSubsets(arr,n,i+1,sum-arr[i]);
    int exc=countSubsets(arr,n,i+1,sum);
    return inc+exc;
}

int main()
{
    vector<int> arr{1,2,3,4,5};
    int x=10;

    cout<<countSubsets(arr,arr.size(),0,x);
    return 0;
}