//
//  종이의 개수(1780번).cpp
//  c++ learning
//
//  Created by 원태희 on 09/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
//생각할 것! 3등분 한다는 것을 잘 생각 규칙찾기!!
#include <iostream>
#include <vector>
using namespace std;
bool check(int,int,int);
void solve(int, int, int);
int count0;
int count1;
int count2;
vector<vector<int>> v;
int main(void)
{
    int N,k;
    
    cin>>N;
    for(int i=0;i<N;i++)
    {
        v.push_back(vector<int>());
        for(int j=0;j<N;j++)
        {
            cin>>k;
            v.at(i).push_back(k);
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<v[i][j];
        }
        cout<<'\n';
    }
    solve(0,0,N);
    printf("%d %d %d",count2,count0,count1);
}
void solve(int start_x, int start_y, int N)
{
    if(!check(start_x,start_y,N))
    {
        int m=N/3;
        
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    solve(start_x+j*m,start_y+i*m,m);
                }
            }
        
        
    }
    else
    {
        if(v[start_y][start_x]==-1)
            count2++;
        
        else if(v[start_y][start_x]==0)
            count0++;
        else
            count1++;
        return;
    }
}

bool check(int x, int y, int N)
{
    int start=v[y][x];
    for(int i=y;i<y+N;i++)
    {
        for(int j=x;j<x+N;j++)
        {
            if(start!=v[i][j])
                return false;
        }
    }
    return true;
}
