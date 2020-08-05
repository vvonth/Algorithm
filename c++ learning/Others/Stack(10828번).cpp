//
//  Stack(10828번).cpp
//  c++ learning
//
//  Created by 원태희 on 20/02/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

int main(){
    stack<int> s;
    string sentence;
    int n,m;
    for(scanf("%d",&n);n>0;n--)
    {
        cin>>sentence;
        if(sentence=="push")
        {    cin>>m;
            s.push(m);
        }
        else if(sentence=="pop")
        {
            if(s.empty())
                printf("%d\n",-1);
            else
            {    cout<<s.top()<<'\n';
                s.pop();
            }
        }
        else if(sentence=="size")
        {
            cout<<s.size()<<'\n';
        }
        else if(sentence=="empty")
        {
            cout<<s.empty()<<'\n';
        }
        else{
            if(s.empty())
                printf("%d\n",-1);
            else
                cout<<s.top()<<'\n';
        }
    }
    
}
