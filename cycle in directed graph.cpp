#include<bits/stdc++.h>
using namespace std;
vector <int> adj[1000];
//bool visited[1000]={0};
bool white[1000];
bool black[1000];
bool grey[1000];
//bool record[1000]={0};
//int flag=0;
bool dfs(int src)
{
     white[src]=0;
     grey[src]=1;
     for(int i=0;i<adj[src].size();i++)
     {
         if(black[adj[src][i]]==true)
            continue;
         else if(grey[adj[src][i]]==true)
         {
             return true;
         }
         else if(dfs(adj[src][i])) return true;
     }
     black[src]=1;
     grey[src]=0;
     return false;
}

int main()
{
    for(int i=1;i<1000;i++)
    {
        white[i]=1;
    }
    int edges,nodes;
    cout<<"enter edges and nodes"<<endl;
    cin>>edges>>nodes;
    int src,dest;
    for(int i=0;i<edges;i++)
    {
        cin>>src>>dest;
        adj[src].push_back(dest);
    }
    int a=0;
    for(int i=1;i<=nodes;i++)
    {
        if(dfs(i))
        {
            a=1;
            cout<<"cycle detected"<<endl;
            break;
        }
    }

    if(a==0)
    {
        cout<<"no cycle"<<endl;
    }
    return 0;
}
