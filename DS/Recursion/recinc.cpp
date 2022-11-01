#include<bits/stdc++.h>
using namespace std;

void inc(int n){
	if(n==0){
		return ;
	}
	inc(n-1);
	cout<<n<<" ";
}

int main(){
	int n;
	cin>>n;
	inc(n);
	return 0;
}
