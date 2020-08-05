//
//  queue(1158번).cpp
//  c++ learning
//
//  Created by 원태희 on 20/02/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    
    int m,n,temp;
    queue<int> q;
    vector<int> v;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        q.push(i);
    while(q.size()>1)
    {
        for(int i=1;i<n;i++)
        {
            temp=q.front();
            q.pop();
            q.push(temp);
        }
        v.push_back(q.front());
        q.pop();
    }
    cout<<"<";
    for(auto x : v)
    {
        cout<<x<<", ";
    }
    cout<<q.front()<<">\n";
    return 0;
}
