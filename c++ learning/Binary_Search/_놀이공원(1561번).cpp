//
//  놀이공원(1561번).cpp
//  c++ learning
//
//  Created by 원태희 on 23/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int arr[10001];
int main(void)
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&arr[i]);
    }
    if(n<=m)
    {
        cout<<n<<'\n';
    }
    else
    {
        long long start=0;
        long long end=2000000000LL * 1000000LL;
        while(start<=end)
        {
            long long sum=m;
            long long mid=(start+end)/2;
            for(int i=1;i<=m;i++)
            {
                sum+=mid/arr[i];
            }
            //sum은 mid분까지개수 n과 같다면? n보다 크다면 줄여야된다 즉 n 보다 작게 n이 존재하는 공간 이전까지..
            if(sum>=n)
            {
                end=mid-1;
            }
            else
                start=mid+1;
            
        }
        //cout<<"start:"<<start<<'\n';
       // cout<<"end:"<<end<<'\n';
        long long s=m;
        for(int i=1;i<=m;i++)
        {
            s+=(end)/arr[i];
        }
        for(int i=1;i<=m;i++)
        {
            if(((end+1)%arr[i])==0)
                s++;
            
            if(s==n)
            {
                cout<<i<<'\n';
                break;
            }
        }
    }
    return 0;
}
