#include<bits/stdc++.h>
using namespace std;

string keypad[]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void printKeypadOutput(string input,string output,int i=0){
    if(input[i]=='\0'){
        cout<<output<<endl;
        return;
    }

    int cur_digit=input[i]-'0';
    if(cur_digit==0 or cur_digit==1){
        printKeypadOutput(input,output,i+1);
    }

    for(int k=0;k<keypad[cur_digit].size();k++){
        printKeypadOutput(input,output+keypad[cur_digit][k],i+1);
    }
    return;

}

int main()
{
    string output;
    string input;
    cin>>input;

    printKeypadOutput(input,output);
    return 0;
}