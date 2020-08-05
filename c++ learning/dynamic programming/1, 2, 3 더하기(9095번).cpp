//
//  dp(9095번).cpp
//  c++ learning
//
//  Created by 원태희 on 15/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
int memo[11];
int dp(int n)
{
 
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(n==3)
        return 4;
    if(memo[n]>0)
        return memo[n];
        memo[n]=dp(n-1)+dp(n-2)+dp(n-3);
    return memo[n];
}
int main(){
    int t, n;
    for(scanf("%d",&t);t>0;t--)
    {
        scanf("%d",&n);
        printf("%d\n",dp(n));
    }
}
