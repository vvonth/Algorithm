//
//  fill_function(10810번).cpp
//  c++ learning
//
//  Created by 원태희 on 27/02/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

int main(){
    int n,m,a,b,c;
    scanf("%d %d",&n,&m);
    vector<int> v(n,0);
    
    for(int k=0;k<m;k++)
    {
        scanf("%d %d %d",&a,&b,&c);
        fill(v.begin()+(a-1),v.begin()+(b),c);
    }
    for(auto x : v)
    {
        cout<<x<<' ';
    }
    return 0;
}
