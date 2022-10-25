#include<bits/stdc++.h>
using namespace std;

vector<int> pairSum(vector<int> arr,int s){
    unordered_set<int> set;
    vector<int> ans;

    for(int i=0;i<arr.size();i++){
        int x=s-arr[i];
        if(set.find(x)!=set.end()){
            ans.push_back(x);
            ans.push_back(arr[i]);
            return ans;
        }
        set.insert(arr[i]);
    }
    return {};
}

int main(){
    vector<int> arr={10,5,2,3,-6,9,11};
    int s=4;

    auto p=pairSum(arr,s);
    if(p.size()==0){
        cout<<"No such pair"<<endl;
        return 0;
    }
    cout<<p[0]<<","<<p[1]<<endl;
    return 0;
}