//
//  dp(11055번).cpp
//  c++ learning
//
//  Created by 원태희 on 21/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int a[1001];
int k;
int main(void)
{
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        dp[i]=a[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
                dp[i]=max(dp[i],dp[j]+a[i]);
        }
    }
    int m=dp[0];
    for(int i=0;i<n;i++)
        m=max(dp[i],m);
    cout<<m<<'\n';
}
