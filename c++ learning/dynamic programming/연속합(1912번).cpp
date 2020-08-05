//
//  dp(1912번).cpp
//  c++ learning
//
//  Created by 원태희 on 22/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
int dp[100001];
int a[100001];
int main(void)
{
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    dp[0]=a[0];
    for(int i=1;i<n;i++)
    {
        if(dp[i-1]+a[i]>a[i])
            dp[i]=dp[i-1]+a[i];
        else
            dp[i]=a[i];
    }
    m=dp[0];
    for(int i=1;i<n;i++)
        m=max(m,dp[i]);
    cout<<m<<'\n';
}
