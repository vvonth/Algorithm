//
//  트리의 부모 찾기.cpp
//  c++ learning
//
//  Created by 원태희 on 27/04/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> e[100001];
int check[100001];
queue<int> q;
int a[100001];
void bfs(int);
int main(void)
{
    int n;
    cin>>n;
    int c,p;
    for(int i=0;i<n-1;i++)
    {
        cin>>c>>p;
        e[c].push_back(p);
        e[p].push_back(c);
    }
    q.push(1);
    check[1]=1;
    bfs(1);
    for(int i=2;i<=n;i++)
    {
        cout<<a[i]<<'\n';
    }
    return 0;
}
void bfs(int n){
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<e[x].size();i++)
        {
            if(!check[e[x][i]])
            {
                check[e[x][i]]=1;
                q.push(e[x][i]);
                a[e[x][i]]=x;
            }
        }
    }
}

