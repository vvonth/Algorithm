//
//  물통(2251번).cpp
//  c++ learning
//
//  Created by 원태희 on 23/06/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
#include <iostream>
#include <queue>
#include <vector>
int visited[201][201];
using namespace std;
int main(void)
{
    vector<int> v;
    int a,b,c;
    cin>>a>>b>>c;
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    visited[0][0]=1;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        int z=c-x-y;
        if(x==0)
            v.push_back(z);
        
        //x->y
        int ny=y;
        int nx=x;
        ny+=nx;
        nx=0;
        if(ny>b)
        {
            nx=ny-b;
            ny=b;
        }
        if(!visited[nx][ny])
        {
            q.push(make_pair(nx,ny));
            visited[nx][ny]=1;
        }
        //x->z
        int nz=z;
        nx=x;
        ny=y;
        nz+=nx;
        nx=0;
        if(nz>c)
        {
            nx=nz-c;
            nz=c;
        }
        if(!visited[nx][ny])
        {
            q.push(make_pair(nx,ny));
            visited[nx][ny]=1;
        }
        //y->x
        ny=y;
        nx=x;
        nx+=ny;
        ny=0;
        if(nx>a)
        {
            ny=nx-a;
            nx=a;
        }
        if(!visited[nx][ny])
        {
            q.push(make_pair(nx,ny));
            visited[nx][ny]=1;
        }
        //y->z
        ny=y;
        nz=z;
        nx=x;
        nz+=ny;
        ny=0;
        if(nz>c)
        {
            ny=nz-c;
            nz=c;
        }
        if(!visited[nx][ny])
        {
            q.push(make_pair(nx,ny));
            visited[nx][ny]=1;
        }
        //z->x
        ny=y;
        nx=x;
        nz=z;
        nx+=nz;
        nz=0;
        if(nx>a)
        {
            nz=nx-a;
            nx=a;
        }
        if(!visited[nx][ny])
        {
            q.push(make_pair(nx,ny));
            visited[nx][ny]=1;
        }
        //z->y
        ny=y;
        nx=x;
        nz=z;
        ny+=nz;
        nz=0;
        if(ny>b)
        {
            nz=ny-b;
            ny=b;
        }
        if(!visited[nx][ny])
        {
            q.push(make_pair(nx,ny));
            visited[nx][ny]=1;
        }
    }
    sort(v.begin(),v.end());
    for(auto x:v)
        cout<<x<<' ';
    cout<<'\n';
    return 0;
}
/* 방향성을 생각해서 배열로 방향성을 나타낸뒤 for문을 돌려도 된다.
 for (int k=0; k<6; k++) {
 int next[3] = {cur[0], cur[1], cur[2]};
 next[to[k]] += next[from[k]];
 next[from[k]] = 0;
 if (next[to[k]] >= cap[to[k]]) {
 next[from[k]] = next[to[k]] - cap[to[k]];
 next[to[k]] = cap[to[k]];
 }
 if (!check[next[0]][next[1]]) {
 check[next[0]][next[1]] = true;
 q.push(make_pair(next[0], next[1]));
 if (next[0] == 0) {
 ans[next[2]] = true;
 }
 }
 }
 */
