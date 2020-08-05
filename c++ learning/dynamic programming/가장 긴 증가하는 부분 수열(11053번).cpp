//
//  dp(11053번).cpp
//  c++ learning
//
//  Created by 원태희 on 21/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int a[1001];
int dp[1001];
int main(){
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    dp[0]=1;
    for(int i=1;i<n;i++)
    {   dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    m=dp[0];
    for(int i=1;i<n;i++)
        m=max(m,dp[i]);
                  cout<<m<<'\n';
}
