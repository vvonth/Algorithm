//
//  suffix(11656번).cpp
//  c++ learning
//
//  Created by 원태희 on 15/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
    string s;
    int i;
    cin>>s;
    vector<int> v;
    for(i=0;i<s.size();i++)
    {
        v.push_back(i);
    }
    sort(v.begin(),v.end(),[&s](int u,int v){
        return (strcmp(s.c_str()+u,s.c_str()+v)<0);
    });
    for(auto &x: v)
        cout<<s.substr(x)<<'\n';
}


