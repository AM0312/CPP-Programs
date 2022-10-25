#include<bits/stdc++.h>
using namespace std;

vector<int> getHashVal(string s,int i,int j){
    vector<int> freq(26,0);

    for(int k=i;k<=j;k++){
        char ch=s[k];
        freq[ch-'a']++;
    }
    return freq;
}

int anagram_strings(string s){
    map<vector<int>,int> m;
    for(int i=0;i<s.length();i++){
        for(int j=i;j<s.length();j++){
            vector<int> h=getHashVal(s,i,j);
            m[h]++;
        }
    }
    int ans=0;
    for(auto p:m){
        int freq=p.second;
        if(freq>=2){
            ans+=(freq)*(freq-1)/2;
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<anagram_strings(s);
    return 0;
}