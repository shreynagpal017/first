#include<bits/stdc++.h>
using namespace std;
vector <int> adj[1000];
bool visited[1000];
int parent[1000]={0};
int flag=0;
int dfs(int src)
{
    visited[src]=true;
   //cout<<parent[adj[src][0]]<<" "<<adj[src][0]<<endl;
//    parent[src]=adj[src][0];
    for(int i=0;i<adj[src].size();i++)
    {
        if(visited[adj[src][i]]==true&&parent[src]!=adj[src][i])
        {
            flag=1;
            break;
        }
        else if(visited[adj[src][i]]==false)
        {
            parent[adj[src][i]]=src;
            dfs(adj[src][i]);
        }
    }
    return flag;
}
int main()
{
    int n,edges,nodes;
    cout<<"enter number of edges and nodes"<<endl;
    cin>>edges>>nodes;
    int src,dest;
    for(int i=0;i<edges;i++)
    {
        cin>>src>>dest;
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    int a=0;
    for(int i=1;i<=nodes;i++)
    {
        if(visited[i]==false)
        {
            a=dfs(i);
           // cout<<a;
            if(a==1)
            {
                cout<<"cycle detected"<<endl;
                break;
            }
        }
    }
    if(a!=1)
    {
        cout<<"no cycle"<<endl;
    }
//    for(int i=1;i<=nodes;i++)
//    {
//        cout<<parent[i];
//    }
    return 0;
}
