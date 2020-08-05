//
//  N과M(7)(15656번).cpp
//  c++ learning
//
//  Created by 원태희 on 21/07/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int>v;
void solution(int cnt,int *arr,int n, int m){
    if(cnt==m){
        for(vector<int>::iterator iter=v.begin();iter!=v.end();iter++)
        {
            cout<<*iter<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<n;i++)
    {
        v.push_back(arr[i]);
        solution(cnt+1,arr,n,m);
        v.pop_back();
    }
}
int main(void){
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    solution(0,arr,n,m);
    return 0;
}
