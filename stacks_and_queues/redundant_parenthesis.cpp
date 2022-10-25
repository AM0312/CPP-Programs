#include<bits/stdc++.h>
using namespace std;

bool checkRedundant(string str){
    stack<char> s;
    for(char ch: str){
        if(ch!=')'){
            s.push(ch);
        }
        else{
            bool operatorfound=false;
            while(!s.empty() and s.top()!='('){
                char top=s.top();
                if(top=='+' or top=='-' or top=='*' or top=='/'){
                    operatorfound = true;
                }
                s.pop();
            }
            s.pop();
            if(operatorfound==false){
                return true;
            }
        }
    }
    return false;
}

int main(){
    string str="((a+b)+(c))";
    if(checkRedundant(str)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}