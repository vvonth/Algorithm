//
//  dp(10844번).cpp
//  c++ learning
//
//  Created by 원태희 on 19/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
long long D[101][10];//범위 조심!!
int main(void){
    int n,i,j;
    long long ans=0;
    scanf("%d",&n);
    for(i=1;i<=9;i++)
    {
         D[1][i]=1;
    }
    for(i=2;i<=n;i++)
    {
        for(j=0;j<10;j++)
        {
            if(j==0)
                D[i][j]=D[i-1][j+1];
            else if(j==9)
                D[i][j]=D[i-1][j-1];
            else
                D[i][j]=D[i-1][j-1]+D[i-1][j+1];
             D[i][j]%=1000000000;
        }
       
    }
    for(int k=0;k<=9;k++)
        ans+=D[n][k];
    printf("%lld",ans%1000000000);
}
