#include <bits/stdc++.h>
using namespace std;

string s = "thequickbrownfoxjumpsoverthehighbridge";

string words[] = {"the", "fox", "thequickbrownfox", 
                  "jumps", "lazy", "lazyfox", "highbridge", "the", 
                  "over", "bridge", "high", "tall", "quick", "brown"};

int min_bars_helper(string s,string words[],int idx,unordered_set<string> &m){
    if(s[idx]=='\0'){
        return 0;
    }
    int ans=INT_MAX;
    string cur="";
    for(int j=idx;s[j]!='\0';j++){
        cur+=s[j];

        if(m.find(cur)!=m.end()){
            int rem=min_bars_helper(s,words,j+1,m);
            if(rem!=-1){
                ans=min(ans,1+rem);
            }
        }
    }
    if(ans==INTMAX_MAX) return -1;
    return ans;
}

int min_bars(){
    unordered_set<string> m;
    for(string w:words){
        m.insert(w);
    }
    int output=min_bars_helper(s,words,0,m);
    return output-1;
}

int main(){
    cout<<min_bars();
    return 0;
}