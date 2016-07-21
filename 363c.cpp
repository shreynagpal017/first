#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    bool a=false,b=false;
    int count=0;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k=0;
    for(k=0;k<n;k++)
    {
        if(arr[k]==3)
        {
            continue;
        }
        if(arr[k]==0)
        {
            count++;

        }
        if(arr[k]==2||arr[k]==1)
            break;
    }
    //cout<<k<<"  "<<a<<"  "<<b<<endl;
    for(int i=k;i<n;i++)
    {
        if(arr[i]==1)
        {
             if(a==true)
             {
                 count++;
                 b=false;
                 a=false;
             }
             else
             {

                 {
                     a=true;
                     b=false;
                 }
             }
        }
        if(arr[i]==2)
        {
            if(b==true)
            {
                count++;
                b=false;
                a=false;
            }
            else
            {
                    b=true;
                    a=false;

            }
        }
        if(arr[i]==3)
        {
            if(a==true&&b==false)
            {
                a=false;
                b=true;
            }
            else if(b==true&&a==false)
            {
                a=true;
                b=false;
            }
            else if(a==true&&b==true)
            {
                count++;
                a=false;
                b=false;
            }


        }
        if(arr[i]==0)
        {
            a=false;
            b=false;
            count++;
        }
    }
    cout<<count;
    return 0;
}
