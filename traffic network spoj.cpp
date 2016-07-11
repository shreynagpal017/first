#include<bits/stdc++.h>
using namespace std;
//#define gc getchar_unlocked
#define INF 0x3f3f3f3f
//void scanint(int &x)
//{
//    register int c = gc();
//    x = 0;
//    for(;(c<48 || c>57);c = gc());
//    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
//}

vector<int> dijkstra(int src,int n,vector< pair<int,int> > graph[])
{
    vector<int> dist(n+1,INF);
    priority_queue< pair< int,int >, vector < pair< int,int > > , greater< pair< int,int > > > pq;
    pq.push(make_pair(0,src));
    dist[src]=0;
    for(int j=1;j<=n&&!pq.empty();j++)
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
    return dist;
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,k,src,trg;
        scanf("%d %d %d %d %d",&n,&m,&k,&src,&trg);
        vector< pair<int,int> > graph[n+1];
        vector< pair<int,int> > tgraph[n+1];
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            graph[a].push_back(make_pair(c,b));
            tgraph[b].push_back(make_pair(c,a));
        }
        vector <int> d1=dijkstra(src,n,graph);
        vector <int> d2=dijkstra(trg,n,tgraph);
        int ans=d1[trg];
        //cout<<ans<<endl;
        for(int i=0;i<k;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            ans= min(ans,d1[a]+c+d2[b]);
            ans= min(ans,d1[b]+c+d2[a]);
        }
        if(ans==INF)
        {
            printf("-1\n");
        }
        else printf("%d\n",ans);

    }
    return 0;
}
