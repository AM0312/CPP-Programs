#include<bits/stdc++.h>
#include"list.h"
using namespace std;

int main(){
    List l;
    l.push_front(1);
    l.push_front(0);
    l.push_back(3);
    l.push_back(4);
    l.insert(2,2);
    l.insert(10,0);
    l.reverse();

    Node * head=l.begin();
    while(head!=NULL){
        cout<<head->getData()<<"->";
        head=head->next;
    }
    cout<<endl;
    //cout<<"2 is at "<<l.search(2)<<endl;
    //cout<<"2 is at index "<<l.recsearch(2)<<" searched recursively";
    
    return 0;
}