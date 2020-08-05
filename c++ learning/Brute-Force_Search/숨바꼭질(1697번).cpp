//
//  숨바꼭질(1697번).cpp
//  c++ learning
//
//  Created by 원태희 on 07/06/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
//dp+bfs!!!
#include <iostream>
#include <queue>
using namespace std;
int visited[100001];
int dist[100001];
int main(void)
{
    int subin;
    int sister;
    cin>>subin>>sister;
    queue<int> q;
    q.push(subin);
    visited[subin]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(x-1>=0&&!visited[x-1])
        {
            visited[x-1]=1;
            q.push(x-1);
            dist[x-1]=dist[x]+1;
        }
        if(x+1<=100000&&!visited[x+1])
        {
            visited[x+1]=1;
            q.push(x+1);
            dist[x+1]=dist[x]+1;
            
        }
        if(x*2<=100000&&!visited[x*2])
        {
            visited[2*x]=1;
            q.push(x*2);
            dist[2*x]=dist[x]+1;
        }
    }
    cout<<dist[sister]<<'\n';
    return 0;
}
