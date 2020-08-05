//
//  dp(2133번).cpp
//  c++ learning
//
//  Created by 원태희 on 27/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
long long dp[31];
int main(void)
{
    int n;
    scanf("%d",&n);
    dp[0]=1;//***
    for(int i=2;i<=n;i+=2)
    { dp[i]=3*dp[i-2];
        for(int j=4;j<=i;j+=2)
        {
            dp[i]+=2*dp[i-j];
        }
    }
    cout<<dp[n]<<'\n';
        
}
