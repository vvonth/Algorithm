//
//  8to2(1212번).cpp
//  c++ learning
//
//  Created by 원태희 on 02/04/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(void)
{
    int k;
    string s;
    cin>>s;
    string v1[8]={"000","001","010","011","100","101","110","111"};
    string v2[8]={"0","1","10","11","100","101","110","111"};
    for(int i=0;i<s.size();i++)
    {
        k=s[i]-'0';
        if(i==0)
        {
            cout<<v2[k];
        }
        else
            cout<<v1[k];
    }
    cout<<'\n';
}

