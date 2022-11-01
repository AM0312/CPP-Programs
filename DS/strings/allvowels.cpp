#include<bits/stdc++.h>
using namespace std;

void allvowels(string a,int n){
	vector<char> vect;
	for(int i=0;i<n;i++){
		if((a[i]=='a')||(a[i]=='e')||(a[i]=='i')||(a[i]=='o')||(a[i]=='u')){
			cout<<a[i];
		}
	}
	
}

int main(){
	string a;
	cout<<"Enter a string"<<endl;
	getline(cin,a);
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"Vowels in "<<a<<" are ";
	allvowels(a,n);
	return 0;
}
