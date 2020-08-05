//
//  dp(11052번).cpp
//  c++ learning
//
//  Created by 원태희 on 15/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int p[10001];//금액
int memo[1001];//최대값
int dp1(int n)
{   int temp;
    memo[1]=p[1];
    int i;
    for(i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            temp=memo[i-j]+p[j];
            if(memo[i]<temp)
                memo[i]=temp;
        }
        
    }
    return memo[n];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("%d\n",dp1(n));
}
