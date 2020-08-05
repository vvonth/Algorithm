//
//  Z(1074번).cpp
//  c++ learning
//
//  Created by 원태희 on 15/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
/*
#include <iostream>
using namespace std;
int k;
void Z(int x,int y, int n, int r, int c)
{
    if(n==2)
    {
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                if(x+i==r&&y+j==c)
                {
                    cout<<k<<'\n';
                    return ;
                }
                k++;
            }
        }
    }else
    {
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            Z(x+n/2*i,y+n/2*j,n/2,r,c);
        }
    }
    }
}
int main(void)
{
    int n,r,c;
    cin>>n>>r>>c;
    Z(0,0,(1<<n),r,c);
    
}
*/
#include<iostream>
using namespace std;
int Z(int r,int c, int n)
{
    if(n==1)
    {
        return 2*r+c;
    }
    else
    {
        if(r<(1<<(n-1)))
        {
            if(c<(1<<(n-1)))
            {
                return Z(r,c,n-1);
            }
            else
            {
                return Z(r,c-(1<<(n-1)),n-1)+(1<<(2*n-2));
            }
        }
        else
        {
            if(c<(1<<(n-1)))
               {
                   return Z(r-(1<<(n-1)),c,n-1)+(1<<(2*n-2))*2;
               }
            else
            {
                return Z(r-(1<<(n-1)),c-(1<<(n-1)),n-1)+(1<<(2*n-2))*3;
            }
        }
    }
}
int main(void)
{
    int n,r,c;
    cin>>n>>r>>c;
    cout<<Z(r,c,n)<<'\n';
}
