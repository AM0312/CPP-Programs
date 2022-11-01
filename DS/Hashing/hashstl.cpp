#include<bits/stdc++.h>
#include<map>
using namespace std;

int main(){
    map<string,int> menu;

    menu["maggi"]=15;
    menu["cold drink"]=20;
    menu["dosa"]=99;

    string item;
    cin>>item;

    if(menu.count(item)==0){
        cout<<item<<" is not available"<<endl;
    }
    else{
        cout<<item<<" is available,and its cost is "<<menu[item]<<endl;
    }

    for(pair<string,int> item:menu){
        cout<<item.first<<"=>"<<item.second<<endl;
    }
    return 0;
}