//
//  DSLR(9019번).cpp
//  c++ learning
//
//  Created by 원태희 on 18/06/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
char now[10000];
int from[10000];
int visited[10000];
int D(int x)
{
    return x*2%10000;
}
int S(int x)
{
    if(x==0)
        return 9999;
    
    else
        return x-1;
}
int L(int x)
{
    return x/1000+(x%1000)*10;
}
int R(int x)
{
    return (x%10)*1000+x/10;
}
void print(int start, int end)
{
    if(start==end)
        return;
    print(start,from[end]);
    cout<<now[end];
}
int main(void)
{
    int T;
   for(scanf("%d",&T);T>0;T--)
   {
       int start, end;
       scanf("%d %d",&start, &end);
       queue<int> q;
       memset(visited,0,sizeof(visited));
       memset(now,0,sizeof(now));
       memset(from,0,sizeof(from));
       visited[start]=1;
       from[start]=-1;
       q.push(start);
       //visited[start]=1;
       while(!q.empty())
       {
           int x=q.front();
           q.pop();
           int d=D(x);
           int s=S(x);
           int l=L(x);
           int r=R(x);
           if(!visited[d])
           {
               visited[d]=1;
               q.push(d);
               from[d]=x;
               now[d]='D';
           }
           if(!visited[s])
           {
               visited[s]=1;
               q.push(s);
               from[s]=x;
               now[s]='S';
           }
           if(!visited[l])
           {
               visited[l]=1;
               q.push(l);
               from[l]=x;
               now[l]='L';
           }
           if(!visited[r])
           {
               visited[r]=1;
               q.push(r);
               from[r]=x;
               now[r]='R';
           }
       }
       print(start, end);
       cout<<'\n';
   }
        return 0;
}
