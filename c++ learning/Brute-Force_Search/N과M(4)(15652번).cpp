//
//  N과M(4)(15652번).cpp
//  c++ learning
//
//  Created by 원태희 on 21/07/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int check[9];
void solution(int cnt, int idx, int n, int m)
{
    if(cnt==m){
        for(int x:v)
            cout<<x<<' ';
        cout<<'\n';
        return;
    }
    if(idx==n+1){
        return;
    }
    v.push_back(idx);
    solution(cnt+1, idx, n, m);
    v.pop_back();
    solution(cnt,idx+1,n,m);
}
int main(void){
    int n,m;
    cin>>n>>m;
    solution(0,1,n,m);
    return 0;
}
