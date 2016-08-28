#include<bits/stdc++.h>
using namespace std;
long long int solve(int n,int x,int y)
{
    long long int dp[n+1];
    dp[1]=x;
    for(int i=2;i<=n;i++)
    {
        if(i%2)   // 3 cases possible (consider both deletion and insertion)
        {
            dp[i]=min(dp[i-1]+x,min(dp[i/2]+x+y,dp[i/2+1]+y+x));
        }
        else
        {
            dp[i]=min(dp[i-1]+x,dp[i/2]+y);
        }
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,y;
    cin>>n>>x>>y;
    cout<<solve(n,x,y);
    return 0;
}
