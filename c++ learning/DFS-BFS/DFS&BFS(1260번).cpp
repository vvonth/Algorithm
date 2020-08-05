//
//  DFS&BFS.cpp
//  c++ learning
//
//  Created by 원태희 on 05/04/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int u[1001][1001];
int check[1001];
int check1[1001];
int check2[1001];
vector<int> arr[1001];
void dfs1(int,int);
void dfs(int,int);
void bfs(int,int);
int main(void)
{
    
    int i,N,M,V,a,b;
    scanf("%d %d %d",&N,&M,&V);
    for(i=M;i>0;i--)
    {
        scanf("%d %d",&a,&b);
        u[a][b]=1;
        u[b][a]=1;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i=1;i<=N;i++)
        sort(arr[i].begin(),arr[i].end());
        dfs1(V,N);
    cout<<'\n';
        dfs(V,N);
    cout<<'\n';
    
        bfs(V,N);
}
void dfs1(int v,int n)
{
    check2[v]=1;
    printf("%d ",v);
    for(int j=0;j<arr[v].size();j++)
    {
        int y=arr[v][j];
        if(!check2[y])
            dfs1(y,n);
    }
}
void dfs(int i,int n)
{
    check[i]=1;
    printf("%d ",i);
    for(int j=1;j<=n;j++)
        if(!check[j]&&u[i][j]==1)
            dfs(j,n);
}

void bfs(int v, int n)
{
    queue<int> q;
    q.push(v);
    check1[v]=1;
    while(!q.empty())
    {
        cout<<q.front()<<' ';
        q.pop();
        for(int i=1;i<=n;i++)
            if(!check1[i]&&u[v][i]==1)
            {
                q.push(i);
                check1[i]=1;
            }
        v=q.front();
    }
   
}
