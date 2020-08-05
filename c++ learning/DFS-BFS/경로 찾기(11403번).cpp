//
//  경로 찾기(11403번).cpp
//  c++ learning
//
//  Created by 원태희 on 01/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
queue<int> q;
vector<int> v[101];
int graph[101][101];
int check[101][101];
void bfs(int,int);
int main(void)
{
    int n,a;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a;
            if(a==1)
            {
                graph[i][j]=a;
                v[i].push_back(j);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(graph[i][j]==0)
                bfs(i,j);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<graph[i][j]<<' ';
        }
        cout<<'\n';
    }
}

void bfs(int to,int from)
{
    memset(check,0,sizeof(check));
    q.push(to);
    while(!q.empty())
    {
        int nto=q.front();
        q.pop();
        for(int i=0;i<v[nto].size();i++)
        {
            if(v[nto][i]==from)
            {
                graph[to][from]=1;
            }
            else if(!check[nto][v[nto][i]])
               {
                   q.push(v[nto][i]);
                   check[nto][v[nto][i]]=1;
               }
        }
    }
}
