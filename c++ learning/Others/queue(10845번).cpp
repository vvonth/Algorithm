//
//  queue(10845번).cpp
//  c++ learning
//
//  Created by 원태희 on 20/02/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    int n,m;
    string s;
    for(scanf("%d",&n);n>0;n--)
    {
        cin>>s;
        if(s=="push")
        {
            cin>>m;
            q.push(m);
        }
        else if(s=="pop")
        {
            if(q.empty())
                printf("%d\n",-1);
            else
            {
                cout<<q.front()<<'\n';
                q.pop();
            }
        }
        else if(s=="size")
        {
            cout<<q.size()<<'\n';
        }
        else if(s=="empty")
        {
            cout<<q.empty()<<'\n';
        }
        else if(s=="front")
        {
            if(q.empty())
                printf("%d\n",-1);
            else
            cout<<q.front()<<'\n';
        }
        else if(s=="back")
        {
            if(q.empty())
                printf("%d\n",-1);
            else
            cout<<q.back()<<'\n';
        }
    }
}
