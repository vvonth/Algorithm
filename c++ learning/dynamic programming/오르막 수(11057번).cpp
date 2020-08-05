//
//  dp(11057번).cpp
//  c++ learning
//
//  Created by 원태희 on 19/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
int D[1001][10];
int main(){
    int n;
    long long ans=0;
    scanf("%d",&n);
    for(int i=0;i<10;i++)
        D[1][i]=1;
    for(int j=2;j<=n;j++)
    {
        for(int k=0;k<10;k++)
        {
            for(int m=0;m<=k;m++)
            { D[j][k]+=D[j-1][m];
                D[j][k]%=10007;
            }
        }
    }
    for(int i=0;i<10;i++)
        ans+=D[n][i];
    printf("%lld\n",ans%10007);
}
