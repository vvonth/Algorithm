//
//  coding test3.cpp
//  c++ learning
//
//  Created by 원태희 on 16/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
int build[1000001];
//int inde[1000001];
using namespace std;
int right(int);
int main(){
    int n;
    int m=0;
    stack<pair<int,int>> s;
    scanf("%d",&n);
    scanf("%d",&build[1]);//높이
    s.push(make_pair(1,build[1]));
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&build[i]);
        while(!s.empty())
        {
            if(s.top().second>build[i])
            {
                m=max(m, abs(i-s.top().first));
                //inde[i]=s.top().first;
                break;
            }
            s.pop();
        }
        s.push(make_pair(i,build[i]));
    }
    m=max(m,right(n));
    printf("%d",m);
    /*for(int i=0;i<=n;i++)
    {
        printf("%d",inde[i]);
    }*/
}
int right(int n)
{
    stack<pair<int,int>> s2;
    s2.push(make_pair(n,build[n]));
    int m=0;
    for(int i=n-1;i>=1;i--)
    {
        while(!s2.empty())
        {
            if(s2.top().second>build[i])
            {
                m=max(m,abs(i-s2.top().first));
                break;
            }
            s2.pop();
        }
        s2.push(make_pair(i,build[i]));
    }
    return m;
}
