//
//  별 찍기 - 11(2448번).cpp
//  c++ learning
//
//  Created by 원태희 on 14/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
/*#include<iostream>
#include<vector>
using namespace std;
void solve(vector<vector<char>> &v,int x,int y,int n)
{
    if(n==3)
    {
        v[x][y]='*';
        v[x+1][y-1]='*';
        v[x+1][y+1]='*';
        v[x+2][y-2]='*';
        v[x+2][y-1]='*';
        v[x+2][y]='*';
        v[x+2][y+1]='*';
        v[x+2][y+2]='*';
        return ;
    }
    solve(v,x,y,n/2);
    solve(v,x+n/2,y-n/2,n/2);
    solve(v,x+n/2,y+n/2,n/2);
    
}
int main(void)
{
    int n;
    cin>>n;
    vector<vector<char>> v(n,vector<char>(2*n,' '));
    solve(v,0,n-1,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2*n;j++)
        {
            printf("%c",v[i][j]);
        }
        printf("\n");
    }
}*/
