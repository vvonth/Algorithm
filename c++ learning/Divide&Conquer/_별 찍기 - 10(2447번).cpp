//
//  별 찍기 - 10(2447번).cpp
//  c++ learning
//
//  Created by 원태희 on 12/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
/*
#include <iostream>
using namespace std;
char arr[2200][2200];
void star(int start_x,int start_y,int n)
{
    if(n==1)
    {
        arr[start_x][start_y]='*';
        return;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==1&&j==1)
            {
                //cout<<"start_x+n: "<<start_x+n/3*i<<"start_y+n/3*j: "<<start_y+n/3*j<<'\n';
                continue;
            }
            else
                star(start_x+n/3*i,start_y+n/3*j,n/3);
        }
    }
    
}

int main()
{
    int n;
    scanf("%d",&n);
    memset(arr,' ',sizeof(arr));
    star(0,0,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
}
*/
/*#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<char>> &v, int x,int y, int n,char c)
{
    if(n==1)
    {
        v[x][y]=c;
    }
    else
    {
        if(c==' ')
        {
        for(int i=x;i<x+n;i++)
        {
            for(int j=y;j<y+n;j++)
            {
                cout<<"x: "<<i<<' '<<"y: "<<j<<' '<<"n: "<<n<<'\n';
                v[i][j]=' ';
            }
        }
        }
        else
        {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(i==1&&j==1)
                {
                    solve(v,x+n/3*i,y+n/3*j,n/3,' ');
                }
                else
                    solve(v,x+n/3*i,y+n/3*j,n/3,'*');
            }
        }
        }
    }
    
    
}

int main(void)
{
    int n;
    cin>>n;
    vector<vector<char>> v(n,vector<char>(n,0));
    solve(v,0,0,n,'*');
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%c",v[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/
#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<char>> &v, int x,int y, int n)
{
    if(n==1)
    {
        //cout<<"x: "<<x<<' '<<"y: "<<y<<' '<<"n: "<<n<<'\n';
        v[x][y]='*';
    }
    else
    {
            for(int i=x;i<x+n;i++)
            {
                for(int j=y;j<y+n;j++)
                {
                    //cout<<"x: "<<i<<' '<<"y: "<<j<<' '<<"n: "<<n<<'\n';
                    v[i][j]=' ';
                }
            }
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    if(i==1&&j==1)
                    {
                        continue;
                    }
                    else
                        solve(v,x+n/3*i,y+n/3*j,n/3);
                }
            
        }
    }
    
    
}

int main(void)
{
    int n;
    cin>>n;
    vector<vector<char>> v(n,vector<char>(n,0));
    solve(v,0,0,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%c",v[i][j]);
        }
        printf("\n");
    }
    return 0;
}

