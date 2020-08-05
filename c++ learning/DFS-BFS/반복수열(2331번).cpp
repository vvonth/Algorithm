//
//  반복수열(2331번).cpp
//  c++ learning
//
//  Created by 원태희 on 23/04/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int check[1000000];
int main(void)
{
    vector<int> v;
    int n,p;
    int cnt=1;
    cin>>n>>p;
    v.push_back(n);
    check[n]=cnt;
    while(1)
    {
    int sum=0;
    while(n)
    {
        
        int k=n%10;
        int tmp=k;
        
        for(int i=0;i<p-1;i++)
        {
            tmp=tmp*k;
        }
        sum+=tmp;
        n/=10;
    }
        if(!check[sum])
        {
            v.push_back(sum);
            check[sum]=++cnt;
            //cout<<"합: "<<sum<<'\n';
            //cout<<"cnt: "<<cnt<<'\n';
            n=sum;
        }
        else
        {
            cout<<check[sum]-1<<'\n';
            break;
        }
    }
    return 0;
}
