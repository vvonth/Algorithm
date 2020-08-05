//
//  coding test2.cpp
//  c++ learning
//
//  Created by 원태희 on 16/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void){
    string s;
    string a;
    stack<char> t;
    stack <char> n;
    vector<char> v;
    stack<char> k;
    int i;
    int count=0;
    int count2=0;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
                   count++;
        if(s[i]>='1'&&s[i]<='9')
        {
            count2++;
        }
    }
    if(count!=count2)
    {
        printf("error");
        return 0;
    }
    
    for(i=0;i<s.size();i++)
    {
        if(s[i+1]>='a'&&s[i+1]<='z')
        {
            t.push(s[i]);
            t.push(s[i+1]);
        }
        else if(s[i]>='A'&&s[i]<='Z')
        {
            t.push(s[i]);
        }
        else if(s[i]>='1'&&s[i]<='9')
        {
            n.push(s[i]);
        }
    }
    
    while((!t.empty())||(!n.empty()))
    {
        if(n.top()!=1&&(!n.empty()))
        {
        v.push_back(n.top());
            n.pop();
        }
        if((t.top()>='a'&&t.top()<='z')&&(!t.empty()))
        {
            v.push_back(t.top());
            t.pop();
            v.push_back(t.top());
            t.pop();
        }
        else if((t.top()>='A'&&t.top()<='Z')&&(!t.empty()))
        {
            v.push_back(t.top());
            t.pop();
        }
    }
    for(auto x: v)
        k.push(x);
    while(!k.empty())
    {
        if(k.top()!='1')
            cout<<k.top();
        
        k.pop();
    }
}
