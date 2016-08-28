#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long> v;
    long long a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    if((n%2)==0)
    {
        cout<<v[n/2-1];
    }
    else cout<<v[n/2];
    return 0;
}
