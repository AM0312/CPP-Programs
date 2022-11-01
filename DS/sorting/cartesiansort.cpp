#include<bits/stdc++.h>
using namespace std;
#define LL unsigned long long
#define mp make_pair
#define pb push_back

bool comparator(const pair<int,int> &A,const pair<int,int> &B)
{
	if(A.first>=B.first)
	{
		if(A.second<=B.second)
		return 1;
		else return 0;
	}
	return 0;
}

int main() 
{
	vector<pair<int,int> >V;
	V.pb(mp(1,2));
	V.pb(mp(1,3));
	V.pb(mp(2,4));
	V.pb(mp(2,1));
	V.pb(mp(2,2));
	sort(V.begin(),V.end(),&comparator);
	for(int i=0;i<V.size();i++)
	cout<<V[i].first<<" "<<V[i].second<<endl;
	return 0;
}
