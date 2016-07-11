#include<bits/stdc++.h>
using namespace std;

int arr[2001],n;
int cache[2001][2001];
int dp(int be,int en)
{


     if(be>en)
        return 0;
     if(cache[be][en]!=-1)
     {
         return cache[be][en];
     }
     int age=n-(en-be+1)+1;
     return cache[be][en]=max(dp(be+1,en)+age*arr[be],dp(be,en-1)+age*arr[en]);

}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cache[i][j]=-1;
        }
    }
    int ans=dp(0,n-1);
    cout<<ans<<endl;
    return 0;
}
