//
//  N과M(1)(15649번).cpp
//  c++ learning
//
//  Created by 원태희 on 18/07/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
/*
#include<iostream>
#include<vector>
using namespace std;
int arr[9];
vector<int> v;
void solution(int cnt,int n,int m){
    if(cnt==m)
    {
        for(int x:v)
            cout<<x<<' ';
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(!arr[i]){
        arr[i]=1;
            v.push_back(i);
        solution(cnt+1,n,m);
            v.pop_back();
        arr[i]=0;
        }
    }
}
int main(void)
{
    int n,m;
    cin>>n>>m;
    solution(0,n,m);
    return 0;
}*/
#include <iostream>
using namespace std;

int arr[9];
int N,R;

int swap(int i, int j)
{
    int temp;
    if (i == j) return 0;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return 0;
}

int Permutation(int n, int r, int depth)
{

    if (r == depth) {
        for (int i = 0; i < R; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return 0;
    }
    
    for (int i = depth; i < n; i++) {
        swap(i, depth);
        Permutation(n, r, depth + 1);
        swap(i, depth);
    }
    return 0;
}

int main()
{
    cin >> N >> R;
    for (int i = 0; i < N; i++) arr[i] = i + 1;
    
    Permutation(N, R, 0);
    return 0;
}
