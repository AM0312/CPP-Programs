#include <bits/stdc++.h>
#include<vector>
using namespace std;
set<vector<int> > s;
void recur(vector<int> &nums, vector<int> ans, int i)
{
    if(i == nums.size()){
        sort(ans.begin(), ans.end());
        s.insert(ans);
        return;
    }
    
    ans.push_back(nums[i]);
    recur(nums, ans, i+1);
    ans.pop_back();
    recur(nums, ans, i+1);
}
vector<vector<int> > uniqueSubsets(vector<int> nums){
    s.clear();
    vector<int> ans;
    recur(nums, ans, 0);
    vector<vector<int> > v;
    for(auto x : s) 
        v.push_back(x);
    return v;
}

int  main(){
	vector<int> nums;
	int n;
	int a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		nums.push_back(a);
	}
	vector<vector<int> > ans=uniqueSubsets(nums);
	int size1=ans.size();
	int size2=ans[0].size();
	for(int i=0;i<size1;i++){
		cout<<"["<<"";
		for(int j=0;j<size2;j++){
			cout<<ans[i][j]<<",";
		}
		cout<<"],";
	}
	return 0;
}
