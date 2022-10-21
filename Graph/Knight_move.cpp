// You are given  N x M, threre is a Knight on point(x,y) and a target cell (a,b),find minimum number of steps to reach the target.
#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
int vis[MAX][MAX];
int adj[MAX][MAX];
int dis[MAX][MAX];
// int dx[4] = {0, -1, 1, 0};
// int dy[4] = {1, 0, 0, -1};
// DFS on Grid
int N, M;
bool is_vaild(int x, int y)
{
    if (x < 1 or x > N or y < 1 or y > M)
        return false;
    return (!vis[x][y]);
}
 int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
 int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
 int bfs(int srcx,int srcy,int &trgx,int &trgy)
 {
    
    queue<pair<int,int>>pr;
    pr.push({srcx,srcy});
    vis[srcx][srcy]=1;
    while(!pr.empty())
    {
       
        auto [x,y]=pr.front();pr.pop();

         if(x==trgx and y==trgy)  return dis[x][y];
         for(int i=0;i<8;i++)
         {
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(is_vaild(newx,newy))
            {
                vis[newx][newy]=1;
             pr.push({newx,newy});
             dis[newx][newy]=dis[x][y]+1;
           
            }
         }
    }
    return -1;
 }
int main()
{
    cin >> N >> M;
    int srcx,srcy;
    cin>>srcx>>srcy;
    int trgx,trgy;
    cin>>trgx>>trgy;
    cout<<bfs(srcx,srcy,trgx,trgy)<<endl;
}