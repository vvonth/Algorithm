//
//  N과M(8)(15657번).cpp
//  c++ learning
//
//  Created by 원태희 on 21/07/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v2;
void solution(int cnt,int idx, vector<int>&v,int n,int m){
    if(cnt==m){
        for(auto x:v2){
            cout<<x<<' ';
        }
        cout<<'\n';
        return;
    }
    if(idx==n)
        return;
        v2.push_back(v[idx]);
        solution(cnt+1,idx,v,n,m);
        v2.pop_back();
        solution(cnt,idx+1,v,n,m);
    
}
int main(void){
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    solution(0,0,v,n,m);
    return 0;
}
