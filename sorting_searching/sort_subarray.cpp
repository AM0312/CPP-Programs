#include<bits/stdc++.h>
using namespace std;

//This is O(NLogN) Solution, O(N) Solution also exists
pair<int,int> subarraySorting(vector<int> a) {

	vector<int> b(a);
	sort(a.begin(),a.end());
	
	//do comparison
	int i = 0;
	int n = a.size();
	while(i<n and a[i]==b[i]){
		i++;
	}
	int j = a.size()-1;
	while(j>=0 and a[j]==b[j]){
		j--;
	}
	//already sorted
	if(i==a.size()){
		return {-1,-1};
	}
  return {i,j};
}

int main(){
    vector<int> a{0,2,4,7,10,11,7,12,13,14,16,19,29};
    pair<int,int> ans=subarraySorting(a);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}