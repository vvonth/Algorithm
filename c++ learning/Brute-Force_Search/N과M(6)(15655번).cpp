//
//  N과M(6)(15655번).cpp
//  c++ learning
//
//  Created by 원태희 on 21/07/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void solution(int cnt, int idx, int *arr, vector<int>&v,int n,int m){
    if(cnt==m){
        for(int x:v)
            cout<<x<<' ';
        cout<<'\n';
        return;
    }
    if(idx==n)
        return;
    v.push_back(arr[idx]);
    solution(cnt+1,idx+1,arr,v,n,m);
    v.pop_back();
    solution(cnt,idx+1,arr,v,n,m);
}

int main(void){
    int arr[9];
    vector<int> v;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    solution(0,0,arr,v,n,m);
    
    return 0;
}
