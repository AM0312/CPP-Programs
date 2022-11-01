#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int n,lenlarge=0;
	char sentence[1000],largest[1000];
	
	cout<<"Enter number of sentences:";
	cin>>n;
	
	int t=n+1;
	
	while(t--){
		cin.getline(sentence,1000);
		int len=strlen(sentence);
		if(len>lenlarge){
			lenlarge=len;
			strcpy(largest,sentence);
		}
	}
	cout<<endl<<"Largest string is '"<<largest<<"'";
	return 0;
}
