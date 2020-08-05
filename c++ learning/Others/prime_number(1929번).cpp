//
//  prime_number(1929번).cpp
//  c++ learning
//
//  Created by 원태희 on 04/04/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
bool c[1000001];
int p[1000001];
int main(void)
{
    int N,M;
    int j=0;
    cin>>M>>N;
    for(int i=2;i<=N;i++)
    {
        if(c[i]==false)
            p[j++]=i;
        for(int k=i*2;k<=N;k+=i)
            c[k]=true;
    }
    for(int i=0;i<j;i++)
    {
        if(p[i]>=M)
        cout<<p[i]<<'\n';
        
    }
}

