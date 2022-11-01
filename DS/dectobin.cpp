#include<bits/stdc++.h>
using namespace std;

int dectobin(int n){
	int ans=0;
	int p=1;
	
	while(n>0){
		int lastbit=n&1;
		ans+=p*lastbit;
		p*=10;
		n=n>>1;
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	
	cout<<dectobin(n)<<endl;
}
