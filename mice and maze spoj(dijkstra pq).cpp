#include<bits/stdc++.h>
using namespace std;
//#define pair<int,int> pi
#define INF INT_MAX
vector< pair<int,int> > graph[101];
int n;
int dijkstra(int ecell,int src)
{
    priority_queue< pair< int,int >, vector < pair< int,int > > , greater< pair< int,int > > > pq;


            vector<int> dist(n+1,INF);
            pq.push(make_pair(0,src));
            dist[src]=0;
            while(!pq.empty())
            {
                int u=pq.top().second;
                pq.pop();
                for(int k=0;k<graph[u].size();k++)
                {
                    if((dist[u]+graph[u][k].first)<dist[graph[u][k].second])
                     {
                       dist[graph[u][k].second]=dist[u]+graph[u][k].first;
                       pq.push(make_pair(dist[graph[u][k].second],graph[u][k].second));
                     }
                }

            }
        return dist[ecell];

}
int main()
{
    int e,t,m;
    cin>>n>>e>>t>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,wt;
        cin>>a>>b>>wt;
        graph[a].push_back(make_pair(wt,b));
    }
    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        arr[i]=dijkstra(e,i);
    }
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]<=t)
        {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
