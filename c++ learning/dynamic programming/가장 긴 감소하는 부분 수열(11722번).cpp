//
//  dp(11722번).cpp
//  c++ learning
//
//  Created by 원태희 on 22/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
int dp[1001];
int a[1001];
int main(void)
{
    int n;
    int m;
    scanf("%d",&n);
    for(int i=n-1;i>=0;i--)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j]&&dp[i]<dp[j]+1)
                dp[i]=dp[j]+1;
        }
    }
    m=dp[0];
    for(int i=1;i<n;i++)
        m=max(m,dp[i]);
    cout<<m<<'\n';
    
}
