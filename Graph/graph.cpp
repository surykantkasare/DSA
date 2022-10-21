#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int vis[100001];
int dis[100001];
int col[100001];
// DFS Traversal
// SSSP Single Source Shorted Paths
void dfs(int node, int d = 0)
{
    cout << node << " ";
    vis[node] = 1;
    dis[node] = d;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, dis[node] + 1);
        }
    }
}
// BFS Traversal

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while (!q.empty())
    {
        int src = q.front();
        q.pop();
        cout << src << " ";
        for (auto it : adj[src])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = true;
            }
        }
    }
}

// Bipartite Graph
bool bidfs(int v, int c)
{
    vis[v] = 1;
    col[v] = c;
    for (auto it : adj[v])
    {
        if (!vis[it])
        {
            if (!bidfs(it, c ^ 1))
                return false;
        }
        else
        {
            if (col[v] == col[it])
                return false;
        }
    }
    return true;
}

// Cycle Detection Using DFS
bool C_dfs(int node, int par = -1)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            if (C_dfs(child, node))
                return;
        }
        else if (child != par)
            return true;
    }
    return false;
}

// In/Out Time of Nodes
int in[100001];
int out[100001];
int timer = 1;
bool dfs_in_out(int v)
{
    vis[v] = 1;
    in[v] = timer++;
    for (auto &child : adj[v])
    {
        if (!vis[child])
            dfs_in_out(v);
    }
    out[v] = timer++;
}

// Diameter of The Tree
int maxD, maxNode;
void d_dfs(int node, int d)
{
    vis[node] = 1;
    if (d > maxD)
        maxD = d, maxNode = node;
    for (int child : adj[node])
    {
        if (!vis[node])
        {
            d_dfs(child, d + 1);
        }
    }
}

// Calculate size of SubTree in O(N)
int subSize[100001];
int subdfs(int node)
{
    int curr_size = 1;
    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            curr_size += subdfs(child);
        }
    }
    subSize[node] = curr_size;
    return curr_size;
}

// SSSP on BFS
void sspBFS(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    dis[src] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto it : adj[curr])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
                dis[it] = dis[curr] + 1;
            }
        }
    }
}
// cc
int cc[100001];
int curr_cc;
void cc_dfs(int src)
{
    vis[src] = 1;
    cc[src] = curr_cc;
    for (auto child : adj[src])
    {
        if (!vis[child])
        {
            cc_dfs(child);
        }
    }
}

int level[1000001];
void level_bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=1;
    dis[src]=0;
    while(!q.empty())
    {
        int curr=q.front();q.pop();
        for(int child:adj[curr])
        {
            if(!vis[child])
            {
                vis[child]=1;
                dis[child]=dis[curr]+1;
                level[dis[child]]++;
            }
        }
    }
}
void social_network()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int q;cin>>q;
    while(q--)
    {
        for(int i=0;i<=n;i++)level[i]=vis[i]=0;
        int src, d;
        level_bfs(src);
        cout<<level[d]<<" ";
    }
}
// Find Bridges 
int timer;
int in[100001],low[100001];
void dfs_b(int node,int par)
{
    vis[node]=1;
    in[node]=low[timer]=timer++;
    for(auto child:adj[node])
    {
        if(child==par) continue;
        else if(vis[child])
        {
            // node to child is backeage
            low[node]=min(low[node],in[child]);
        }
        else 
        {
            // forward edge
            dfs(child,node);
            if(low[child]>in[child])
            {
                cout<<node<<"-"<<child<<"is a Brigh "<<endl;
            }
        }

    }

}
// ARticulation points 
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << x << " " << y << " ";
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            count++;
        }
    }
    // Print Conected Componets
    cout << "Conected Componets are" << count << endl;
    // is it Tree
    if (count == 1 and m == n - 1)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;

    // Longest path in tree nodes
    maxD = -1;
    d_dfs(1, 0);
    fill(vis, vis + n, 0);
    maxD = -1;
    d_dfs(maxNode, 0);
    cout << "Longest path in Tree is :" << maxD << " ";

    // Feassible Relations ("=" or "!=")
    vector<pair<int, int>> pr;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        string s;
        cin >> x >> s >> y;
        if (s == "=")
        {
            adj[x].push_back(y), adj[y].push_back(x);
        }
        else
            pr.push_back({x, y});
    }
    bool flag = true;
    // Two are not same then they don't have same componet
    for (int i = 0; i < pr.size(); i++)
    {
        if (cc[pr[i].first] == cc[pr[i].second])
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}