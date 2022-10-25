#include<bits/stdc++.h>
using namespace std;

vector<int> mergeKarrays(vector<vector<int> > arrays){
    int k=arrays.size();
    priority_queue<vector<int>,vector<vector<int> >,greater<vector<int> > > q;
    vector<int> out;

    for(int i=0;i<k;i++){
        int ele=arrays[i][0];
        q.push({ele,i,0});
    }
    while(!q.empty()){
        auto top=q.top();
        q.pop();
        int ele=top[0];
        int a_idx=top[1];
        int e_idx=top[2];

        out.push_back(ele);

        if(e_idx+1<arrays[a_idx].size()){
            int next=arrays[a_idx][e_idx+1];
            q.push({next,a_idx,e_idx+1});
        }
    }
    return out;
}

int main(){
    vector<vector<int> > arr={{10,15,20,30},
                              {2,5,8,14,24},
                              {0,11,60,90}};
    
    vector<int> result=mergeKarrays(arr);
    for(auto x:result){
        cout<<x<<" ";
    }
    return 0;
}