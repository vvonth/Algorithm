//
//  병든 나이트(1783번).cpp
//  c++ learning
//
//  Created by 원태희 on 05/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
    int height,width;
    cin>>height>>width;
    if(height==1)
    {
        cout<<1<<'\n';
        
    }
    else if(height==2)
    {
        
        cout<<min(3,(width-1)/2)+1<<'\n';
    }
    else
    {
        if(width>=7)
        {
            cout<<width-2<<'\n';
        }
        else
        {
            cout<<min(4,width)<<'\n';
        }
    }
    
    return 0;
}
