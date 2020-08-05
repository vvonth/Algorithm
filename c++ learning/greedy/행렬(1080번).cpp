//
//  행렬(1080번).cpp
//  c++ learning
//
//  Created by 원태희 on 06/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
int A[501][501];
int B[501][501];
int main(void)
{
    int n,m;
    int cnt=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%1d",&A[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%1d",&B[i][j]);
        }
    }
    
    
    for(int h=0;h<n-2;h++)
    {
        for(int k=0;k<m-2;k++)
        {
            if(A[h][k]!=B[h][k])
            {
                cnt++;
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        A[h+i][k+j]=1-A[h+i][k+j];
                    }
                }
            }
        }
    }
    bool check=true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]!=B[i][j])
            {
                check=false;
            }
        }
        if(!check)
        {   cout<<-1<<'\n';
            break;
        }
    }
    if(check)
        cout<<cnt<<'\n';
    return 0;
}
