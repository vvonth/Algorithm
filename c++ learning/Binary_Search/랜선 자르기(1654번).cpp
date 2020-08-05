//
//  랜선 자르기(1654번).cpp
//  c++ learning
//
//  Created by 원태희 on 21/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
/*
#include <iostream>
#include <algorithm>
using namespace std;
long long arr[10001];

long long binary(long long start,long long end,int n,int k)
{
    long long ans=0;
    while(start<=end)
    {
        long long mid=(start+end)/2;
        int count=0;
        for(int i=1;i<=k;i++)
        {
            count+=(arr[i]/mid);
        }
        if(n>count)
        {
            end=mid-1;
        }
        else if(n<=count)
        {
            if(ans<mid)
                ans=mid;
            start=mid+1;
        }
    }
    return ans;
    
}
int main(void)
{
    int k,n;
    scanf("%d %d",&k,&n);
    for(int i=1;i<=k;i++)
    {
        scanf("%lld",&arr[i]);
    }
    //**정렬 범위 생각할 것**
    sort(arr,arr+k+1);
    printf("%lld\n",binary(1, arr[k], n, k));
    return 0;
}
*/
#include<iostream>
#include <algorithm>
using namespace std;
long long arr[10001];
long long bin(long long start, long long end,int n,int k)
{
    long long mid=(start+end)/2;
    if(start>end)
        return start;
    int cnt=0;
    for(int i=0;i<k;i++)
        cnt+=arr[i]/mid;
    if(n>cnt)
    {
        return bin(start,mid-1,n,k);
    }
    else
        return bin(mid+1,end,n,k);
    
}
int main(void)
{
    int k,n;
    scanf("%d %d",&k,&n);
    for(int i=0;i<k;i++)
    {
        scanf("%lld",&arr[i]);
    }
    sort(arr,arr+k);
    cout<<bin(1,arr[k-1],n,k)-1<<'\n';
}

