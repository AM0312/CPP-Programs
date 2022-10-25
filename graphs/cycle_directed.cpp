#include<bits/stdc++.h>
using namespace std;

class Graph{
    list<int> *l;
    int V;

    bool dfs(int node,vector<bool> &visited,vector<bool> &stack){
        visited[node]=true;
        stack[node]=true;

        for(int nbr:l[node]){
            if(stack[nbr]) return true;
            else if(visited[nbr]==false){
                bool nbrcycle=dfs(nbr,visited,stack);
                if(nbrcycle) return true;
            }
        }
        stack[node]=false;
        return false;
    }

public:
    Graph(int v){
        V=v;
        l=new list<int>[V];
    }

    void addEdge(int i,int j){
        l[i].push_back(j);
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
        vector<bool> stack(V,false);

        for(int i=0;i<V;i++){
            int source=i;
            if(!visited[source]){
                if(dfs(source,visited,stack)) return true;
            }
        }
        return false;
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