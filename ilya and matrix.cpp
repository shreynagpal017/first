#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {

        cin>>arr[i];

    }
    long long sum=0;

     sort(arr.rbegin(), arr.rend());

        for(int i=1;i<=n;i=i*4)
        {

            for(int j=0;j<i;j++)
            {
                sum+=arr[j];

            }

        }

    cout<<sum;
    return 0;
}
