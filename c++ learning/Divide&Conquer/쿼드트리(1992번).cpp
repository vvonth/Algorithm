//
//  쿼드트리(1992번).cpp
//  c++ learning
//
//  Created by 원태희 on 12/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
//논리오류:(n/2)*(j+1)->첫부분만 성립하고 중간에서 인덱스 위치가 달라진다.!!!!!중요***
#include <iostream>
using namespace std;
int pixel[65][65];
void divide(int,int,int);
int main(void)
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%1d",&pixel[i][j]);
        }
    }
    divide(0,0,n);
    return 0;
}
bool find(int start_x, int start_y,int n)
{
    int k=pixel[start_x][start_y];
    for(int i=start_x;i<n+start_x;i++)
    {
        for(int j=start_y;j<n+start_y;j++)
        {
            if(k!=pixel[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
void divide(int start_x, int start_y, int n)
{
    if(!find(start_x,start_y,n))
    {
        printf("(");
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                divide(start_x+n/2*i,start_y+n/2*j,n/2);
            }
        }
        printf(")");
    }
    else
    {
        
        printf("%d",pixel[start_x][start_y]);
        
    }
}
