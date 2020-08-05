//
//  coding test1.cpp
//  c++ learning
//
//  Created by 원태희 on 16/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(void) {
    long long min=0;
    long long n;
    long long w,h;
    cin>>n;
    long long k=sqrtl(n);
    for(w=1;w<=k;w++)
    {
        h=n/w;
        if(h*w==n)
            min=abs(h-w);
    }
    cout<<min<<'\n';
    return 0;
}
