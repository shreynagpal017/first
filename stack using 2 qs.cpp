#include<bits/stdc++.h>
using namespace std;
queue<int> q1,q2,temp;
void enqueue(int data)
{
    q1.push(data);
}
void dequeue()
{
    if(q1.size()==0)
    {
        cout<<"underflow"<<endl;
        return;
    }
    while(q1.size()!=1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    cout<<"popped element"<<q1.back()<<endl;
    q1.pop();
    temp=q2;
    q2=q1;
    q1=temp;
}
int main()
{
//    vector<int> v;
//    cout<<v.size()<<endl;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}
