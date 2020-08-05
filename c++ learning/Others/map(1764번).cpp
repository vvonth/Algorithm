//
//  map(1764번).cpp
//  c++ learning
//
//  Created by 원태희 on 19/02/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <map>

using namespace std;
int main(){
    map<string, int>m;
    int n,k;
    int count=0;
    string name;
    cin>>n>>k;
    for(int i=0;i<n+k;i++)
    {
        cin>>name;
        pair<map<string,int>::iterator, bool>pr=m.insert({name,1});
        if(pr.second!=true)
        {
            m[name]++;
        }
    }
    for(auto x : m)
    {
        if(x.second>1)
        {
            count++;
        }
    }
    cout<<count<<'\n';
    for(auto k: m)
    {
        if(k.second>1)
        {
            cout<<k.first<<'\n';
        }
            
    }
}
