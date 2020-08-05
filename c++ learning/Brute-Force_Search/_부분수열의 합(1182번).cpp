//
//  부분수열의 합(1182번).cpp
//  c++ learning
//
//  Created by 원태희 on 18/07/2019.
//  Copyright © 2019 원태희. All rights reserved.
//종료조건 생각할 것
/*
#include <iostream>
using namespace std;

void solution(int *arr,int *ans, int idx,int sum, int S,int N){
   
    if(idx==N){
        if(sum==S)
        {
            (*ans)++;
        }
        return;
    }
    solution(arr,ans,idx+1,sum+arr[idx],S,N);
    solution(arr,ans,idx+1,sum,S,N);
}
int main(void){
    int N,S;
    cin>>N>>S;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    int ans=0;
    solution(arr,&ans,0,0,S,N);
    cout<<ans<<'\n';
    return 0;
}*/
#include<iostream>
using namespace std;
int main(void)
{
    int N,S;
    int ans=0;
    cin>>N>>S;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<(1<<N);i++)
    {
        int sum=0;
        for(int k=0;k<N;k++)
        {
            if((i&(1<<k)))
            {
                sum+=arr[k];
            }
        }
        if(sum==S)
            ans++;
    }
    cout<<ans<<'\n';
    return 0;
}
