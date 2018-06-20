#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
#define N 30
 
vector<int> Edge[N];
vector<int> rEdge[N];
bool visit[N];
vector<int> order;
vector<int> scc[N];
int C;
int n;
 
void DFS1(int u){
    visit[u] = true;
    for(int i = 0; i < Edge[u].size(); i ++){
        int v = Edge[u][i];
        if(!visit[v])
            DFS1(v);
    }
    order.push_back(u);
}
 
void DFS2(int u){
    visit[u] = true;
    scc[C].push_back(u);
     
    for(int i = 0; i < rEdge[u].size(); i ++){
        int v = rEdge[u][i];
        if(!visit[v])
            DFS2(v);
    }
}
 
void Kosaraju(){
    order.clear();
    for(int i = 1; i <= n; i ++)
        visit[i] = false;
         
    for(int u = 1; u <= n; u ++)
        if(!visit[u])
            DFS1(u);
     
    for(int i = 1; i <= n; i ++)
        visit[i] = false;
    C = 0;
         
    for(int i = n - 1; i >= 0; i --){
        int u = order[i];
        if(!visit[u]){
            C++;
            scc[C].clear();
            DFS2(u);    
        }
    }
}