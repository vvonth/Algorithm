//
//  토마토(7576번).cpp
//  c++ learning
//
//  Created by 원태희 on 24/04/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int tomato[1001][1001];
int day[1001][1001];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
queue<pair<int,int>> q;
int m,n;
void bfs();
int main(void)
{
    
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&tomato[i][j]);
            day[i][j]=-1;
            if(tomato[i][j]==-1)
                day[i][j]=-2;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(tomato[i][j]==1&&day[i][j]==-1)
            {
                q.push(make_pair(i,j));
                day[i][j]=0;
            }
        }
    }
    bfs();
    return 0;
}
void bfs(){
    int m1=-1;
    while(!q.empty())
    {
        int x=q.front().second;
        int y=q.front().first;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(day[ny][nx]==-1&&tomato[ny][nx]==0&&ny>=0&&nx>=0&&ny<n&&nx<m)
            {
                q.push(make_pair(ny, nx));
                tomato[ny][nx]=1;
                day[ny][nx]=day[y][x]+1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(tomato[i][j]==0)
            {
                cout<<-1<<'\n';
                return;
            }
            else
            {
                m1=max(m1,day[i][j]);
            }
        }
    }
    cout<<m1<<'\n';
}
