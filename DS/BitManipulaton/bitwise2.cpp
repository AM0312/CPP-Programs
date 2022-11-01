#include<bits/stdc++.h>
using namespace std;

void clearithbit(int &n,int i){
	int mask=~(1<<i);
	n=n&mask;
}

int main(){
	int n=5;
	int i;
	cin>>i;
	cout<<n<<endl;
	clearithbit(n,i);
	cout<<n;
	
}
