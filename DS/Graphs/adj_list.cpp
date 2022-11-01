#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;

    void dfshelper(int node,bool* visited){
        visited[node]=true;
        cout<<node<<",";
        for(int nbr:l[node]){
            if(!visited[nbr]){
                dfshelper(nbr,visited);
            }
        }
        return;
    }

public:
    Graph(int v){
        V=v;
        l=new list<int>[V];
    }

    void addEdge(int i,int j,bool undir=true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void bfs(int source){
        queue<int> q;

        bool* visited=new bool[V]{0};

        q.push(source);
        visited[source]=true;

        while(!q.empty()){
            int f=q.front();
            cout<<f<<endl;
            q.pop();

            for(auto nbr: l[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
    }

    void dfs(int source){
        bool* visited=new bool[V]{0};
        dfshelper(source,visited);
    }

    void print(){
        for(int i=0;i<V;i++){
            cout<<i<<"-->";
            for(auto node:l[i]){
                cout<<node<<",";
            }
            cout<<endl;
        }
    }

    void topological_sort(){
        vector<int> indegree(V,0);

        for(int i=0;i<V;i++){
            for(auto nbr:l[i]){
                indegree[nbr]++;
            }
        }

        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            cout<<node<<" ";
            q.pop();

            for(auto nbr:l[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
    }

    int dijkshtra(int src,int dest){
        vector<int> dist(V,INT_MAX);
        set<pair<int,int> > s;

        dist[src]=0;

        while(!s.empty()){
            auto it=s.begin();
            int node=it->second;
            int nodedist=it->first;
            s.erase(it);

            for(auto nbrpair:l[node]){
                int nbr= nbrpair.second;
                int curedge=nbrpair.first;

                if(nodedist+curedge<dist[nbr]){
                    auto f=s.find({dist[nbr],nbr});
                    if(f!=s.end()){
                        s.erase();
                    }

                    dist[nbr]=nodedist+curedge;
                    s.insert({dist[nbr],nbr});
                }
            }
        }

        return dist[dest];
    }


};

int main(){
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(2,3); 
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(1,4);
    g.addEdge(1,2);  
    

    g.topological_sort();

    return 0;
}