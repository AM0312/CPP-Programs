#include<bits/stdc++.h>
using namespace std;

vector<int> arrayProduct(vector<int> arr){
    vector<int> ans(arr.size(),1);
    int temp=1;
    for(int i=0;i<arr.size();i++){
        ans[i]*=temp;
        temp*=arr[i];
    }
    temp=1;
    for(int i=arr.size()-1;i>=0;i--){
        ans[i]*=temp;
        temp*=arr[i];
    }

    return ans;
}

int main(){
    vector<int> arr{1,2,3,4,5};
    vector<int> res=arrayProduct(arr);
    for(auto x:res){
        cout<<x<<" ";
    }
    return 0;
}