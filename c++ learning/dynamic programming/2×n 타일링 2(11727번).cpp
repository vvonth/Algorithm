//
//  dp(11727번).cpp
//  c++ learning
//
//  Created by 원태희 on 15/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
int dp[1001];
int go(int n)
{
    if(n==1)
        return 1;
    if(n==2)
        return 3;
    if(dp[n]>0)
        return dp[n];
    if(n>2)
        dp[n]=(go(n-1)+2*go(n-2))%10007;
    return dp[n];
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",go(n));
}
