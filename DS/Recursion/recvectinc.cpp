#include<bits/stdc++.h>
#include<vector>
using namespace std;

void help(int i, int n, vector<int> &v)
{
    if(i > n) {
		return;
	}
	v.push_back(i);
    help(i+1, n, v);
}

vector<int> increasingNumbers(int N) {
    vector<int> v;
    help(1, N, v);
    return v;
}

int main(){
	int n;
	cin>>n;
	vector<int> arr=increasingNumbers(n);
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
