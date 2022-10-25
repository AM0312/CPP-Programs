#include<bits/stdc++.h>
using namespace std;

string find_window(string s,string p){
    int FP[256]={0};
    int FS[256]={0};
    for(int i=0;i<p.length();i++){
        FP[p[i]]++;
    }

    int cnt=0;
    int start=0;
    int starti=-1;
    int min=INT_MAX;
    for(int i=0;i<s.length();i++){
        FS[s[i]]++;

        if(FP[s[i]]!=0 and FS[s[i]]<=FP[s[i]]){
            cnt++;
        }

        if(cnt==p.length()){
            while(FP[s[start]]==0 or FS[s[start]]>FP[s[start]]){
                FS[s[start]]--;
                start++;
            }

            int wsize=i-start+1;
            if(wsize<min){
                min=wsize;
                starti=start;
            }

        }
    }
    if(starti==-1){
        return NULL;
    }
    return s.substr(starti,min);
}

int main()
{
    string s,p;
    cin>>s>>p;

    cout<<find_window(s,p);
    return 0;
}