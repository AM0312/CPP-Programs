#include <bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
const int MAX_CHAR = 26;

vector<char> firstnonrepeating(vector<char> str)
{
	queue<char> q;
    vector<char> v;
	int charCount[MAX_CHAR] = { 0 };

	for (int i = 0; i<str.size(); i++) {

		q.push(str[i]);

		charCount[str[i] - 'a']++;

		while (!q.empty()) {
			if (charCount[q.front() - 'a'] > 1)
				q.pop();
			else {
				v.push_back(q.front());
				break;
			}
		}

		if (q.empty())
			v.push_back('0');
	}
	return v;
}

int main(){
    vector<char> vect{'a','a','b','c'};
    vector<char> ans=firstnonrepeating(vect);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}