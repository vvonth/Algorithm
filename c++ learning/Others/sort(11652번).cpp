//
//  sort(11652번).cpp
//  c++ learning
//
//  Created by 원태희 on 17/04/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
long long arr[1000001];
//메모리:8MB
int main(void)
{
    int N;
    int count=1;
    int ans=1;
    long long r;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+N);
    r=arr[0];//초기화 바꿔줌->input 1개일 때 고려!!!
    for(int i=1;i<N;i++)
    {
        if(arr[i-1]==arr[i])
        {
            count++;
        }
        else
            count=1;
        
        if(ans<count)
            {
                ans=count;
                r=arr[i-1];
            }
    }
    printf("%lld\n",r);
}
