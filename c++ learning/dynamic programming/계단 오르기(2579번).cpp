//
//  dp(2579번).cpp
//  c++ learning
//
//  Created by 원태희 on 25/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int dp[301][3];
int arr[301];
int dp1[301];
/*int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    dp[1][1]=arr[1];
    for(int i=2;i<=n;i++)
    {
        dp[i][1]=max(dp[i-2][1],dp[i-2][2])+arr[i];
        dp[i][2]=dp[i-1][1]+arr[i];
    }
    cout<<max(dp[n][1],dp[n][2])<<'\n';
}*/
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    dp1[1]=arr[1];
    dp1[2]=arr[1]+arr[2];
    for(int i=3;i<=n;i++)
    {
        dp1[i]=max(dp1[i-2]+arr[i],dp1[i-3]+arr[i-1]+arr[i]);
    }
    printf("%d\n",dp1[n]);
}
    

