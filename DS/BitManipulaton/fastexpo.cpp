#include<bits/stdc++.h>
using namespace std;

int fastexponent(int n,int x){
	int ans=1;
	while(x>0){
		int lastbit=x&1;
		if (lastbit){
			ans=ans*n;	
		}
		n*=n;
		x=x>>1;
	}
	return ans;	
}

int main(){
	int n,x;
	cin>>n>>x;
	
	cout<<fastexponent(n,x)<<endl;
}
