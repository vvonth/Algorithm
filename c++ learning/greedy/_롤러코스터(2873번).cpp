//
//  롤러코스터(2873번).cpp
//  c++ learning
//
//  Created by 원태희 on 06/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
//체스판에 대한 이해(짝수*짝수 일때 경로에 대해서 생각)
#include <iostream>
using namespace std;
int map[1001][1001];
int visit[1001][1001];

void wrote(string &s,char m, int n)
{
    for(int i=0;i<n;i++)
        s+=m;
}

int main(void)
{
    int r,c;
    int m=1000;
    int min_x,min_y;
    string s="";
    string s2="";
    string s3="";
    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>map[i][j];
            if((i+j)%2==1)
            {
                if(m>map[i][j])
                {
                    m=map[i][j];
                    min_y=i;
                    min_x=j;
                }
            }
        }
    }
    if(r%2==1)
    {
        for(int j=0;j<r;j++)
        {
            
            if(j%2==0)
                wrote(s,'R', c-1);
            else
                wrote(s,'L',c-1);
            if(j==r-1)
                break;
                wrote(s,'D',1);
        }
    }
    else if(r%2==0&&c%2==1)
    {
        for(int j=0;j<c;j++)
        {
            
            if(j%2==0)
                wrote(s,'D', r-1);
            else
                wrote(s,'U',r-1);
            if(j==c-1)
                break;
            wrote(s,'R',1);
        }
    }
    else if(r%2==0&&c%2==0)
    {
        int start_x=0;
        int start_y=0;
        int final_x=c-1;
        int final_y=r-1;
        if(final_y-start_y>1)
        {
            while(start_y/2<min_y/2)
            {
                wrote(s,'R',c-1);
                wrote(s,'D',1);
                wrote(s,'L',c-1);
                wrote(s,'D',1);
                start_y+=2;
            }
            while(min_y/2<final_y/2)
            {
                wrote(s2,'D',1);
                wrote(s2,'L',c-1);
                wrote(s2,'D',1);
                wrote(s2,'R',c-1);
                final_y-=2;
            }
        }
        if(final_x-start_x>1)
        {
            while(start_x/2<min_x/2)
            {
                wrote(s,'D',1);
                wrote(s,'R',1);
                wrote(s,'U',1);
                wrote(s,'R',1);
                start_x+=2;
            }
            while(min_x/2<final_x/2)
            {
                wrote(s3,'R',1);
                wrote(s3,'U',1);
                wrote(s3,'R',1);
                wrote(s3,'D',1);
                final_x-=2;
            }
        }
        if(min_y==start_y)
        {
            wrote(s,'D',1);
            wrote(s,'R',1);
        }
        else
        {
            wrote(s,'R',1);
            wrote(s,'D',1);
        }
    }
    s+=s3;
    s+=s2;
    cout<<s<<'\n';
    return 0;
}
