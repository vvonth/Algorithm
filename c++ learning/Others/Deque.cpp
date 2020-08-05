//
//  Deque.cpp
//  c++ learning
//
//  Created by 원태희 on 15/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
deque<int> dq;
int main(){
    int n,m;
    string s;
    for(scanf("%d",&n);n>0;n--)
    {
        cin>>s;
        if(s=="push_back")
        {
            scanf("%d",&m);
            dq.push_back(m);
        }
        else if(s=="push_front")
        {
            scanf("%d",&m);
            dq.push_front(m);
        }
        else if(s=="front")
        {   if(dq.empty())
            cout<<-1<<"\n";
            else
            cout<<dq.front()<<"\n";
        }
        else if(s=="back")
        {   if(dq.empty())
            cout<<-1<<"\n";
            else
            cout<<dq.back()<<"\n";
        }
        else if(s=="pop_front")
        {
            if(dq.empty())
                cout<<-1<<"\n";
            else
            {
                cout<<dq.front()<<"\n";
                dq.pop_front();
            }
        }
        else if(s=="pop_back")
        {
            if(dq.empty())
                cout<<-1<<"\n";
            else{
                cout<<dq.back()<<"\n";
                dq.pop_back();
            }
        }
        else if(s=="size")
        {
            cout<<dq.size()<<"\n";
        }
        else if(s=="empty")
        {
            if(dq.empty())
                cout<<1<<"\n";
            else
                cout<<0<<"\n";
        }
    }
    return 0;
}
