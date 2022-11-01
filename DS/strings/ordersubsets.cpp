#include<bits/stdc++.h>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string a,string b){
	if(a.length()==b.length()){
		return a<b;
	}
	return a.length()<b.length();
}

void findSubsets(char *input,char *output,int i,int j,vector<string> &v){
	if(input[i]=='\0'){
		output[j]='\0';
		string temp(output);
		v.push_back(temp);
		return ;
	}
	
	output[j]=input[i];
	findSubsets(input,output,i+1,j+1,v);
	output[j]='\0';
	findSubsets(input,output,i+1,j,v);
	
}

int main(){
	char input[100];
	char output[100];
	char s[100];
	
	cin>>input;
	vector<string> list;
	findSubsets(input,output,0,0,list);
	sort(list.begin(),list.end(),compare);
	for(int i=0;i<list.size();i++){
		cout<<list[i]<<endl;
	}
	return 0;
}
