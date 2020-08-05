//
//  eb_test1.cpp
//  c++ learning
//
//  Created by 원태희 on 06/06/2019.
//  Copyright © 2019 원태희. All rights reserved.

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
int solution(vector<int>);
int main(void)
{
    clock_t start, end;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    start=clock();
    cout<<solution(v)<<'\n';
    end=clock();
    printf("%f\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
int solution(vector<int> prices)
{
    int m=prices[0];
    int gap=0;
    int n=(int)prices.size();
    for(int i=0;i<n;i++)
    {
        if(gap<prices[i]-m)
        {
            gap=prices[i]-m;
        }
        if(m>prices[i])
        {
            m=prices[i];
        }
        
    }
    return gap;
}
