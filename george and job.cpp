#include<bits/stdc++.h>
using namespace std;
long long int sum[5001];
bool check[5001][5001];
long long int dp[5001][5001];
int n,m;
long long max(long long a,long long b)
{
    if(a>b)
        return a;
    else return b;
}
long long solve(int i,int k)
{
    if(k==0)
    {
        return 0;
    }
    if(i>n-m&&k>0) // important statement when k is still greater than zero and i goes greater than n-m so we do not need to consider this case.
    {
        return -1;
    }
    if(check[i][k]==1)
    {
        return dp[i][k];
    }
    check[i][k]=1;
    dp[i][k]=max(solve(i+1,k),solve(i+m,k-1)+sum[i]);
    return dp[i][k];
}
int main()
{
    int k;
    cin>>n>>m>>k;
    long long int arr[n];//sum[n-m+1];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int j=0;j<n-m+1;j++)
    for(int i=0+j;i<m+j;i++)
    {
        sum[j]+=arr[i];
    }
//    for(int i=0;i<=n-m;i++)
//    {
//        cout<<sum[i]<<" ";
//    }
//    cout<<endl;
    cout<<solve(0,k);
    return 0;
}
