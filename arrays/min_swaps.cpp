#include<bits/stdc++.h>
using namespace std;

int minswaps(vector<int> arr){
    int ans=0;
    pair<int,int> ap[arr.size()];
    for(int i=0;i<arr.size();i++){
        ap[i].first=arr[i];
        ap[i].second=i;
    }
    sort(ap,ap+arr.size());
    vector<bool> visited(arr.size(),false);
    for(int i=0;i<arr.size();i++){
        int old=ap[i].second;
        if(visited[i]==true or old==i){
            continue;
        }
        int node=i;
        int cycle=0;
        while(visited[node]==false){
            visited[node]=true;
            int next=ap[node].second;
            node=next;
            cycle+=1;
        }
        ans+=(cycle-1);
    }
    return ans;
}


int main(){
    vector<int> arr{5,4,3,2,1};
    cout<<minswaps(arr);
    return 0;
}