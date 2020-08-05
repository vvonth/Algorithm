//
//  퇴사(14501번).cpp
//  c++ learning
//
//  Created by 원태희 on 04/08/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int dp[16];
int main(void)
{
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> v;
    int m=0;
    for(int i=0;i<n;i++){
        int T,P;
        scanf("%d %d",&T,&P);
        v.push_back(make_pair(T,P));
        dp[i]=v[i].second;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(i-j>=v[j].first){
                if(dp[i]<dp[j]+v[i].second)
                    dp[i]=dp[j]+v[i].second;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(m<dp[i]&&i+v[i].first<=n)
            m=dp[i];
    }
    cout<<m<<'\n';
        return 0;
}
