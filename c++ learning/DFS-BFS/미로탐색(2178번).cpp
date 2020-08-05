//
//  미로탐색(2178번).cpp
//  c++ learning
//
//  Created by 원태희 on 24/04/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int map[101][101];
int dist[101][101];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m;
queue<pair<int,int>> q;
void bfs(int ,int);
int main(void)
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%1d",&map[i][j]);
        }
    }
    bfs(0,0);
    printf("%d\n",dist[n-1][m-1]);
    return 0;
}
void bfs(int y, int x)
{
    q.push({y,x});
    dist[y][x]=1;
    while(!q.empty())
    {
        int a=q.front().first;
        int b=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int ny=a+dy[i];
            int nx=b+dx[i];
            if(!dist[ny][nx]&&map[ny][nx]==1&&ny>=0&&nx>=0&&ny<n&&nx<m)
            {
                q.push(make_pair(ny,nx));
                dist[ny][nx]=dist[a][b]+1;
            }
        }
    }
}
