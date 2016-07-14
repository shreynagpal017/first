#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<long long,long long> mymap;
    long long q;
    cin>>q;
    while(q--)
    {
        int c;
        cin>>c;

        if(c==1)
        {
            long long u,v,w;
            cin>>u>>v>>w;
            while(v!=u)
            {
                if(v>u)
                {
                    mymap[v]+=w;
                    v=v/2;
                }
                else
                {
                    mymap[u]+=w;
                    u=u/2;
                }
            }
        }
        else
        {
             long long u,v;
             cin>>u>>v;
             long long sum=0;
             while(v!=u)
             {
                 if(v>u)
                 {
                     sum+=mymap[v];
                     v=v/2;
                 }
                 else
                 {
                     sum+=mymap[u];
                     u=u/2;
                 }

             }
             cout<<sum<<endl;

        }
    }
    return 0;
}
