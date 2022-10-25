#include<bits/stdc++.h>
using namespace std;

void space20(char* str){
    int count =0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==' '){
            count++;
        }
    }

    int idx=strlen(str)+2*count;
    str[idx]='\0';

    for(int i=strlen(str)-1;i>=0;i--){
        if(str[i]==' '){
            str[idx-1]='0';
            str[idx-2]='2';
            str[idx-3]='%';
            idx-=3;
        }
        else{
            str[idx-1]=str[i];
            idx--;
        }
    }
}

int main(){
    char input[1000];
    cin.getline(input,1000);
    space20(input);
    cout<<input;
    return 0;
}