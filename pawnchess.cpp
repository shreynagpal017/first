#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[8][8];
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cin>>str[i][j];
        }
    }
    int mini=INT_MAX;
    char ans;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(str[i][j]=='W')
            {
               // cout<<"yes"<<endl;
                int flag=0;
                for(int k=i-1;k>=0;k--)
                {
                  //  cout<<str[k][j]<<endl;
                    if(str[k][j]=='B'||str[k][j]=='W')
                    {
                        flag=1;
                    }

                }
                if(flag==0)
                {
                    int m=i;
                    if(m<=mini)
                    {
                        ans='A';
                        mini=m;
                    }
                  //  cout<<"  "<<mini<<endl;
                }
            }

            else if(str[i][j]=='B')
            {
                int flag=0;
                for(int k=i+1;k<8;k++)
                {
                    if(str[k][j]=='B'||str[k][j]=='W')
                    {
                        flag=1;
                    }


                }
                if(flag==0)
                {
                    int m=7-i;
                    if(m<mini)
                    {
                        ans='B';
                        mini=m;
                    }
                //    cout<<"  "<<mini<<endl;
                }
            }

        }
    }
    cout<<ans;//<<"  "<<mini;
    return 0;
}
