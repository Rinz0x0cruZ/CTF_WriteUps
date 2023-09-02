#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void add_edge(int src,int des,vector<int> graph[]){
    graph[src].emplace_back(des);
}

string dijk(vector<int> graph[],int src,int des,int v,int dist[]){
    queue<int> q;
    bool vis[v];
    for(int i=0;i<v;++i){
        vis[i]=0; //unvisited
        dist[i]=1e5; //infinity
    }

    q.push(src);
    dist[src]=0;
    vis[src]=1;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(auto& x:graph[temp]){
            if(!vis[x]) {
                q.push(x);
                dist[x]=dist[temp]+1;
                vis[x]=1;
                if(x==des) break;
            }
        }
    }
    return (dist[des]!=1e5 && dist[des]<=6) ? "YES" : "NO";
}



int main() {
    int test_cases;
    cin>>test_cases;
    while(test_cases--){
        int v,e;
        cin>>v>>e;
        vector<int> graph[v];
        for(int i=0;i<e;++i) {
            int x,y;
            cin>>x>>y;
            add_edge(x,y,graph);
        }
        int src,des,dist[v];
        cin>>src>>des;
        cout<<dijk(graph,src,des,v,dist)<<endl;
    }
    
    return 0;
}
