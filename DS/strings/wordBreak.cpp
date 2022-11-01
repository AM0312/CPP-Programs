#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
vector<string> v;
void help(string s, int n, string res, vector<string> &word)
{
	for (int i = 1; i <= n; i++)
	{
		string ss = s.substr(0, i);
		int l = word.size();
		bool flag = false;

		for (int j = 0; j < l; j++)
			if (word[j] == ss)
				flag = true;

		if (flag)
		{
			if (i == n)
			{
				res += ss;
				// v.push_back(res);
				cnt++;
				return;
			}
			help(s.substr(i, n - i), n - i, res + ss + " ", word);
		}
	}
}

int wordBreak(string s, vector<string> &dictionary)
{
	cnt = 0;
	// v.clear();
	help(s, s.size(), "", dictionary);
	// for (auto x : v) cout << x << '\n';
	return cnt;
}


int main(){
	vector<string> dictionary;
	int n;
	string a,b;
	cout<<"Enter no of dictionary words"<<endl;
	cin>>n;
	cout<<"Now enter the words:"<<endl;
	for(int i=0;i<n;i++){
		cin>>a;
		dictionary.push_back(a); 
	}
	cout<<"Enter the sentence to check(without white spaces)"<<endl;
	cin>>b;
	cout<<wordBreak(b,dictionary);
	
	return 0;
}
