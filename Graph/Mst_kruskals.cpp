#include<bits/stdc++.h>
using namespace std;
struct edge{
    int a,b,w;
};

edge ar[10001];
int par[10001];
bool mycom(edge a,edge b)
{
    return a.w<b.w;
}
int find(int a)
{
    if(par[a]==-1) return a;
    return par[a]=find(par[a]);
}
void merge(int a,int b)
{
    par[a]=b;
}
int main()
{
    int n,m,a,b,w;cin>>n>>m;
    for(int i=1;i<=n;i++) par[i]=-1;
    for(int i=0;i<m;i++)
    {
        cin>>ar[i].a>>ar[i].b>>ar[i].w;
    }
    long long sum=0;
    sort(ar,ar+m,mycom);
    for(int i=0;i<m;i++)
    {
        a=find(ar[i].a);
        b=find(ar[i].b);
        if(a!=b)
        {
            sum+=ar[i].w;
            merge(a,b);
        }
    }
    cout<<sum<<endl;

}
