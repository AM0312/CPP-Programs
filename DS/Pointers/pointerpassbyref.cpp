#include<bits/stdc++.h>
using namespace std;

void applyTax(int *money){
	*money*=0.9;
}

int main(){
	int income;
	cin>>income;
	
	applyTax(&income);
	cout<<income<<endl;
}
