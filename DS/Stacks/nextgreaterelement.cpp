#include<bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextGreaterElement(vector<int> arr){
    int n = arr.size();
    vector<int> arr1(n, 0);
    stack<int> s;
 
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();
 
        if (s.empty())
            arr1[i] = -1;        
        else
            arr1[i] = s.top();       
 
        s.push(arr[i]);
    }
        
    return arr1;
}

int main(){
    vector<int> n{4,5,2,25};
    vector<int> ans=nextGreaterElement(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
    