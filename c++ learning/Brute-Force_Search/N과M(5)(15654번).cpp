//
//  N과M(5)(15654번).cpp
//  c++ learning
//
//  Created by 원태희 on 21/07/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[9];
int check[9];
vector<int>v;
void solution(int cnt, int n, int m, int *arr){
    if(cnt==m)
    {
        for(int x:v)
            cout<<x<<' ';
        cout<<'\n';
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!check[i]){
            v.push_back(arr[i]);
            check[i]=1;
            solution(cnt+1,n,m,arr);
            v.pop_back();
            check[i]=0;
        }
    }
}
int main(void){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    solution(0,n,m,arr);
    return 0;
}
