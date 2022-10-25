#include<bits/stdc++.h>
using namespace std;

void minpair(vector<int> a1,vector<int> a2){
    sort(a2.begin(),a2.end());

    int p1,p2;
    int diff=INT_MAX;

    for(int x:a1){
        auto lb=lower_bound(a2.begin(),a2.end(),x)-a2.begin();
        if(lb>=1 and x-a2[lb-1]){
            diff=x-a2[lb-1];
            p1=x;
            p2=a2[lb-1];
        }
        if(lb!=a2.size() and a2[lb]-x<diff){
            diff=a2[lb]-x;
            p1=x;
            p2=a2[lb];
        }
    }
    cout<<p1<<" "<<p2<<endl;
    return;
}

int main()
{
    vector<int> a1{-1,5,10,20,3};
    vector<int> a2{26,134,135,15,17};
    minpair(a1,a2);
    return 0;
}