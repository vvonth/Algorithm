//
//  dp(11054번).cpp
//  c++ learning
//
//  Created by 원태희 on 22/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
int dp1[1001];
int dp2[1001];
int a[1001];
int main(void){
    int n;
    int m1=-2147483648;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        dp1[i]=1;
        dp2[n-i-1]=1;
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j]&&dp1[i]<dp1[j]+1)
            {
                dp1[i]=dp1[j]+1;
            }
            if(a[n-i-1]>a[n-j-1]&&dp2[n-i-1]<dp2[n-j-1]+1)
            {
                dp2[n-i-1]=dp2[n-j-1]+1;
            }
            
        }
    }
    for(int i=0;i<n;i++)
        m1=max(dp1[i]+dp2[i],m1);
        cout<<m1-1<<'\n';
}
