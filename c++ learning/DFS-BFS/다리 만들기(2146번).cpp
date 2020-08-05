//
//  다리 만들기(2146번).cpp
//  c++ learning
//
//  Created by 원태희 on 24/04/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
#include <iostream>
#include <queue>
using namespace std;
int map[101][101];
int group[101][101];
int dist[101][101];
int check[101][101];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n;
queue<pair<int,int>> q;
void dfs(int y, int x,int number)
{
    if(!map[y][x])
    {
        return;
    }
    else
    {
        check[y][x]=1;
        dist[y][x]=0;
        group[y][x]=number;
    }
    for(int i=0;i<4;i++)
    {
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny>=0&&nx>=0&&ny<n&&nx<n&&!check[ny][nx])
            dfs(ny,nx,number);
    }
}


void bfs()
{
    while(!q.empty())
    {
        int x=q.front().second;
        int y=q.front().first;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&ny>=0&&nx<n&&ny<n&&dist[ny][nx]==-1)//방문 안하는 경우
            {
                group[ny][nx]=group[y][x];
                dist[ny][nx]=dist[y][x]+1;
                q.push(make_pair(ny,nx));
            }
                
        }
    }
}
int main(void)
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&map[i][j]);
            dist[i][j]=-1;
        }
    }
    int number=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!check[i][j]&&map[i][j]==1)
            {
                dfs(i,j,number);
                number++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if(map[i][j]==0)
            {
                for(int k=0;k<4;k++)
                {
                    int ni=i+dy[k];
                    int nj=j+dx[k];
                    if(map[ni][nj]&&ni>=0&&nj>=0&&ni<n&&nj<n)
                    {
                        group[i][j]=group[ni][nj];
                        q.push(make_pair(i,j));
                        dist[i][j]=1;
                        break;
                    }
                }
            }
        }
    }
    bfs();
    
    int m2=0x7ffff;
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            for(int k=0;k<4;k++)
            {
                int nx=j+dx[k];
                int ny=i+dy[k];
                if(group[i][j]!=group[ny][nx]&&nx>=0&&ny>=0&&nx<n&&ny<n)
                {
                   m2= min(m2,dist[i][j]+dist[ny][nx]);
                }
            }
        }
    }
    cout<<m2<<'\n';
}


/*for(int i=0;i<n;i++)
 {
 for (int j=0;j<n;j++)
 {
 cout<<group[i][j];
 }
 cout<<'\n';
 for(int i=0;i<n;i++)
 {
 for (int j=0;j<n;j++)
 {
 cout<<dist[i][j];
 }
 cout<<'\n';
 }
 }*/
