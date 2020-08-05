//
//  공유기 설치(2110번).cpp
//  c++ learning
//
//  Created by 원태희 on 21/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    int n,c;
    scanf("%d %d",&n,&c);
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }
    sort(v.begin(),v.end());
    long long start=v[0];
    long long end=v[n-1];
    while(start<=end)
    {
        int count=1;
        long long mid=(start+end)/2;
        cout<<"mid:"<<mid<<'\n';
        int f=0;
        for(int i=1;i<n;i++)
        {
            
            if(v[f]+mid<=v[i])
            {
                cout<<"v[i]:"<<v[i]<<'\n';
                count++;
                f=i;
            }
        }
        if(count>=c)
        {
            start=mid+1;
        }
        else
            end=mid-1;
    }
    cout<<start-1<<'\n';
    return 0;
}
