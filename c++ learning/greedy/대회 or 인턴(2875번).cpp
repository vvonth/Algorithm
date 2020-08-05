//
//  대회 or 인턴(2875번).cpp
//  c++ learning
//
//  Created by 원태희 on 03/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
int main(void)
{
    int n,m,k;
    int count=0;
    cin>>n>>m>>k;
    while(n>=2&&m>=1)
    {
        if(k>n+m-3)
            break;
        n-=2;
        m-=1;
        count++;
    }
    cout<<count<<'\n';
}
