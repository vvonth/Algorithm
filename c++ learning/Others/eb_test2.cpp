//
//  eb_test2.cpp
//  c++ learning
//
//  Created by 원태희 on 09/06/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
bool solution(string, string);
int fail[10001];
int main(void)
{
    string s,t;
    cin>>s>>t;
    cout<<solution(s,t)<<'\n';
    return 0;
}

bool solution(string s, string t)
{
    if(s.size()>t.size())
    {
        s=s+s;
        int i=0;
        int j=0;
        int m=(int)s.size();
        int n=(int)t.size();
        while(i<m)
        {
            if(s[i++]!=t[j++])
            {
                return false;
            }
            if(j==n)
                j=0;
        }
        return true;
    }
    else
    {
        t=t+t;
        int i=0;
        int j=0;
        int m=(int)s.size();
        int n=(int)t.size();
        while(j<n)
        {
            if(s[i++]!=t[j++])
            {
                return false;
            }
            if(i==m)
                i=0;
        }
        return true;
    }
}


