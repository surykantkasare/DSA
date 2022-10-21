#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10001];
int vis[10001];
vector<int>temp;
bool dfs(int node,int ptr)
{
    vis[node]=true;
    temp.push_back(node);
    for(int v:adj[node])
    {
        if(vis[v]==false)
        {
            if(dfs(v,node)) return true;
        }
        else if(ptr!=v) 
        {
            temp.push_back(v);
            return true;
        }
    }
    temp.pop_back();
    return false;

}
int main()
{

}