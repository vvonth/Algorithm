//
//  퍼즐(1525번).cpp
//  c++ learning
//
//  Created by 원태희 on 20/06/2019.
//  Copyright © 2019 원태희. All rights reserved.
// 문자열변환으로 자리를 바꿔주고 숫자로 바꾸어 맵을 이용해 value를 저장<- 배열을 사용할때보다 용량이 작아짐 배열 사용하려면 9!을 사용해야함 너무 크다.
//map 사용법!!
#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main(void)
{   int start=0;
    int n;
    for(int i=1;i<=9;i++)
    {
        cin>>n;
        if(n==0)
            n=9;
        start=start*10+n;
    }
    queue<int> q;
    q.push(start);
    map<int,int> d;
    d[start]=0;
    while(!q.empty())
    {
        int x=q.front();
        string now=to_string(x);
        q.pop();
        int k=now.find('9');
        int y=k/3;
        int z=k%3;
        for(int i=0;i<4;i++)
        {
            int ny=y+dx[i];
            int nz=z+dy[i];
            if(ny>=0&&ny<3&&nz>=0&&nz<3)
            {
                string next=now;
                swap(next[y*3+z],next[ny*3+nz]);
                int change=stoi(next);
                if(d.count(change)==0)
                {
                    d[change]=d[x]+1;
                    q.push(change);
                }
                
            }
        }
    }
    if(d.count(123456789)==0)
        cout<<-1<<'\n';
    else
        cout<<d[123456789]<<'\n';
    return 0;
}
