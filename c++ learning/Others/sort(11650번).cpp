//
//  sort(11650번).cpp
//  c++ learning
//
//  Created by 원태희 on 01/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<pair<int, int>> v;
    int n,x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    for(auto x : v)
        cout<<x.first<<' '<<x.second<<'\n';
}
