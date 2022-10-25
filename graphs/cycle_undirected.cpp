#include<bits/stdc++.h>
using namespace std;

class Graph{
    list<int> *l;
    int V;

    bool dfs(int node,vector<bool> &visited,int parent){
        visited[node]=true;
        for(auto nbr:l[node]){
            if(!visited[nbr]){
                bool nbrcycle=dfs(nbr,visited,node);
                if(nbrcycle) return true;
            }
            else if(nbr!=parent) return true;
        }
        return false;;
    }

public:
    Graph(int v){
        V=v;
        l=new list<int>[V];
    }

    void addEdge(int i,int j,bool undir=true){
        l[i].push_back(j);
        if(undir) l[j].push_back(i);
    }

    void printAdjList(){
        for(int i=0;i<V;i++){
            cout<<i<<"-->";
            for(auto node:l[i]){
                cout<<node<<",";
            }
            cout<<endl;
        }
    }

    bool contains_cycle(){
        vector<bool> visited(V,false);
        return dfs(0,visited,-1);
    }

};

int main(){
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);

    cout<<g.contains_cycle();

    return 0;
}