#include<bits/stdc++.h>
#include<string>

using namespace std;

string ispermutation(string a, string b){
	int len1=a.length();
	int len2=b.length();
	if (len1!=len2){
		return "Not a permutation";
	}
	else{
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		
		for(int i=0;i<len1;i++){
			if(a[i]!=b[i]){
				return "Not a permutation";
			}
			
		}
		return "Yes, they are permutations";		
	}
}

int main(){
	string a,b;
	cout<<"Enter two strings"<<endl;
	getline(cin,a);
	getline(cin,b);
	cout<<ispermutation(a,b);
	return 0;
}
