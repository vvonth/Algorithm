//
//  dp(2011번).cpp
//  c++ learning
//
//  Created by 원태희 on 28/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
int dp[5001];
int main(void)
{
    string s;
    cin>>s;
    s=" "+s;//***엄청 중요!!자릿수 맞출려고 1자리 2자리 3자리...
    dp[0]=1;//dp[2]의 기준을 맞추기 위해서...
    for(int i=1;i<s.size();i++)
    {
        int x=s[i]-'0';
        if(1<=x&&x<=9)
        {
            dp[i]+=dp[i-1];
            dp[i]%=1000000;
        }
        if(s[i-1]=='0')
            continue;
            x=(s[i-1]-'0')*10+(s[i]-'0');
        if(10<=x&&x<=26)
        {
            dp[i]+=dp[i-2];
            dp[i]%=1000000;
        }
    }
    cout<<dp[s.size()-1]<<'\n';
        
}
