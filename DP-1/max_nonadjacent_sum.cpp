#include<bits/stdc++.h>
using namespace std;

int maxNonAdjacentSum(vector<int> arr){
    int n=arr.size();
    vector<int> dp(n+1,0);

    if(n==1) return max(arr[0],0);
    else if(n==2) return max(0,max(arr[0],arr[1]));

    dp[0]=max(arr[0],0);
    dp[1]=max(0,max(arr[0],arr[1]));

    for(int i=2;i<n;i++){
        int inc=arr[i]+dp[i-2];
        int exc=dp[i-1];
        dp[i]=max(inc,exc);
    }
    return dp[n-1];
}

int main(){
    vector<int> arr{6,10,12,7,9,14};
    cout<<maxNonAdjacentSum(arr)<<endl;
    return 0;
}