//
//  섬의 개수(4963번).cpp
//  c++ learning
//
//  Created by 원태희 on 24/04/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int map[51][51];
int check[51][51];
int dx[]={1,-1,0,0,1,-1,-1,1};
int dy[]={0,0,1,-1,-1,1,-1,1};
queue<pair<int,int>> q;
void bfs(int, int, int, int);
int main(void)
{
    while(1)
    {
        memset(map,0,sizeof(map));
        memset(check,0,sizeof(check));
        int w, h;
        int count=0;
        cin>>w>>h;
        
        if(w==0&&h==0)
        {
            break;
        }
        
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(!check[i][j]&&map[i][j]==1)
                {
                    bfs(i,j,w,h);
                    count++;
                }
            }
        }
        cout<<count<<'\n';
    }
    return 0;
}
void bfs(int y, int x,int w, int h)
{
    q.push(make_pair(y,x));
    check[y][x]=1;
    while(!q.empty())
    {
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        for(int k=0;k<8;k++)
        {
            int di=i+dy[k];
            int dj=j+dx[k];
            if(!check[di][dj]&&di>=0&&dj>=0&&di<h&&dj<w&&map[di][dj]==1)
            {
                check[di][dj]=1;
                q.push(make_pair(di,dj));
            }
        }
    }
}
