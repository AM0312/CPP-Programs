#include<bits/stdc++.h>
using namespace std;

string extractStringatKey(string str,int key){
    char* s=strtok((char*) str.c_str()," ");
    while(key>1){
        s=strtok(NULL," ");
        key--;
    }
    return string(s);
}

int convertoint(string s){
    int ans=0,p=1;
    for(int i=s.length()-1;i>=0;i--){
        ans+=((s[i]-'0')*p);
        p*=10;
    }
    return ans;
}
bool numeric_Compare(pair<string,string> s1,pair<string,string> s2){
    string key1,key2;
    key1=s1.second;
    key2=s2.second;

    return convertoint(key1)<convertoint(key2);   
}

bool lexico_Compare(pair<string,string> s1,pair<string,string> s2){
    string key1,key2;
    key1=s1.second;
    key2=s2.second;

    return key1<key2;
}



int main()
{
    int n;
    cin>>n;
    cin.get();
    string temp;
    vector<string> v;
    for(int i=0;i<n;i++){
        getline(cin,temp);
        v.push_back(temp);
    }
    int key;
    string order,reversal;
    cin>>key>>reversal>>order;

    vector<pair<string,string> > vp;
    for(int i=0;i<n;i++){
        vp.push_back({v[i],extractStringatKey(v[i],key)});
    }

    if(order=="numeric"){
        sort(vp.begin(),vp.end(),numeric_Compare);
    }
    else{
        sort(vp.begin(),vp.end(),lexico_Compare);
    }

    if(reversal=="true"){
        reverse(vp.begin(),vp.end());
    }

    for(int i=0;i<n;i++){
        cout<<vp[i].first<<endl;
    }
    return 0;
}