//
//  동전 0(11047번).cpp
//  c++ learning
//
//  Created by 원태희 on 30/04/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
int money[11];
int main(void)
{
    int n, k;
    int start=-1;
    int sum=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>money[i];
        if(money[i]>k)
        {
            start=i-1;
        }
    }
    if(start==-1)
    {
        start=n-1;
    }
    while(k)
    {
        if(k>=money[start])
        {
            sum+=k/money[start];
            k%=money[start];
        }
        else
        {
            if(start>0)
                start--;
        }
    }
    cout<<sum<<'\n';
}
