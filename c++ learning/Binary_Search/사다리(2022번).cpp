//
//  사다리(2022번).cpp
//  c++ learning
//
//  Created by 원태희 on 24/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(void)
{
    double x,y,c;
    scanf("%lf %lf %lf",&x,&y,&c);
    double start=0;
    double end=min(x,y);
    while((float)start<(float)end)
    {
        double mid=(start+end)/2;
        double h1=sqrt(x*x-mid*mid);
        double h2=sqrt(y*y-mid*mid);
        double k=(h1*h2)/(h1+h2);
        if(k>c)
            start=mid;
        else
            end=mid;
    }
    printf("%.3f\n",start);
    return 0;
}
