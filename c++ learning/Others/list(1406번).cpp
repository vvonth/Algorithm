//
//  list(1406번).cpp
//  c++ learning
//
//  Created by 원태희 on 17/02/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <list>
#include<stack>
using namespace std;

/*int main(){
    
    string c;
    int k;
    cin>>c>>k;
    list<char> editor(c.begin(),c.end());//외우기!
    auto cursor = editor.end();
    for(;k>0;k--)
    {
        char i;
        cin>>i;
        if(i=='P')
        {
            cin>>i;
            editor.insert(cursor, i);
        }
        else if(i=='L')
        {
            if(cursor!=editor.begin())
                cursor--;
            
        }
        else if(i=='D')
        {
            if(cursor!=editor.end())
                cursor++;
        }
        else
        {
            if(cursor!=editor.begin())
            {
                auto temp=cursor;
                editor.erase(--cursor);
                cursor=temp;
            }
        }
        
    }
    for(auto x : editor)
        cout<<x;
    cout<<'\n';
    return 0;
}*/

int main()
{
    stack<char> left,right;
    string n;
    char j;
    int k;
    cin>>n;
    for(int i=0;i<n.size();i++)
        left.push(n[i]);
    scanf("%d",&k);
    while(k>0)
    {
        cin>>j;
        if(j=='P')
        {
            cin>>j;
            left.push(j);
        }
        else if(j=='L'&&!left.empty())
        {
            right.push(left.top());
            left.pop();
        }
        else if(j=='D'&&!right.empty())
        {
            left.push(right.top());
            right.pop();
        }
        else if(j=='B'&&!left.empty())
        {
            left.pop();
        }
        k--;
    }
    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    while(!right.empty())
    {
        cout<<right.top();
        right.pop();
    }
}
