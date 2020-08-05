//
//  N과M(3)(15651번).cpp
//  c++ learning
//
//  Created by 원태희 on 20/07/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void solution(vector<int>&v,int cnt, int n, int m){
    if(cnt==m){
        for(int x:v)
            cout<<x<<' ';
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++)
    {
        v.push_back(i);
        solution(v,cnt+1,n,m);
        v.pop_back();
    }
    
}
int main(void){
    int n,m;
    cin>>n>>m;
    vector<int>v;
    solution(v,0,n,m);
    return 0;
}
