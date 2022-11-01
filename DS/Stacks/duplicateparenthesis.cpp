#include<bits/stdc++.h>
#include<stack>
#include<cstring>
using namespace std;

bool duplicateParentheses(string str){
    
    stack<char> Stack;
  
    for (char ch : str)
    {
        if (ch == ')')
        {
            char top = Stack.top();
            Stack.pop();
  
            int elementsInside = 0;
            while (top != '(')
            {
                elementsInside++;
                top = Stack.top();
                Stack.pop();
            }
            if(elementsInside < 1) {
                return true;
            }
        }
  
        else
            Stack.push(ch);
    }
  
    return false;
    
}

int main(){
    string a="(((a+(b)))+c)";
    string b="(a+b)+c";
    /*if(duplicateParentheses(a)){
        cout<<"True for string "<<a;
    }*/
   
    if(duplicateParentheses(b)){
        cout<<"True for string "<<b;
    }
    return 0;
}