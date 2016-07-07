#include<bits/stdc++.h>
using namespace std;
int arr[601][601];
int x[201],y[201];
int n;
int dp(int w,int h)
{
    if(arr[w][h]!=-1)
    {
        return arr[w][h];
    }
    if(w==0||h==0)
    {
        arr[w][h]=0;
        return 0;
    }

    int res=w*h;
    for(int i=0;i<n;i++)
    {
        if(h-y[i]<0||w-x[i]<0)
            continue;
        res=min((dp(x[i],h-y[i])+dp(w-x[i],h)),res);
        res=min((dp(w-x[i],y[i])+dp(w,h-y[i])),res);
    }
    return arr[w][h]=res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int W,H;
        cin>>W>>H>>n;

        for(int i=0;i<n;i++)
        {
            cin>>x[i]>>y[i];
        }
        memset(arr, -1, sizeof(arr));
        int ans=dp(W,H);
        cout<<ans<<endl;
    }
    return 0;
}
