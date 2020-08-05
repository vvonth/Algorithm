//
//  connect_component(11724번).cpp
//  c++ learning
//
//  Created by 원태희 on 19/04/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int check[1001];
//vector<int> a[1001];
void dfs(int i,vector<int> *a)
{   check[i]=1;
    for(int j=0;j<a[i].size();j++)
    {
        if(!check[a[i][j]])
        {   //cout<<"방문노드:"<<a[i][j]<<'\n';
            dfs(a[i][j],a);
        }
    }
}
int main(void)
{
    vector<int> a[1001];
    int component=0;
    int n,m,u,v;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        sort(a[i].begin(),a[i].end());
    }
    for(int i=1;i<=n;i++)
    {
        if(!check[i])
        {   dfs(i,a);
            component++;
           // cout<<"연결요소개수:"<<component<<'\n';
            
        }
    }
    cout<<component<<'\n';
    return 0;
}
