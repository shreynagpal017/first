#include<bits/stdc++.h>
using namespace std;
char matrix[501][501];
int arr[250001];
bool visited[250001];
int n,m;
int dfs(int r1,int c1,int r2,int c2)
{
    int ans=0,count=0;
    int src=(r1-1)*m+c1;
    int dest=(r2-1)*m+c2;
    if(src==dest)
    {
        if(arr[src-1]==1&&(src-1)%m!=0&&(src-1)>=0&&(src-1)<=n*m)
        {
            count++;
        }
        if(arr[src+1]==1&&(src+1)%m!=1&&(src+1)<=n*m&&(src+1)>=0)
        {
            count++;
        }
        if(arr[src+m]==1&&(src+m)<=n*m)
        {
            count++;
        }
        if(arr[src-m]==1&&(src-m)>=0)
        {
            count++;
        }
        //cout<<count<<endl;
            if(count>=1)
            {
                ans=1;
            }


        return ans;
    }
    count=0;
    if(((src+1)==dest&&(dest%m)!=1)||(src+m)==dest||(src-m)==dest||(src-1)==dest&&(dest)%m!=0)
    {
        //cout<<"blahblah";
        if(arr[dest-1]==1&&(dest-1)%m!=0&&(dest-1)>=0&&(dest-1)<=n*m)
        {
            count++;
        }
        if(arr[dest+1]==1&&(dest+1)%m!=1&&(dest+1)<=n*m&&(dest+1)>=0)
        {
            count++;
        }
        if(arr[dest+m]==1&&(dest+m)<=n*m)
        {
            count++;
        }
        if(arr[dest-m]==1&&(dest-m)>=0)
        {
            count++;
        }
        if(arr[dest]==1)
        {
            if(count>=1)
                ans=1;
        }
        else ans=1;
        return ans;

    }
    stack <int> s;
    visited[src]=true;
    s.push(src);
    int flag=0;
    if(arr[dest]==0)
    {
        arr[dest]=1;
        flag=1;
    }
    arr[src]=1;
    while(!s.empty())
    {
        int x=s.top();
        //cout<<x<<endl;
        s.pop();
        if(arr[x-1]==1&&(x-1)%m!=0&&(x-1)>=0&&(x-1)<=n*m&&visited[x-1]==false)
        {
            s.push(x-1);
            visited[x-1]=true;
        }
        if(arr[x+1]==1&&(x+1)%m!=1&&(x+1)<=n*m&&(x+1)>=0&&visited[x+1]==false)
        {
            s.push(x+1);
            visited[x+1]=true;
        }
        if(arr[x+m]==1&&(x+m)<=n*m&&visited[x+m]==false)
        {
            s.push(x+m);
            visited[x+m]=true;
        }
        if(arr[x-m]==1&&(x-m)>=0&&visited[x-m]==false)
        {
            s.push(x-m);
            visited[x-m]=true;
        }
    }
//    for(int i=1;i<=n*m;i++)
//    {
//        cout<<i<<"  "<<visited[i]<<endl;
//    }
    int reach=0;
    if(visited[dest]==true)
    {
        reach=1;
    }
    count=0;
    if(reach==1)
    {
        if(arr[dest-1]==1&&(dest-1)%m!=0&&(dest-1)>=0&&(dest-1)<=n*m)
        {
            count++;
        }
        if(arr[dest+1]==1&&(dest+1)%m!=1&&(dest+1)<=n*m&&(dest+1)>=0)
        {
            count++;
        }
        if(arr[dest+m]==1&&(dest+m)<=n*m)
        {
            count++;
        }
        if(arr[dest-m]==1&&(dest-m)>=0)
        {
            count++;
        }
        if(flag==1)
        {
            if(count>=1)
                ans=1;
        }
        else if(arr[dest]==1&&flag==0)
        {
            if(count>=2)
            {
                ans=1;
            }
        }
    }
    return ans;
}
int main()
{
    //int n,m;//n->rows m->cols
    cin>>n>>m;
    int i,j,k=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>matrix[i][j];
            if(matrix[i][j]=='.')
            {
                arr[k]=1;
                k++;
            }
            else {arr[k]=0; k++;}
        }
    }
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    int res=dfs(r1,c1,r2,c2);
    if(res==1)
    {
        cout<<"YES";
    }
    else cout<<"NO";
    return 0;
}
