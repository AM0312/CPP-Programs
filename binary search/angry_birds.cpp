#include<bits/stdc++.h>
using namespace std;

bool canplacebirds(int b,int n,vector<int> nests,int sep){
    int birds=1;
    int location=nests[0];

    for(int i=1;i<=n-1;i++){
        int curloc=nests[i];
        if(curloc-location>=sep){
            birds++;
            location=curloc;

            if(birds==b){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int b=3;
    vector<int> nests{1,2,4,8,9};
    int n=nests.size();

    int s=0;
    int e=nests[n-1]-nests[0];
    int ans=0;
    while(s<=e){
        int mid=(s+e)/2;

        bool canplace=canplacebirds(b,n,nests,mid);
        if(canplace){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}