//Kahrn's alogrithms
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10001];
int vis[10001];
int in[10001];
vector<int>res;
bool kahn(int n)
{
    // queue<int>q; // Normal topological sort
    priority_queue<int,vector<int>,greater<int>>q; // smallest element in possiblity
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        // int curr=q.front();q.pop();
        int curr=q.top();q.pop();
        res.push_back(curr);
        for(auto node:adj[curr])
        {
            in[node]--;
            if(in[node]==0) q.push(node);
        }
    }
    return (res.size()==n);
}
int main()
{
    int n,m,x,y;cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        in[y]++;
    }
    if(kahn(n))
    {
        cout<<"Toplogical Sort: ";
        for(auto it:res) cout<<it<<" ";
        cout<<endl;
    }
    else cout<<"Toplogical not possible"<<endl;

}