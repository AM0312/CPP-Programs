#include<bits/stdc++.h>
using namespace std;

pair<int,int> minDiff(vector<int> a,vector<int> b){
   sort(b.begin(),b.end());
	vector<int> result;
	//iterate over 1 and do binary search
	int p1,p2;
	
	int diff = INT_MAX;
	
	for(int x : a){
			auto lb = lower_bound(b.begin(),b.end(),x) - b.begin();

			if(lb>=1 and x - b[lb-1] < diff){
					diff = x - b[lb-1];
				  p2 = b[lb-1];
				  p1 = x;
			}

		 if(lb!=b.size() and b[lb]-x < diff ){
			 		diff = b[lb] - x;
			 		p1 = x;
			 		p2 = b[lb];
		 }
	}
	
  return {p1,p2};
}

int main(){
    vector<int> a{23,5,10,17,30},b{26,134,135,14,19};
    pair<int,int> res=minDiff(a,b);
    cout<<res.first<<" "<<res.second<<endl;
    return 0;
}