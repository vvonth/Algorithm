//
//  dp(1699번).cpp
//  c++ learning
//
//  Created by 원태희 on 27/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
int dp[100001];
int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        dp[i]=i;//max값 (1의 제곱 개수)
        for(int k=1;k*k<=i;k++)
            if(dp[i]>dp[i-k*k]+1)
                dp[i]=dp[i-k*k]+1;
    }
    cout<<dp[n]<<'\n';
}
