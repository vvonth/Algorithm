//
//  나무 자르기(2805번).cpp
//  c++ learning
//
//  Created by 원태희 on 21/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000001];
int main(void)
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    long long min=0;
    long long max=arr[n-1]-1;
    long long ans=0;
    while(min<=max)
    {
        long long sum=0;
        long long h=(min+max)/2;
        for(int i=0;i<n;i++)
        {
            //음수 생각할 것!!
            if(arr[i]>=h)
                sum+=arr[i]-h;
        }
        
        if(m>sum)
        {
            max=h-1;
        }
        else
        {
            if(ans<h)
                ans=h;
            min=h+1;
        }
    }
    cout<<ans<<'\n';
}
