#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
int vis[MAX][MAX];
int adj[MAX][MAX];
int dis[MAX][MAX];
int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};
// DFS on Grid
int N, M;
bool is_vaild(int x, int y)
{
    if (x < 1 or x > N or y < 1 or y > M)
        return false;
    return (!vis[x][y] and adj[x][y]);
}
void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        if (is_vaild(x + dx[i], y + dy[i]))
        {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}
void bfs(int x,int y)
{
    queue<pair<int,int>>q;
    dis[x][y]=0;
    vis[x][y]=1;
    q.push({x,y});
    while (!q.empty())
    {
        auto pr=q.front();q.pop();
        for(int i=0;i<4;i++)
        {
            int newx=pr.first+dx[i];
            int newy=pr.second+dy[i];
            if(is_vaild(newx,newy))
            {
               vis[newx][newy]=1;
               dis[newx][newy]=dis[x][y]+1;
                q.push({newx,newy});
            }

        }
    }
}
int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
       for(int j=1;j<=M;j++)
            cin >> adj[i][j];
    }
    cout<<endl;
    for (int i = 1; i <= N; i++)
    {
       for(int j=1;j<=M;j++)
            cout<< adj[i][j]<<" ";
            cout<<endl;
    }
    // Count the conected Componets in 2D Grid
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (adj[i][j] == 1 and !vis[i][j])
            {
                cnt++;
                cout<<i<<" "<<j<<endl;
               bfs(i,j);
            }
        }
    }
    cout << "Conected Componet in Grid are : " << cnt << endl;
}