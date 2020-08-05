//
//  dp(2225번).cpp
//  c++ learning
//
//  Created by 원태희 on 28/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
long long dp[201][201];
int main(void){
    int n,k;
    scanf("%d %d",&n,&k);
    dp[0][0]=1;
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int m=0;m<=j;m++)
            {
                dp[i][j]+=dp[i-1][j-m];
                dp[i][j]%=1000000000;
            }
        }
    }
    cout<<dp[k][n]<<'\n';
}
