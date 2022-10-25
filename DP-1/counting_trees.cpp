#include<bits/stdc++.h>
using namespace std;

int countBST(int n){
    if(n==0 or n==1) return 1;

    int ans=0;
    for(int i=1;i<=n;i++){
        int x=countBST(i-1);
        int y=countBST(n-i);
        ans+=x*y;
    }
    return ans;
}

int countBSTTopDown(int n,int dp[]){
    if(n==0 or n==1) return 1;
    if(dp[n]!=0) return dp[n];

    int ans=0;
    for(int i=1;i<=n;i++){
        int x=countBSTTopDown(i-1,dp);
        int y=countBSTTopDown(n-i,dp);
        ans+=x*y;
    }
    return dp[n]=ans;
}

int countBSTBottomUp(int n){
    vector<int> dp(n+1,0);
    dp[0]=dp[1]=1;

    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i]+=dp[j-1]*dp[i-j];
        }
    }
    return dp[n];
}

int main(){
    int n=5;
    cout<<countBST(n)<<endl;
    int dp[n+1]={0};
    cout<<countBSTTopDown(n,dp)<<endl;
    cout<<countBSTBottomUp(n)<<endl;
    return 0;
}