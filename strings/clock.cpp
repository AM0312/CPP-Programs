#include<bits/stdc++.h>
using namespace std;

string convert_to_digital_time(int minutes){
    int hours=minutes/60;
    minutes%=60;
    string out=to_string(hours)+":";
    string min=to_string(minutes);
    if(min.length()==1){
        min="0"+min;
    }
    out+=min;
    return out;    
}
int main()
{
    int min;
    cin>>min;
    cout<<convert_to_digital_time(min);
    return 0;
}