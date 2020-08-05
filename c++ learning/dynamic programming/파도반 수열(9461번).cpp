//
//  dp(9461번).cpp
//  c++ learning
//
//  Created by 원태희 on 28/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
#include<iostream>
using namespace std;
long long dp[101];
int main(void)
{
    int n,a;
    for(scanf("%d",&n);n>0;n--)
    {
        dp[1]=1;
        dp[2]=1;
        dp[3]=1;
        dp[4]=2;
        dp[5]=2;
        scanf("%d",&a);
        
        for(int i=6;i<=a;i++)
        {
            dp[i]=dp[i-1]+dp[i-5];
        }
        cout<<dp[a]<<'\n';
    }
}
