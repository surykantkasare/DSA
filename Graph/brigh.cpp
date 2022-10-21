#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int vis[100001];
int in[100001], low[100001];
int timer = 0;
void dfs(int node, int parnet)
{
    vis[node] = 1;
    in[node] = low[node] = timer++;
    for (auto it : adj[node])
    {

         if(!vis[it])
        {
            // forward edge
            dfs(it, node);
            if (low[it] > in[node])
            {
                cout << node << "-" << it << " brigh" << endl;
            }
        }
        if(it==parnet) continue;
            low[node]=min(low[node],low[it]);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, -1);
    // for(int i=0;i<=n;i++)cout<<in[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<=n;i++)cout<<low[i]<<" ";
}