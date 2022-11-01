#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int ispalindrome(char a[]){
	int len=strlen(a);
	int i,j;
	char b[len];
	for(i=(len-1);i>=0;i--){
		for(j=0;;j++){
			b[j]=a[i];
		}
	}
	if(strcmp(a,b)==0){
		return 1;
	}
	else{
		return 2;
	}
}

int main(){
	char a[1000];
	cin>>a;
	
	if(ispalindrome(a)==1){
		cout<<"True";
	}
	else{
		cout<<"False";
	}
	return 0;
}
