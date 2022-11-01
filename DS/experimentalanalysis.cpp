#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr(n,0);
	
	for(int i=0;i<n;i++){
		arr[i]=n-1;
	}
	
	float start_time =clock();
	sort(arr.begin(),arr.end());
	float end_time=clock();
	
	cout<<end_time-start_time;
	return 0;
}
