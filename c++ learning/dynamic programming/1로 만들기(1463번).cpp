//
//  dp(1463번).cpp
//  c++ learning
//
//  Created by 원태희 on 15/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
int go(int);
int dp[1000001];
int main(){
    
    int n;
    scanf("%d",&n);
    
    printf("%d",go(n));
}

int go(int n)
{
    int temp;
    if(n==1)
    return 0;
    if(dp[n]>0)
        return dp[n];
    dp[n]=go(n-1)+1;
    if(n%3==0)
    {
        temp=go(n/3)+1;
        if(dp[n]>temp)
            dp[n]=temp;
    }
    else if(n%2==0)
    {
        temp=go(n/2)+1;
        if(dp[n]>temp)
            dp[n]=temp;
    }
    return dp[n];
}
/*
 int go(int n)
 {
    dp[1]=0;
    for(int i=2;i<n;i++)
    {
        dp[i]=dp[i-1]+1;
        if((i%3==0)&&dp[i]>dp[i/3]+1)
        {
        dp[i]=dp[i/3]+1;
        }
        else if((i%2==0&&dp[i]>dp[i/2]+1)
        {
        dp[i]=dp[i/2]+1;
        }
    }
 }
 */
 
